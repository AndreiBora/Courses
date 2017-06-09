#include "Employee.h"
#include <sstream>
using namespace std;

Employee::Employee(int _id, std::string _name, double _salary): id{_id},name{_name},salary{ _salary }
{
}

Employee::Employee()
{
	this->id = 0;
	this->name = "";
	this->salary = 0;
}


Employee::~Employee()
{
}


bool Employee::operator<(Employee & e) const
{
	return this->id < e.getId();
}

bool Employee::operator>(Employee & e) const
{
	return this->id > e.getId();
}

std::string Employee::toString()
{
	std::stringstream ss;
	ss << "Employee: " << this->id << " name:" << this->name << " salary:" << this->salary << "\n";
	return ss.str();
}


void Employee::operator=(Employee e)
{
	this->id = e.getId();
	this->name = e.getName();
	this->salary = e.getSalary();
}

std::ostream & operator<<(std::ostream & os, Employee & e)
{
	os << e.getId() << "," << e.getName() << "," << e.getSalary() << "\n";
	return os;
}