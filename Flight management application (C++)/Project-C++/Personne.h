#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "P_date.h"
using namespace std;
class Personne
{
protected:
	string nom;
	string prenom;
	string natio;
	P_date date_naiss;
public:
	Personne(string, string, string, int ,int,int);
	~Personne();
};

