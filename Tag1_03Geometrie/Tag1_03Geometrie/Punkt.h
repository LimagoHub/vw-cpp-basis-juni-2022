#pragma once
#include <string>
#include <ostream>
using namespace std;

class Punkt
{
	

private:
	const double max{10.0};
	double x, y;

	void set_x(double x)
	{
		if (x < -max) x = -max;
		if (x > max) x = max;
		this->x = x;
	}

	void set_y(double y)
	{
		if (y < -max) y = -max;
		if (y > max) y = max;
		this->y = y;
	}
public:
	Punkt(double x = 0.0, double y = 0.0)
	{
		set_x(x);
		set_y(y);
	}
	

	double get_x() const
	{
		return x;
	}

	

	double get_y() const
	{
		return y;
	}

	string to_string() const
	{
		return "Punkt: x=" + std::to_string(x) + ", x=" + std::to_string(y);
	}

	//void rechts()
	//{
	//	rechts(1.0);
	//}
	
	void rechts(double offset=1.0)
	{
		set_x(get_x() + offset);
		
	}



	void links()
	{
		set_x(get_x() - 1.0);
	}
	
	void oben()
	{
		set_y(get_y() + 1.0);
	}
	void unten()
	{
		set_y(get_y() - 1.0);
	}

	Punkt & operator *= (double skalar)
	{
		set_x(get_x() * skalar);
		set_y(get_y() * skalar);
		return *this;
	}

	friend Punkt operator + (const Punkt& a, const Punkt& b)
	{
		return Punkt{ a.x + b.x, a.y + b.y };
	}

	friend ostream & operator << (ostream & out, const Punkt & p)
	{
		out << "x=" << p.get_x() << ", y=" << p.get_y();
		return out;
	}
	
};

