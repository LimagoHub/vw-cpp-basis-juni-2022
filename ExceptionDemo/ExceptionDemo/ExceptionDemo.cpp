// ExceptionDemo.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <stdexcept>

void upps()
{
	throw std::out_of_range{ "Mist" };
}


int main()
{
	try {
		upps();
	} catch (std::out_of_range & ex)
	{
		std::cout << ex.what() << std::endl;
	}
    std::cout << "Hello World!\n";
}


