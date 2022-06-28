// Tag2_01Stapel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Stapel.h"

using namespace vw::collections;

int main()
{
    Stapel myStapel;

    for (int i = 0; i < 10; ++i)
    {
        if (!myStapel.is_full())
            myStapel.push(i);
    }

    while (!myStapel.is_empty())
        std::cout << myStapel.pop() << std::endl;
}


