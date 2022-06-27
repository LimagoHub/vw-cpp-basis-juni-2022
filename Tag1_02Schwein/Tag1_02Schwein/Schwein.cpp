#include <iostream>
#include "Schwein.h"

int Schwein::counter = 0;

Schwein::Schwein(std::string name):name(name), gewicht(10)
{
	Schwein::counter++;
}

Schwein::~Schwein()
{
	Schwein::counter--;
	std::cout << "Quieeekkkk!" << std::endl;
}

void Schwein::fressen()
{
	set_gewicht(get_gewicht() + 1);
}


