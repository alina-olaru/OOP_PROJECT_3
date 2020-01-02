#pragma once
#include "Examen.h"
class Partial:public Examen
{
protected:
	float nota_oral;
public:
	float get_nota_oral();
	void set_nota_oral(float nota_oral);
	Partial();
	Partial(float, std::string, float);
	//~Partial();
	void citire();
	void afis();
	
};

