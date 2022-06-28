#include <iostream>

int main()
{
	try {
		throw "Ein fehler ist aufgetreten";
	} catch(const char * fehlercode)
	{
		std::cout << fehlercode;
	} catch(...)
	{
		
	}
    std::cout << "Vielen Dank Sie haben ein kleines Programm echt gluecklich gemacht\n";
}

