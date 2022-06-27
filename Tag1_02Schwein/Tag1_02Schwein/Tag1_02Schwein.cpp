// Tag1_02Schwein.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Schwein.h"



int main()
{
	Schwein piggy;
	Schwein babe;
	piggy.set_name("Miss Piggy");
	

	std::cout <<  piggy.to_string() << std::endl;

	babe = piggy;
	
	piggy.fressen();

	std::cout <<  babe.to_string() << std::endl;
	
	
	
}

