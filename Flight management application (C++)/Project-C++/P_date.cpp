#include "P_date.h"

P_date::P_date(int jour, int mois, int annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
}

ostream& operator<<(ostream& out, P_date& d)
{
	out << d.jour << " " << d.mois << " " << d.annee;
	return out;
}
istream& operator>>(istream& in, P_date& d)
{
	in >> d.jour;
	in >> d.mois;
	in >> d.annee;
	return in;
}
void P_date::ajoutdate()
{
	cout << "\t\tJour : "; cin >> jour;
	cout << "\t\tMois : "; cin >> mois;
	cout << "\t\tAnnee : "; cin >> annee;
}
void P_date::affichedate()
{
	cout << jour << "/" << mois << "/" << annee;
}