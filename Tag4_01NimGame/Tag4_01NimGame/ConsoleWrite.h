#pragma once
#include <iostream>
#include "Writer.h"
class ConsoleWrite: public Writer
{
public:
	auto write(std::string message) const -> void override
	{
		std::cout << message << std::endl;
	}
};

