// VRPROG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main()
{
	bool flagJUMP = false;
	bool flagZERO = false;
	bool flagEND = false;

	char reader;
	char simbolis;

	int memory[256];
	int index = 0;
	int registras[16];
	int skaitliukas = 0;
	int x, y;

	ifstream duomenys("decryptor.bin", ios::binary);
	ifstream encryptor("q1_encr.txt"); 

	while (reader = duomenys.get(), duomenys.good()) {
		memory[index] = (int)reader;
		index++;
	}

	while (1) {
		x = 0x0f & memory[skaitliukas + 1];
		y = 0xf0 & memory[skaitliukas + 1] >> 4;

		switch (memory[skaitliukas])
		{
			case 0x01: registras[x] += 1; break; //INC Rx
			case 0x02: registras[x] -= 1; break; //DEC RX
			case 0x03: registras[x] = registras[y]; break; // MOV Rx, Ry 
			case 0x04: registras[0] = memory[skaitliukas + 1]; break; //MOVC <<baito konstanta>>
			case 0x05: registras[x] << 1; break; //LSL Rx
			case 0x06: registras[x] >> 1; break; //LsR Rx
			case 0x07: skaitliukas += memory[skaitliukas + 1]; //JMP addr
				while (skaitliukas >= index) // Kol skaitliukas didesnis uz visu komandu skaiciu
				{
					skaitliukas -= index; // atimam po 32, nes memory masyvas 32 elementai
				}
				flagJUMP = true; break;
			case 0x08: if (flagZERO == true) { //JZ addr
				skaitliukas += memory[skaitliukas + 1];
				while (skaitliukas >= index) // Kol skaitliukas didesnis uz visu komandu skaiciu
				{
					skaitliukas -= index; // atimam po 32, nes memory masyvas 32 elementai
				}
				flagJUMP = true; break;
			}
			case 0x09: if (flagZERO == false) { //JNZ addr
				skaitliukas += memory[skaitliukas + 1];
				while (skaitliukas >= index) // Kol skaitliukas didesnis uz visu komandu skaiciu
				{
					skaitliukas -= index; // atimam po 32, nes memory masyvas 32 elementai
				}
				flagJUMP = true; break;
			}
			case 0x0A: if (flagEND == true) //JFE
			{
				skaitliukas += memory[skaitliukas + 1];
				while (skaitliukas >= index) // Kol skaitliukas didesnis uz visu komandu skaiciu
				{
					skaitliukas -= index; // atimam po 32, nes memory masyvas 32 elementai
				}
				flagJUMP = true; break;
			}
			case 0x0B: return 0; break;//RET
			case 0x0C: registras[x] = registras[x] + registras[y]; break;//ADD Rx, Ry
			case 0x0D: registras[x] = registras[x] - registras[y]; break;//SUB Rx,Ry
			case 0x0E: registras[x] = registras[x] ^ registras[y]; break;//XOR Rx,Ry
			case 0x0F: registras[x] = registras[x] | registras[y]; break;//OR Rx,Ry
			case 0x10: if (!encryptor.eof()) {
				encryptor >> simbolis;
				registras[x] = (int)simbolis;
			}
					   else {
				flagEND = true;
			} break;
			case 0x11: cout << (char)registras[x]; break;
		}

		if (flagJUMP == false) {
			skaitliukas += 2;
		}
		else {
			flagJUMP = false;
		}
	}

	duomenys.close();
	encryptor.close();
}