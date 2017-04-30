#pragma once
#include "Repository.h"

class ShoppingBasket {
public:
	std::vector<Tshirt> Tshirts;
	double totalSum;
public:
	//default contructor;
	ShoppingBasket(double _totalSum = 0) : totalSum{ _totalSum }
	{
	}
	double getTotalSum() const { return this->totalSum; };
	
	/*
	Add a Tshirt to the repository
	input: s- Tshirt
	*/
	void add1(const Tshirt& t);

	std::vector<Tshirt> getTshirts() const { return Tshirts; }

};

