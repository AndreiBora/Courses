#include "Controller.h"
#include "TshirtList.h"
#include "ShoppingBasket.h"
#include <algorithm>
#include <iterator>

void Controller::addTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link,int length)
{
	Tshirt t{ size ,color ,price ,quantity,link,length};
	this->validator.validate(t);
	this->repo.add(t);
}

void Controller::deleteTshirt(const std::string & link)
{
	Tshirt t{ "","",0,0,link,0};
	this->repo.remove(t);
}

void Controller::updateTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link,int length)
{
	Tshirt t{ size ,color ,price ,quantity,link,length };
	this->validator.validate(t);
	this->repo.update(t);
}


bool Controller::createTshirtList(std::string size) {
	this->tshirtList.clear();
	std::vector<Tshirt> all = this->getRepo().getTshirts();
	for (int i = 0; i < all.size(); i++) {
		if (size == "" || all[i].getSize() == size) {
			this->tshirtList.add(all[i]);
		}
	}
	if (this->tshirtList.getSize() == 0) {
		return false;
	}
	return true;
}

bool Controller::startTshirtList()
{
	return this->tshirtList.start();
}

Tshirt & Controller::displayCurrent()
{
	this->tshirtList.display();
	return this->tshirtList.getCurrent();
}

Tshirt & Controller::displayNext()
{
	this->tshirtList.displayNext();
	return this->tshirtList.getCurrent();
}


Tshirt & Controller::getCurrentTshirt()
{
	return this->tshirtList.getCurrent();
}

void Controller::buyTshirt(const Tshirt & tshirt)
{
	this->shoppingBasket->add1(tshirt);
	double price = tshirt.getPrice();
	this->shoppingBasket->totalSum += price;
}

std::vector<Tshirt> Controller::filterByLength(int length)
{
	std::vector<Tshirt> all1 = this->getRepo().getTshirts();
	std::vector<Tshirt> filter;
	auto isLess = [length](Tshirt t) {return t < length; };

	copy_if(all1.begin(), all1.end(), back_inserter(filter), isLess);
	/*for (int i = 0; i < all1.size(); i++)
	{
		if (all1[i] < length) {
			filter.push_back(all1[i]);
		}
	}*/
	return filter;
}

void Controller::saveShoppingBasketToFile(const std::string & filename)
{
	if (this->shoppingBasket == nullptr)
		return;
	this->shoppingBasket->setFilename(filename);
	this->shoppingBasket->writeToFile();
}

void Controller::openShoppingBasket() const
{
	if (this->shoppingBasket == nullptr)
		return;
	this->shoppingBasket->displayShoppingBasket();
}