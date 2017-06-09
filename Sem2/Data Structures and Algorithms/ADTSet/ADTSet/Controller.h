#pragma once
#include"Repository.h"
#include "EmployeeValidator.h"

class Controller
{
private:
	Repository repo;
	EmployeeValidator validator;
public:
	Controller(const Repository& r, EmployeeValidator v): repo{r},validator{v}{}
	void addEmployeeCtrl(int _id, std::string _name,double _salary);
	int getNrEmployeesCtrl();
	Employee findByIdCtrl(int id);
	bool removeByIdCtrl(int id);
	Repository getRepo() { return repo; }
	BSTSet getEmplyeesCtrl();
	void writeToFileCtrl();
};

