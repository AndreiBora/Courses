#pragma once
#include "Controller.h"
#include  "EmployeeValidator.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl{ c } {};
	void run();
	~UI();
private:
	void addEmployeeUI();
	void getNrEmployeesUI();
	void findByIdUI();
	void removeByIdUI();
	void displayAllUI();

	static void printMenu();
};

