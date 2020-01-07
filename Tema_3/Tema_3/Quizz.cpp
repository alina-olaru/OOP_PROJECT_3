#include "Quizz.h"
#include <ostream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace  std;


Quizz::Quizz():Examen()
{
	srand(time(NULL));

	this->nr_itemi = rand() % 10 + 10;
}

Quizz::Quizz(int c, std::string d, float e) 
	:Examen(d, e)
{
	srand(time(NULL));
	this->nr_itemi = rand() % 10 + 10;

}

void Quizz::citire()
{
	Examen::citire();
}



void Quizz::afis()
{
	Examen::afis();
	cout << "QUIZZ PT MARIRE";
	cout << endl;
	Examen::afis();
	cout << endl;
	cout << "Nr. itemi " << endl << this->nr_itemi;

}

int Quizz::get_nr_itemi()
{
	return this->nr_itemi;
}
