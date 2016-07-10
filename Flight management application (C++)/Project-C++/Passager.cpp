#include "Passager.h"

Passager::Passager(string nom, string prenom, string natio, int a, int b, int c, long numpassport, long r, float p) :Personne(nom, prenom, natio, a,b,c), bag(r,p)
{
	this->numpassport = numpassport;
}
void Passager::ajoutinfopass()
{
	cout << "Nom : "; cin >> nom;
	cout << "Prenom : "; cin >> prenom;
	cout << "Nationalite : "; cin >> natio;
	cout << "Date de naissance : "<<endl; date_naiss.ajoutdate();
	cout << "Numero de passport : "; cin >> numpassport;
	cout << "Bagage : "<<endl; bag.ajoutbag();
}
void Passager::afficheinfopass()
{
	cout << "\tNom : "<< nom << endl;
	cout << "\tPrenom : " << prenom << endl;
	cout << "\tNationalite : " << natio << endl;
	cout << "\tDate de naissance : "; date_naiss.affichedate();
	cout << endl << "\tNumero de passport : " << numpassport << endl;
	cout << "\tBagage : "; bag.affichebag();
	cout << endl;
}
ostream& operator<<(ostream& out, Passager& p)
{
	out << p.numpassport << " " << p.nom << " " << p.prenom << " " << p.natio << " " << p.date_naiss << " " << p.bag;
	return out;
}
istream& operator>>(istream& in, Passager& p)
{
	in >> p.numpassport >> p.nom >> p.prenom >> p.natio >> p.date_naiss >> p.bag;
	return in;
}

