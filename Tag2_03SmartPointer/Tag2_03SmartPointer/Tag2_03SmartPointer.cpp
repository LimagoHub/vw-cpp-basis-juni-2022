// Tag2_03SmartPointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;
class MyClass
{
public:
	MyClass()
	{
		cout << "Ctor" << endl;
	}

	~MyClass()
	{
		cout << "dtor" << endl;
	}

	void foo()
	{
		cout << "foo" << endl;
	}
};

//auto source() -> std::unique_ptr<MyClass>
//{
//	return std::unique_ptr<MyClass>{new MyClass};
//}
//
//auto myfunc(std::unique_ptr<MyClass> other)
//{
//	// do something with other
//	return other;
//}
//
//auto sink(std::unique_ptr<MyClass> other)
//{
//	cout << "sink" << endl;
//}
//
//auto main() -> int
//{
//	unique_ptr<MyClass> myptr = source();
//
//	myptr->foo();
//	
//	sink(myfunc(std::move(myptr)));
//	
// 	cout << "fetisch" << endl;
//}
//

auto main()->int
{
	shared_ptr<MyClass> myPtr{ new MyClass };

	weak_ptr<MyClass> weak = myPtr;
	
	weak.lock()->foo();

	
	cout << myPtr.use_count() << endl;
	{
		shared_ptr<MyClass> other = myPtr;

		cout << other.use_count() << endl;
	}
	cout << myPtr.use_count() << endl;
	
	shared_ptr<MyClass> m2 = myPtr;

	cout << myPtr.use_count() << endl;
	
	return 0;
}