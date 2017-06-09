#pragma once
#include <vector>
#include "Employee.h"

class EmployeeException
{
private:
	std::vector<std::string> errors;
public:
	EmployeeException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class EmployeeValidator
{
public:
	EmployeeValidator() {};
	static void validate(const Employee& e);
};

