#pragma once
#include "Examen.h"
#include <stdlib.h>
class Examen_final:public Examen
{
	protected:
	float puncte_proiect;
public:
	float get_puncte_proiect() const;
	Examen_final();
	Examen_final(float, std::string, float);
	//~Examen_final();
	void citire();
	void citire_cu_denumire(std::string);
	void afis();

};

