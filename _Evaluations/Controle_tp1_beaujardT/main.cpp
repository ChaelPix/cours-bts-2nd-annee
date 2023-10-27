/*********************************************************
Programme de gestion de Livres ultra complet et détaillé
Merci de votre achat de mon code.

						Copyright Beaujard Traïan - 2023
**********************************************************/
#include <iostream> 
#include "Livre.h"

int main()
{
	//********* Ex 4 - 1
	Livre::Auteur auteur;
	auteur.nom = "MEURSDESOIF";
	auteur.prenom = "JEAN";
	Livre livre1("un super livre", auteur, Livre::Etat::DISPONIBLE);

	//********* Ex 4 - 2
	std::cout << "id enum correspondant au genre du Livre1 : " << static_cast<int>(livre1.getGenre()) << std::endl << std::endl; //le genre n'a pas été initialisé, il prendra sa valeur par défaut "Inconnu" = 99.

	//********* Ex 4 - 3
	livre1.setGenre(Livre::Genre::FANTASTIQUE);

	//********* Ex 4 - 4
	std::cout << livre1.recapituler() << std::endl;

	//********* Ex 4 - 5
	auteur.nom = "AFFRITT"; 
	auteur.prenom = "Barack";
	Livre livre2("Elle est bonne ma...", auteur, Livre::Etat::INCONNU, Livre::Genre::COMEDIE, 2018); // ma quoi ??? Pizza ?

	//********* Ex 4 - 6
	std::cout << livre2.recapituler() << std::endl;

	return 0; //On return 0 car la fonction int main() renvoie un int, c'est à dire un entier. Pourquoi 0 ? Cela est un choix arbitraire, nous pouvons mettre n'importe quel chiffre entier mais il est plus logique d'utiliser 0. En effet, les nombres négatifs sont généralement utilisées pour des codes erreurs, permettant ainsi aux développeurs de trouver via la documentation l'erreur associée. Les nombres positifs sont trop positifs dans leur vie pour être utiliser en tant que return final, pas sûr que cela soit une vraie explication. Cordialement.
}