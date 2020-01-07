#pragma once
#include "Facultate.h"
#include "global.h"

using namespace std;

int Facultate::get_nr_studenti() const
{
	return nr_studenti;
}

Facultate::Facultate(int nr_studenti)
{
	this->nr_studenti = nr_studenti;
	for(int i=0;i<this->nr_studenti;i++)
	{
		CatalogIndividual<Examen> cat_ind;
		cat_ind.citire();
		this->studenti.push_back(cat_ind);

		PrintLongString::Print('*', 40);

	}
	
}


void Facultate::redare_partial()
{
	for(auto x:this->studenti)
	{
		x.verifica_redare_partial();
	}
}

void Facultate::calcul_note_finale()
{
	for(auto y:this->studenti)
	{//y vect de studenti 
		vector<int> materii_picate=y.calculare_nota_finala();
		//vectorul materiilor la care a picat 

		for(auto w:materii_picate)
		{
			if(this->picati.find(w)==this->picati.end())
			{
				//nu exista->il inserez
				this->picati.insert(make_pair(w,
					vector<CatalogIndividual<Examen>>{
					y}));
			}
			else
			{
				this->picati[w].push_back(y);
			}
		}
	}
}

void Facultate::afisare_picati()
{
	
	for(auto y:this->picati)
	{
		std::string x = NumeExamene::nume_examene.at(y.first);
		//aici sus am luat denumirea examenului cu id ul din y
		cout << endl << "Studentii picati pt materia: " << x << endl;
		for(auto a:y.second)
		{
			cout << endl << a.get_nr_matricol();
			//a.afisare();
		}
	}
}

void Facultate::afis()
{
	for (auto x : this->studenti)
	{
		x.afisare();
	}
}