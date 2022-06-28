// tag2_06Auto.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <memory>

class MyClass
{
	
};

auto x = 8;

auto foo(int a , int b)->long
{
	
	return a *b ;
}


auto main() -> int
{
	auto mptr = std::make_shared<MyClass>(new MyClass);
	
	auto a = 10;
	auto b = a + 1;
	auto c = b * b;

	auto* ptr = &a;

	
    std::cout << "Hello World!\n";
}

