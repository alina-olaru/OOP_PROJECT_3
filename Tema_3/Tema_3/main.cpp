#include "Examen.h"

#include "Partial.h"
#include "Quizz.h"
#include "CatalogIndividual.h"
#include "Examen_final.h"
#include <typeinfo>
#include "Facultate.h"

int main()
{
	//1 nr matricol student
//	CatalogIndividual<Examen> a;
	//Examen_final *b = new Examen_final(10,10,"OOP",15);
	//a+=b;
	//a->Add(*b);
	/*

	
	Examen_final* e = new Examen_final();
	e->citire();
	Partial* f = new Partial();
	f->citire();
	//a->Add(e);
	//a->Add(f);

	
	a += e;

	a += f;

	a.afisare();

	*/
	int nr_studenti_fac;
	while (1) {
		try {
			cout << "Cati studenti sunt in facultate:";
			cin >> nr_studenti_fac;
			if(nr_studenti_fac<2)
			{
				throw("invalid arg");
			}
			break;
		}
		catch(std::invalid_argument& arg)
		{
			cout << arg.what();
			
		}
		catch(...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}
	}




	Facultate* facultate = new Facultate(nr_studenti_fac);
	facultate->redare_partial();
	facultate->calcul_note_finale();
	facultate->afisare_picati();
	
	
	
	
	
	return 0;
	
}
