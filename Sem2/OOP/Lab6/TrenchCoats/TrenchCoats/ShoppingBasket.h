#pragma once
#include "Repository.h"

class ShoppingBasket : public Repository {
public:
	double totalSum;
public:
	//default contructor;
	ShoppingBasket(double _totalSum = 0) : Repository{}, totalSum{ _totalSum }
	{

	}
	double getTotalSum() const { return this->totalSum; };

};

