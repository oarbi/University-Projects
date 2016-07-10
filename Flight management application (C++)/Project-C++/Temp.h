#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Temp
{
private:
	int h;
	int m;
public:
	Temp(int = 0, int = 0);
	friend ostream& operator<<(ostream&, Temp&);
	friend istream& operator>>(istream&, Temp&);
	void affichertemps();
	void ajouttemps();
};

