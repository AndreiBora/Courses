#include "UI.h"
#include <string>
#include <iostream>

using namespace std;


void UI::printMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add an employee." << endl;
	cout << "\t 2 - Get number of employees" << endl;
	cout << "\t 3 - Find employee by Id" << endl;
	cout << "\t 4 - Remove by Id" << endl;
	cout << "\t 5 - Display all." << endl;
	cout << "\t 0 - Exit." << endl;
	
}

void UI::addEmployeeUI()
{
	int id;
	string name;
	double salary;
	cout << "Enter the id of the employee" << endl;
	cin >> id;
	cin.ignore();
	cout << "Enter the name of the employee" << endl;
	getline(cin, name);
	cout << "Enter the salary of the employee" << endl;
	cin >> salary;
	cin.ignore();
	try {
		this->ctrl.addEmployeeCtrl(id, name, salary);
	}
	catch (EmployeeException& e) {
		for (auto emp : e.getErrors())
			cout << emp;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void UI::getNrEmployeesUI()
{
	int nr;
	nr = this->ctrl.getNrEmployeesCtrl();
	cout << "Total number of employees in the company is :" << nr << endl;
}

void UI::findByIdUI()
{
	int id;
	cout << "Enter the ID: ";
	cin >> id;
	Employee e =  this->ctrl.findByIdCtrl(id);
	if (e.getName() == "") {
		cout << "The employee was not fount" << endl;
	}
	else {
		cout << e.toString() << endl;
	}
}

void UI::removeByIdUI()
{
	int id;
	cout << "Enter the id: ";
	cin >> id;
	bool flag = this->ctrl.removeByIdCtrl(id);
	if (flag) {
		cout << "The Employee was removed" << endl;
	}
	else {
		cout << "The employee was not found" << endl;
	}
}

void UI::displayAllUI()
{
	BSTSet employees = this->ctrl.getEmplyeesCtrl();
	auto it = employees.createIterator();
	while (!it->valid()) {
		Employee e = it->getCurrent();
		cout << e.toString();
		it->next();
	}
}


void UI::run()
{
	while (true) {
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0) {
			this->ctrl.writeToFileCtrl();
			break;
		}
		switch (command)
		{
		case 1:
		{
			this->addEmployeeUI();
			break;
		}
		case 2:
		{
			this->getNrEmployeesUI();
			break;
		}
		case 3:
		{
			this->findByIdUI();
			break;
		}
		case 4:
		{
			this->removeByIdUI();
			break;
		}
		case 5:
		{
			this->displayAllUI();
			break;
		}

		} 
	}
}


UI::~UI()
{
}
