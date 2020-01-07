#pragma once
#include "Examen.h"
class Partial:public Examen
{
protected:
	float nota_oral;
public:
	//getteri si setteri
	float get_nota_oral();
	void set_nota_oral(float nota_oral);
	//constructori
	Partial();
	Partial(float, std::string, float);
	//metodele de citire si afisare
	//~Partial();
	void citire();
	void afis();
	
};

