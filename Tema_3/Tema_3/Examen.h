#pragma once

#include <string>
#include <vector>

using namespace std;

static int increment_id = 1;

static std::vector<std::string> nume_examene{ "Necunoscut" };

class Examen

{
protected:
	int nr;
public:
	int get_nr() const;
protected:
	std::string denumire;
	float nota_scris;
public:
	std::string get_denumire() const;
	float get_nota_scris() const;
	void set_nota_scris(float nota_scris);
	//std::istream& operator>>(std::istream& in, Examen& ob);
	Examen(std::string, float);
	Examen();
	//~Examen();
	
	virtual void citire();
	virtual void citire_cu_denumire(std::string);
	virtual void afis();
	
};

