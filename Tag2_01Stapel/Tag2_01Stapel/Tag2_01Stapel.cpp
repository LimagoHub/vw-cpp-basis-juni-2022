// Tag2_01Stapel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Stapel.h"
#include "Schwein.h"

using namespace vw::collections;


void main_impl()
{
	size_t size = 10;

	Stapel myStapel{ size };

	for (int i = 0; i < 10; ++i)
	{
		if (!myStapel.is_full())
			myStapel.push(i);
	}

	while (!myStapel.is_empty())
		std::cout << myStapel.pop() << std::endl;

	std::cout << myStapel.pop() << std::endl;
}

int main()
{

    try {
        main_impl();

    }
    catch (std::out_of_range& ex)
    {
    	// throw or log
        std::cout << "Out of Range " <<  ex.what() << std::endl;
    }
	catch(std::exception &ex)
    {
        std::cout << "Hä?" << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Upps" << std::endl;
    }
}


