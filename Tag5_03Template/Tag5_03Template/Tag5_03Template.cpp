// Tag5_03Template.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

//static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit

template<typename T>
void ausgabe(T t)
{
	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	std::cout << t << std::endl;
}

template<typename T, typename... Tail >
void ausgabe(T head, Tail ... tail)
{
	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	std::cout << head << std::endl;
	ausgabe(tail...);
}

template<typename T>
T summe(T head)
{
	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	return head;

}


template<typename T, typename... Tail>
auto summe(T head, Tail... tail)->double
{

	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit

	return head + sum(tail...);

}


int main()
{
	ausgabe(10);
	ausgabe(10, "gfg", 10.0);

	double sum = summe(1, 30, 6.9);
    std::cout << "Hello World!\n";
}

