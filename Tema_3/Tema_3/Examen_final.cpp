#include "Examen_final.h"
#include "Examen.h"
#include <iostream>
#include <stdlib.h>
using namespace  std;

float Examen_final::get_puncte_proiect() const
{
	return puncte_proiect;
}

Examen_final::Examen_final():Examen()
{
	this->puncte_proiect = 0;
	
}


Examen_final::Examen_final(float a, std::string c, float d):Examen(c,d)
{
	
	this->puncte_proiect = a;
}

void Examen_final::citire()
{
	cout << endl << "--EXAMEN FINAL--";
	Examen::citire();



	while (1)
	{
		cout << endl << "Puncte proiect(extra): ";


		try
		{
			cin >> this->puncte_proiect;


			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}


			if ((this->puncte_proiect> 10) || (this->puncte_proiect<0)) {
				throw invalid_argument("Nu se pot acorda aceste puncte bonus.Reintroduceti bonusul");
			}
			break;

		}

		catch (std::invalid_argument & arg)
		{
			cout << arg.what();

		}
		catch (...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}


	}








}

void Examen_final::citire_cu_denumire(std::string denumire)
{
	cout << endl << "--EXAMEN FINAL--" << endl;
	Examen::citire_cu_denumire(denumire);
	//cout << endl << "Puncte proiect(extra): ";
	//cin >> this->puncte_proiect;



	while (1)
	{
		cout << endl << "Puncte proiect(extra): ";


		try
		{
			cin >> this->puncte_proiect;


			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}


			if ((this->puncte_proiect > 10) || (this->puncte_proiect < 0)) {
				throw invalid_argument("Nu se pot acorda aceste puncte bonus.Reintroduceti bonusul");
			}
			break;

		}

		catch (std::invalid_argument & arg)
		{
			cout << arg.what();

		}
		catch (...)
		{
			cout << "A intervenit o problema in sistem." << endl;
		}


	}







}


void Examen_final::afis()
{
	cout << "Examen final" << endl;
	Examen::afis();
	cout << endl;
	cout << "Puncte in plus: " << this->puncte_proiect;
}
