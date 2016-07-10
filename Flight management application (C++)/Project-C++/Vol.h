#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Temp.h"
#include "P_date.h"
#include "Reservation.h"
#include "Trajet.h"
using namespace std;
class Vol
{
private:
	long nvol;
	long reftrajet;
	Temp hd; // heure-depart
	Temp ha; // heure-arrive
	P_date date_vol;
	int nbrmax; // capacite maximale des passager
public:
	Vol(long = 0, long = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	friend ostream& operator<<(ostream&, Vol&);
	friend istream& operator>>(istream&, Vol&);
	friend void ajoutvol();
	friend void affichevol();
	friend void recherchevol();
	friend void modifvol();
	friend void supprimvol(long);
	friend void ajoutres();
	friend void recherchtrajet();
	friend void supprimtrajet(long);
};
