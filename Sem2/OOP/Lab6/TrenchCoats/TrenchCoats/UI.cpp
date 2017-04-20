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
	cout << "\t 5 - Show Tshirt under a given length" << endl;
	cout << "\t 0 - Exit" << endl;
}

void UI::printUserMenu() {
	cout << "Possible commands: " << endl;
	cout << "\t 1 - View Tshirts by size " << endl;
	cout << "\t 2 - View Shopping basket and total sum " << endl;
	cout << "\t 0 - Exit" << endl;
}

void UI::printPlayListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Buy a tshirt " << endl;
	cout << "\t 2 - Next " << endl;
	cout << "\t 0 - Exit" << endl;
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
	cout << "Enter the length: ";
	int length;
	cin >> length;
	cin.ignore();
	cout << "Photo link:";
	std::string link;
	getline(cin, link);

	return this->ctrl.addTshirt(size, color, price, quantity, link,length);
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
	cout << "Enter the new length: ";
	int length;
	cin >> length;
	cin.ignore();
	cout << "Enter the photo link:";
	std::string link;
	getline(cin, link);

	return this->ctrl.updateTshirt(size, color, price, quantity, link,length);
}

void UI::displayAllTshirtsUI()
{
	DynamicVector<Tshirt> v = this->ctrl.getRepo().getTshirts();
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

void UI::displayTshirtsByLengthUI()
{
	int length;
	cout << "Enter the length";
	cin >> length;
	DynamicVector<Tshirt> v = this->ctrl.filterByLength(length);
	Tshirt* tshirts = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++) {
		Tshirt t = tshirts[i];
		cout << t.toString() << endl;
	}
}

void UI::seeShoppingBasketUI()
{
	double total = this->ctrl.getShoppingBascket().getTotalSum();
	DynamicVector<Tshirt> v = this->ctrl.getShoppingBascket().getTshirts();
	Tshirt* tshirts = v.getAllElems();
	cout << "Total price to be paid: " << total << endl;
	for (int i = 0; i < v.getSize(); i++)
	{
		Tshirt t = tshirts[i];
		cout << t.toString() << endl;
	}

}

void UI::seeTshirtBySizeUI() {
	string size;
	cout << "Enter size :";
	getline(cin, size);
	if (!this->ctrl.createTshirtList(size)) {
		cout << "There are no tshirts with such size\n";
		return;
	}
	this->ctrl.startTshirtList();
	Tshirt& tshirt = this->ctrl.displayCurrent();
	cout << tshirt.toString() << endl;
	while (true) {
		cout << "Currently: \n";
		printPlayListMenu();
		int cmdPlayList{ 0 };
		cout << "Enter the command";
		cin >> cmdPlayList;
		cin.ignore();

		if (cmdPlayList == 0) {
			return;
		}
		switch (cmdPlayList)
		{
		case 1: {
			Tshirt& tshirt = this->ctrl.getCurrentTshirt();
			int newQuantity = tshirt.getQuantity() - 1;
			if (newQuantity < 0){
				cout << "Sold out";
				break;
			}
			tshirt.setQuantity(newQuantity);
			this->ctrl.buyTshirt(tshirt);
			double sum = this->ctrl.getShoppingBascket().getTotalSum();
			cout << "Total amount to be paid: " << sum << endl;
			break;
		}
		case 2:
			Tshirt& tshirt = this->ctrl.displayNext();
			cout << tshirt.toString() << endl;
			break;
		}
		
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
				case 5:
				{
					this->displayTshirtsByLengthUI();
					break;
				}
				}
		

			}
		}

		// user management
		if (command == 2){
			while (true)
			{
				UI::printUserMenu();
				int cmdUsr{ 0 };
				cout << "Input the command: ";
				cin >> cmdUsr;
				cin.ignore();
				if (cmdUsr == 0)
					break;
				switch (cmdUsr)
				{
				case 1:
				{
					this->seeTshirtBySizeUI();
					break;
				}
				case 2:
				{
					this->seeShoppingBasketUI();
				}
					
				default:
					break;
				}
			}

		}
	}
}
