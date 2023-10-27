#ifndef _BDDPVC_
#define _BDDPVC_

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>

#include <vector>
#include <string>

// Chemins � modifier �ventuellement
#include "Personnel.h"
#include "Formule.h"
#include "OrdreFabrication.h"

ref class CBdDPVC
{
public:
	/**
	 * Constructeur unique et par d�faut
	 */
	CBdDPVC();

	/**
	 * Assure la connexion � la base de donn�es du projet
	 * Les donn�es necessaires � la connexion sont d�finies dans le code
	 * @return l'�tat de la connexion
	 */
	bool connecter();

	/**
	 * Assure la connexion � la base de donn�es du projet
	 * Les donn�es necessaires � la connexion sont pass�es en param�tre
	 * @return l'�tat de la connexion
	 */
	bool connecter(std::string serveur, std::string login, std::string password, std::string baseDeDonnee);

	/**
	 * Assure la d�connexion de la base de donn�es du projet
	 */
	void deconnecter(); 

	/**
	 * Permet de conna�tre si l'utilisateur transmis en param�tre existe bien dans la base de donn�es.
	 * @param user Utilisateur dont on souhaite v�rifier l'existence
	 * @return true si l'utilisateur en question existe bien dans la BdD et que sa qualit� est bien 'OPERATEUR'
	 */
	bool estUnOperateurAutorise(CPersonnel user);

	/**
	 * Permet de conna�tre tous les ordres de fabrication pr�sents dans la BD
	 * @return un tableau de chaine contenant les r�f�rences des OF
	 */
	std::vector<std::string> getListeReferencesOF();

	/**
	 * Permet de conna�tre tous les ordres de fabrication � traiter
	 * @return un tableau de chaine contenant les r�f�rences des OF � traiter
	 */
	std::vector<std::string> getReferencesOFaTraiter();

	/**
	 * Permet de conna�tre toutes les formules existant actuellement dans 
	 * la base, ( donc utilisable dans un ordre de fabrication)
	 * @return un tableau de chaine contenant les types (Ex : RIGIDE/SOUPLE) 
	 * des formules
	 */
	std::vector<std::string> getTypesFormule();

	/**
	 * Permet de conna�tre les caract�ristiques d'un OF � partir de sa r�f�rence
	 * @param refrenceOF r�f�rence de l'OF dont on souhaite conna�tre les caract�ristiques
	 * @return l'ordre de fabrication correspondant � la r�f�rence transmis en param�tre
	 */
	COrdreFabrication getOrdreFabrication(std::string referenceOF);

	/**
	 * Permet de conna�tre les caract�ristiques d'un utilisateur � partir de son login
	 * @param loginP login de l'utilisateur dont on souhaite conna�tre les caract�ristiques
	 * @return la personne correspondant au login transmis en param�tre
	 */
	CPersonnel getPersonnel(std::string loginP);

	/**
	 * Permet de mettre � jour la base de donn�es en indiquant que l'OF transmis 
	 * en param�tre est en cours de traitement et en indiquant les caract�ristiques de l'op�rateur
	 * @param of l'OF dont on souhaite modifier l'�tat
	 * @return true en cas de succ�s de la mise � jour dans la BdD
	 */
	bool majEtatEnCours(COrdreFabrication& of, CPersonnel operateur);

	/**
	 * Permet de mettre � jour la base de donn�es en indiquant que l'OF transmis 
	 * en param�tre a �t� trait� et inscrit dans la BdD l'heure de fin de traitement
	 * @param of l'OF dont on souhaite modifier l'�tat et mettre � jour l'heure de la fin du traitement
	 * @return true en cas de succ�s de la mise � jour dans la BdD
	 */
	bool majHeureFin(COrdreFabrication& of);

private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	//sql::ResultSet* res;	// A SUPPRIMER ET A METTRE DANS LES METHODES EN LOCAL

		// M�thodes utilitaires priv�es

	
	/* throw ("erreur creation formule") */
	CFormule makeFormule(int idF);
	/* throw ("erreur creation personnel") */
	CPersonnel makePersonnel(int idP);
	int getIdFormule(CFormule formule);
	int getIdPersonnel(CPersonnel user);
	int getIdOF(COrdreFabrication of);
};

#endif