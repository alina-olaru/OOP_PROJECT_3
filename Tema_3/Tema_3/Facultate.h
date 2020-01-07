#pragma once
#include <vector>
#include "CatalogIndividual.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;


//clasa facultate contine un vector de studenti (adica n cataloage individuale)
//si o structura cu studentii picati+examenul picat de catre acestia
class Facultate
{
private:
	int nr_studenti;
public:
	//getteri
	int get_nr_studenti() const;
private:
	//vectorul de studenti picati
	std::vector<CatalogIndividual<Examen>> studenti;
	//structura unde retin elevii care nu au trecut examenul impreuna cu id-ul examenului
	//pe care l-au picat
	unordered_map<int, vector<CatalogIndividual<Examen>>> picati;
public:
	//constructor parametrizat
	Facultate(int nr_studenti = 0);
	//metodele pentru a calcula notele finale pentru fiecare examen,redare partial
	//quizz si afisare picati
	void redare_partial();
	void calcul_note_finale();
	void afisare_picati();
	void afis();

};


