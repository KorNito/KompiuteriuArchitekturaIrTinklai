// Battleship

#include "stdafx.h"
#include <iostream>
#include <string>
#include "BattleShip.h"
#include "time.h"
#include <cmath>
using namespace std;


int main() {
	BattleShip laukas;

	int xsas, ygrikas;
	char pasirinkimas;

	srand(time(NULL));

	laukas.Clear();
	laukas.SetShipsCarrier();
	laukas.SetShipsCruiser();
	laukas.SetShipsSubmarine();
	laukas.SetShipsDestroyer();

	while(1){
		cout << "Iveskite koordinates(0-9)" << endl;
		cout << "X = Pataikyta M = Nepataikyta" << endl;
		cout << endl;
		cout << "X:"; cin >> xsas;
		cout << "Y:"; cin >> ygrikas;
		cout << endl;

		if(laukas.Suvis(xsas, ygrikas)){
			system("cls");
			laukas.ShowBoard();
		}

		if (laukas.NumberOfShips() == 0) {
			cout << "GG WP";
			return 0;
		}

		cout << "Likusiu laivu skaicius " << laukas.NumberOfShips() << endl;
		cout << "Ar norite pasiduoti (Y/N)?"; 
		cin >> pasirinkimas;
		if(pasirinkimas == 'Y' || pasirinkimas == 'y'){
			break;
		}
	}

	system("cls");
	cout << "Pabaiga" << endl;
	cout << "1 = Destroyer 2 = Submarine 3 = Cruiser 4 = Carrier" << endl;
	cout << endl;
	laukas.ShowEnd();
	system ("pause");

	return 0;
}