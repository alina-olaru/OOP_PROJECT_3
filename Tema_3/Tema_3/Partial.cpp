#include "Partial.h"
#include "Examen.h"
#include <iostream>
#include <stdlib.h>
using namespace  std;


float Partial::get_nota_oral()
{
	return this->nota_oral;
}

void Partial::set_nota_oral(float nota_oral)
{
	this->nota_oral = nota_oral;
}

Partial::Partial():Examen()
{
	this->nota_oral = 0;
}

Partial::Partial(float a, std::string c, float d):Examen(c,d)
{
	this->nota_oral = a;
}

void Partial::citire()
{
	cout << endl;
	cout << "--PARTIAL--";
	cout << endl;
	Examen::citire();


	while (1)
	{
		cout << endl;
		cout << "nota oral: ";
		try
		{
			cin >> this->nota_oral;


			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}


			if ((this->nota_oral > 10) || (this->nota_oral < 1)) {
				throw invalid_argument("Argument invalid pentru o nota");
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


void Partial::afis()
{
	cout << endl;
	cout << "PARTIAL";
	cout << endl;
	Examen::afis();
	cout << endl << "Nota oral " << this->nota_oral;
}
