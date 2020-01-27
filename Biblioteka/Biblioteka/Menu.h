#pragma once
#include <windows.h>
#include <string>

namespace Menu
{
	class Langas {
	private:
		int milgis, mplotis;
		int mygtukuKiekis;
		int mygtukokoordinateX[10];
		int mygtukokoordinateY[10];
		COORD vieta;
	public:
		void LangoPiesimas(int ilgis, int plotis, int pradkoordX, int pradkoordY, int color);
		void MygtukoPiesimas(int ilgis, int plotis, int pradkoordX, int pradkoordY, int color);
		void Uzrasas(char words[], int size, int color);
		int Controls(int pranesimoNumeris, int color);
		void PradineBusena(int mygtukas, int color);
		int Pranesimas(int mygtukas);
	};

};

