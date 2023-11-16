/*--------------------------------------------
LECTEUR HEURE GPS : 
    Beaujard Traïan
--------------------------------------------*/


/*------Includes-------*/
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <vector>      
#include <sstream>   


typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

ushort NUM_PORT = 50000;
std::string IP_SERVEUR = "10.187.52.16";
const ushort DIMMAX = 1024; 

const uint dateIndex = 1; 
const uint longueurUnite = 2;

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

int main()
{
    uint noctets;
    struct sockaddr_in adr_serveur; 
    uint  ids_client;              
    char trame_lect[DIMMAX + 1];

    // initialisation du winsock
    WORD nVersion = MAKEWORD(2, 2);
    WSADATA donneeWS;
    WSAStartup(nVersion, &donneeWS);

    // 1) Création du socket client
    if ((ids_client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        std::cout << "Echec creation Socket ! " << std::endl;
        exit(1);
    }

    // 2) Connect
    adr_serveur.sin_family = AF_INET;                 
    adr_serveur.sin_port = htons(NUM_PORT);        
    inet_pton(AF_INET, IP_SERVEUR.c_str(), &adr_serveur.sin_addr) <= 0;
    if (connect(ids_client, (struct sockaddr*)&adr_serveur, sizeof(adr_serveur)) < 0)
    {
        std::cout << "Echec connexion ! " << std::endl;
        exit(1);
    }

    // 3) Recv
    noctets = recv(ids_client, trame_lect, DIMMAX, 0);
    trame_lect[noctets] = '\0'; 

    // 4) close
    closesocket(ids_client);

    // Fermeture de winsock
    WSACleanup();

    //---- Traitement de la trame 
    std::vector<std::string> tramesGPS = split(trame_lect, '*');
    std::string trameGPGGA = "";

    for (int i = tramesGPS.size() - 1; i > 0; i--)
    {
        if (tramesGPS.at(i).find("GPGGA") < tramesGPS.at(i).size())
        {
            trameGPGGA = tramesGPS.at(i);
            break;
        }
    }

    if (trameGPGGA == "")
    {
        std::cerr << "ERREUR pas trouv\202 GPGGA";
        return -1;
    }

    std::cout << "Trame GPGGA : " << trameGPGGA << std::endl;
    std::vector<std::string> trameinfos = split(trameGPGGA, ',');
    std::string heureBrute = trameinfos.at(dateIndex);

    int i = 0;
    int heure = std::stoi(heureBrute.substr(i, longueurUnite));
    i += longueurUnite;

    int minute = std::stoi(heureBrute.substr(i, longueurUnite));
    i += longueurUnite;

    double secondes = std::stod(heureBrute.substr(i, heureBrute.size() - i));
    heure = (heure + 2) % 24;
    std::cout << "HEURE GPS: " << heure << "h" << minute << "m" << secondes << "s" << std::endl;

    
    //----
    std::cout << "--- FIN du prog" << std::endl;
    return 0;
}
