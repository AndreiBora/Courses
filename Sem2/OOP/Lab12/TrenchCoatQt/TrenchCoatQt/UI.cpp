#include "UI.h"
#include "TshirtValidator.h"
#include "RepositoryException.h"
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
	cout << "\t 3 - Save shopping basket to a file " << endl;
	cout << "\t 4 - Open saved shopping basket " << endl;
	cout << "\t 0 - Exit" << endl;
}

void UI::printPlayListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Buy a tshirt " << endl;
	cout << "\t 2 - Next " << endl;
	cout << "\t 0 - Exit" << endl;
}

void UI::deleteTshirtUI() {
	cout << "Enter the link to the photo";
	std::string link;
	cin >> link;
	cin.ignore();
	try{
		
		this->ctrl.deleteTshirt(link);
	}
	catch (TshirtException& e)
	{
		for (auto t : e.getErrors())
			cout << t;
	}
	catch (RepositoryException& e) {
		cout << e.what() << endl;
	}
	catch (FileException& e) {
		cout << e.what() << endl;
	}
}
void UI::addTshirtUI()
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

	try {
		this->ctrl.addTshirt(size, color, price, quantity, link, length);
	}
	catch(TshirtException& e)
	{
		for (auto t : e.getErrors())
			cout << t;
	}
	catch (RepositoryException& e) {
		cout << e.what() << endl;
	}
	catch (FileException& e) {
		cout << e.what() << endl;
	}
}

void UI::updateTshirtUI()
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

	try {
		this->ctrl.updateTshirt(size, color, price, quantity, link, length);
	}
	catch (TshirtException& e)
	{
		for (auto t : e.getErrors())
			cout << t;
	}
	catch (RepositoryException& e) {
		cout << e.what() << endl;
	}
	catch (FileException& e) {
		cout << e.what() << endl;
	}
}

void UI::displayAllTshirtsUI()
{
	std::vector<Tshirt> v = this->ctrl.getRepo().getTshirts();
	if (v.size() == 0) {
		cout << "There are no TShirt in the repository" << endl;
		return;
	}
	/*for (int i = 0; i < v.size(); i++) {
		Tshirt t = v[i];
		cout << "Tshirt: " << t.getSize() << ";" << t.getColor() << "; Quantity: " << t.getQuantity() << "; Price:" << t.getPrice() << endl;
	}*/

	for (auto t : v) {
		cout << "Tshirt: " << t.getSize() << ";" << t.getColor() << "; Quantity: " << t.getQuantity() << "; Price:" << t.getPrice() << endl;
	}
}

void UI::displayTshirtsByLengthUI()
{
	int length;
	cout << "Enter the length";
	cin >> length;
	std::vector<Tshirt> v = this->ctrl.filterByLength(length);
	/*for (int i = 0; i < v.size(); i++) {
		Tshirt t = v[i];
		cout << t.toString() << endl;
	}*/

	for (auto t : v) {
		cout << t.toString() << endl;
	}
}

void UI::seeShoppingBasketUI()
{
	double total = this->ctrl.getShoppingBascket()->getTotalSum();
	
	std::vector<Tshirt> v = this->ctrl.getShoppingBascket()->getTshirts();
	cout << "Total price to be paid: " << total << endl;
	/*for (int i = 0; i < v.size(); i++)
	{
		Tshirt t = v[i];
		cout << t.toString() << endl;
	}
*/
	for (auto t : v) {
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
			double sum = this->ctrl.getShoppingBascket()->getTotalSum();
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

void UI::saveShoppingBaskettoFileUI()
{
	std::string filename;
	cout << "Input the file name (absolute path): ";
	getline(cin, filename);

	try {
		this->ctrl.saveShoppingBasketToFile(filename);
		
		if (this->ctrl.getShoppingBascket() == nullptr)
		{
			cout << "Playlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
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
					this->addTshirtUI();
					break;
				case 2:
					this->deleteTshirtUI();
					break;
				case 3:
					this->updateTshirtUI();
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
					break;
				}
				case 3:
				{
					this->saveShoppingBaskettoFileUI();
					break;
				}
				case 4:
				{
					this->ctrl.openShoppingBasket();
					break;
				}
					
				default:
					break;
				}
			}

		}
	}
}
