#include "ListeChainee.h"
#include <iostream>
/**
* Affiche le contenu de la liste chainée passée en paramètre
*/
void afficher(ListeChainee<std::string>& l)
{
	std::cout << "Taille : " << l.taille() << std::endl;

	for (int i = 0; i < l.taille(); ++i)
	{
		try {
			std::cout << l[i] << std::endl;
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

int main()
{
	ListeChainee<std::string> l;

	l.ajouter("toto");
	l.ajouter("titi");
	l.inserer("tutu", 1);
	l.inserer("pouf", 0);

	afficher(l);

	std::cout << "Suppression du dernier" << std::endl;
	l.supprimer(3);
	afficher(l);

	std::cout << "Suppression du millieu" << std::endl;
	l.supprimer(1);
	afficher(l);

	std::cout << "Suppression du premier" << std::endl;
	l.supprimer(0);
	afficher(l);
	
	return 0;
}