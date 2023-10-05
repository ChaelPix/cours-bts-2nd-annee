#ifndef  _Livre_ //Evite la multi inclusion du .h. fonctionne sur tous les os
#define _Livre
#pragma once

#include <string> //Permet d'utiliser les std::string

class Livre
{
public: //Pour pouvoir les utiliser depuis le main

	/***********************************
	* struct Auteur : Contient un std::string nom et std::string prenom.
	***********************************/
	struct Auteur {
		std::string nom;
		std::string prenom;
	};

	/***********************************
	* Livre::Genre : Genre littéraire du livre, dans cette version seulement 2 genres disponibles, Work In Progress.
	***********************************/
	enum class Genre {FANTASTIQUE, COMEDIE, INCONNU = 99};

	/***********************************
	* Livre::Etat : Etat du livre dans la bilibilibilothèque
	***********************************/
	enum class Etat {EMPRUNTE, DISPONIBLE, INCONNU}; 

private:

	/***********************************
	* Titre : nom du livre donné par l'auteur
	***********************************/
	std::string titre;

	/***********************************
	* Auteur : Nom et prenom de l'auteur du livre
	***********************************/
	Auteur auteur;

	/***********************************
	* Genre : genre littéraire du livre
	***********************************/
	Genre genre;

	/***********************************
	* Etat : etat actuel du livre dans la librairie
	***********************************/
	Etat etat;

	/***********************************
	* Annee : Annee d'écriture du livre, 0 = inconnue
	***********************************/
	int annee;

public:

	/********************************************
	* Nom : Livre
	* argument : std::string titre, Auteur auteur, Etat etat
	* Description : Constructeur permettant de donner un titre, l'auteur et l'etat. Le genre sera init a Livre::Genre::Inconnu et annee à 0
	********************************************/
	Livre(std::string titre, Auteur auteur, Etat etat);

	/********************************************
	* Nom : Livre
	* argument : std::string titre, Auteur auteur, Etat etat, Genre genre, int annee
	* Description : Constructeur permettant d'initialiser tous les attributs avec les arguments donnés
	********************************************/
	Livre(std::string titre, Auteur auteur, Etat etat, Genre genre, int annee);

	/********************************************
	* Nom : recapitulatif
	* argument : Aucun
	* retourne : std::string
	* Description : Donne un std::string contenant toute les informations du livre en se basant sur les attributs
	********************************************/
	std::string recapituler();

	/********************************************
	* Nom : getGenre
	* argument : Aucun
	* retourne : Livre::Genre
	* Description : Donne le genre du livre, attention Livre::Genre est un enum, cela donne donc un int
	********************************************/
	Genre getGenre() const;

	/********************************************
	* Nom : getAnnee
	* argument : Aucun
	* retourne : int
	* Description : Donne l'année à laquelle le livre a été écrit. 0 = date est inconnue
	********************************************/
	int getAnnee() const;

	/********************************************
	* Nom : setGenre
	* argument : Livre::Genre genre
	* retourne : rien
	* Description : Change le genre du livre
	********************************************/
	void setGenre(Genre genre);

	/********************************************
	* Nom : setAnnee
	* argument : int annee
	* retourne : rien
	* Description : Change l'année du livre,  0 = date inconnue
	********************************************/
	void setAnnee(int annee);
};

#endif