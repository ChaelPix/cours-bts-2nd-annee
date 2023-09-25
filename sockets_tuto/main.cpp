#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>      
#include <sstream>   

#include "TrameAnalyzer.h"

using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

ushort NUM_PORT = 12345;
const ushort DIMMAX = 150; // Taille max des tableaux
string IP_SERVEUR = "";


std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main(int argc, char* argv[])
{

    if (argc < 3)
    {
        std::cout << "Erreur : Entrez IP (x.x.x.x) puis le Port !";
        return -1;
    }

    /*---------IP Verif--------*/
    std::string ip = argv[1];

    std::vector<string> ipSplit = split(ip, '.');

    if (ipSplit.size() != 4)
    {
        std::cout << "Erreur : L'adresse IP n'est pas en format x.x.x.x !";
        return -1;
    }

    for (int i = 0; i < ipSplit.size(); i++)
    {
        try
        {
            std::stoi(ipSplit.at(i));
            IP_SERVEUR += ipSplit.at(i) + ".";
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Erreur : L'adresse IP a un probleme au " << i+1 << "e nombre";
            return -1;
        }
    }

    IP_SERVEUR.erase(IP_SERVEUR.size() - 1); //retire le dernier point


    /*---------Port Verif--------*/
    try
    {
        NUM_PORT = std::stoi(argv[2]);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Erreur : Port doit etre un nombre entier";
        return -1;
    }


    std::cout << "Adr serveur : " << IP_SERVEUR << " : " << NUM_PORT << std::endl;

    uint n = 0, noctets;

    // Particularités Windows
    WORD nVersion = MAKEWORD(2, 2);
    WSADATA donneeWS;

    struct sockaddr_in  adr_serveur; // @ internet du serveur

    uint  ids_client;   // id du socket client                  
    // tableau contenant les messages provenant du serveur  
    char trame_lect[DIMMAX + 1];

    // initialisation du winsock
    WSAStartup(nVersion, &donneeWS);

    cout << "--- DEBUT du prog" << endl << endl;

    // Création du socket client
    if ((ids_client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Echec creation Socket ! " << endl;
        exit(1);
    }

    // Mise en place de l'@ inet et demande de connexion au serveur 
    adr_serveur.sin_family = AF_INET;                  // Domaine d'@ 
    adr_serveur.sin_port = htons(NUM_PORT);          // N° du port 
    inet_pton(AF_INET, IP_SERVEUR.c_str(), &adr_serveur.sin_addr) <= 0;

    if (connect(ids_client, (struct sockaddr*)&adr_serveur, sizeof(adr_serveur)) < 0)
    {
        cout << "Echec connexion ! " << endl;
        exit(1);
    }

    // Reçoit l'heure du serveur
    noctets = recv(ids_client, trame_lect, DIMMAX, 0);
    trame_lect[noctets] = '\0';

    // Affichage des données reçues
    cout << "Longueur de la chaine recue = " << noctets << endl;
    cout << "Trame recue du serveur = " << trame_lect << endl;

    // fermeture le socket ouvert
    closesocket(ids_client); // à la place de close() sous Linux

    // Fermeture de winsock
    WSACleanup();

    //---- Traitement de la trame 
    TrameAnalyzer trameAnalyse(trame_lect);

    std::cout << "Date : " << trameAnalyse.getDate() << std::endl
        << "Temp : " << trameAnalyse.getTemp() << std::endl
        << "Humidite : " << trameAnalyse.getHumidite() << std::endl
        << "Humidite Corigee : " << trameAnalyse.gethumiditeCorrigee() << std::endl;

    //----

    cout << "--- FIN du prog" << endl;

    cin.get();
    return 0;
}
