#include "Reservation.h"


Reservation::Reservation(long numres, long nvol, int a, int b, int c, string type, float prix, string d, string e, string f, int g, int h, int i, long j, long k, float l) :date_res(a,b,c), p(d,e,f,g,h,i,j,k,l)
{
	this->numres = numres;
	this->nvol = nvol;
	this->prix = prix;
	this->type = type;
}
void ajoutres()
{
	system("cls");
	Reservation r,r1;
	Vol v;
	ofstream fout("Reservation.txt", ios::app);
	ifstream fin("Reservation.txt");
	ifstream fvol("Vol.txt");
	if (fin.bad() || fvol.bad() || fout.bad())
		cerr << "Erreur";
	cout << " Veuillez introduire les informations necessaire :" << endl;
a:cout << "Numero de reservation : ";
	cin >> r.numres;
	fin.seekg(0);
	while (!fin.eof())
	{
		fin >> r1;
		if (r.numres == r1.numres)
		{
			cout << "La reservation existe deja " << endl;
			goto a;
		}
	}
b:cout << "Numero de vol : ";
	cin >> r.nvol;
	bool exist = false;
	bool plein = false;
	fvol.seekg(0);
	while (!fvol.eof())
	{
		fvol >> v;
		if (v.nvol == r.nvol)
		{
			exist = true;
			/*int i = 0;
			fin.seekg(0);
			while (!fin.eof())
			{
				fin >> r1;
					if (r1.nvol == v.nvol)
						i++;
			}
			if (i >= v.nbrmax)
				plein = true;*/
		}
	}
	if (!exist)
	{
		cout << "Ce vol n'existe pas !!" << endl;
		goto b;
	}
	if (plein)
	{
		cout << "La capacite maximal est atteinte !!" << endl;
		goto b;
	}
	cout << "Date :  "<< endl; r.date_res.ajoutdate();
c:	cout << "Type : "; cin >> r.type;
	cout << "Prix : "; cin >> r.prix;
	cout << "Passager : "<< endl; r.p.ajoutinfopass();
	/*fin.seekg(0);
	while (!fin.eof())
	{
		fin >> r1;
		if (r.p.numpassport == r1.p.numpassport)
		{
			if (r.nvol == r1.nvol)
			{
				cout << "La reservation existe deja " << endl;
				goto c;
			}
		}
	}*/
	fout << endl << r;
	fout.close();
	fin.close();
	fvol.close();
}

void afficheres()
{
	system("cls");
	Reservation r;
	ifstream fin("Reservation.txt");
	if (fin.bad())
		cerr << "erreur !";
	cout << "Numero de reservation - Date de reservation - type - Nom et Prenom de passager "<<endl;
	while (!fin.eof())
	{
		fin >> r;
		if (r.numres != 0)
		{
			cout << r.numres << " - ";
			r.date_res.affichedate();
			cout << " - " << r.type << " - " << r.p.nom << " - " << r.p.prenom << endl;
		}
		else
			cout << endl << "Vide !!" << endl;;
		
	}
	fin.close();
}
void supprimres( long x)
{

	Reservation r;
	ifstream fires("Reservation.txt");
	ofstream fotmres("tempres.txt");
	if ((fires.bad()) || (fotmres.bad()))
		cerr << "erreur !";
	bool exist = false;
	while (!fires.eof())
	{
		fires >> r;
		if (r.numres != x)
			fotmres << endl << r;
		else
			exist = true;
	}
	if (!exist)
		cout << "La reservation n'existe pas !!" << endl;
	fotmres.close();
	fires.close();
	ifstream fitmres("tempres.txt");
	ofstream fores("Reservation.txt", ios::trunc);
	if ((fores.bad()) || (fitmres.bad()))
		cerr << "erreur !";
	while (!fitmres.eof())
	{
		fitmres >> r;
		fores << endl << r;
	}
	fores.close();
	fitmres.close();
	remove("tempres.txt");
}
void modifres()
{
	system("cls");
	cout << "Donner le numero de reservation"  << endl;
	long x;
	cin >> x;
	Reservation r;
	ifstream fin("Reservation.txt");
	ofstream fout("tempres.txt");
	if ((fin.bad()) || (fout.bad()))
		cerr << "erreur !";
	bool exist = false;
	while (!fin.eof())
	{
		fin >> r;
		if (r.numres != x)
		{
			fout << endl << r;
		}
		else
		{
			exist = true;
			cout << " Veuillez introduire les informations necessaire :" << endl;
			cout << "Numero de reservation : "; cin >> r.numres;
			cout << "Numero de vol : "; cin >> r.nvol;
			cout << "Date :  "; r.date_res.ajoutdate();
			cout << "Type : "; cin >> r.type;
			cout << "Prix : "; cin >> r.prix;
			cout << "Passager : "; r.p.ajoutinfopass();

			fout << endl << r;
		}
	}
	if (!exist)
		cout << "La reservation n'existe pas !!" << endl;
	fout.close();
	fin.close();
	ifstream fin1("tempres.txt");
	ofstream fout1("Reservation.txt", ios::trunc);
	if ((fin1.bad()) || (fout1.bad()))
		cerr << "erreur !";
	while (!fin1.eof())
	{
		fin1 >> r;
		fout1 << endl << r;
	}
	fin1.close();
	fout1.close();
	remove("tempres.txt");
}
void recherchres()
{
	system("cls");
	cout << "Donner le numero de reservation" << endl;
	long x;
	cin >> x;
	Reservation r;
	ifstream fin("Reservation.txt");
	if (fin.bad())
		cerr << "Erreur";
	bool ok = false;
	while (!fin.eof())
	{
		fin >> r;
		if (r.numres == x)
		{
			cout << "Numero de reservation : " << r.numres;
			cout << "Numero de vol : " << r.nvol;
			cout << "Date de reservation : "; r.date_res.affichedate();
			cout << "Type : " << r.type;
			cout << "Prix : " << r.prix;
			cout << "Information de passager : " << endl;
			r.p.afficheinfopass();
			ok = true;
		}
	}
	if (ok == false)
		cout << "l'element n'existe pas" << endl;
	fin.close();
}
ostream& operator<<(ostream& out, Reservation& r)
{
	out << r.numres << " " << r.nvol << " " << r.date_res << " " << r.type << " " << r.prix << " " << r.p;
	return out;
}
istream& operator>>(istream& in, Reservation& r)
{
	in >> r.numres >> r.nvol >> r.date_res >> r.type >> r.prix >> r.p;
	return in;
}
