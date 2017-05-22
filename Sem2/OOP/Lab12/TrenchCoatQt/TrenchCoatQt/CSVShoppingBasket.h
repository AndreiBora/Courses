#pragma once
#include "FileShoppingBasket.h"
#include <string>

class CSVShoppingBasket : public FileShoppingBasket
{
public:
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Microsof Excel.
	*/
	void displayShoppingBasket() const override;

};