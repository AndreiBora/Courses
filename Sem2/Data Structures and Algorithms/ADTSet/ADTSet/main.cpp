#include "Employee.h"
#include "BSTSet.h"
#include "Iterator.h"
#include <iostream>
#include "UI.h"
#include "EmployeeValidator.h"
#include "Tests.h"
using namespace std;

int main() {
	Tests::testAll();
	Repository repo("employees.txt");
	Controller ctrl{ repo,EmployeeValidator{}};
	UI ui{ ctrl };
	ui.run();

	system("pause");
	return 0;
}