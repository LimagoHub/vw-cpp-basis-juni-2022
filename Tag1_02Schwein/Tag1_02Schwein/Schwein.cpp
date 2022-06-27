#include <iostream>
#include "Schwein.h"

Schwein::Schwein():name("Nobody"), gewicht(10)
{
	
}

Schwein::~Schwein()
{
	std::cout << "Quieeekkkk!" << std::endl;
}

void Schwein::fressen()
{
	set_gewicht(get_gewicht() + 1);
}


