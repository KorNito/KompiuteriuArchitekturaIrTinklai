// AAA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
int func(int a, int b);
int main(int argc, char* argv[])
{
	int a0, b0, a = 0, b = 0, c, d, e, f, res = 0, ten, res1=0;

	a0 = atoi(argv[1]);
	b0 = atoi(argv[2]);

	int kasp;
	kasp = a0 ^ b0;
	cout << "XOR: " << kasp << endl;
	ten = 1;
	while (a0 > 0)
	{
		a += a0 % 2 * ten;
		a0 /= 2;
		ten *= 10;
	}
	//	cout<<a<<endl;
	ten = 1;
	while (b0 > 0)
	{
		b += b0 % 2 * ten;
		b0 /= 2;
		ten *= 10;
	}
	//	cout<<b<<endl<<endl;
	c = func(a, b);
	d = func(a, c);
	e = func(b, c);
	f = func(d, e);

	for (int i = 0; f > 0; i++)
	{
		if (f % 10 == 1)
			res += pow(2, i);
		f /= 10;
	}
	for (int i = 0; c > 0; i++)
	{
		if (c % 10 == 1)
			res1 += pow(2, i);
		c /= 10;
	}
	cout << "schema"<<res<<endl;
	cout << "a xor b" << res1;
}
int func(int a, int b)
{

	int res = 0, ten = 10;
	//	cout<<a<<endl<<b<<endl<<res<<endl<<endl;
	res += (((a % 10) || (b % 10)) && !((a % 10) && (b % 10)));
	while ((a > 0) || (b > 0))
	{
		a /= 10;
		b /= 10;
		res += ten * (((a % 10) || (b % 10)) && !((a % 10) && (b % 10)));
		//		cout<<a<<endl<<b<<endl<<res<<endl<<endl;
		ten *= 10;

	}
	return res;
}