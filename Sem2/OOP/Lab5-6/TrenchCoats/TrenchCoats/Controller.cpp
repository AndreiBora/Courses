#include "Controller.h"

bool Controller::addTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link)
{
	Tshirt t{ size ,color ,price ,quantity,link };
	if (this->getRepo().find(t) != -1)
		return false;
	this->repo.add(t);
	return true;
}

bool Controller::deleteTshirt(const std::string & link)
{
	Tshirt t{ "","",0,0,link };
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

bool Controller::updateTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link)
{
	Tshirt t{ size ,color ,price ,quantity,link };
	if (this->repo.find(t) == -1) {
		return false;
	}
	this->repo.update(t);
	return true;
}
