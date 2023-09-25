#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#include "TrameAnalyzer.h"

using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const ushort NUM_PORT = 12345;
const ushort DIMMAX = 150; // Taille max des tableaux
const string IP_SERVEUR = "10.187.52.16";

int main()
{
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
