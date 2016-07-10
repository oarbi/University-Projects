#include "Vol.h"

Vol::Vol(long nvol, long reftrajet ,int nbrmax, int a, int b, int c, int d, int e, int f, int g) : date_vol(a,b,c), hd(d, e), ha(f, g)
{
	this->nvol = nvol;
	this->reftrajet = reftrajet;
	this->nbrmax = nbrmax;
}
ostream& operator<<(ostream& out, Vol& v)
{
	out << v.nvol << " " << v.reftrajet << " " << v.hd << " " << v.ha << " " << v.date_vol << " "<< v.nbrmax;
	return out;
}
istream& operator>>(istream& in, Vol& v)
{
	in >> v.nvol;
	in >> v.reftrajet;
	in >> v.hd;
	in >> v.ha;
	in >> v.date_vol;
	in >> v.nbrmax;
	return in;
}
void ajoutvol()
{
	system("cls");
	Vol v;
	Vol v1;
	Trajet t;
	ifstream fin("Vol.txt");
	ofstream fout("Vol.txt", ios::app);
	ifstream ftr("Trajet.txt");
	if (fin.bad() || ftr.bad() || fout.bad())
		cerr << "Erreur";
	cout <<" Veuillez introduire les informations necessaire :"  << endl;
	cout << "Numero de vol : ";
a: cin >> v.nvol;
	fin.seekg(0);
	while (!fin.eof())
	{
		fin >> v1;
		if (v.nvol == v1.nvol)
		{
			cout << "Le vol existe deja " << endl;
			goto a;
		}
	}
b:	cout << "Reference de trajet : ";
	cin >> v.reftrajet;
	bool exist = false;
	ftr.seekg(0);
	while (!ftr.eof())
	{
		ftr >> t;
		if (v.reftrajet == t.ref)
		{
			exist = true;
			if (t.ouvert == false)
			{
				cout << "Ce trajet est ferme pour le moment !!! impossible d'ajouter le vol !";
				goto b;
			}
		}
	}
	if (!exist)
	{
		cout << "Ce trajet n'existe pas !" << endl;
		goto b;
	}
	cout << "Heure de depart : "<< endl;
	v.hd.ajouttemps();
	cout << "Heure d'arrivee : "<< endl;
	v.ha.ajouttemps();
	cout << "Date de vol :  "<< endl;
	v.date_vol.ajoutdate();
	cout << "Capacite maximale : ";
	cin >> v.nbrmax;
	fout << endl << v;
	fout.close();
	fin.close();
	ftr.close();
}
void affichevol()
{
	system("cls");
	Vol v;
	Reservation r;
	ifstream fvol("vol.txt");
	ifstream fres("Reservation.txt");
	if (fvol.bad() || fres.bad())
		cerr << "erreur !";
	cout << "Numero de Vol - Date de vol - Depart - Arrivee - Nombre de place " << endl;
	while (!fvol.eof())
	{
		
		fvol >> v;
		if (v.nvol != 0)
		{
			cout << v.nvol << " - "; v.date_vol.affichedate(); cout << " - "; v.hd.affichertemps(); cout << " - "; v.ha.affichertemps(); cout << " - " << v.nbrmax << endl;
		}
		else
			cout<< endl << "Vide !!" << endl;
	}
	fvol.close();
	fres.close();
}
void recherchevol()
{
	system("cls");
	cout << "Donner le numero de vol : ";
	long nv;
	cin >> nv;
	Vol v;
	Reservation r;
	ifstream fin("Vol.txt");
	ifstream fres("Reservation.txt");
	if (fin.bad())
		cerr << "erreur !";
	bool ok = false;
	while (!fin.eof())
	{
		fin >> v;
		
		if (v.nvol == nv)
		{
			cout << "Numero de vol : " << v.nvol << endl;
			cout << "Reference de trajet : " << v.reftrajet << endl;
			cout << "Date de vol : "; v.date_vol.affichedate();
			cout << endl<<"Heure de depart : "; v.hd.affichertemps();
			cout << endl << "Heure d'arrivee : "; v.ha.affichertemps();
			cout << endl << "Liste de passagers : ";
			int i = 0;
			while (!fres.eof())
			{
				fres >> r;
				if (r.nvol == v.nvol)
					i++;
			}
			cout << i << "/" << v.nbrmax << endl;
			fres.seekg(0);
			while (!fres.eof())
			{
				fres >> r;
				if (r.nvol == v.nvol)
					cout << " \t Numero de reservation : " << r.numres << " - Nom : " << r.p.nom << "- Prenom : " << r.p.prenom << endl;
			}
			ok = true;
		}
	}
	if (ok == false)
		cout << "l'element n'existe pas" << endl;
	fin.close();
	fres.close();
}
void modifvol()
{
	system("cls");
	cout << "Donner le numero de vol : ";
	long nv;
	cin >> nv;
	Vol v;
	ofstream fout("tempvol.txt");
	ifstream fin("Vol.txt");
	if (fout.bad() || fin.bad())
		cerr << "erreur !";
	bool exist = false;
	while (!fin.eof())
	{
		fin >> v;
		if (v.nvol != nv)
		{
			fout << endl << v;
		}
		else
		{
			exist = true;
			cout << " Veuillez introduire les nouvelles informations :" << endl;
			cout << "Heure de depart : ";
			v.hd.ajouttemps();
			cout << "Heure d'arrivee : ";
			v.ha.ajouttemps();
			cout << "Date de vol :  ";
			v.date_vol.ajoutdate();
			fout << endl << v;
		}
	}
	if (!exist)
		cout << "Le vol n'existe pas !!" << endl;
	fout.close();
	fin.close();
	ifstream fin1("tempvol.txt");
	ofstream fout1("Vol.txt", ios::trunc);
	if (fout1.bad() || fin1.bad())
		cerr << "erreur !";
	while (!fin1.eof())
	{
		fin1 >> v;
		fout1 << endl << v;
	}
	fout1.close();
	fin1.close();
	remove("tempvol.txt");
}
void supprimvol(long nv)
{
	Vol v;
	Reservation r;
	ifstream fivol("Vol.txt");
	ifstream fivres("Reservation.txt");
	ofstream fotmvol("tempvol.txt");
	if (fotmvol.bad() || fivol.bad())
		cerr << "erreur !";
	bool exist = false;
	fivol.seekg(0);
	while (!fivol.eof())
	{
		fivol >> v;
		if (v.nvol != nv)
		{
			fotmvol << endl << v;
		}
		else
		{
			exist = true;
		}
	}
	if (!exist)
		cout << "Ce vol n'existe pas !!" << endl;
	fotmvol.close();
	fivol.close();
	ifstream fitmvol("tempvol.txt");
	ofstream fovol("Vol.txt");
	if (fitmvol.bad() || fovol.bad())
		cerr << "Erreur";
	while (!fitmvol.eof())
	{
		fitmvol >> v;
		fovol << endl << v;
	}
	fovol.close();
	fitmvol.close();
	remove("tempvol.txt");
	while (!fivres.eof())
	{
		fivres >> r;
		if (r.nvol == nv)
		{
			supprimres(r.numres);
			fivres.seekg(0);
		}
	}
	fivres.close();
}