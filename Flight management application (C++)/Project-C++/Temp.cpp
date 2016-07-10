#include "Temp.h"

Temp::Temp(int h,int m)
{
	this->h = h;
	this->m = m;
}
ostream& operator<<(ostream& out, Temp& t)
{
	out << t.h << " " << t.m;
	return out;
}
istream& operator>>(istream& in, Temp& t)
{
	in >> t.h;
	in >> t.m;
	return in;
}

void Temp::affichertemps()
{
	cout << h << ":" << m;
}
void Temp::ajouttemps()
{
	cout << "\t\tHeure : ";
	cin >> h;
	cout << "\t\tMinute : ";
	cin >> m;
}
