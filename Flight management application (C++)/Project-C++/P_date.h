#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class P_date
{
private:
	int jour;
	int mois;
	int annee;
public:
	P_date(int = 0, int = 0, int = 0);
	friend ostream& operator<<(ostream&, P_date&);
	friend istream& operator>>(istream&, P_date&);
	void ajoutdate();
	void affichedate();
};