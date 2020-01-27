#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

namespace Menu{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //Mygtuku, spalvos ir kursorio vietos isvedimas

	void Langas::LangoPiesimas(int ilgis, int plotis, int pradkoordX, int pradkoordY, int color){
		COORD vieta; //Koordinatems ivesti
		mygtukuKiekis = 0;
		
		for (int y = 0; y < ilgis; y++)
			for (int x = 0; x < plotis; x++) {
				vieta.X = pradkoordX + x;
				vieta.Y = pradkoordY + y;
				SetConsoleCursorPosition(console, vieta); // Nustato kursoriu i tam tikra vieta
				SetConsoleTextAttribute(console, color); // Teksto ir fono spalva
				if (y == 0) cout << (char)220;
				if (x == 0) cout << (char)219;
				if (x == plotis - 1 && y != 0) cout << (char)219;
				if (y == ilgis - 1 && x != plotis - 1) cout << (char)220;
				else cout << " ";
			}
	}
	void Langas::MygtukoPiesimas(int ilgis, int plotis, int pradkoordX, int pradkoordY, int color) {
		COORD vieta; //Koordinatems ivesti

		milgis = ilgis;
		mplotis = plotis;

		mygtukuKiekis++;

		for (int y = 0; y < ilgis; y++)
			for (int x = 0; x < plotis; x++) {
				vieta.X = pradkoordX + x;
				vieta.Y = pradkoordY + y;
				SetConsoleCursorPosition(console, vieta); // Nustato kursoriu i tam tikra vieta
				SetConsoleTextAttribute(console, color); // Teksto ir fono spalva
				if (y == 0) cout << (char)220;
				if (x == 0) cout << (char)219;
				if (x == plotis-1 && y != 0) cout << (char)219;
				if (y == ilgis-1 && x != plotis-1) cout << (char)220;
				else cout << " ";
			}

		mygtukokoordinateX[mygtukuKiekis] = pradkoordX;
		mygtukokoordinateY[mygtukuKiekis] = pradkoordY;
	}
	void Langas::Uzrasas(char words[], int size, int color) {
		int pradzia = (mplotis - (size - 1)) / 2; //Mygtuko viduryje isvedamas zodis
		
		for (int i = 0; i < size; i++) {
			SetConsoleTextAttribute(console, color);
			vieta.X = mygtukokoordinateX[mygtukuKiekis] + pradzia + i;
			vieta.Y = mygtukokoordinateY[mygtukuKiekis] + 1;
			SetConsoleCursorPosition(console, vieta);
			cout << words[i];
		}
	}
	int Langas::Controls(int pranesimoNumeris, int color) {
		char key;
		int currentMygtukas = 1, buvesMygtukas = 1;

		while (1) {
			vieta.X = mygtukokoordinateX[currentMygtukas];
			vieta.Y = mygtukokoordinateY[currentMygtukas];

			SetConsoleCursorPosition(console, vieta);

			for (int y = 0; y < milgis; y++)
				for (int x = 0; x < mplotis; x++) {
					vieta.X = mygtukokoordinateX[currentMygtukas] + x;
					vieta.Y = mygtukokoordinateY[currentMygtukas] + y;
					SetConsoleCursorPosition(console, vieta); // Nustato kursoriu i tam tikra vieta
					SetConsoleTextAttribute(console, color); // Teksto ir fono spalva
					if (y == 0) cout << (char)220;
					if (x == 0) cout << (char)219;
					if (x == mplotis - 1 && y != 0) cout << (char)219;
					if (y == milgis - 1 && x != mplotis - 1) cout << (char)220;
				}
			key = _getch();

			buvesMygtukas = currentMygtukas; // Isimename sena mygtuka, kad ji nuspalvintume

			switch (key) {
			case 72: currentMygtukas--; break; //arrow key up
			case 80: currentMygtukas++; break; //arrow key down
			case 13: if (pranesimoNumeris == 0) return currentMygtukas; //Enter grazina 1 arba 2, kuris naudojamas pranesimo funkcijoj
					 else if (currentMygtukas == 2) return 0;
					 else return 1;
				break;
			}

			if (currentMygtukas == 0) currentMygtukas = 1;
			else if (currentMygtukas > 2) currentMygtukas = 2;

			if (pranesimoNumeris == 1) PradineBusena(buvesMygtukas, 12);
			else PradineBusena(buvesMygtukas, 6);

		}
		
	}
	void Langas::PradineBusena(int mygtukas, int color) {
		for (int y = 0; y < milgis; y++)
			for (int x = 0; x < mplotis; x++) {
				vieta.X = mygtukokoordinateX[mygtukas] + x;
				vieta.Y = mygtukokoordinateY[mygtukas] + y;
				SetConsoleCursorPosition(console, vieta); // Nustato kursoriu i tam tikra vieta
				SetConsoleTextAttribute(console, color); // Teksto ir fono spalva
				if (y == 0) cout << (char)220;
				if (x == 0) cout << (char)219;
				if (x == mplotis - 1 && y != 0) cout << (char)219;
				if (y == milgis - 1 && x != mplotis - 1) cout << (char)220;
			}
	}
	int Langas::Pranesimas(int currentMygtukas) {
		if (currentMygtukas == 2) {
			LangoPiesimas(8, 30, 5, 5, 12);
			SetConsoleCursorPosition(console, { 7, 8 });
			cout << "Exit the program?" ;

			MygtukoPiesimas(3, 8, 11, 9, 12);
			char word[] = { "Yes" };
			int size = sizeof(word);
			Uzrasas(word, size, 12);

			MygtukoPiesimas(3, 8, 21, 9, 12);
			char word1[] = { "No" };
			size = sizeof(word1);
			Uzrasas(word1, size, 12);

			if (Controls(1, 15) == 1) return 1; //najmame lange controls funkcija su parametru 1
			else return 0;
		}
		return 0;
	}
}

