#pragma once
#include <iostream>
#include "Calculator.h"
class CalculatorImpl: public Calculator
{
public:
	double add(double a, double b) override
	{
		
		return a + b;
	}

	double sub(double a, double b) override
	{
		return add(a, -b);
	}

};