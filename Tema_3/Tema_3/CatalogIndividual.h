#pragma once
#include <iostream>
#include<vector>
#include "Examen_final.h"
#include "Partial.h"
#include "Quizz.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include "global.h"

using namespace std;

static int idx_nr_matricol = 1;

template<class T>
class CatalogIndividual
{

	int nr_matricol;
public:
	static int nr_studenti_quizz;
	int get_nr_matricol() const;
	int get_quizz() {
		return this->quizzuri_date;
	}

	void set_quizz(int a) {
		this->quizzuri_date = a;
	}
private:
	int quizzuri_date;
	int nr_examene_student;
	std::vector<T*> examene;
	std::unordered_map<int, float> note_finale;
public:

	void operator+=(T* ob)
	{
		this->examene.push_back(ob);
		this->nr_examene_student++;
	}

	CatalogIndividual Add(T* ob)
	{
		this->examene.push_back(ob);
		this->nr_examene_student++;
		return *this;
	};


	//constructorul care initializeaza campurile
	CatalogIndividual()
	{
		this->nr_matricol = idx_nr_matricol++;
		this->nr_examene_student = 0;
		this->quizzuri_date = 0;
	};

	//functia de citire a datelor
	void citire()
	{
		this->examene.clear();
		//initializez nr examene=0
		int nr_exam = 0;
		while (1) {

			cout << endl << endl << "Student nr matricol: " << this->nr_matricol;
			cout << endl << "Introdu numarul de examene sustinute de acest student: ";


			try {

				cin >> nr_exam;

				if (cin.fail())
					//dupa ce cin-ul da fail,trebuie neaparat dat clear
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					//dau throw erorii aparute
					throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
				}


				if ((nr_exam < 1) || (nr_exam) > 100) {
					throw invalid_argument("Argument invalid pentru numarul de examene per student.");
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

		for (int i = 0; i < nr_exam; i++)
		{
			PrintLongString::Print('-', 30);

			Partial* p = new Partial();
			p->citire();
			//	this += dynamic_cast<T*>(*p);
			Add(p);

			Examen_final* f = new Examen_final();
			f->citire_cu_denumire(p->get_denumire());
			//this += *f;
			Add(f);
		}

	}

	void verifica_redare_partial()
	{

		for (int i = 0; i != this->examene.size(); i++)
		{
			if (typeid(*(this->examene.at(i))) == typeid(Partial))
			{
				Partial* p = dynamic_cast<Partial*>(this->examene[i]);

				if (p->get_nota_scris() < 5 || p->get_nota_oral() < 5)
				{
					cout << endl << endl;
					cout << "Studentul cu numarul matricol " << this->nr_matricol << " a picat partialul la materia " << p->get_denumire();





					while (1) {

						cout << endl << "Introdu noua nota pentru partial: ";
						int nota;


						try {
							cin >> nota;
							p->set_nota_scris(nota);

							if (cin.fail())
								//dupa ce cin-ul da fail,trebuie neaparat dat clear
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								//dau throw erorii aparute
								throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
							}


							if ((nota < 1) || (nota) > 10) {
								throw invalid_argument("Argument invalid pentru o nota.");
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












					while (1) {

						cout << endl << "Introdu noua nota oral pentru partial: ";
						int nota;


						try {
							cin >> nota;
							p->set_nota_oral(nota);

							if (cin.fail())
								//dupa ce cin-ul da fail,trebuie neaparat dat clear
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								//dau throw erorii aparute
								throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
							}


							if ((nota < 1) || (nota) > 10) {
								throw invalid_argument("Argument invalid pentru o nota.");
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
			}
		}

	}

	vector<int> calculare_nota_finala()
	{
		vector<int> materii_picate;
		cout << endl << "Student numar matricol " << this->nr_matricol << endl;

		for (int i = 0; i < this->nr_examene_student; i++)
		{
			if (typeid(*this->examene.at(i)) == typeid(Examen_final))
			{

				for (int j = 0; j < this->nr_examene_student; j++)
				{
					if (typeid(*this->examene.at(j)) == typeid(Partial))
					{
						Examen_final* f = dynamic_cast<Examen_final*>(this->examene[i]);
						Partial* p = dynamic_cast<Partial*>(this->examene[j]);

						if (f->get_nr() == p->get_nr())
						{
							float nota_partial = (p->get_nota_scris() + p->get_nota_oral()) / 2;
							float nota_examen_final = std::min((f->get_nota_scris() + f->get_puncte_proiect()), 10.0f);

							float nota_final = (nota_partial + nota_examen_final) / 2;

							cout << endl << "Nota finala materia " << p->get_denumire() << "(id examen=" << p->get_nr() << ") este " << nota_final;
							this->note_finale.insert(make_pair(p->get_nr(), nota_final));
						}

					}
				}





			}
		}


		while (1)
		{
			cout << endl << endl;
			//cout << "Doriti marire?Introduceti 0 pentru nu,1 pentru da" << endl;

			int ch;
			while (1)
			{
				cout << endl << endl;
				cout << "Doriti marire?Introduceti 0 pentru nu,1 pentru da" << endl;
				try
				{
					cout << "Introdu optiunea: ";
					cin >> ch;


					if (cin.fail())
						//dupa ce cin-ul da fail,trebuie neaparat dat clear
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						//dau throw erorii aparute
						throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
					}


					if ((ch != 0) && (ch != 1)) {
						throw std::invalid_argument("Arg. invalid.");

					}
					break;
				}
				catch (const invalid_argument & arg)
				{
					cout << arg.what();
				}

			}


			if (ch == 0)
			{
				cout << endl << "Notele vor ramane la fel." << endl;
				break;
			}
			else
			{

				cout << endl << "Pentru ce materie doriti marire?" << endl;

				while (1) {
					cout << "Introdu id-ul materiei " << endl << "Introdu -1 daca vrei sa iesi ." << endl;
					int _id;
					cin >> _id;


					if (cin.fail())
						//dupa ce cin-ul da fail,trebuie neaparat dat clear
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						//dau throw erorii aparute
						throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
					}


					if (_id == -1)
					{
						break;
					}
					if (this->note_finale.find(_id) == this->note_finale.end())
					{
						cout << endl << "Id gresit.Nu se poate mari nota." << endl;
						continue;
					}

					else
					{
						this->set_quizz(this->get_quizz() + 1);
						Quizz* quizz_local = new Quizz();
						cout << "Pentru marire s-a dat un  test cu " << quizz_local->get_nr_itemi() << " itemi" << endl;
						cout << "Nota dupa marire ";
						float nota;
						while (1)
						{
							try
							{
								cin >> nota;


								if (cin.fail())
									//dupa ce cin-ul da fail,trebuie neaparat dat clear
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									//dau throw erorii aparute
									throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
								}


								if ((nota < 1) || (nota > 10))
								{
									throw std::invalid_argument("Arg. invalid.");
								}

								break;
							}
							catch (const invalid_argument & arg)
							{
								cout << arg.what();
							}
						}

						quizz_local->set_nota_scris(nota);

						if (nota > this->note_finale[_id]) {
							this->note_finale[_id] = nota;
						}
						else
						{
							cout << endl << "Pentru ca nota marita este mai mica decat cea initiala,nu se va schimba nota la acest examen" << endl;

						}

					}



				}
			}
		}

		if (this->get_quizz() >= 2)
		{
			nr_studenti_quizz++;
		}

		for (auto x : this->note_finale)
		{
			if (x.second < 5)
			{
				materii_picate.push_back(x.first);

			}
		}


		return materii_picate;

	}
	void afisare()
	{

		PrintLongString::Print('*', 40);
		cout << endl;
		cout << "Nr matricol " << this->nr_matricol;
		cout << endl << "Nr student" << this->nr_examene_student;
		for (int a = 0; a < this->nr_examene_student; a++)
		{

			//am folosit rtti pentru afisare (dynamic_cast la o anumita clasa din examen_final/quizz/partial
			cout << endl << endl;
			if (typeid(*this->examene.at(a)) == typeid(Examen_final))
			{
				(*dynamic_cast<Examen_final*>(this->examene.at(a))).afis();
			}
			else if (typeid(*this->examene.at(a)) == typeid(Partial))
			{
				(*dynamic_cast<Partial*>(this->examene.at(a))).afis();
			}
			else if (typeid(*this->examene.at(a)) == typeid(Quizz))
			{
				(*dynamic_cast<Quizz*>(this->examene.at(a))).afis();
			}




			cout << endl << endl << endl;
			cout << "A dat " << this->get_quizz() << " quiz-uri" << endl;
		}





	};

	template <class T>
	int CatalogIndividual<T>::get_nr_matricol() const
	{
		return nr_matricol;
	}



	template <class T>
	int CatalogIndividual<T>::nr_studenti_quizz = 0;



	/*
	template<>
	void CatalogIndividual::operator() <int> {
		cout << endl;

	*/
	/*

	void operator+=(T* ob)
	*/









	template<>
	class CatalogIndividual<Quizz>
	{
		int nr_matricol;
		int nr_quizzuri;
	public:
		int get_nr_matricol() const;
	private:
		int nr_examene_student;
		std::vector<Quizz*> examene;
		std::unordered_map<int, float> note_finale;
	public:

		void operator+=(Quizz* ob)
		{
			this->examene.push_back(ob);
			this->nr_examene_student++;
		}

		CatalogIndividual Add(Quizz* ob)
		{
			this->examene.push_back(ob);
			this->nr_examene_student++;
			return *this;
		};
		/*
		CatalogIndividual Add_p(Partial* ob)
		{
			this->examene.push_back(ob);
			this->nr_examene_student++;
			return *this;
		};

		CatalogIndividual Add_f(Examen_final* ob)
		{
			this->examene.push_back(ob);
			this->nr_examene_student++;
			return *this;
		};*/
		CatalogIndividual()
		{
			this->nr_matricol = idx_nr_matricol++;
			this->nr_examene_student = 0;
			this->nr_quizzuri = 0;
		};

		void citire()
		{
			this->examene.clear();
			cout << endl << endl << "Student nr matricol: " << this->nr_matricol;
			cout << endl << "Introdu numarul de examene sustinute de acest student: ";


			Quizz* quizz = new Quizz();
			quizz->citire();
			Add(quizz);



		}

		void verifica_redare_partial()
		{

			for (int i = 0; i != this->examene.size(); i++)
			{
				if (typeid(*(this->examene.at(i))) == typeid(Partial))
				{
					Partial* p = dynamic_cast<Partial*>(this->examene[i]);

					if (p->get_nota_scris() < 5 || p->get_nota_oral() < 5)
					{
						cout << endl << endl;
						cout << "Studentul cu numarul matricol " << this->nr_matricol << " a picat partialul la materia " << p->get_denumire();
						cout << endl << "Introdu noua nota pentru partial: ";
						int nota;
						cin >> nota;
						p->set_nota_scris(nota);
						cout << endl << "Introdu noua nota oral pentru partial: ";
						cin >> nota;
						p->set_nota_oral(nota);
					}
				}
			}

		}

		vector<int> calculare_nota_finala()
		{
			vector<int> materii_picate;
			cout << endl << "Student numar matricol " << this->nr_matricol << endl;

			for (int i = 0; i < this->nr_examene_student; i++)
			{
				if (typeid(*this->examene.at(i)) == typeid(Examen_final))
				{

					for (int j = 0; j < this->nr_examene_student; j++)
					{
						if (typeid(*this->examene.at(j)) == typeid(Partial))
						{
							Examen_final* f = dynamic_cast<Examen_final*>(this->examene[i]);
							Partial* p = dynamic_cast<Partial*>(this->examene[j]);

							if (f->get_nr() == p->get_nr())
							{
								float nota_partial = (p->get_nota_scris() + p->get_nota_oral()) / 2;
								float nota_examen_final = std::min((f->get_nota_scris() + f->get_puncte_proiect()), 10.0f);

								float nota_final = (nota_partial + nota_examen_final) / 2;

								cout << endl << "Nota finala materia " << p->get_denumire() << "(id examen=" << p->get_nr() << ") este " << nota_final;
								this->note_finale.insert(make_pair(p->get_nr(), nota_final));
							}

						}
					}





				}
			}



			while (1)
			{
				cout << endl << endl;
				cout << "Doriti marire?Introduceti 0 pentru nu,1 pentru da" << endl;

				int ch;
				while (1)
				{
					try
					{
						cout << "Introdu optiunea: ";
						cin >> ch;
						if ((ch != 0) && (ch != 1)) {
							throw std::invalid_argument("Arg. invalid.");

						}
						break;
					}
					catch (const invalid_argument & arg)
					{
						cout << arg.what();
					}

				}


				if (ch == 0)
				{
					cout << endl << "Notele vor ramane la fel." << endl;
					break;
				}
				else
				{
					this->nr_quizzuri = this->nr_quizzuri + 1;
					cout << endl << "Pentru ce materie doriti marire?" << endl;

					while (1) {
						cout << "Introdu id-ul materiei " << endl << "Introdu -1 daca vrei sa iesi ." << endl;
						int _id;
						cin >> _id;
						if (_id == -1)
						{
							break;
						}
						if (this->note_finale.find(_id) == this->note_finale.end())
						{
							cout << endl << "Id gresit.Nu se poate mari nota." << endl;
							continue;
						}

						else
						{
							Quizz* quizz_local = new Quizz();
							cout << "Pentru marire s-a dat un  test cu " << quizz_local->get_nr_itemi() << " itemi" << endl;
							cout << "Nota dupa marire ";
							float nota;
							while (1)
							{
								try
								{
									cin >> nota;
									if ((nota < 1) || (nota > 10))
									{
										throw std::invalid_argument("Arg. invalid.");
									}

									break;
								}
								catch (const invalid_argument & arg)
								{
									cout << arg.what();
								}
							}

							quizz_local->set_nota_scris(nota);

							if (nota > this->note_finale[_id]) {
								this->note_finale[_id] = nota;
							}
							else
							{
								cout << endl << "Pentru ca nota marita este mai mica decat cea initiala,nu se va schimba nota la acest examen" << endl;

							}

						}



					}
				}
			}

			for (auto x : this->note_finale)
			{
				if (x.second < 5)
				{
					materii_picate.push_back(x.first);

				}
			}


			return materii_picate;

		}
		void afisare()
		{

			for (int i = 0; i < 40; i++)
			{
				cout << "*";
			}
			cout << endl;
			cout << "Nr matricol " << this->nr_matricol;
			cout << endl << "Nr student" << this->nr_examene_student;
			for (int a = 0; a < this->nr_examene_student; a++)
			{
				cout << endl << endl;
				if (typeid(*this->examene.at(a)) == typeid(Examen_final))
				{
					(*dynamic_cast<Examen_final*>(this->examene.at(a))).afis();
				}
				else if (typeid(*this->examene.at(a)) == typeid(Partial))
				{
					(*dynamic_cast<Partial*>(this->examene.at(a))).afis();
				}
				else if (typeid(*this->examene.at(a)) == typeid(Quizz))
				{
					(*dynamic_cast<Quizz*>(this->examene.at(a))).afis();
				}
			}
		}


	};
};