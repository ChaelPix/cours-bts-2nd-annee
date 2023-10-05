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
   

    try {

        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM personnel WHERE qualite = 'OPERATEUR'");
        while (res->next()) {
            references.push_back(res->getString("reference"));
        }

        delete res;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur SQL : " << e.what();
    }


    res =

    // Etape 5 : exploitation du résultat de la requête
    while (res->next()) {
        cout << "\t... MySQL a repondu: Liste des op\202rateurs : ";
        // Acces par non du champ de la table : ici le champ 'id' que l'on recupère au format string
        cout << res->getString("id_Personnel") << endl;
        cout << "\t... MySQL la suite : ";
        // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'),
        cout << res->getString(2) << " : " << res->getString(3) << endl;
    }

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


CFormule CBdDPVC::makeFormule(int idF) {
    
}

CPersonnel CBdDPVC::makePersonnel(int idP) {
   
}

int CBdDPVC::getIdFormule(CFormule formule) {
   
}

int CBdDPVC::getIdPersonnel(CPersonnel user) {
  
}

int CBdDPVC::getIdOF(COrdreFabrication of) {
   
}
