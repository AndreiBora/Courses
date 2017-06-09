#pragma once
#include <vector>
#include "Employee.h"
#include "BSTSet.h"
#include <memory>
class Repository
{
private:
	BSTSet employees;
	std::string filename;
public:
	Repository(const std::string& filename);
	void addEmployee( Employee& e);
	int getSize();
	BSTSet getEmployees() { return employees; }
	void removeEmployee(Employee& e);
	void writeToFile();
private:
	void readFromFile();
	
};

