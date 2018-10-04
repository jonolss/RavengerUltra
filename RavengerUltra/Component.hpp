#pragma once
#include <string>

class Component
{
private:
	const std::string name;
public:
	Component(std::string name);
	~Component();
	std::string getName();
};

