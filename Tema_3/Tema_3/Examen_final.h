#pragma once
#include "Examen.h"
#include <stdlib.h>
class Examen_final :public Examen
{
protected:
	float puncte_proiect;
public:
	//getter
	float get_puncte_proiect() const;
	//constructori
	Examen_final();
	Examen_final(float, std::string, float);
	//~Examen_final();
	void citire();
	//functia de citire_cu_denumire este apelata pentru citirea datelor despre
//partial si examen final (pentru a nu introduce numele examenului la fiecare nota)
	void citire_cu_denumire(std::string);
	void afis();

};

