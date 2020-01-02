#pragma once
#include <vector>
#include "CatalogIndividual.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Facultate
{
private:
	int nr_studenti;
public:
	int get_nr_studenti() const;
private:
	std::vector<CatalogIndividual<Examen>> studenti;
	unordered_map<int, vector<CatalogIndividual<Examen>>> picati;
public:
	Facultate(int nr_studenti=0);
	void redare_partial();
	void calcul_note_finale();
	void afisare_picati();
	
};

