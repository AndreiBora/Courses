#include "Controller.h"



void Controller::addEmployeeCtrl(int _id, std::string _name, double _salary)
{
	Employee e{ _id,_name,_salary };
	this->validator.validate(e);
	this->repo.addEmployee(e);
}


int Controller::getNrEmployeesCtrl()
{
	return this->repo.getSize();
}


Employee Controller::findByIdCtrl(int id)
{
	BSTSet employees = this->repo.getEmployees();
	std::unique_ptr<Iterator>it = employees.createIterator();
	while (!it->valid()) {
		Employee e = it->getCurrent();
		if (e.getId() == id) {
			return e;
		}
		it->next();
	}
	return Employee{};
}

bool Controller::removeByIdCtrl(int id)
{
	BSTSet employees = this->repo.getEmployees();
	Employee e{ id,"",0 };
	if (!employees.find(e)) {
		return false;
	}
	this->repo.removeEmployee(e);
	return true;
}

BSTSet Controller::getEmplyeesCtrl()
{
	return this->repo.getEmployees();
}

void Controller::writeToFileCtrl()
{
	this->repo.writeToFile();
}