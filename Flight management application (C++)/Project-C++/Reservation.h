#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "P_date.h"
#include "Passager.h"
#include "Vol.h"
using namespace std;
class Reservation
{
	long numres; // numero reservation
	long nvol;
	P_date date_res;
	string type;
	float prix;
	Passager p;
public:
	Reservation(long = 0, long = 0, int = 0, int = 0, int = 0, string = "", float = 0.0, string = "", string = "", string = "", int = 0, int = 0, int = 0, long = 0, long = 0, float=0.0);
	friend void ajoutres();
	friend void afficheres();
	friend void supprimres( long);
	friend void modifres();
	friend void recherchres();
	friend ostream& operator<<(ostream&, Reservation&);
	friend istream& operator>>(istream&, Reservation&);
	friend void affichevol();
	friend void supprimvol(long);
	friend void recherchevol();
};