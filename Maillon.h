#pragma once
#include <memory>

template<class T> class Maillon
{
private:
	//Donnée conservée par la maillon
	T donnee;

	//Maillon précédent dans la liste chainée
	std::shared_ptr<Maillon<T> > precedent;

	//Maillon suivant dans la liste chainée
	std::shared_ptr<Maillon<T> > suivant;

public:
	/**
	* Constructeur
	*/
	Maillon(T donnee, std::shared_ptr<Maillon<T> > precedent, std::shared_ptr<Maillon> suivant);

	/**
	* Getters
	*/
	T getDonnee() const;
	const std::shared_ptr<Maillon<T> >& getPrecedent() const;
	const std::shared_ptr<Maillon<T> >& getSuivant() const;

	/**
	* Setters
	*/
	void setDonnee(T valeur);
	void setPrecedent(const std::shared_ptr<Maillon<T> >& valeur);
	void setSuivant(const std::shared_ptr<Maillon<T> >& valeur);
};

template <class T>
Maillon<T>::Maillon(T donnee, std::shared_ptr<Maillon<T> > precedent, std::shared_ptr<Maillon<T> > suivant)
	: donnee(donnee), precedent(precedent), suivant(suivant)
{

}

template <class T>
T Maillon<T>::getDonnee() const
{
	return donnee;
}

template <class T>
const std::shared_ptr<Maillon<T> >& Maillon<T>::getPrecedent() const
{
	return precedent;
}

template <class T>
const std::shared_ptr<Maillon<T> >& Maillon<T>::getSuivant() const
{
	return suivant;
}

template <class T>
void Maillon<T>::setDonnee(T valeur)
{
	donnee = valeur;
}

template <class T>
void Maillon<T>::setPrecedent(const std::shared_ptr<Maillon<T> >& valeur)
{
	precedent = valeur;
}

template <class T>
void Maillon<T>::setSuivant(const std::shared_ptr<Maillon<T> >& valeur)
{
	suivant = valeur;
}

