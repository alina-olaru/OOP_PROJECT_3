#include "global.h"
#include <iostream>

std::vector<std::string> NumeExamene::nume_examene;

void PrintLongString::Print(char caracter, int no_of_outputs)
{
	std::cout << std::endl;
	for(int i=0;i<no_of_outputs;i++)
	{
		std::cout << caracter;
	}
	std::cout << std::endl;
}
