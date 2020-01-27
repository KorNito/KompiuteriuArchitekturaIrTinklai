#include "stdafx.h"
#include "Masina.h"


Masina::Masina()
{
}

void Masina::Skaitymas(string uzduotis) {
	ifstream filename;
	failo_vardas = uzduotis;
	filename.open(uzduotis);

	filename >> gpj >> juosta;

	while (filename.good()) {
		komandos temp;
		string tempString;
		filename >> temp.esama_busena >> temp.esamas_simbolis >> temp.naujas_simbolis >> temp.kryptis >> tempString;
		if (tempString == "X") {
			temp.nauja_busena = -1;
		}
		else {
			temp.nauja_busena = stoi(tempString);
		}
		Komandos.push_back(temp);
	}
}

void Masina::Spausdinimas() {
	cout << failo_vardas << endl;
	cout << juosta << endl;
	for (int i = 0;i<gpj-1;i++) {
		cout << " ";
	}
	cout << "^" << endl;
	cout << endl;
}

bool Masina::Patikrinimas() {
	if (busena == -1 || gpj < 0 || gpj >= juosta.length()) {
		return false;
	}
	else {
		return true;
	}
}

void Masina::Zingsnis() {
	if (Patikrinimas()) {
		for (int i = 0;i < Komandos.size(); i++) {
			if (Komandos[i].esama_busena == busena && Komandos[i].esamas_simbolis == juosta[gpj]) {
				juosta[gpj] = Komandos[i].naujas_simbolis;
				busena = Komandos[i].nauja_busena;
				if (Komandos[i].kryptis == 'R') {
					gpj++;
				}
				else {
					gpj--;
				}
			}
		}
	}
}

Masina::~Masina()
{
	
}
