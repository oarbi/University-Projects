#include "Personne.h"

Personne::Personne(string nom, string prenom, string natio, int a, int b, int c) :date_naiss(a, b, c)
{
	this->nom = nom;
	this->prenom = prenom;
	this->natio = natio;
}
Personne::~Personne()
{
}