// Kursinis.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Game salis; 

	string saliesPavadinimas;

	cin >> saliesPavadinimas;

	salis.VardintiSali(saliesPavadinimas);

	system("pause");
	
}