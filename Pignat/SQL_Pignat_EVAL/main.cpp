#include <iostream>

// Les includes strictement nécessaire pour cet exemple
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>
#include <Windows.h>

#include "Personnel.h"
#include "Formule.h"
#include "OrdreFabrication.h"
#include "BdDPVC.h"

const std::string grayColor = "\033[38;5;" + std::to_string(255) + "m";
const std::string blueColor = "\033[38;5;" + std::to_string(27) + "m";
const std::string redColor = "\033[38;5;" + std::to_string(196) + "m";
const std::string greenColor = "\033[38;5;" + std::to_string(118) + "m";
const std::string resetColor = "\033[0m";

void DeleteOF(CBdDPVC* bdd)
{
    std::string refOF;

    std::cout << blueColor << "List of OFs: " << resetColor << std::endl;
    std::vector<std::string> listOf = bdd->getListeReferencesOF();

    for (int i = 0; i < listOf.size(); i++)
    {
        std::cout << listOf.at(i) << std::endl;
    }

    std::cout << std::endl << "Choose the " << greenColor << "OF's reference "
        << resetColor << "to" << redColor << " DELETE" << resetColor << " : ";

    std::cin >> refOF;

    bdd->supprimerOF(refOF);

    std::cout << refOF << greenColor << " has been deleted! " << resetColor;
    Sleep(2000);
}

void MakeOF(CBdDPVC* bdd, CPersonnel personnel)
{
    std::string refOF;
    int formulOF;
    double quantityOF;

    COrdreFabrication OF;

    bool isInputOk = true;

    do {
        isInputOk = true;
        //Show List
        std::cout << blueColor << "List of OFs: " << resetColor << std::endl;
        std::vector<std::string> listOf = bdd->getListeReferencesOF();

        for (int i = 0; i < listOf.size(); i++)
        {
            std::cout << listOf.at(i) << std::endl;
        }

        //Input REf
        std::cout << std::endl << grayColor << "Give a reference: " << resetColor;
        std::cin >> refOF;

        //Check Ref
        for (int i = 0; i < listOf.size(); i++)
        {
            if (refOF == listOf.at(i))
                isInputOk = false;
        }
      
        if (!isInputOk)
        {
            system("cls");
            std::cout << redColor << "REF: " << refOF << " ALREADY EXISTS!" << resetColor << std::endl << std::endl;
        }
           
    } while (!isInputOk);
    OF.setReference(refOF);


    do {
        isInputOk = false;
        //Show List
        std::cout << blueColor << "List of Formulas Ids: " << resetColor << std::endl;
        std::vector<int> listFormulas = bdd->GetFormulesId();

        for (int i = 0; i < listFormulas.size(); i++)
        {
            std::cout << listFormulas.at(i) << std::endl;
        }

        //Input FId
        std::cout << grayColor << "Give a formula ID: " << resetColor;
        std::cin >> formulOF;

        //Check Ref
        for (int i = 0; i < listFormulas.size(); i++)
        {
            if (formulOF == listFormulas.at(i))
                isInputOk = true;
        }
      

        if (!isInputOk)
        {
            system("cls");
            std::cout << redColor << "ID :" << formulOF << " DOESN'T EXIST!" << resetColor << std::endl << std::endl;
        }
           

    } while (!isInputOk);

   
    CFormule f = bdd->makeFormule(formulOF);
    OF.setFormule(f);

    std::cout << grayColor << "Set quantity: " << resetColor;
    std::cin >> quantityOF;
    OF.setQuantite(quantityOF);

    OF.setEtat(COrdreFabrication::X);
    OF.setPreparateur(personnel);

    bdd->AddOF(OF);
    std::cout << refOF << greenColor << " has been added! " << resetColor;
    Sleep(2000);
}

int main()
{
    CBdDPVC* bdd = new CBdDPVC();
    bdd->connecter();

    CPersonnel personnel;
    std::string input;

    //Get login
    std::cout << blueColor << "Login : " << resetColor;
    std::cin >> input;
    personnel.setLogin(input);

    //Get Password
    std::cout << blueColor << "Password : " << resetColor;
    std::cin >> input;
    personnel.setPassword(input);

    //Test personnel
    bool isPrepa = bdd->estUnPreparateurAutorise(personnel);

    if (!isPrepa)
    {
        std::cout << redColor << "NO AUTHORIZED!" << std::endl;
        return -1;
    }

    system("cls");
    

    //Menu d'actions...
    bool isRunning = true;
    char choice;

    while (isRunning)
    {
        std::cout << greenColor << "Welcome " << personnel.getLogin() << "!" << resetColor << std::endl << std::endl;

        system("cls");

        std::cout << "\t.....:Choose Action:....." << std::endl << std::endl;

        std::cout << "[1] Delete OF" << std::endl;
        std::cout << "[2] Create OF" << std::endl;
        std::cout << "[0] Exit" << std::endl;

        std::cin >> choice;

        system("cls");

        switch (choice)
        {
            case '1': DeleteOF(bdd);
                break;

            case '2': MakeOF(bdd, personnel);
                break;

            default:
                isRunning = false;
        }
    }

    return 0;
}


