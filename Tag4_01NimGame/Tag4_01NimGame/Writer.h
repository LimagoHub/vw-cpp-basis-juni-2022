#pragma once
#include <string>
class Writer
{

public:
	virtual auto write(std::string message) const -> void = 0;
};

