#pragma once
#include <iostream>
using namespace std;
class BAGAGE
{
private:
	long ref;
	float poid;
public:
	BAGAGE(long = 0, float = 0.0);
	friend ostream& operator<<(ostream&, BAGAGE&);
	friend istream& operator>>(istream&, BAGAGE&);
	void ajoutbag();
	void affichebag();
};
