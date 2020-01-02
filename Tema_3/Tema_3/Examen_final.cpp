#include "Examen_final.h"
#include "Examen.h"
#include <iostream>
#include <stdlib.h>
using namespace  std;

float Examen_final::get_puncte_proiect() const
{
	return puncte_proiect;
}

Examen_final::Examen_final():Examen()
{
	this->puncte_proiect = 0;
	
}


Examen_final::Examen_final(float a, std::string c, float d):Examen(c,d)
{
	
	this->puncte_proiect = a;
}

void Examen_final::citire()
{
	cout << "--EXAMEN FINAL--" << endl;
	Examen::citire();
	cout << endl << "Puncte proiect(extra): ";
	cin >> this->puncte_proiect;
}

void Examen_final::citire_cu_denumire(std::string denumire)
{
	cout << "--EXAMEN FINAL--" << endl;
	Examen::citire_cu_denumire(denumire);
	cout << endl << "Puncte proiect(extra): ";
	cin >> this->puncte_proiect;
}


void Examen_final::afis()
{
	cout << "Examen final" << endl;
	Examen::afis();
	cout << endl;
	cout << "Puncte in plus: " << this->puncte_proiect;
}
