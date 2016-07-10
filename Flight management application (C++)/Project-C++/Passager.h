#pragma once
#include <iostream>
#include <fstream>
#include "Personne.h"
#include "BAGAGE.h"
using namespace std;
class Passager : public Personne
{
private:
	long numpassport;
	BAGAGE bag;
public:
	Passager(string = "", string = "", string = "", int=0, int=0, int=0, long=0, long=0, float=0.0);
	void ajoutinfopass();
	void afficheinfopass();
	friend ostream& operator<<(ostream&, Passager&);
	friend istream& operator>>(istream&, Passager&);
	friend void afficheres();
	friend void recherchevol();
	friend void ajoutres();
};
