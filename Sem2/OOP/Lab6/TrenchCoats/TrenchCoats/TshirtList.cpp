#include "TshirtList.h"


void TshirtList::add(const Tshirt & tshirt)
{
	this->tshirts.add(tshirt);
}

int TshirtList::getSize()
{
	return this->tshirts.getSize();
}

bool TshirtList::start()
{
	if (this->tshirts.getSize() == 0) {
		return false;
	}
	this->current = 0;
	return true;
}

void TshirtList::display()
{
	if (this->tshirts.getSize() == 0)
		return;
	Tshirt& current = this->getCurrent();
	current.display();
}

void TshirtList::displayNext()
{
	if (this->tshirts.getSize() == 0)
		return;
	this->current++;
	Tshirt& currentTshirt = this->getCurrent();
	currentTshirt.display();
}

Tshirt & TshirtList::getCurrent()
{
	if (this->current == this->tshirts.getSize())
		this->current = 0;
	return this->tshirts[this->current];
}

TshirtList::TshirtList()
{
	this->current = 0;
}

void TshirtList::clear()
{
	this->tshirts.removeAll();
}