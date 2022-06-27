// tag1_04StaticInC.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include "Header.h"

void bar()
{
	static int tiefe=0;
	

	printf("%d\n", tiefe);
	
	tiefe++;
	if (tiefe >= 10)
		return;
	bar();
}

int main()
{
    //foo();
	bar();
	bar();
}


