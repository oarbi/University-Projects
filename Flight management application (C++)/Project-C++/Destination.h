#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Trajet.h"
using namespace std;
class Destination
{
private:
	long ref;
	string pd; // pays depart
	string pa; // pays arrivee
public:
	Destination(long = 0,string = "",string = "");
	friend ostream& operator<<(ostream&, Destination&);
	friend istream& operator>>(istream&, Destination&);
	friend void ajoutdes();
	friend void afficherdes();
	friend void recherchdes();
	friend void supprimdes(long);
	friend void ajouttrajet();
};

