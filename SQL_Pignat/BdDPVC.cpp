#include "BdDPVC.h"
#include <stdexcept>
#include <iostream>

CBdDPVC::CBdDPVC() {

	driver = get_driver_instance();
	con = nullptr;
	stmt = nullptr;

}

bool CBdDPVC::connecter() {

	try {
		con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");
		con->setSchema("beaujardt_b");
		stmt = con->createStatement();
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur lors de la connexion: " << e.what();
		return false;
	}

	return true;
}

bool CBdDPVC::connecter(std::string serveur, std::string login, std::string password, std::string baseDeDonnee) {

	try {
		con = driver->connect(serveur, login, password);
		con->setSchema(baseDeDonnee);
		stmt = con->createStatement();
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur lors de la connexion: " << e.what();
		return false;
	}

	return true;
}

void CBdDPVC::deconnecter() {
	delete stmt;
	delete con;
	stmt = nullptr;
	con = nullptr;
}

bool CBdDPVC::estUnOperateurAutorise(CPersonnel user) {

	bool estOperateur = false;
	try {

		std::string requete = "SELECT COUNT(*) FROM personnel WHERE login = " + user.getLogin() + " AND password = " + user.getPassword() + " AND qualite = 'OPERATEUR'";
		sql::ResultSet* res = stmt->executeQuery(requete);

		if (res->next() && res->getInt(1) > 0)
			estOperateur = true;

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return estOperateur;
}

std::vector<std::string> CBdDPVC::getListeReferencesOF() {

	std::vector<std::string> references;

	try {

		sql::ResultSet* res = stmt->executeQuery("SELECT reference FROM ordrefabrication");
		while (res->next()) {
			references.push_back(res->getString("reference"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return references;
}

std::vector<std::string> CBdDPVC::getReferencesOFaTraiter()
{
	std::vector<std::string> refs;

	try {
		sql::ResultSet* res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'X'");

		while (res->next()) {
			refs.push_back(res->getString("reference"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return refs;
}

std::vector<std::string> CBdDPVC::getTypesFormule()
{
	std::vector<std::string> formules;

	try {
		sql::ResultSet* res = stmt->executeQuery("SELECT DISTINCT type FROM Formules");

		while (res->next()) {
			formules.push_back(res->getString("type"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return formules;
}


CFormule CBdDPVC::makeFormule(int idF) {

	try {
		sql::ResultSet* res = stmt->executeQuery("SELECT * FROM formule WHERE id_formule = " + std::to_string(idF));

		if (res->next())
		{
			float pvcBase = std::stof(res->getString("pvcBase"));
			float plastifiant = std::stof(res->getString("plastifiant"));
			float lubrifiant = std::stof(res->getString("lubrifiant"));
			int dureeMalaxage = std::stoi(res->getString("dureeMalaxage"));
			int dureeRefroidissement = std::stoi(res->getString("dureeRefroidissement"));

			CFormule formule(CFormule::RIGIDE, pvcBase, plastifiant, lubrifiant, dureeMalaxage, dureeRefroidissement);
			return formule;

			delete res;
		}
		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	throw("Erreur creation formule");
}


CPersonnel CBdDPVC::makePersonnel(int idP) {

	try {
		sql::ResultSet* res = stmt->executeQuery("SELECT * FROM personnel WHERE id_Personnel = " + std::to_string(idP));

		if (res->next())
		{
			std::string login = res->getString("login");
			std::string password = res->getString("password");
			CPersonnel::Qualite qualite = CPersonnel::Qualite::INCONNU;
			res->getString("qualite") == "OPERATEUR" ? qualite = CPersonnel::Qualite::OPERATEUR : qualite = CPersonnel::Qualite::PREPARATEUR;

			CPersonnel personnel(login, password, qualite);
			return personnel;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	throw("Erreur creation personnel");
}

int CBdDPVC::getIdFormule(CFormule formule) {

	std::string type = formule.getType();
	double pvcBase = formule.getPvcBase();
	double plastifiant = formule.getPlastifiant();
	double lubrifiant = formule.getLubrifiant();
	int dureeMalaxage = formule.getDureeMalaxage();
	int dureeRefroidissement = formule.getDureeRefroidissement();

	try {
		std::string sqlQuery = "SELECT id_Formule FROM Formules WHERE type = '" + type +
			"' AND pvcBase = " + std::to_string(pvcBase) +
			" AND plastifiant = " + std::to_string(plastifiant) +
			" AND lubrifiant = " + std::to_string(lubrifiant) +
			" AND dureeMalaxage = " + std::to_string(dureeMalaxage) +
			" AND dureeRefroidissement = " + std::to_string(dureeRefroidissement) + ";";

		sql::ResultSet* res = stmt->executeQuery(sqlQuery);

		if (res->next())
		{
			int fId = res->getInt("id_Formule");
			return fId;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return -1;
}

int CBdDPVC::getIdPersonnel(CPersonnel user) {

	std::string login = user.getLogin();
	std::string password = user.getLogin();

	try {
		std::string sqlQuery = "SELECT id_Formule FROM Formules WHERE login = " + login + " AND password = " + password;

		sql::ResultSet* res = stmt->executeQuery(sqlQuery);

		if (res->next())
		{
			int uId = res->getInt("id_Personnel");
			return uId;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return -1;
}

int CBdDPVC::getIdOF(COrdreFabrication of) {

	std::string ref = of.getReference();

	try {
		std::string sqlQuery = "SELECT id_Formule FROM Formules WHERE login = " + ref;

		sql::ResultSet* res = stmt->executeQuery(sqlQuery);

		if (res->next())
		{
			//comment recup ?
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Erreur SQL : " << e.what();
	}

	return -1;
}
