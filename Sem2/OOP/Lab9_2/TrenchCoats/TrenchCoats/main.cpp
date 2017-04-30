#include "Tshirt.h"
#include "RepositoryException.h"
#include "UI.h"
#include <Windows.h>
#include "Tester.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include <iostream>
using namespace std;

int main() {

	system("color f4");
	//Tester t;
	int input{ 0 };
	while (true) {
		cout << "Chose the type of the file: " << endl;
		cout << "\t 1 - CSV " << endl;
		cout << "\t 2 - HTML" << endl;
		cin >> input;
		if (input == 1 || input == 2)
			break;
		else {
			cout << "Please choose a value between 1 and 2" << endl;
		}
	}
	try {
		Repository repo{"tshirts.txt"};
		if (input == 1) {
			CSVShoppingBasket* sb = new CSVShoppingBasket{};
			Controller ctrl{ repo, sb, TshirtValidator{} };
			UI ui{ ctrl };
			ui.run();
		}
		else{
			HTMLShoppingBasket* sb = new HTMLShoppingBasket{};
			Controller ctrl{ repo, sb, TshirtValidator{} };
			UI ui{ ctrl };
			ui.run();
		}
	}
	catch (FileException& e)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}
	return 0;
}