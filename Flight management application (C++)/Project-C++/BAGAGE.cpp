#include "BAGAGE.h"


BAGAGE::BAGAGE(long ref, float poid)
{
	this->ref = ref;
	this->poid = poid;
}
ostream& operator<<(ostream& out, BAGAGE& b)
{
	out << b.ref << " " << b.poid;
	return out;
}
istream& operator>>(istream& in, BAGAGE& b)
{
	in >> b.ref >> b.poid;
	return in;
}
void BAGAGE::ajoutbag()
{
	cout << "\t\tReference: "; cin >> ref;
	cout << "\t\tPoids : "; cin >> poid;
}
void BAGAGE::affichebag()
{
	cout << "Reference : " << ref << " -- Poids : " << poid << " Kg ";
}
