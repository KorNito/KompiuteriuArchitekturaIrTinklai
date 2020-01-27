// TiuringoMasina

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Masina.h"

//#include <cstring> konvertuoja

using namespace std;

int main() {
	Masina Turing[4];

	Turing[0].Skaitymas("U1.txt");
	Turing[1].Skaitymas("U2.txt");
	Turing[2].Skaitymas("U3.txt");
	Turing[3].Skaitymas("U4.txt");

	while (1) {
		Sleep(50);

		system("cls");

		for (int i = 0; i < 4; i++) {
			Turing[i].Zingsnis();
		}

		for (int i = 0; i < 4; i++) {
			Turing[i].Spausdinimas();
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}

	}

}
/*
int funkcija(int gpj, string juosta, int busena, int esama_busena[], int nauja_busena[], char esamas_simbolis[], char naujas_simbolis[], char kryptis[], int a) {
	
	system("cls");

	if (gpj < 0){
		cout << "galvutes pozicija negali buti neigiama" << endl;
		return 0;
	}

	if (nauja_busena == -1) {
		cout << "Negalimas simbolis" << endl;
		return 0;
	}

	cout << "Press q to end this program" << endl; 
	for (int i = 0;i<gpj - 1;i++) {
		cout << " ";
	}
	cout << "V" << endl;
	cout << juosta << endl;

	if (GetAsyncKeyState('Q')) {
		return 0;
	}

	for (int i = 0;i<a / 5;i++) {
		if (esama_busena[i] == busena && esamas_simbolis[i] == juosta[gpj - 1]) {
			juosta[gpj - 1] = naujas_simbolis[i];
			busena = nauja_busena[i];
			if (kryptis[i] == 'R') {
				gpj++;
			}
			else {
				gpj--;
			}

			return funkcija(gpj, juosta, busena, esama_busena, nauja_busena, esamas_simbolis, naujas_simbolis, kryptis, a);
		}
	}
	return 0;
}
int main() {
	int* esama_busena;
	int* nauja_busena;
	char* esamas_simbolis;
	char* naujas_simbolis;
	char* kryptis;
	int a = 0, gpj, busena = 0, eil_sk = 0;
	char filename[50];
	string juosta, programa;

	ifstream inFile;

	ivedimas:
	cout << "Iveskite failo pavadinima." << endl;
	cin.getline(filename, 50);

	inFile.open(filename);
	if (inFile.fail()) {
		cerr << "Negalima atidaryti failo." << endl;
		goto ivedimas;
	}

	while (inFile.good()) {
		inFile >> programa;
		a++;
	}
	a -= 2;

	esama_busena = new int[a / 5];
	nauja_busena = new int[a / 5];
	esamas_simbolis = new char[a / 5];
	naujas_simbolis = new char[a / 5];
	kryptis = new char[a / 5];

	inFile.close();
	inFile.open(filename);

	inFile >> gpj;
	inFile >> juosta;

	for (int i = 0;i<a / 5;i++) {
		inFile >> esama_busena[i];
		inFile >> esamas_simbolis[i];
		inFile >> naujas_simbolis[i];
		inFile >> kryptis[i];
		inFile >> nauja_busena[i];
		if (inFile.fail()) {
			nauja_busena[i] = -1;
			inFile.clear();
			inFile >> programa;
		}
	}

	inFile.close();

	funkcija(gpj, juosta, busena, esama_busena, nauja_busena, esamas_simbolis, naujas_simbolis, kryptis, a);

	goto ivedimas;

	system ("pause");

	/*
	//  konvertavimas
	inFile >> programa;
	stringstream convert(programa);
	convert>>esama_busena;
	}
	
	
}*/