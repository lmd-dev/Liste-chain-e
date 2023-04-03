#pragma once
#include <memory>
#include "Maillon.h"

template<class T> class ListeChainee
{
private:
	//Premier maillon de la liste chainee (null si vide)
	std::shared_ptr<Maillon<T> > premierMaillon;

	//Dernier maillon de la liste chainee (null si vide)
	std::shared_ptr<Maillon<T> > dernierMaillon;

	/**
	* Retourne le maillon situé à la position demandée
	* @throw Lève une exception si la position demandée n'est pas valide
	*/
	const std::shared_ptr<Maillon<T> >& getMaillon(int position) const;

public:
	/**
	* Constructeur
	*/
	ListeChainee();

	/**
	* Retourne le nombre d'éléments contenus dans la liste
	*/
	int taille() const;

	/*
	* Ajoute un élément à la liste
	*/
	void ajouter(T donnee);

	/**
	* Insère un élément avant la position indiquée
	* @throw Lève une exception si la position donnée n'est pas valide
	*/
	void inserer(T donnee, int position);

	/**
	* Supprime de la liste l'élément se trouvant à la position donnée
	* @throw Lève une exception si la position donnée n'est pas valide
	*/
	void supprimer(int position);

	/**
	* Retourne la valeur située à la position donnée
	* @throw Lève une exception si la position donnée n'est pas valide
	*/
	T operator[](int position) const;
};

template<class T>
ListeChainee<T>::ListeChainee()
	: premierMaillon(nullptr), dernierMaillon(nullptr)
{

}

template<class T>
int ListeChainee<T>::taille() const
{
	int t = 0;

	auto maillon = premierMaillon;

	while (maillon)
	{
		++t;

		maillon = maillon->getSuivant();
	}

	return t;
}

template<class T>
void ListeChainee<T>::ajouter(T donnee)
{
	auto m = std::make_shared<Maillon<T> >(donnee, dernierMaillon, nullptr);

	if (dernierMaillon != nullptr)
		dernierMaillon->setSuivant(m);

	dernierMaillon = m;

	if (premierMaillon == nullptr)
		premierMaillon = m;
}

template<class T>
void ListeChainee<T>::inserer(T donnee, int position)
{
	auto suivant = getMaillon(position);

	auto precedent = suivant->getPrecedent();

	auto maillon = std::make_shared<Maillon<T> >(donnee, precedent, suivant);

	suivant->setPrecedent(maillon);

	if (precedent == nullptr)
		premierMaillon = maillon;
	else
		precedent->setSuivant(maillon);
}

template<class T>
void ListeChainee<T>::supprimer(int position)
{
	auto maillon = getMaillon(position);

	if (maillon->getPrecedent() != nullptr)
		maillon->getPrecedent()->setSuivant(maillon->getSuivant());
	else
		premierMaillon = maillon->getSuivant();

	if (maillon->getSuivant() != nullptr)
		maillon->getSuivant()->setPrecedent(maillon->getPrecedent());
	else
		dernierMaillon = maillon->getPrecedent();
}

template<class T>
const std::shared_ptr<Maillon<T> >& ListeChainee<T>::getMaillon(int position) const
{
	if (position < 0 || position >= taille())
		throw std::exception("Position incorrecte");

	int index = 0;

	auto maillon = premierMaillon;

	while (maillon && index < position)
	{
		maillon = maillon->getSuivant();

		++index;
	}

	return maillon;
}

template<class T>
T ListeChainee<T>::operator[](int position) const
{
	auto maillon = getMaillon(position);

	return maillon->getDonnee();
}

