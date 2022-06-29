#pragma once
#include "Punkt.h"
class Kreis :
    public Punkt // Alle Eigenchaften und Methoden werden vererbt außer den Konstruktoren
{
private:
	double radius;

	// void rechts() {} // Verstoss gegen das liskovche Substitutionsprinzip
public:


	Kreis(double x = 0, double y = 0):Punkt(x,y), radius(0.0)
	{
		
		
	
	}

	

	double get_radius() const
	{
		return radius;
	}

	void set_radius(const double radius)
	{
		this->radius = radius;
	}

	string to_string() const override  
	{
		
		return Punkt::to_string() + ", Radius=" + std::to_string(radius);
	}
};

