#include "Examen.h"

#include "Partial.h"
#include "Quizz.h"
#include "CatalogIndividual.h"
#include "Examen_final.h"
#include <typeinfo>
#include "Facultate.h"
#include "global.h"



int main()
{
	NumeExamene::nume_examene.push_back("Necunoscut");
	
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



			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}

			if (nr_studenti_fac < 2)
			{
				throw("Minim 2 studenti");
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
	facultate->afis();
	facultate->afis_q();
	
	
	
	
	return 0;
	
}
