#ifndef _BDDPVC_
#define _BDDPVC_

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>

#include <vector>
#include <string>

// Chemins à modifier éventuellement
#include "Personnel.h"
#include "Formule.h"
#include "OrdreFabrication.h"

ref class CBdDPVC
{
public:
	/**
	 * Constructeur unique et par défaut
	 */
	CBdDPVC();

	/**
	 * Assure la connexion à la base de données du projet
	 * Les données necessaires à la connexion sont définies dans le code
	 * @return l'état de la connexion
	 */
	bool connecter();

	/**
	 * Assure la connexion à la base de données du projet
	 * Les données necessaires à la connexion sont passées en paramètre
	 * @return l'état de la connexion
	 */
	bool connecter(std::string serveur, std::string login, std::string password, std::string baseDeDonnee);

	/**
	 * Assure la déconnexion de la base de données du projet
	 */
	void deconnecter(); 

	/**
	 * Permet de connaître si l'utilisateur transmis en paramètre existe bien dans la base de données.
	 * @param user Utilisateur dont on souhaite vérifier l'existence
	 * @return true si l'utilisateur en question existe bien dans la BdD et que sa qualité est bien 'OPERATEUR'
	 */
	bool estUnOperateurAutorise(CPersonnel user);

	/**
	 * Permet de connaître tous les ordres de fabrication présents dans la BD
	 * @return un tableau de chaine contenant les références des OF
	 */
	std::vector<std::string> getListeReferencesOF();

	/**
	 * Permet de connaître tous les ordres de fabrication à traiter
	 * @return un tableau de chaine contenant les références des OF à traiter
	 */
	std::vector<std::string> getReferencesOFaTraiter();

	/**
	 * Permet de connaître toutes les formules existant actuellement dans 
	 * la base, ( donc utilisable dans un ordre de fabrication)
	 * @return un tableau de chaine contenant les types (Ex : RIGIDE/SOUPLE) 
	 * des formules
	 */
	std::vector<std::string> getTypesFormule();

	/**
	 * Permet de connaître les caractéristiques d'un OF à partir de sa référence
	 * @param refrenceOF référence de l'OF dont on souhaite connaître les caractéristiques
	 * @return l'ordre de fabrication correspondant à la référence transmis en paramètre
	 */
	COrdreFabrication getOrdreFabrication(std::string referenceOF);

	/**
	 * Permet de connaître les caractéristiques d'un utilisateur à partir de son login
	 * @param loginP login de l'utilisateur dont on souhaite connaître les caractéristiques
	 * @return la personne correspondant au login transmis en paramètre
	 */
	CPersonnel getPersonnel(std::string loginP);

	/**
	 * Permet de mettre à jour la base de données en indiquant que l'OF transmis 
	 * en paramètre est en cours de traitement et en indiquant les caractéristiques de l'opérateur
	 * @param of l'OF dont on souhaite modifier l'état
	 * @return true en cas de succès de la mise à jour dans la BdD
	 */
	bool majEtatEnCours(COrdreFabrication& of, CPersonnel operateur);

	/**
	 * Permet de mettre à jour la base de données en indiquant que l'OF transmis 
	 * en paramètre a été traité et inscrit dans la BdD l'heure de fin de traitement
	 * @param of l'OF dont on souhaite modifier l'état et mettre à jour l'heure de la fin du traitement
	 * @return true en cas de succès de la mise à jour dans la BdD
	 */
	bool majHeureFin(COrdreFabrication& of);

private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	//sql::ResultSet* res;	// A SUPPRIMER ET A METTRE DANS LES METHODES EN LOCAL

		// Méthodes utilitaires privées

	
	/* throw ("erreur creation formule") */
	CFormule makeFormule(int idF);
	/* throw ("erreur creation personnel") */
	CPersonnel makePersonnel(int idP);
	int getIdFormule(CFormule formule);
	int getIdPersonnel(CPersonnel user);
	int getIdOF(COrdreFabrication of);
};

#endif