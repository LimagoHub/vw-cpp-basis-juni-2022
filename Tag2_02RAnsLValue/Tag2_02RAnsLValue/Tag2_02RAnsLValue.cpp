// Tag2_02RAnsLValue.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>

void foo(int &x) // nur LVALUE
{
	std::cout << "Hier ist foo mit LVALUE" << std::endl;
	x = 100;
	foo(x);
}

void foo(int&& x) // nur RVALUE
{
	std::cout << "Hier ist foo mit RVALUE" << std::endl;
	x = 100000;
	foo(x);
}

int main()
{

	int a = 1000;

	//foo(a);
	foo(std::move(a));
	foo(10);
	
	std::cout << a << std::endl;

	/*std::string mystring = "Dies ist mystring";
	
	std::string neuerString = std::move(mystring);
	std::cout << mystring << std::endl;
	std::cout << neuerString << std::endl;*/
	
}

