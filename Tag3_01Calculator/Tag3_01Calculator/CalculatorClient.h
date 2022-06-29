#pragma once

#include "Calculator.h"
#include <iostream>
class CalculatorClient
{

private:
	Calculator& calculator_;


public:
	CalculatorClient(Calculator& calculator)
		: calculator_(calculator)
	{
	}

	void run()
	{
		std::cout << calculator_.add(3, 4) << std::endl;
	}
};

