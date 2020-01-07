#pragma once

#include "Examen.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "global.h"

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

	auto it = find(NumeExamene::nume_examene.begin(), NumeExamene::nume_examene.end(), b);
	
	if (it == NumeExamene::nume_examene.end())
	{
		NumeExamene::nume_examene.push_back(b);
		it = find(NumeExamene::nume_examene.begin(), NumeExamene::nume_examene.end(), b);
	}
	
	this->nr = std::distance(NumeExamene::nume_examene.begin(), it);
	this->denumire = b;
	this->nota_scris = c;
}

void Examen::citire()
{

	string den;

	while (1) {
		try {
			cout << endl << "Denumirea materiei: ";
			cin >> den;
			if (den.length() < 2)
			{
				throw invalid_argument("Denumirea trebuie sa aiba minim 3 litere");
			}

			break;


		}

		catch (std::invalid_argument & arg)
		{
			cout << arg.what();

		}
		catch (...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}



	}
	for (auto& c : den) c = toupper(c);

	auto it = find(NumeExamene::nume_examene.begin(), NumeExamene::nume_examene.end(), den);
	
	if (it == NumeExamene::nume_examene.end())
	{
		NumeExamene::nume_examene.push_back(den);
		it = find(NumeExamene::nume_examene.begin(), NumeExamene::nume_examene.end(), den);
	}

	this->nr = std::distance(NumeExamene::nume_examene.begin(), it);

	this->denumire = den;
	




	while (1)
	{
		cout << endl << "Nota la scris: ";

		try
		{

			cin >> this->nota_scris;


			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}


			if ((this->nota_scris > 10) || (this->nota_scris < 1)) {
				throw invalid_argument("Argument invalid pentru o nota");
			}
			break;

		}

		catch (std::invalid_argument & arg)
		{
			cout << arg.what();

		}
		catch (...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}


	}




}

void Examen::citire_cu_denumire(std::string denumire)
{
	auto it = find(NumeExamene::nume_examene.begin(), NumeExamene::nume_examene.end(), denumire);
	this->nr = std::distance(NumeExamene::nume_examene.begin(), it);

	this->denumire = denumire;
	while (1)
	{
		cout << endl << "Nota la scris: ";

		try
		{

			cin >> this->nota_scris;


			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}


			if ((this->nota_scris > 10) || (this->nota_scris < 1)) {
				throw invalid_argument("Argument invalid pentru o nota");
			}
			break;

		}

		catch (std::invalid_argument & arg)
		{
			cout << arg.what();

		}
		catch (...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}


	}
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
