// Tag1_03Geometrie.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Punkt.h"



int main()
{
	
	Punkt p{ 2.0 , 4.9};
	for (int i = 0; i < 12; ++i)
	{
		std::cout << p << std::endl;
		p.rechts();
	}

	
 }


