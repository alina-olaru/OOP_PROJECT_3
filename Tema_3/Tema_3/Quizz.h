#pragma once
#include "Examen.h"
class Quizz:public Examen
{
protected:
	int nr_itemi;

public:
	//constructori
	Quizz();
	Quizz(int, std::string, float);
	//~Quizz();
	void citire();
	void afis();
	//getter
	int get_nr_itemi();
	
};

