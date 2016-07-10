#include "Trajet.h"


Trajet::Trajet(long ref, long refdes, float pt, int escale, string ad, string aa, bool ouvert)
{
	this->ref = ref;
	this->refdes = refdes;
	this->pt = pt;
	this->escale = escale;
	this->ad = ad;
	this->aa = aa;
	this->ouvert = ouvert;
}
ostream& operator<<(ostream& out, Trajet& t)
{
	out << t.ref << " " << t.refdes << " " << t.pt << " " << t.escale << " " << t.ad << " " << t.aa << " " << t.ouvert;
	return out;
}
istream& operator>>(istream& in, Trajet& t)
{
	in >> t.ref;
	in >> t.refdes;
	in >> t.pt;
	in >> t.escale;
	in >> t.ad;
	in >> t.aa;
	in >> t.ouvert;
	return in;
}
void ajouttrajet()
{
	system("cls");
	Trajet t,t1;
	Destination d;
	ofstream fout("Trajet.txt", ios::app);
	ifstream fin("Trajet.txt");
	ifstream fdes("Destination.txt");
	if (fin.bad() || fdes.bad() || fout.bad())
		cerr << "Erreur";
	cout << " Veuillez introduire les informations necessaire :" << endl;
a:	cout << "Reference : ";
	cin >> t.ref;
	fin.seekg(0);
	while (!fin.eof())
	{
		fin >> t1;
		if (t.ref == t1.ref)
		{
			cout << "Le trajet existe deja " << endl;
			goto a;
		}
	}
b:cout << "Reference destination :  ";
	cin >> t.refdes;
	fdes.seekg(0);
	bool exist = false;
	while (!fdes.eof())
	{
		fdes >> d;
		if (d.ref == t.refdes)
			exist = true;
	}
	if (exist == false)
	{
		cout << "Cette destination n'existe pas !!" << endl;
		goto b;
	}
	cout << "Prix : "; cin >> t.pt;
	cout << "Nombre d'escale : "; cin >> t.escale;
	cout << "Aeroport de depart : "; cin >> t.ad;
	cout << "Aeroport d'arivee : "; cin >> t.aa;
	t.ouvert = 1;
	fout << endl << t;
	fin.close();
	fdes.close();
	fout.close();
}
void affichetrajet()
{
	system("cls");
	Trajet t;
	ifstream ftr("Trajet.txt");
	if (ftr.bad())
		cerr << "erreur !";
	cout << "Reference - Prix - Depart - Arrivee - Nombre d'escale - Ouvert " << endl;
	while (!ftr.eof())
	{
		ftr >> t;
		if (t.ref != 0)
		{
			cout << t.ref << " - " << t.pt << " - " << t.ad << " - " << t.aa << " - " << t.escale << " - " << t.ouvert << endl;
		}
		else
			cout << endl << "Vide !!" << endl;
	}
	ftr.close();
}
void recherchtrajet()
{
	system("cls");
	cout << "Donner le reference de trajet : ";
	long x;
	cin >> x;
	Vol v;
	Trajet t;
	ifstream fvol("Vol.txt");
	ifstream ftr("Trajet.txt");
	if (fvol.bad() || ftr.bad())
		cerr << "erreur !";
	bool ok = false;
	while (!ftr.eof())
	{
		ftr >> t;
		if (t.ref == x)
		{
			cout << "Reference : " << t.ref << endl;
			cout << "Reference de destination : " << t.refdes << endl;
			cout << "Prix : " << t.pt << endl;
			cout << "Nombre d'escale: "<< t.escale<<endl;
			cout << "Aeroport de depart : "<< t.ad<<endl;
			cout << "Aeroport d'arrivee : "<< t.aa<<endl;
			cout << "Ouvert : " << t.ouvert << endl;
			cout << "Liste de vol : " << endl;
			while (!fvol.eof())
			{
				fvol >> v;
				if (v.reftrajet == t.ref)
					cout << " \t Numero de vol : " << v.nvol << " - Date : "; v.date_vol.affichedate();
			}
			ok = true;
		}
	}
	if (ok == false)
		cout << "le trajet n'existe pas" << endl;
	fvol.close();
	ftr.close();

}
void modiftrajet(char var)
{
	system("cls");
	cout << "Donner le reference de trajet : ";
	long x;
	cin >> x;
	Trajet t;
	ifstream fin("Trajet.txt");
	ofstream fout("temptr.txt");
	if (fout.bad() || fin.bad())
		cerr << "erreur !";
	bool exist = false;
	while (!fin.eof())
	{
		fin >> t;
		if (t.ref != x)
		{
			fout << endl << t;
		}
		else
		{
			exist = true;
			switch (var)
			{
			case 'm':
				cout << "Prix : "; cin >> t.pt;
				cout << "Nombre d'escale : "; cin >> t.escale;
				cout << "Aeroport de depart : "; cin >> t.ad;
				cout << "Aeroport d'arivee : "; cin >> t.aa;
				break;
			case 'o':
				t.ouvert = 1; break;
			case 'f':
				t.ouvert = 0; break;
			}
			fout << endl << t;
		}
	}
	if (!exist)
		cout << "Le trajet n'existe pas !!" << endl;
	fout.close();
	fin.close();
	ifstream fin1("temptr.txt");
	ofstream fout1("Trajet.txt", ios::trunc);
	if (fout1.bad() || fin1.bad())
		cerr << "erreur !";
	while (!fin1.eof())
	{
		fin1 >> t;
		fout1 << endl << t;
	}
	fout1.close();
	fin1.close();
	remove("temptr.txt");
}
void supprimtrajet(long x)
{
	Trajet t;
	Vol v;
	ifstream fitvol("Vol.txt");
	ifstream fitr("Trajet.txt");
	ofstream fotmtr("temptr.txt");
	if (fotmtr.bad() || fitvol.bad() || fitr.bad())
		cerr << "erreur !";
	bool exist = false;
	fitr.seekg(0);
	while (!fitr.eof())
	{
		fitr >> t;
		if (t.ref != x)
		{
			fotmtr << endl << t;
		}
		else
		{
			exist = true;
			
		}
	}
	if (!exist)
		cout << "Ce trajet n'existe pas !!" << endl;
	fotmtr.close();
	
	fitr.close();
	ifstream fitmtr("temptr.txt");
	ofstream fotr("Trajet.txt", ios::trunc);
	if (fitmtr.bad() || fotr.bad())
		cerr << "Erreur";
	while (!fitmtr.eof())
	{
		fitmtr >> t;
		fotr << endl << t;
	}
	fotr.close();
	fitmtr.close();
	remove("temptr.txt");
	while (!fitvol.eof())
	{
		fitvol >> v;
		if (v.reftrajet == x)
		{
			supprimvol(v.nvol);
			fitvol.seekg(0);
		}
	}
	fitvol.close();
}
