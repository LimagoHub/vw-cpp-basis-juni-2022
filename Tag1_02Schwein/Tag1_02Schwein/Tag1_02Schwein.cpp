// Tag1_02Schwein.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Schwein.h"



int main()
{

	
	
	//Schwein piggy{"Miss Piggy"};

	std::string name = "Miss Piggy";
	
	Schwein piggy;
	piggy = name;
	
	std::cout << piggy << std::endl;
	++piggy;
	std::cout << piggy << std::endl;
	
	
}

