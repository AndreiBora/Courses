#include "Tshirt.h"

Tshirt::Tshirt() :size(""), color(""), price(0), quantity(0), link(""){}

Tshirt::Tshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->link = link;
}
