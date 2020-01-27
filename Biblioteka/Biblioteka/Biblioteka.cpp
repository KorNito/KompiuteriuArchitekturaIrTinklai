// Biblioteka.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include "Menu.h"
#include <windows.h>

using namespace std;

int main()
{
	while (true) {
		int mygtukas;
		Menu::Langas naujasLangas;

		// Remu brezimas
		naujasLangas.LangoPiesimas(15, 30, 5, 2, 6);

		// Start mygtukas
		naujasLangas.MygtukoPiesimas(3, 15, 13, 5, 6);
		char word[] = { "Start" };
		int size = sizeof(word);
		naujasLangas.Uzrasas(word, size, 6);

		// Exit mygtukas
		naujasLangas.MygtukoPiesimas(3, 15, 13, 11, 6);
		char word1[] = { "Exit" };
		size = sizeof(word1);
		naujasLangas.Uzrasas(word1, size, 6);

		//Valdymas
		mygtukas = naujasLangas.Controls(0, 9);
		if (naujasLangas.Pranesimas(mygtukas) == 1) break;
	}
}