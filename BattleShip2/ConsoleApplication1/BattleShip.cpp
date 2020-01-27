#include "stdafx.h"
#include "BattleShip.h"


void BattleShip::Clear()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = 0;
		}
	}
}

void BattleShip::ShowEnd() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (matrix[i][j]) {
			case -1: cout << "X" << " ";
				break;
			case 0: cout << '0' << " "; 
				break;
			case 1: cout << '1' << " ";
				break;
			case 2: cout << '2' << " ";
				break;
			case 3: cout << '3' << " ";
				break;
			case 4: cout << '4' << " ";
				break;
			case -2: cout << "M" << " ";
			}
		}
		cout << endl;
	}
}

void BattleShip::ShowBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix[i][j] == 0 || matrix[i][j] == 1 || matrix[i][j] == 2 || matrix[i][j] == 3 || matrix[i][j] == 4) {
				cout << 0 << " ";
			}
			else if (matrix[i][j] == -2) {
				cout << "M" << " ";
			}
			else {
				cout << "X" << " ";
			}
		}
		cout << endl;
	}
}

void BattleShip::SetShipsDestroyer() {
	// destroyer 1*1 max 4 number 1
	// submarine 2*2 max 3 number 2
	// cruiser 3*3 max 2 number 3
	// carrier 4*4 max 1 number4
	
	int laivu_kiekis = 7;
	int destroyer_kiekis = 0;

	while (laivu_kiekis < maxships) {
		int x = rand() % 10;
		int y = rand() % 10;
		int dir = rand() % 4;

		if (destroyer_kiekis != 4 && matrix[x][y] != 1 && matrix[x][y] != 2 && matrix[x][y] != 3 && matrix[x][y] != 4) {
			matrix[x][y] = 1;
			destroyer_kiekis++;
			laivu_kiekis++;
		}

	else break;
	}
}

void BattleShip::SetShipsSubmarine() {
	// destroyer 1*1 max 4 number 1
	// submarine 2*2 max 3 number 2
	// cruiser 3*3 max 2 number 3
	// carrier 4*4 max 1 number4

	int laivu_kiekis = 3;

	int submarine_kiekis = 0;
	
	while (laivu_kiekis < maxships) {
		int x = rand() % 10;
		int y = rand() % 10;
		int dir = rand() % 4;

		if (submarine_kiekis != 3 && matrix[x][y] != 1 && matrix[x][y] != 2 && matrix[x][y] != 3 && matrix[x][y] != 4) {
			if (dir == 0) { //deda vertikaliai i virsu
				matrix[x][y] = 2;
				matrix[x][y + 1] = 2;
				submarine_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 1) { //deda horizontaliai i desine
				matrix[x][y] = 2;
				matrix[x + 1][y] = 2;
				submarine_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 2) { //deda vertikaliai i apacia
				matrix[x][y] = 2;
				matrix[x][y - 1] = 2;
				submarine_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 3) { //deda horizontaliai i kaire
				matrix[x][y] = 2;
				matrix[x - 1][y] = 2;
				submarine_kiekis++;
				laivu_kiekis++;
			}
		}
		else break;
	}
}

void BattleShip::SetShipsCruiser() {
	// destroyer 1*1 max 4 number 1
	// submarine 2*2 max 3 number 2
	// cruiser 3*3 max 2 number 3
	// carrier 4*4 max 1 number4

	int laivu_kiekis = 1;

	int destroyer_kiekis = 0;
	int submarine_kiekis = 0;
	int cruiser_kiekis = 0;
	int carrier_kiekis = 0;

	while (laivu_kiekis < maxships) {
		int x = rand() % 10;
		int y = rand() % 10;
		int dir = rand() % 4;

		if (cruiser_kiekis != 2 && matrix[x][y] != 1 && matrix[x][y] != 2 && matrix[x][y] != 3 && matrix[x][y] != 4) {
			if (dir == 0) { //deda vertikaliai i virsu
				matrix[x][y] = 3;
				matrix[x][y + 1] = 3;
				matrix[x][y + 2] = 3;
				cruiser_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 1) { //deda horizontaliai i desine
				matrix[x][y] = 3;
				matrix[x + 1][y] = 3;
				matrix[x + 2][y] = 3;
				cruiser_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 2) { //deda vertikaliai i apacia
				matrix[x][y] = 3;
				matrix[x][y - 1] = 3;
				matrix[x][y - 2] = 3;
				cruiser_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 3) { //deda horizontaliai i kaire
				matrix[x][y] = 3;
				matrix[x - 1][y] = 3;
				matrix[x - 2][y] = 3;
				cruiser_kiekis++;
				laivu_kiekis++;
			}
		}
		else break;
	}
}

void BattleShip::SetShipsCarrier() {
	// destroyer 1*1 max 4 number 1
	// submarine 2*2 max 3 number 2
	// cruiser 3*3 max 2 number 3
	// carrier 4*4 max 1 number4

	int laivu_kiekis = 0;

	int carrier_kiekis = 0;

	while (laivu_kiekis < maxships) {
		int x = rand() % 10;
		int y = rand() % 10;
		int dir = rand() % 4;

		if (carrier_kiekis != 1 && matrix[x][y] != 1 && matrix[x][y] != 2 && matrix[x][y] != 3 && matrix[x][y] != 4) {
			if (dir == 0) { //deda vertikaliai i virsu
				matrix[x][y] = 4;
				matrix[x][y + 1] = 4;
				matrix[x][y + 2] = 4;
				matrix[x][y + 3] = 4;
				carrier_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 1) { //deda horizontaliai i desine
				matrix[x][y] = 4;
				matrix[x + 1][y] = 4;
				matrix[x + 2][y] = 4;
				matrix[x + 3][y] = 4;
				carrier_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 2) { //deda vertikaliai i apacia
				matrix[x][y] = 4;
				matrix[x][y - 1] = 4;
				matrix[x][y - 2] = 4;
				matrix[x][y - 3] = 4;
				carrier_kiekis++;
				laivu_kiekis++;
			}
			else if (dir == 3) { //deda horizontaliai i kaire
				matrix[x][y] = 4;
				matrix[x - 1][y] = 4;
				matrix[x - 2][y] = 4;
				matrix[x - 3][y] = 4;
				carrier_kiekis++;
				laivu_kiekis++;
			}
		}
		else break;
	}
}

bool BattleShip::Suvis(int x, int y) {
	if (matrix[x][y] == 1 || matrix[x][y] == 2 || matrix[x][y] == 3 || matrix[x][y] == 4) {
		matrix[x][y] = -1;
		return true;
	}
	if (matrix[x][y] == 0) {
		matrix[x][y] = -2;
		return true;
	}
	return false;
}

double BattleShip::NumberOfShips() {
	double skaicius = 0;
	double skaicius_destroyer = 0;
	double skaicius_submarine = 0;
	double skaicius_cruiser = 0;
	double skaicius_carrier = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix[i][j] == 1) {
				skaicius_destroyer++;
			}
			else if (matrix[i][j] == 2) {
				skaicius_submarine++;
			}
			else if (matrix[i][j] == 3) {
				skaicius_cruiser++;
			}
			else if (matrix[i][j] == 4) {
				skaicius_carrier++;
			}
		}
	}

	skaicius = skaicius_destroyer + ceil(skaicius_submarine/2) + ceil(skaicius_cruiser/3) + ceil(skaicius_carrier/4);
	return skaicius;
}

BattleShip::BattleShip()
{
}

BattleShip::~BattleShip()
{
}
