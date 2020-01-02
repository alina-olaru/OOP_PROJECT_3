#include "Partial.h"
#include "Examen.h"
#include <iostream>
#include <stdlib.h>
using namespace  std;


float Partial::get_nota_oral()
{
	return this->nota_oral;
}

void Partial::set_nota_oral(float nota_oral)
{
	this->nota_oral = nota_oral;
}

Partial::Partial():Examen()
{
	this->nota_oral = 0;
}

Partial::Partial(float a, std::string c, float d):Examen(c,d)
{
	this->nota_oral = a;
}

void Partial::citire()
{
	cout << endl;
	cout << "--PARTIAL--";
	cout << endl;
	Examen::citire();
	cout << endl;
	cout << "nota oral: ";
	cin >> this->nota_oral;
}


void Partial::afis()
{
	cout << endl;
	cout << "PARTIAL";
	cout << endl;
	Examen::afis();
	cout << endl << "Nota oral " << this->nota_oral;
}
