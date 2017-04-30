#pragma once
#include "ShoppingBasket.h"

class FileShoppingBasket : public ShoppingBasket
{
public:
	std::string filename;
public:
	FileShoppingBasket();
	virtual ~FileShoppingBasket() {}
	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayShoppingBasket() const = 0;
};