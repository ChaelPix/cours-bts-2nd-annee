#include <iostream>

// Les includes strictement nécessaire pour cet exemple
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main()
{
    cout << endl;
    cout << "Premier test du connecteur C++ Mysql" << endl;

    // La gestion d'erreur se fait proprement avec les exceptions
    // sinon retirer le try...catch

    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // Etape 1 : créer une connexion à la BDD
        driver = get_driver_instance();
        // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");

        // Etape 2 : connexion à la base choisie, ici olivier_db
        con->setSchema("beaujardt_b");

        // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
        stmt = con->createStatement();

        // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
        res = stmt->executeQuery("SELECT * FROM personnel");

        // Etape 5 : exploitation du résultat de la requête
        while (res->next()) {
            cout << "\t... MySQL a repondu: ";
            // Acces par non du champ de la table : ici le champ 'id' que l'on recupère au format string
            cout << res->getString("id") << endl;
            cout << "\t... MySQL la suite : ";
            // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'), 5 le nom de l'animal
            cout << res->getString(1) << endl;
        }

        // On nettoie tout avant de sortir : effacement des pointeurs
        // le pointeur sur le Driver sera effacé tout seul
        delete res;
        delete stmt;
        delete con;

    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}