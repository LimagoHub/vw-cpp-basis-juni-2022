// Tag1_01Unterprogramme.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

int z = 10;

void unter(int &a)
{
	a = 100;
	
}

void ober()
{
	int x= 10;
	unter(x);
	std::cout << x << std::endl;
}

int myFunction()
{
	int y = 100;
	return y;
}

int & getZ()
{
	return z;
}


int main()
{
	// ober();
	getZ() = 20;
	std::cout << getZ() << std::endl;
}

