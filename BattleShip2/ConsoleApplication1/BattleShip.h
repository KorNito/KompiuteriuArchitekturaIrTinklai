#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class BattleShip {

private:
	int maxships = 10;
	int matrix[10][10];

public:
	BattleShip();
	~BattleShip();

	void Clear();
	void ShowEnd();
	void SetShipsDestroyer();
	void SetShipsSubmarine();
	void SetShipsCruiser();
	void SetShipsCarrier();
	bool Suvis(int, int);
	double NumberOfShips();
	void ShowBoard();
};

