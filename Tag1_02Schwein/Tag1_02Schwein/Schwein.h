#pragma once
#include <ostream>
#include <string>

class Schwein
{
private:
	std::string name;
	int gewicht;
	
	
	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}
	static int counter;

public:
	
	
	Schwein(std::string name= "Nobody");
	~Schwein();

	static int get_counter() 
	{
		return Schwein::counter;
	}
	
	void fressen();


	std::string get_name() const
	{
		return name;
	}

	void set_name(const std::string& name)
	{
		this->name = name;
	}

	int get_gewicht() const
	{
		return this->gewicht;
	}

	std::string to_string() const
	{
		return "Schwein: Name=" + name + ", Gewicht=" + std::to_string(gewicht);
	}

	Schwein & operator ++ () 
	{ 
		fressen();
		return *this;
	}


	friend std::ostream& operator<<(std::ostream& os, const Schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}
};

