#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Destination.h"
#include "Vol.h"
using namespace std;
class Trajet
{
private:
	long ref;
	long refdes; //reference de la destination
	float pt; //prix_trajet
	int escale;
	string ad; //aeroport_depart
	string aa; //aeroport_arrivee
	bool ouvert;
public:
	Trajet(long = 0, long = 0 , float = 0.0, int = 0, string ="", string = "", bool = false);
	friend ostream& operator<<(ostream&, Trajet&);
	friend istream& operator>>(istream&, Trajet&);
	friend void ajouttrajet();
	friend void affichetrajet();
	friend void recherchtrajet();
	friend void modiftrajet(char);
	friend void supprimtrajet(long);
	friend void affichevol();
	friend void ajoutvol();
	friend void recherchdes();
	friend void supprimdes(long);
};
