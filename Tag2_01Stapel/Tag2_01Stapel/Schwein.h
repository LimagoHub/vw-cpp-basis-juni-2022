#pragma once
#include <ostream>
#include <string>

class Schwein
{
private:
	std::string name;
	int gewicht;
	static int counter;
	
	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}
	

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


	friend bool operator==(const Schwein& lhs, const Schwein& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.gewicht == rhs.gewicht;
	}

	friend bool operator!=(const Schwein& lhs, const Schwein& rhs)
	{
		return !(lhs == rhs);
	}
};

