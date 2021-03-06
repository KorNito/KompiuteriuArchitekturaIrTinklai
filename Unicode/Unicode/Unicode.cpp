// Unicode

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int KurisSablonas(int skaicius) {
	int sablonas = 0;

	if (skaicius <= 127) {
		sablonas = 1;
	}
	else if (skaicius >= 128 && skaicius <= 2047) {
		sablonas = 2;
	}
	else if (skaicius >= 2048 && skaicius <= 65535) {
		sablonas = 3;
	}
	else {
		sablonas = 4;
	}

	return sablonas;
}

void Dejimas(int skaicius, char binArray[], int masDydis) {
	char A[32];
	char UTF8[6];
	int uzpildytoSablonoDydis = 0;
	string keturiElementai("0000");
	int ASK = 0;

	if (KurisSablonas(skaicius) == 1) { 
		for (int i = 7; i >= 0; i--) {
			A[i] = binArray[masDydis-1]; //Pildomam sablonui priskiriami apskaiciuoto masyvo elementai. -1, nes kiekis nuo 0 pradedamas skaiciuot
			masDydis--;
			if (A[i] != '0' && A[i] != '1') { // Uzpildome likusi masyva nuliais jei ten nebuvo 1 ir 0
				A[i] = '0';
			}
		}
		A[0] = '0'; // nes pirmam sablone 0xxx xxxx
		uzpildytoSablonoDydis = 8; //esamas sablono dydis 8, nes 1 sablone 8 bitai
	}
	else if (KurisSablonas(skaicius) == 2) {
		for (int i = 15; i >= 0; i--) {
			A[i] = binArray[masDydis - 1];
			masDydis--;
			if (A[i] != '0' && A[i] != '1') {
				A[i] = '0';
			}
		}
		A[9] = '0';
		A[8] = '1';
		A[2] = '0';
		A[1] = '1';
		A[0] = '1';
		uzpildytoSablonoDydis = 16; 
	}
	else if (KurisSablonas(skaicius) == 3) {
		for (int i = 23; i >= 0; i--) {
			A[i] = binArray[masDydis - 1];
			masDydis--;
			if (A[i] != '0' && A[i] != '1') {
				A[i] = '0';
			}
		}
		A[17] = '0';
		A[16] = '1';
		A[9] = '0';
		A[8] = '1';
		A[3] = '0';
		A[2] = '1';
		A[1] = '1';
		A[0] = '1';
		uzpildytoSablonoDydis = 24;
	}
	else {
		for (int i = 31; i >= 0; i--) {
			A[i] = binArray[masDydis - 1];
			masDydis--;
			if (A[i] != '0' && A[i] != '1') {
				A[i] = '0';
			}
		}
		A[25] = '0';
		A[24] = '1';
		A[17] = '0';
		A[16] = '1';
		A[9] = '0';
		A[8] = '1';
		A[4] = '0';
		A[3] = '1';
		A[2] = '1';
		A[1] = '1';
		A[0] = '1';
		uzpildytoSablonoDydis = 32;
	}

	int temp = 0;
	while(uzpildytoSablonoDydis>0){
	for (int i = 0; i < 4; i++) {
		keturiElementai[i] = A[ASK]; // stringo elementai iki 4 dideja, o sablono masyvas nuolatos dideja
		ASK++;
	}
	if (keturiElementai == "0000") UTF8[temp] = '0';
	else if (keturiElementai == "0001") UTF8[temp] = '1';
	else if (keturiElementai == "0010") UTF8[temp] = '2';
	else if (keturiElementai == "0011") UTF8[temp] = '3';
	else if (keturiElementai == "0100") UTF8[temp] = '4';
	else if (keturiElementai == "0101") UTF8[temp] = '5';
	else if (keturiElementai == "0110") UTF8[temp] = '6';
	else if (keturiElementai == "0111") UTF8[temp] = '7';
	else if (keturiElementai == "1000") UTF8[temp] = '8';
	else if (keturiElementai == "1001") UTF8[temp] = '9';
	else if (keturiElementai == "1010") UTF8[temp] = 'A';
	else if (keturiElementai == "1011") UTF8[temp] = 'B';
	else if (keturiElementai == "1100") UTF8[temp] = 'C';
	else if (keturiElementai == "1101") UTF8[temp] = 'D';
	else if (keturiElementai == "1110") UTF8[temp] = 'E';
	else if (keturiElementai == "1111") UTF8[temp] = 'F';
	temp++;
	uzpildytoSablonoDydis -= 4;
	}

	for (int i = 0; i < temp-1; i++) {
		cout << UTF8[i];
	}
}

int MasyvoDydis(char binArray[]) {
	int masDydis = 0;
	for (int i = 0; i <= 31; i++) {
		if (binArray[i] == '0' || binArray[i] == '1') {
			masDydis++;
		}
	}
	return masDydis;
}

int ReturnUnicodeFromLentele(int skaicius) {
	ifstream lentele("473_to_Unicode.txt");

	int pirmasStulpelis;
	int antrasStulpelis;

	while (!lentele.eof()) {
		lentele >> pirmasStulpelis >> antrasStulpelis;
			if (pirmasStulpelis == skaicius) {
				lentele.close();
				return antrasStulpelis;
		}
	}
	return -1;
}

int main()
{	
	ifstream filename("386intel.txt");
	ofstream rezultatas("rezultatas.txt");

	int skaicius;
	char binArray[32];
	unsigned char simbolis;
	int i = 0;

	while (i < 5) {
		i++;
		filename >> simbolis;
		skaicius = (int)simbolis;
		if (skaicius < 128) {
			rezultatas << simbolis;
		}
		else {
			_itoa_s(ReturnUnicodeFromLentele(skaicius), binArray, 2);
			KurisSablonas(skaicius);
			Dejimas(skaicius, binArray, MasyvoDydis(binArray));
		}
	}
	
	system("pause");

	return 0;
}