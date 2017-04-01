#include "UI.h"
#include <string>
#include <iostream>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add Tshirt." << endl;
	cout << "\t 2 - Delete Tshirt" << endl;
	cout << "\t 3 - Update Tshirt" << endl;
	cout << "\t 4 - Show all Tshirt" << endl;
	cout << "\t 0 - Break" << endl;
}

bool UI::deleteTshirtUI() {
	cout << "Enter the link to the photo";
	std::string link;
	cin >> link;
	cin.ignore();
	return this->ctrl.deleteTshirt(link);
}
bool UI::addTshirtUI()
{
	cout << "Enter the Tshirt size: ";
	std::string size;
	cin >> size;
	cin.ignore();
	cout << "Enter the color: ";
	std::string color;
	cin >> color;
	cin.ignore();
	cout << "Enter the price: ";
	double price;
	cin >> price;
	cout << "Enter the quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Photo link:";
	std::string link;
	getline(cin, link);

	return this->ctrl.addTshirt(size, color, price, quantity, link);
}

bool UI::updateTshirtUI()
{
	cout << "Enter the new Tshirt size: ";
	std::string size;
	cin >> size;
	cin.ignore();
	cout << "Enter the new color: ";
	std::string color;
	cin >> color;
	cin.ignore();
	cout << "Enter the new price: ";
	double price;
	cin >> price;
	cout << "Enter the new quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter the photo link:";
	std::string link;
	getline(cin, link);

	return this->ctrl.updateTshirt(size, color, price, quantity, link);
}

void UI::displayAllTshirtsUI()
{
	DynamicVector v = this->ctrl.getRepo().getTshirts();
	Tshirt* tshirts = v.getAllElems();
	if (tshirts == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no TShirt in the repository" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++) {
		Tshirt t = tshirts[i];
		cout << "Tshirt: " << t.getSize() << ";" << t.getColor() << "; Quantity: " << t.getQuantity() << "; Price:" << t.getPrice() << endl;
	}
}
void UI::run()
{
	while (true)
	{
		UI::printMenu();
		bool flag = false;
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					flag = this->addTshirtUI();
					if (flag) {
						cout << "Tshirt added" << endl;
					}
					else {
						cout << "Tshirt already in the repository" << endl;
					}
					break;
				case 2:
					flag = this->deleteTshirtUI();
					if (flag) {
						cout << "Tshirt deleted" << endl;
					}
					else {
						cout << "Tshirt not in the list or quantity is not 0" << endl;
					}
					break;
				case 3:
					flag = this->updateTshirtUI();
					if (flag) {
						cout << "Tshirt was updated" << endl;
					}
					else {
						cout << "Tshirt was not updated" << endl;
					}
					break;
				case 4:
					this->displayAllTshirtsUI();
					break;
				}
			}
		}

		// playlist management
		if (command == 2){}
	}
}
