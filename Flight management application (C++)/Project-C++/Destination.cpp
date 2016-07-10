#include "Destination.h"

Destination::Destination(long ref, string  pd, string  pa)
{
	this->ref = ref;
	this->pd = pd;
	this->pa = pa;
}

ostream& operator<<(ostream& out, Destination& d)
{
	out << d.ref << " " << d.pd << " " << d.pa;
	return out;
}
istream& operator>>(istream& in, Destination& d)
{
	in >> d.ref;
	in >> d.pd;
	in >> d.pa;
	return in;
}
void ajoutdes()
{
	system("cls");
	Destination d,d1;
	ifstream fdes("Destination.txt");
	ofstream fout("Destination.txt", ios::app);
	if (fdes.bad() || fout.bad())
		cerr << "Erreur";
	cout << "Veuillez introduire une destination : " << endl;

a:cout << "Reference : ";cin >> d.ref;
	fdes.seekg(0);
	while (!fdes.eof())
	{
		fdes >> d1;
		if (d1.ref == d.ref)
		{
			cout << "La destination existe deja " << endl;
			goto a;
		}
	}
	cout << "Pays de depart : "; cin >> d.pd;
	cout << "Pays d'arrivee : "; cin >> d.pa;
	fdes.close();
	fout << endl << d;
	fout.close();
}
void afficherdes()
{
	system("cls");
	Destination d;
	ifstream fin("Destination.txt");
	if (!fin)
		cerr << "Erreur !!" << endl;
	cout << " Reference - Depart - Arrivee " << endl;
	while (!fin.eof())
	{
		fin >> d;
		if (d.ref != 0)
		{
			cout << d.ref << " - " << d.pd << " - " << d.pa << endl;
		}
		else
			cout << endl << "Vide !!" << endl;
	}
	fin.close();
}
void recherchdes()
{
	system("cls");
	cout << "Donner la reference de la destination" << endl;
	int x;
	cin >> x;
	Destination d;
	Trajet t;
	ifstream fin("Destination.txt");
	ifstream ftr("Trajet.txt");
	bool ok = false;
	while (!fin.eof())
	{
		fin >> d;
		if (d.ref == x)
		{
			cout << "Reference : " << d.ref << endl;
			cout << "Pays de depart : " << d.pd << endl;
			cout << "Pays d'arrivee : " << d.pa << endl;
			while (!ftr.eof())
			{
				ftr >> t;
				if (t.refdes == d.ref)
					cout << "\tReference : " << t.ref << " - Depart : " << t.ad << " - Arrivee : " << t.aa << endl;
			}
			ok = true;
		}
	}
	if (ok == false)
		cout << "l'element n'existe pas" << endl;
	fin.close();
	ftr.close();
}
 void supprimdes(long x)
{
	Trajet t;
	Destination d;
	ifstream fides("Destination.txt");
	ifstream fidtr("Trajet.txt");
	ofstream fotmdes("tempdes.txt");
	if (fotmdes.bad() || fides.bad() || fidtr.bad())
		cerr << "erreur !";
	bool exist = false;
	while (!fides.eof())
	{
		fides >> d;
		if (d.ref != x)
		{
			fotmdes << endl << d;
		}
		else
		{
			exist = true;
		}
	}
	if (!exist)
		cout << "Cette destination n'existe pas !! " << endl;
	fotmdes.close();
	fides.close();
	ifstream fitmdes("tempdes.txt");
	ofstream fodes("Destination.txt");
	if (fitmdes.bad() || fodes.bad())
		cerr << "Erreur";
	while (!fitmdes.eof())
	{
		fitmdes >> d;
		fodes << endl << d;
	}
	fodes.close();
	fitmdes.close();
	remove("tempdes.txt");
	while (!fidtr.eof())
	{
		fidtr >> t;
		if (t.refdes == x)
		{
			supprimtrajet(t.ref);
			fidtr.seekg(0);
		}
	}
	fidtr.close();
}