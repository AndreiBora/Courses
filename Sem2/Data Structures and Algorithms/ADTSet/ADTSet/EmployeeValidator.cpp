#include "EmployeeValidator.h"

using namespace std;
EmployeeException::EmployeeException(std::vector<std::string> _errors):errors{_errors}
{
}

std::vector<std::string> EmployeeException::getErrors() const
{
	return this->errors;
}

void EmployeeValidator::validate(const Employee & e)
{
	vector<string> errors;
	if (e.getName() == "") {
		errors.push_back("The name cannot be empty\n");
	}
	if (!isupper(e.getName()[0])) {
		errors.push_back("Name must start with upper case\n");
	}
	if (e.getId() < 0) {
		errors.push_back("Id cannot be negative\n");
	}
	if (e.getSalary() < 0) {
		errors.push_back("Salary cannot be negative\n");
	}
	if (errors.size()) {
		throw EmployeeException(errors);
	}
}