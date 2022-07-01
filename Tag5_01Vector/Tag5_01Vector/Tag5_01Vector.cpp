// Tag5_01Vector.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

class Akkumulator
{
	int result{ 0 };
public:
	void operator() (int value)
	{
		result += value;
	}


	int get_result() const
	{
		return result;
	}
};

class intgen // Supplier
{
private:
	int n;
public:
	intgen() :n(5) {}

	int operator()()
	{
		return n++;
	}
};

template<class T>
bool greater_then(T a, T b)
{
	static_assert (std::is_arithmetic<T>::value, "Parameter sollte eine Zahl sein"); // Prüfung zur Compilezeit
	return a > b;
}

class MyClass
{
public:
	int x{10};
	int y{10};

	void demo_lamda()
	{
		
		auto lambda = [this]() {return this->x + y; };
		
	}
};


void demo_lamda()
{
	int x;
	int y;

	x = y = 10;
	auto lambda = [=,&y]() {return x + y; };
	x++;
	y++;
	std::cout << lambda() << std::endl;
}

int main()
{
	std::vector<int> v = { 10,20,30,40 , 3};
	std::vector<int> erg;

	//auto my_predicate = std::bind(greater_then, std::placeholders::_1, 20);
	
	//std::for_each(v.begin(), v.end(), [](int value) {std::cout << value << std::endl; });
	Akkumulator a;
	a = std::for_each(v.begin(), v.end(), a);
	
	std::cout << a.get_result() << std::endl;

	std::copy_if(v.begin(), v.end(), std::back_inserter(erg), std::bind(greater_then<int>, std::placeholders::_1, 20));

	for( int v: erg)
	{
		std::cout << v << std::endl;
	}

	std::remove_if(v.begin(), v.end(), [](int value) {return value % 3 == 0; });

	std::generate(v.begin(), v.end(), intgen{});
}


