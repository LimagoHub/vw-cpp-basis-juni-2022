// Tag5_02UnorderedSet.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

class Schwein
{
private:
	std::string name;
	int gewicht;
public:
	Schwein(std::string name = "Nobody") :name(name), gewicht(10) {}

	void fressen()
	{
		gewicht++;
	}
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
		return gewicht;
	}

	void set_gewicht(int gewicht)
	{
		this->gewicht = gewicht;
	}


	friend bool operator==(const Schwein& lhs, const Schwein& rhs)  noexcept
	{
		return lhs.name == rhs.name && lhs.gewicht == rhs.gewicht;
	}

	friend bool operator!=(const Schwein& lhs, const Schwein& rhs)
	{
		return !(lhs == rhs);
	}


	friend std::ostream& operator<<(std::ostream& os, const Schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}
};

struct PigEqual
{
	auto operator()(const Schwein& lhp, const Schwein& rhp) const noexcept -> bool
	{
		return lhp == rhp;
	}
};

struct PigHash
{
	auto operator()(const Schwein& pig) const -> size_t
	{
		std::hash<std::string> str_hash;
		std::hash<int> int_hash;
		return str_hash(pig.get_name()) * int_hash(pig.get_gewicht());
	}
};

int main()
{

	std::unordered_set<Schwein, PigHash, PigEqual> my_set{ Schwein{ "Piggy" }, Schwein{ "Babe" }, Schwein{ "Piggy" } };

	Schwein s{ "Demo" };
	Schwein p{ "piggy" };
	std::vector<std::reference_wrapper<Schwein>> v;
	v.push_back(std::ref(s));
	v.push_back(std::ref(p));
	
	for(auto schwein_ref : v)
	{
		schwein_ref.get().fressen();
	}

	for (auto schwein_ref : v)
	{
		std::cout << schwein_ref.get() << std::endl;
	}

	std::cout << s << std::endl;
	
    std::cout << "Hello World!\n";
}

