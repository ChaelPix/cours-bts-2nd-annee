#include "BdDPVC.h"
#include <stdexcept>
#include <iostream>

CBdDPVC::CBdDPVC() {
    driver = get_driver_instance();
    con = nullptr;
    stmt = nullptr;
    //res = nullptr;
}

bool CBdDPVC::connecter() {
    try {
        con = driver->connect("tcp://[SERVER_IP]:3306", "[LOGIN]", "[PASSWORD]");
        con->setSchema("[DATABASE_NAME]");
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
    //delete res;
    delete stmt;
    delete con;
    //res = nullptr;
    stmt = nullptr;
    con = nullptr;
}

bool CBdDPVC::estUnOperateurAutorise(CPersonnel user) {
    // Implement the logic based on CPersonnel data and SQL queries
    // The implementation will depend on the structure and methods available in CPersonnel
    // And should check if a person exists in a certain table of the database with a role 'OPERATEUR'.
}

std::vector<std::string> CBdDPVC::getListeReferencesOF() {
    // Similar to the other methods, the implementation here would involve executing a SQL query
    // to retrieve a list of references and then returning a vector of these references.
    // Example code might look like:
    std::vector<std::string> references;
    try {

        sql::ResultSet* res = stmt->executeQuery("SELECT reference FROM ordrefabrication");
        while (res->next()) {
            references.push_back(res->getString("reference"));
        }

        delete res;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur lors de la récupération des références: " << e.what();
    }
     
    return references;
}

// Similar implementations should be provided for other member functions.

CFormule CBdDPVC::makeFormule(int idF) {
    // Logic to create and return a CFormule object based on idF
}

CPersonnel CBdDPVC::makePersonnel(int idP) {
    // Logic to create and return a CPersonnel object based on idP
}

int CBdDPVC::getIdFormule(CFormule formule) {
    // Logic to retrieve id of a CFormule object from the database
}

int CBdDPVC::getIdPersonnel(CPersonnel user) {
    // Logic to retrieve id of a CPersonnel object from the database
}

int CBdDPVC::getIdOF(COrdreFabrication of) {
    // Logic to retrieve id of a COrdreFabrication object from the database
}
