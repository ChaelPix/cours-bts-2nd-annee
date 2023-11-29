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

	std::string requete = "SELECT COUNT(*) FROM personnel WHERE login = '" + user.getLogin() + "' AND password = '" + user.getPassword() + "' AND qualite = 'OPERATEUR'";
	sql::ResultSet* res = stmt->executeQuery(requete);

	if (res->rowsCount() > 0)
		estOperateur = true;

	delete res;

	return estOperateur;
}

bool CBdDPVC::estUnPreparateurAutorise(CPersonnel user) {

	bool estPreparateur = false;

	std::string requete = "SELECT COUNT(*) FROM personnel WHERE login = '" + user.getLogin() 
		+ "' AND password = '" + user.getPassword() + "' AND qualite = 'PREPARATEUR'";
	sql::ResultSet* res = stmt->executeQuery(requete);

	std::cout << requete << std::endl;

	//si resultat, alors login, mdp, prepa ok
	if (res->next() && res->getInt(1) > 0)
		estPreparateur = true;

	delete res;

	return estPreparateur;
}

bool CBdDPVC::supprimerOF(std::string refOF)
{
	bool isSuccess = false;

	std::string requete = "DELETE from ordrefabrication WHERE reference = '" + refOF + "'";
	stmt->executeUpdate(requete);
	isSuccess = true;

	std::cout << requete << std::endl;

	return isSuccess;
}

std::vector<std::string> CBdDPVC::getListeReferencesOF() {

	std::vector<std::string> references;

	sql::ResultSet* res = stmt->executeQuery("SELECT reference FROM ordrefabrication");
	while (res->next()) {
		references.push_back(res->getString("reference"));
	}

	delete res;

	return references;
}

std::vector<std::string> CBdDPVC::getReferencesOFaTraiter()
{
	std::vector<std::string> refs;

	sql::ResultSet* res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'X'");

	while (res->next()) {
		refs.push_back(res->getString("reference"));
	}

	delete res;

	return refs;
}

std::vector<std::string> CBdDPVC::getTypesFormule()
{
	std::vector<std::string> formules;

	sql::ResultSet* res = stmt->executeQuery("SELECT DISTINCT type FROM formule");

	while (res->next()) {
		formules.push_back(res->getString("type"));
	}

	delete res;

	return formules;
}

COrdreFabrication CBdDPVC::getOrdreFabrication(std::string referenceOF)
{

	sql::ResultSet* res = stmt->executeQuery("SELECT * FROM ordrefabrication WHERE reference = '" + referenceOF + "'");

	if (res->next()) {

		int idF = res->getInt("id_Formule");
		CFormule formule = makeFormule(idF);
		double quantite = res->getDouble("quantite");

		COrdreFabrication::Etat etat;
		std::string etatChar = res->getString("etat");
		if (etatChar == "T")
			etat = COrdreFabrication::Etat::T;
		else if (etatChar == "E")
			etat = COrdreFabrication::Etat::E;
		else
			etat = COrdreFabrication::Etat::X;

		std::string heureFin = res->getString("heureFin");

		int idP = res->getInt("id_Personnel");
		CPersonnel personnel = makePersonnel(idP);

		COrdreFabrication of(referenceOF, formule, quantite, etat, heureFin, personnel);
		return of;
	}

	delete res;
}

CPersonnel CBdDPVC::getPersonnel(std::string loginP)
{
	sql::ResultSet* res = stmt->executeQuery("SELECT * FROM personnel WHERE login = '" + loginP + "'");

	if (res->next()) {

		int idP = res->getInt("id_Personnel");
		CPersonnel personnel = makePersonnel(idP);
		return personnel;
	}

	delete res;
}

bool CBdDPVC::majEtatEnCours(COrdreFabrication& of, CPersonnel operateur)
{
	bool isSuccess = false;

	int idPersonnel = getIdPersonnel(operateur);
	int idOf = getIdOF(of);
	stmt->executeUpdate("UPDATE ordrefabrication SET etat = 'E', id_Personnel = '" + std::to_string(idPersonnel) + "' WHERE id_OrdreFabrication = '" + std::to_string(idOf) + "'");
	isSuccess = true;
	of.setEtat(COrdreFabrication::E);

	return isSuccess;
}

bool CBdDPVC::majHeureFin(COrdreFabrication& of)
{
	bool isSucess = false;

	int idOf = getIdOF(of);
	stmt->executeUpdate("UPDATE ordrefabrication SET etat = 'T', heurefin = NOW() WHERE id_OrdreFabrication = " + std::to_string(idOf));
	isSucess = true;

	of.setEtat(COrdreFabrication::E);

	return isSucess;
}

bool CBdDPVC::AddOF(const COrdreFabrication& of)
{
	bool isSucess = false;

	int idOf = getIdOF(of);

	int f = (getIdFormule(of.getFormule()));

	if (f == -1) f = 2;

	std::string requete = "INSERT INTO `ordrefabrication`(`reference`, `id_Formule`, `quantite`, `etat`, `id_Personnel`) VALUES('" 
		+ of.getReference() + "', "
		+ std::to_string(f) + ", "
		+ std::to_string(of.getQuantite()) + ", " 
		+ "'" + of.getEtat() + "', "
		+ std::to_string(getIdPersonnel(of.getPreparateur())) 
		+ ")";

	std::cout << requete << std::endl;

	stmt->executeUpdate(requete);
	isSucess = true;

	return isSucess;
}


CFormule CBdDPVC::makeFormule(int idF) {

	sql::ResultSet* res = stmt->executeQuery("SELECT * FROM formule WHERE id_formule = " + std::to_string(idF));

	if (res->next())
	{
		float pvcBase = std::stof(res->getString("pvcBase"));
		float plastifiant = std::stof(res->getString("plastifiant"));
		float lubrifiant = std::stof(res->getString("lubrifiant"));
		int dureeMalaxage = std::stoi(res->getString("dureeMalaxage"));
		int dureeRefroidissement = std::stoi(res->getString("dureeRefroidissement"));

		CFormule formule(CFormule::Type::RIGIDE, pvcBase, plastifiant, lubrifiant, dureeMalaxage, dureeRefroidissement);
		return formule;

		delete res;
	}
	delete res;
}

std::vector<int> CBdDPVC::GetFormulesId()
{
	std::vector<int> formules;

	sql::ResultSet* res = stmt->executeQuery("SELECT id_Formule FROM formule");
	while (res->next()) {
		formules.push_back(res->getInt("id_Formule"));
	}
	delete res;

	std::cout << "SELECT id_Formule FROM formule" << std::endl;

	return formules;
}

CPersonnel CBdDPVC::makePersonnel(int idP) {

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

int CBdDPVC::getIdFormule(CFormule formule) {

	std::string type = formule.getType();
	double pvcBase = formule.getPvcBase();
	double plastifiant = formule.getPlastifiant();
	double lubrifiant = formule.getLubrifiant();
	int dureeMalaxage = formule.getDureeMalaxage();
	int dureeRefroidissement = formule.getDureeRefroidissement();

	std::string sqlQuery = "SELECT id_Formule FROM formule WHERE type = '" + type +
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

	return -1;
}

int CBdDPVC::getIdPersonnel(CPersonnel user) {

	std::string login = user.getLogin();
	std::string password = user.getPassword();

	std::string sqlQuery = "SELECT id_Personnel FROM personnel WHERE login = '" + login + "' AND password = '" + password + "'";

	sql::ResultSet* res = stmt->executeQuery(sqlQuery);

	if (res->next())
	{
		int uId = res->getInt("id_Personnel");
		return uId;
	}

	return -1;
}

int CBdDPVC::getIdOF(COrdreFabrication of) {

	std::string ref = of.getReference();

	std::string sqlQuery = "SELECT id_OrdreFabrication FROM ordrefabrication WHERE reference = '" + ref + "'";

	sql::ResultSet* res = stmt->executeQuery(sqlQuery);

	if (res->next())
	{
		int id = res->getInt("id_OrdreFabrication");
		return id;
	}

	return -1;
}
