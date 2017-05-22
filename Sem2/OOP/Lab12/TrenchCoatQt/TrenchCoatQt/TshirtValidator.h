#pragma once
#include <string>
#include "Tshirt.h"
#include <vector>

class TshirtException
{
private:
	std::vector<std::string> errors;
public:
	TshirtException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class TshirtValidator {
public:
	TshirtValidator() {}
	static void validate(const Tshirt& t);
};