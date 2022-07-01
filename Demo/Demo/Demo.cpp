// Demo.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

class A
{
public:

	A(int x){}
	
	A()
	{
		std::cout << "CTOR von A" << std::endl;
		bar();
	}
	virtual ~A()
	{
		std::cout << "DTOR von A" << std::endl;
	}

	void bar()
	{
		this->foo();
	}

	virtual void foo()
	{
		std::cout << "foo von A" << std::endl;
	}
};

class B: public A
{
public:

	B() 
	{
		std::cout << "CTOR von B" << std::endl;
	}

	virtual ~B()
	{
		std::cout << "DTOR von B" << std::endl;
	}

	void foo() override
	{
		std::cout << "foo von B" << std::endl;
	}
};

int main()
{
	A *a = new B;
	a->bar();
	delete a;
}


