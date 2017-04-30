#include "FileShoppingBasket.h"

FileShoppingBasket::FileShoppingBasket(): ShoppingBasket{},filename{""}
{
}

void FileShoppingBasket::setFilename(const std::string & filename)
{
	this->filename = filename;
}