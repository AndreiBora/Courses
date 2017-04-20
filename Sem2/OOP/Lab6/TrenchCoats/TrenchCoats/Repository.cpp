#include "Repository.h"
#include <string>
using namespace std;

void Repository::add(const Tshirt& t) {
	this->Tshirts.add(t);
}

void Repository::remove(int pos) {
	this->Tshirts.remove(pos);
}

void Repository::update(const Tshirt & t)
{
	for (int i = 0; i < this->getTshirts().getSize(); i++) {
		if (this->getElementAtPos(i) == t)
			this->Tshirts.getAllElems()[i] = t;
	}
}
int Repository::find(const Tshirt & s)
{
	DynamicVector<Tshirt> v = this->getTshirts();
	Tshirt* tshirts = v.getAllElems();
		if (tshirts == NULL)
			return -1;
		if (v.getSize() == 0)
			return 0;
		for (int i = 0; i < v.getSize(); i++) {
			if (s == tshirts[i])
				return i;
		}
	
	return -1;
}

Tshirt  Repository::getElementAtPos(int pos)
{	
	DynamicVector<Tshirt> v = this->getTshirts();
	Tshirt* tshirts = v.getAllElems();
	return tshirts[pos];
}