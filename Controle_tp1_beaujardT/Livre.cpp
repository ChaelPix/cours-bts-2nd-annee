#include "Livre.h"

#pragma region Constructeurs

Livre::Livre(std::string titre, Auteur auteur, Etat etat) 
	: titre(titre), auteur(auteur), etat(etat), genre(Livre::Genre::INCONNU), annee(0) {} // On init les variables non renseignées


Livre::Livre(std::string titre, Auteur auteur, Etat etat, Genre genre, int annee)
	: titre(titre), auteur(auteur), etat(etat), genre(genre), annee(annee) {}

#pragma endregion


std::string Livre::recapituler()
{
	std::string recapitulatif = 
		"Titre : " + titre 
		+ "\nAuteur : " + auteur.nom  + " " + auteur.prenom 
		+ "\nGenre : ";

	//genre est un int, on n'a pas de std::map ou autres, on peut simplement faire un switch et ajouter à la chaine le mot correspondant
	switch (genre) 
	{
		case Genre::FANTASTIQUE : recapitulatif += "Fantastique"; break;
		case Genre::COMEDIE : recapitulatif += "Com\202die"; break;
		default:  recapitulatif += "Inconnu"; break;
	}

	recapitulatif += "\nEtat : ";

	//pareil pour etat
	switch (etat)
	{
		case Etat::EMPRUNTE: recapitulatif += "Emprunt\202"; break;
		case Etat::DISPONIBLE: recapitulatif += "Disponible"; break;
		default:  recapitulatif += "Introuvable"; break;
	}

	recapitulatif += "\nAnnee : ";
	annee != 0 ? recapitulatif += std::to_string(annee) : recapitulatif += "Inconnue"; //Si l'annee n'a pas été initiliasée : on ne la connaît pas. L'uml impose annee = 0, si l'année du livre est 0 il y aura conflit. Il vaudrait peut etre mieux mettre annee à une date impossible comme -99999.

	recapitulatif += "\n";
	return recapitulatif;
}


#pragma region Accesseurs/Mutateurs
Livre::Genre Livre::getGenre() const
{
	return genre;
}

int Livre::getAnnee() const
{
	return annee;
}

void Livre::setGenre(Genre genre)
{
	this->genre = genre;
}

void Livre::setAnnee(int annee)
{
	this->annee = annee;
}
#pragma endregion


