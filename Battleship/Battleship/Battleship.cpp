#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;
unsigned int microseconds;
class BattleShipGame
{
private:
	int ilgis, bothit, playerhit, hita, hitb, sk, fire, direction, length, End, checka, checkb;
public:
	int Ships[10][10], Shots[10][10], BotShips[10][10], BotShots[10][10], person, Laivas, ZaidKiek, BotKiek;
private:
	void AimBot(int BotShots[][10], int Ships[][10]) //Protingas saudymas
	{
		if (direction == 1 || direction == 0)
		{
			// kaire

			if (checkb + 1 == 10)
				fire = 1;
			if (End == 0)
			{
				checkb -= 1;
			}
			if (checkb > -1 && End == 0)
			{
				if (Ships[hita][hitb - 1] == 1)
				{
					bothit = 1;
					ZaidKiek--;
					length++;
					if (direction == 0)
						direction = 1;
					if (hita - 1 > -1)
						BotShots[hita - 1][hitb] = 3;
					if (hita + 1 < 10)
						BotShots[hita + 1][hitb] = 3;
					if (hita - 1 > -1)
						BotShots[hita - 1][hitb - 1] = 3;
					if (hita + 1 < 10)
						BotShots[hita + 1][hitb - 1] = 3;
					BotShots[hita][hitb - 1] = 2;
					Ships[hita][hitb - 1] = 2;
					hitb -= 1;
				}
				else
				{

					if (direction == 0)
					{
						End = 1;
						if (hita - 1 > -1 && hitb - 1 > -1)
							BotShots[hita - 1][hitb - 1] = 3;
						if (hita + 1 < 10 && hitb - 1 > -1)
							BotShots[hita + 1][hitb - 1] = 3;
						BotShots[hita][hitb - 1] = 3;
						Ships[hita][hitb - 1] = 3;
						if (fire == 1 && direction == 0) {
							direction = 2;
							End = 0;
						}
					}
					if (direction == 1)
					{
						if (hita - 1 > -1)
							BotShots[hita - 1][hitb] = 3;
						if (hita + 1 < 10)
							BotShots[hita + 1][hitb] = 3;
						if (hita - 1 > -1 && hitb - 1 > -1)
							BotShots[hita - 1][hitb - 1] = 3;
						if (hita + 1 < 10 && hitb - 1 > -1)
							BotShots[hita + 1][hitb - 1] = 3;
						BotShots[hita][hitb - 1] = 3;
						Ships[hita][hitb - 1] = 3;
						End = 1;
						checkb = hitb + length;
					}
				}
			}
			//Desine
			else
			{
				if (checkb == -1)
				{
					checkb--;
					End = 1;
				}
				checkb += 1;
				if (checkb < 10)
				{
					if (End == 1) {
						hitb += length;
						End = 2;
					}
					length = 1;
					if (Ships[hita][hitb + 1] == 1)
					{
						bothit = 1;
						ZaidKiek--;
						length++;
						if (direction == 0)
							direction = 1;
						if (hita - 1 > -1)
							BotShots[hita - 1][hitb] = 3;
						if (hita + 1 < 10)
							BotShots[hita + 1][hitb] = 3;
						if (hita - 1 > -1)
							BotShots[hita - 1][hitb + 1] = 3;
						if (hita + 1 < 10)
							BotShots[hita + 1][hitb + 1] = 3;
						BotShots[hita][hitb + 1] = 2;
						Ships[hita][hitb + 1] = 2;
						hitb += 1;
					}
					else
					{
						if (direction == 0)
						{
							if (hita - 1 > -1 && hitb + 1 < 10)
								BotShots[hita - 1][hitb + 1] = 3;
							if (hita + 1 < 10 && hitb + 1 < 10)
								BotShots[hita + 1][hitb + 1] = 3;
							BotShots[hita][hitb + 1] = 3;
							Ships[hita][hitb + 1] = 3;
							direction = 2;
							End = 0;
						}
						if (direction == 1)
						{
							if (hita - 1 > -1)
								BotShots[hita - 1][hitb] = 3;
							if (hita + 1 < 10)
								BotShots[hita + 1][hitb] = 3;
							if (hita - 1 > -1 && hitb + 1 < 10)
								BotShots[hita - 1][hitb + 1] = 3;
							if (hita + 1 < 10 && hitb + 1 < 10)
								BotShots[hita + 1][hitb + 1] = 3;
							Ships[hita][hitb + 1] = 3;
							BotShots[hita][hitb + 1] = 3;
							sk = 0;
						}
					}
				}
				else
				{
					if (direction == 0)
					{
						direction = 2;
						AimBot(BotShots, Ships);
					}
					else
					{
						sk = 0;
					}
				}
			}
		}
		else
		{
			//virsu
			if (End == 0)
			{
				checka -= 1;
			}
			if (checka > -1 && End == 0)
			{
				if (Ships[hita - 1][hitb] == 1)
				{
					bothit = 1;
					length++;
					ZaidKiek--;
					if (direction == 0)
						direction = 2;
					if (hitb - 1 > -1)
						BotShots[hita][hitb - 1] = 3;
					if (hitb + 1 < 10)
						BotShots[hita][hitb + 1] = 3;
					if (hitb - 1 > -1)
						BotShots[hita - 1][hitb - 1] = 3;
					if (hitb + 1 < 10)
						BotShots[hita - 1][hitb + 1] = 3;
					BotShots[hita - 1][hitb] = 2;
					Ships[hita - 1][hitb] = 2;
					hita -= 1;
				}
				else
				{
					if (direction == 0)
						direction = 2;
					if (direction == 2)
					{
						if (hitb - 1 > -1)
							BotShots[hita][hitb - 1] = 3;
						if (hitb + 1 < 10)
							BotShots[hita][hitb + 1] = 3;
						if (hita - 1 > -1 && hitb - 1 > -1)
							BotShots[hita - 1][hitb - 1] = 3;
						if (hita - 1 > -1 && hitb + 1 < 10)
							BotShots[hita - 1][hitb + 1] = 3;
						Ships[hita - 1][hitb] = 3;
						BotShots[hita - 1][hitb] = 3;
						End = 1;
						checka = hita + length;
					}
				}
			}
			else
			{
				//apacia
				if (checka == -1)
				{
					checka--;
					End = 1;
				}
				checka += 1;
				if (checka < 11)
				{
					if (End == 1) {
						if (fire == 1)
							hita += length;
						hita += length - 1;
						End = 2;
					}
					length = 1;
					//	cout<<Ships[hita+2][hitb]<<" hita "<<hita<<" hitb "<< hitb<<endl;
				//		cin>>sk;
					if (Ships[hita + 1][hitb] == 1)
					{
						bothit = 1;
						ZaidKiek--;
						length++;
						if (direction == 0)
							direction = 2;
						if (hitb - 1 > -1)
							BotShots[hita][hitb - 1] = 3;
						if (hitb + 1 < 10)
							BotShots[hita][hitb + 1] = 3;
						if (hitb - 1 > -1)
							BotShots[hita + 1][hitb - 1] = 3;
						if (hitb + 1 < 10)
							BotShots[hita + 1][hitb + 1] = 3;
						BotShots[hita + 1][hitb] = 2;
						Ships[hita + 1][hitb] = 2;
						hita += 1;
					}
					else
					{
						if (direction == 2)
						{
							if (hitb - 1 > -1)
								BotShots[hita][hitb - 1] = 3;
							if (hitb + 1 < 10)
								BotShots[hita][hitb + 1] = 3;
							if (hita - 1 > -1 && hitb - 1 > -1)
								BotShots[hita + 1][hitb - 1] = 3;
							if (hita + 1 < 10 && hitb + 1 > -1)
								BotShots[hita + 1][hitb + 1] = 3;
							Ships[hita + 1][hitb] = 3;
							BotShots[hita + 1][hitb] = 3;
							sk = 0;
						}
					}
				}
				else
				{
					sk = 0;
				}
			}
		}
	}
	int Convert(string let) // Vercia raides kai irasai kai saudai i skaicius
	{
		if (let == "a")
			return 1;
		else if (let == "b")
			return 2;
		else if (let == "c")
			return 3;
		else if (let == "d")
			return 4;
		else if (let == "e")
			return 5;
		else if (let == "f")
			return 6;
		else if (let == "g")
			return 7;
		else if (let == "h")
			return 8;
		else if (let == "i")
			return 9;
		else if (let == "j")
			return 10;
		else
			return 0;
	}
	void Location(int Ships[][10], int ShipLength)// Laiveliu pacio deliojimas
	{
		int sk1, sk2, ska, skb, err = ShipLength;
		string a, b;
		cout << "Please write your " << err << " tile ship the most left up square coordinate (pvz 1 a)" << endl;
		cin >> sk1 >> a;
		ska = Convert(a);
		if (ska == 0)
		{
			cout << "Wrong letter, please try again" << endl;
			Location(Ships, ShipLength);
		}
		cout << "Please write your " << err << " tile ship the most right down square coordinate (pvz 1 a)" << endl;
		cin >> sk2 >> b;
		skb = Convert(b);
		if (skb == 0)
		{
			cout << "Wrong letter, please try again" << endl;
			Location(Ships, ShipLength);
		}
		if (sk1 == sk2)
		{
			if (skb - ska != err - 1)
			{
				cout << "Your ship size is not " << err << ", plz try again" << endl;
				Location(Ships, ShipLength);
			}
			for (int i = ska - 1; i < err + ska - 1; i++)
				Ships[sk1 - 1][i] = 1;
			Board(Ships);
		}
		else if (ska == skb)
		{
			if (sk2 - sk1 != err - 1 || sk2 > 10)
			{
				cout << "Your ship size is not " << err << ", plz try again" << endl;
				Location(Ships, ShipLength);
			}
			for (int i = sk1 - 1; i < err + sk1 - 1; i++)
				Ships[i][ska - 1] = 1;
			Board(Ships);
		}
	}
	void BotMassive(int BotShips[][10], int x, int y, int dir)// Protingas laiveliu isdeliojimas
	{
		while (Laivas > 0)
		{
			if (Laivas == 5)
			{
				ilgis = 4;
				BotPrint(BotShips, x, y, dir);
			}
			else if (Laivas == 4)
			{
				ilgis = 3;
				PositionCheck(BotShips, x, y, dir);

				BotPrint(BotShips, x, y, dir);
			}
			else if (Laivas == 3 || Laivas == 2)
			{
				ilgis = 2;
				PositionCheck(BotShips, x, y, dir);
				BotPrint(BotShips, x, y, dir);
			}
			else if (Laivas == 1)
			{
				ilgis = 1;
				PositionCheck(BotShips, x, y, dir);
				BotPrint(BotShips, x, y, dir);
			}
		}
	}
	void PositionCheck(int BotShips[][10], int x, int y, int dir) //Pozicijos tikrinimas ( ar gali padetil laiveli )
	{
		int tx = x, ty = y, tilgis = 0;
		while (tilgis <= ilgis)
		{
			if (BotShips[tx][ty] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx - 1 < 0 || ty - 1 < 0 || BotShips[tx - 1][ty - 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx - 1 < 0 || BotShips[tx - 1][ty] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx - 1 < 0 || ty + 1 > 9 || BotShips[tx - 1][ty + 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (ty - 1 < 0 || BotShips[tx][ty - 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (ty + 1 > 9 || BotShips[tx][ty + 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx + 1 > 9 || ty - 1 < 0 || BotShips[tx + 1][ty - 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx + 1 > 9 || BotShips[tx + 1][ty] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			if (tx + 1 > 9 || ty + 1 > 9 || BotShips[tx + 1][ty + 1] != 1) {
			}
			else {
				BotBoard(BotShips);
			}
			tilgis++;
			if (dir == 0)
				tx++;
			else if (dir == 1)
				ty++;
			else
				cout << "Error, direction not found" << endl;
		}
	}
	void BotPrint(int BotShips[][10], int x, int y, int dir)
	{
		if (Laivas < 1)
		{
			return;
		}
		else
		{
			if (dir == 0 && x + ilgis <= 9)
			{

				while (ilgis > -1)
				{
					BotShips[x + ilgis][y] = 1;
					ilgis--;
				}
				Laivas--;
				if (person == 1) {
					Board(BotShips);
				}
			}
			else if (dir == 1 && y + ilgis <= 9)
			{
				while (ilgis > -1)
				{
					BotShips[x][y + ilgis] = 1;
					ilgis--;

				}
				Laivas--;
				if (person == 1) {
					Board(BotShips);
				}
			}
			else
			{
				BotBoard(BotShips);
			}
		}
	}
	void Attack(int Shots[][10], int BotShips[][10])// Zaidejo saudymas
	{
		int sk1, skA;
		string let;
		cout << "Please write your tagged square coordinates (pvz 1 a)" << endl;
		cin >> sk1 >> let;
		if (sk1 > 10)
		{
			if (sk1 == 666)
			{
				cout << endl << "Enemy board is shown" << endl;
				Board(BotShips);
				cout << "plz reenter coordinates (pvz 1 a)" << endl;
				cin >> sk1 >> let;
			}
			else
			{
				cout << "Wrong coordinates, plsease try again ";
				Attack(Shots, BotShips);
			}
		}
		skA = Convert(let);
		if (Shots[sk1 - 1][skA - 1] > 0)
		{
			cout << " You have already shot to that coordinate" << endl;
			Attack(Shots, BotShips);
		}
		system("cls");
		if (BotShips[sk1 - 1][skA - 1] == 1)
		{
			playerhit = 1;
			Shots[sk1 - 1][skA - 1] = 2;
			BotKiek--;
		}
		else
		{
			Shots[sk1 - 1][skA - 1] = 3;
		}
	}
	void BotAttack(int BotShots[][10], int Ships[][10])// Boto saudymas
	{
		if (sk == 1)
		{
			AimBot(BotShots, Ships);
		}
		else
		{
			int r = (rand() % 10);
			int r1 = (rand() % 10);
			if (BotShots[r][r1] > 0)
				BotAttack(BotShots, Ships);
			else if (Ships[r][r1] == 1)
			{
				bothit = 1;
				ZaidKiek--;
				BotShots[r][r1] = 2;
				Ships[r][r1] = 2;
				hita = r; hitb = r1;
				checka = r; checkb = r1; End = 0; fire = 0; length = 0, direction = 0;
				sk = 1;
			}
			else
			{
				BotShots[r][r1] = 3;
				Ships[r][r1] = 3;
			}
		}
	}
public:
	BattleShipGame();
	void EmptyMassives()// Sukuria tuscius masyvus
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Ships[i][j] = 0;
				Shots[i][j] = 0;
				BotShips[i][j] = 0;
				BotShots[i][j] = 0;
			}
		}
	}
	void Board(int Ships[][10])// Spausdina lenta
	{
		int sk = 0, SKC[10] = { 1,2,3,4,5,6,7,8,9,10 };
		cout << "   A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J " << endl;
		while (sk < 10)
		{
			if (SKC[sk] != 10)
			{
				cout << " " << SKC[sk] << " ";
			}
			else
			{
				cout << SKC[sk] << " ";
			}
			for (int j = 0; j < 10; j++)
			{
				if (Ships[sk][j] == 1)
					cout << (char)254 << " ";
				else if (Ships[sk][j] == 2)
					cout << "X" << " ";
				else if (Ships[sk][j] == 3)
					cout << "*" << " ";
				else
					cout << (char)250 << " ";
			}
			cout << endl;
			sk++;
		}
		cout << endl;
	}
	void Placement(int Ships[][10]) // Kai pats deliojiesi laivelius nurodo koks turi eiti
	{
		int ShipLength, sk = 1;
		ShipLength = 5;
		Location(Ships, ShipLength);
		ShipLength = 4;
		while (sk > 0)
		{
			Location(Ships, ShipLength);
			sk--;
		}
		sk = 2;
		ShipLength = 3;
		while (sk > 0)
		{
			Location(Ships, ShipLength);
			sk--;
		}
		sk = 1;
		ShipLength = 2;
		while (sk > 0)
		{
			Location(Ships, ShipLength);
			sk--;
		}

		cout << "You have placed all the ships, now we can start the game" << endl << endl;
	}
	void BotBoard(int BotShips[][10])// Gauna random skaicius kad galetu saudi ir deti laivelius
	{
		int y = (rand() % 10);
		int x = (rand() % 10);
		int dir = (rand() % 2);
		if (y == 0 && x == 0)
			BotBoard(BotShips);
		else if (y == 0 && x == 9)
			BotBoard(BotShips);
		else if (y == 9 && x == 0)
			BotBoard(BotShips);
		else
			BotMassive(BotShips, x, y, dir);
	}
	void Game(int Ships[][10], int Shots[][10], int BotShips[][10], int BotShots[][10])// pagrindine funkcija, kurioje vyksta zaidimas
	{
		cout << "  ====GAME STARTED====" << endl;
		cout << "====Your shots board====" << endl;
		Board(Shots);
		cout << endl << " &========_*_========&" << endl;
		cout << "====Your ships board====" << endl;
		Board(Ships);
		if (BotKiek == 0)
		{
			cout << "You Won" << endl;
			cin >> sk;
			exit(0);
		}
		else if (ZaidKiek == 0)
		{
			cout << "You Lost" << endl;
			cin >> sk;
			exit(0);
		}
		if (bothit == 1)
			bothit = 0;
		else
			Attack(Shots, BotShips);
		if (playerhit == 1)
			playerhit = 0;
		else
		{
			Sleep(100);
			BotAttack(BotShots, Ships);
		}
		system("cls");
		Game(Ships, Shots, BotShips, BotShots);
	}
};
BattleShipGame::BattleShipGame() {
	bothit = 0, playerhit = 0, hita, hitb, sk = 0, direction = 0, length = 0, End = 0, Laivas = 5, ZaidKiek = 17, BotKiek = 17;
}
int main()
{
	srand((int)time(0));
	BattleShipGame Game;
	int choice;
	Game.EmptyMassives();
	Game.Board(Game.Ships);
	cout << "1 - Place ships" << endl;
	cout << "2 - Generate ships automatically" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "You will have to put 1 5tile size ship, 1 4tile size ship, 2 3tile size ship and 1 2tile size ship" << endl;
		Game.Placement(Game.Ships);
	}
	else if (choice == 2)
	{
		Game.person = 1;
		Game.BotBoard(Game.Ships);
	}
	else
	{
		system("cls");
		cout << "You haven't pressed 1 or 2" << endl;
		main();
	}
	Game.Laivas = 5;
	Game.person = 0;
	cout << "Creating bot board" << endl;
	Game.BotBoard(Game.BotShips);
	system("cls");
	Game.Game(Game.Ships, Game.Shots, Game.BotShips, Game.BotShots);
}