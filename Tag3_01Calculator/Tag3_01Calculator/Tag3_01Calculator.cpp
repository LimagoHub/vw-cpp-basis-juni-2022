// Tag3_01Calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "CalculatorClient.h"
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorSecure.h"

int main()
{
	CalculatorImpl impl;
	CalculatorLogger logger{ impl };
	CalculatorSecure secure{ logger };
	CalculatorClient client{ secure };

	client.run();
	
	
	
}


