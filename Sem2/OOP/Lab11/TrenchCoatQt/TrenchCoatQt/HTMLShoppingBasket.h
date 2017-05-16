#pragma once
#include "FileShoppingBasket.h"
#include <fstream>
#include <string>

class HTMLShoppingBasket : public FileShoppingBasket
{
public:
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	void displayShoppingBasket() const override;
};