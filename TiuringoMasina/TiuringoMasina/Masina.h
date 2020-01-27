#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Masina
{
public:
	int gpj;
	string juosta;
	int busena = 0;
	string failo_vardas;

	struct komandos{
		int esama_busena;
		int nauja_busena;
		char esamas_simbolis;
		char kryptis;
		char naujas_simbolis;
	};
	
	vector<komandos> Komandos;

	void Skaitymas(string);
	bool Patikrinimas();
	void Zingsnis();
	void Spausdinimas();
	Masina();
	~Masina();
};

