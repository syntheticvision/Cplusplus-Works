/***********************************************************************
// OOP244 Workshop #03 p2
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 08 Feb 2024
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Icecream.h"

using namespace std;
namespace seneca {

    void Icecream::displayMenu() const {
        cout << "Select flavour:\n";
        cout << "----------------\n";
        cout << "1: Chocolate\n";
        cout << "2: Strawberry\n";
        cout << "3: Mango\n";
        cout << "4: Tutti fruit\n";
        cout << "5: Almond crunch\n";
        cout << "----------------\n";
    }

    void Icecream::getFlavour() {

        while (true) {
            cout << "> ";

            if (!(cin >> flavour)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }
            else if (flavour < 1 || flavour > 5) {
                cout << "Invlid value(1<=val<=5)" << endl;
            }
            else {
                break; 
            }
        }
    }

    void Icecream::getNumScoops() {
        while (true) {
            cout << "> ";

            if (!(cin >> n_scoops)) {
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }
            else if (n_scoops < 1 || n_scoops > 3) {
                cout << "Invlid value(1<=val<=3)" << endl;
            }
            else {
                break; 
            }
        }
    }

    void Icecream::getOrder() {
        displayMenu();

        getFlavour();

        cout << "Number of Scoops (max 3)\n";
        getNumScoops();

        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o > ";

        string choice = "x"; 
        cin >> choice;

        while (choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
            cout << "Only Y or N are acceptable:" << endl;
            cout << "> ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        if (choice == "y" || choice == "y") {
            wantsVanillaWafer = true;
        }
        else if (choice == "n" || choice == "N")
        {
            wantsVanillaWafer = false;
        }
    }

    double Icecream::printOrder() {


        cout.setf(ios::left);
        cout << "Number of scoops, " << n_scoops << " total:";
        cout.unsetf(ios::left);

        cout.setf(ios::right);
        cout.width(9);
        cout << fixed << setprecision(2) << n_scoops * priceScoop << endl;
        cout.unsetf(ios::right);

        switch (flavour) {
        case 1: cout.setf(ios::left);
            cout.width(24);
            cout << "Chocolate flavour:";
            cout.unsetf(ios::left);

            cout.setf(ios::right);
            cout.width(11);
            cout << priceChocolate * n_scoops << endl;
            cout.unsetf(ios::right);
            break;

        case 2: cout.setf(ios::left);
            cout.width(24);
            cout << "Strawberry flavour\n";
            break;

        case 3: cout << "Mango flavour\n"; break;
        case 4: cout << "Tutti fruit flavour\n"; break;
        case 5: cout << "Almond crunch flavour\n";
            cout.unsetf(ios::left);
            cout.width(0);
            break;
        }

        cout.setf(ios::left);
        cout.width(24);
        cout << "Vanilla Wafer:";
        cout.unsetf(ios::left);

        cout.setf(ios::right);
        cout.width(11);
        if (wantsVanillaWafer) {
            cout << priceVanillaWafer << endl;
            cout.unsetf(ios::right);
        }
        else
        {
            cout << "0.00" << endl;
            cout.unsetf(ios::right);
        }

        double totalPrice = n_scoops * 5.0 + (flavour == 1 ? n_scoops * 1.0 : 0.0) + (wantsVanillaWafer ? 5.0 : 0.0);

        cout.setf(ios::left);
        cout.width(24);
        cout << "Price:";
        cout.unsetf(ios::left);

        cout.setf(ios::right);
        cout.width(11);
        cout << totalPrice << endl;
        cout.unsetf(ios::right);

        return totalPrice;
    }
}
