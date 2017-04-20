#include "Controller.h"
#include "TshirtList.h"

bool Controller::addTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link,int length)
{
	Tshirt t{ size ,color ,price ,quantity,link,length};
	if (this->getRepo().find(t) != -1)
		return false;
	this->repo.add(t);
	return true;
}

bool Controller::deleteTshirt(const std::string & link)
{
	Tshirt t{ "","",0,0,link,0};
	Tshirt found;
	int pos = this->getRepo().find(t);
	if (pos != -1 ) {
		found = this->getRepo().getElementAtPos(pos);
		//we can delete the Tshirt only if there is no quantity in stock
		if (found.getQuantity() == 0) {
			this->repo.remove(pos);
			return true;
		}
	}
	return false;
}

bool Controller::updateTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link,int length)
{
	Tshirt t{ size ,color ,price ,quantity,link,length };
	if (this->repo.find(t) == -1) {
		return false;
	}
	this->repo.update(t);
	return true;
}


bool Controller::createTshirtList(std::string size) {
	this->tshirtList.clear();
	DynamicVector<Tshirt> all = this->getRepo().getTshirts();
	for (int i = 0; i < all.getSize(); i++) {
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
	this->shoppingBasket.add(tshirt);
	double price = tshirt.getPrice();
	this->shoppingBasket.totalSum = price;
}

DynamicVector<Tshirt> Controller::filterByLength(int length)
{
	DynamicVector<Tshirt> all1 = this->getRepo().getTshirts();
	DynamicVector<Tshirt> filter;
	for (int i = 0; i < all1.getSize(); i++)
	{
		if (all1[i] < length) {
			filter.add(all1[i]);
		}
	}
	return filter;
}

