#include "Examen.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace  std;


/*	int nr;
	std::string denumire;
	float nota_scris;*/

Examen::Examen()
{
	
	this->nr = 0;
	this->denumire = "Necunoscut";
	this->nota_scris = 5;
}

int Examen::get_nr() const
{
	return nr;
}

std::string Examen::get_denumire() const
{
	return denumire;
}

float Examen::get_nota_scris() const
{
	return nota_scris;
}

void Examen::set_nota_scris(float nota_scris)
{
	this->nota_scris = nota_scris;
}

Examen::Examen(std::string b , float c)
{
	for (auto& c : b) c = toupper(c);

	auto it = find(nume_examene.begin(), nume_examene.end(), b);
	
	if (it == nume_examene.end())
	{
		nume_examene.push_back(b);
		it = find(nume_examene.begin(), nume_examene.end(), b);
	}
	
	this->nr = std::distance(nume_examene.begin(), it);
	this->denumire = b;
	this->nota_scris = c;
}

void Examen::citire()
{

	string den;
	cout << endl << "Denumirea materiei: ";
	cin >> den;

	for (auto& c : den) c = toupper(c);

	auto it = find(nume_examene.begin(), nume_examene.end(), den);
	
	if (it == nume_examene.end())
	{
		nume_examene.push_back(den);
		it = find(nume_examene.begin(), nume_examene.end(), den);
	}

	this->nr = std::distance(nume_examene.begin(), it);

	this->denumire = den;
	
	cout << endl << "Nota la scris: ";
	cin >> this->nota_scris;
}

void Examen::citire_cu_denumire(std::string denumire)
{
	auto it = find(nume_examene.begin(), nume_examene.end(), denumire);
	this->nr = std::distance(nume_examene.begin(), it);

	this->denumire = denumire;

	cout << endl << "Nota la scris: ";
	cin >> this->nota_scris;
}


void Examen::afis()
{
	for (int i = 0; i < 40; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "ID: " << this->nr << endl;
	cout << "Denumire: "<< this->denumire << endl << "Nota scris:" << this->nota_scris << endl;
}
