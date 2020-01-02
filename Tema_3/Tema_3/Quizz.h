#pragma once
#include "Examen.h"
class Quizz:public Examen
{
protected:
	int nr_itemi;

public:
	Quizz();
	Quizz(int, std::string, float);
	//~Quizz();
	void citire();
	void afis();
	int get_nr_itemi();
	
};

