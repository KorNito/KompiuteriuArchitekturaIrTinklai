// XOR.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void XOR(int sk1, int sk2) {
	
	vector<int> pirmassk;
	vector<int> antrassk;
	vector<int> ats1;
	vector<int> ats2;

	int vektIlgis;
	int didVekt = 0;

	char binArray1[100];
	char binArray2[100];

	_itoa_s(sk1, binArray1, 2);
	_itoa_s(sk2, binArray2, 2);

	for (int i = 0; i < sizeof(binArray1); i++) { // Sudedam i vektoriu, kad ilgiai vienodi butu
		if (binArray1[i] == '1') {
			pirmassk.push_back(1);
		}
		else if (binArray1[i] == '0') {
			pirmassk.push_back(0);
		}

		if (binArray2[i] == '1') {
			antrassk.push_back(1);
		}
		else if (binArray2[i] == '0') {
			antrassk.push_back(0);
		}
	}

	int skirtumas = 0;

	if (pirmassk.size() > antrassk.size()) { // vektoriaus ilgis ir kuris didziausias
		vektIlgis = pirmassk.size();
		didVekt = 1;
		skirtumas = pirmassk.size() - antrassk.size();
	}
	else {
		vektIlgis = antrassk.size();
		didVekt = 2;
		skirtumas = antrassk.size() - pirmassk.size();
	}

	for (int i = 0; i < skirtumas; i++) { // Uzpildomas vektorius nuliais
		if (didVekt == 1 /*&& antrassk[i] != 0 && antrassk[i] != 1*/) {
			antrassk.insert(antrassk.begin(), 0); 
		}
		else if(didVekt == 2 /*&& pirmassk[i] != 0 && pirmassk[i] != 1*/){
			pirmassk.insert(pirmassk.begin(), 0);
		}
	}

	/*
		V = ||
		^ = &&
		not = !
	*/
	for (int i = 0; i < vektIlgis; i++) {
		ats1.push_back(!(pirmassk[i] && antrassk[i]) && (pirmassk[i] || antrassk[i])); // pagal formule
		ats2.push_back(!(!(pirmassk[i] && (!(pirmassk[i] && antrassk[i]))) && (!(antrassk[i] && (!(pirmassk[i] && antrassk[i]))))));
	}

    int rezultatas = 0;
	int rezultatas2 = 0;	
	int elementas = 0;
	int elementas2 = 0;
	int laipsnis = ats1.size() - 1;

	for (int i = 0; i < ats1.size(); i++) { // vertimas is 10 i 2

		elementas = ats1[i];
		rezultatas = rezultatas + (elementas*pow(2, laipsnis));
		
		elementas2 = ats2[i];
		rezultatas2 = rezultatas2 + (elementas2*pow(2, laipsnis));

		laipsnis--;
	}

	cout << "XOR pagal formule: " << rezultatas << endl;
	cout << "NAND: " << rezultatas2 << endl;
}

int main(int argc, char** argv) //int argc, char** argv
{
	int sk1, sk2, blt;
	
	sk1 = atoi(argv[1]);
	sk2 = atoi(argv[2]);

	//cin >> sk1 >> sk2;
	blt = sk1 ^ sk2;
	
	cout << "XOR: " << blt << endl;
	
	XOR(sk1, sk2);

	system("pause");
}