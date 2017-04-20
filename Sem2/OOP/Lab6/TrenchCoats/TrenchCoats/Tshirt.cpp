#include "Tshirt.h"
#include <sstream>
#include <Windows.h>
#include <shellapi.h>


Tshirt::Tshirt() :size(""), color(""), price(0), quantity(0), link(""){}

Tshirt::Tshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link,int len)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->link = link;
	this->length = len;
}

void Tshirt::display()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string Tshirt::toString()
{
	std::stringstream ss;
	ss << "Tshirt\ncolor:" << this->getColor() << "\nsize: " << this->getSize() << "\nprice: " << this->getPrice() << "\n";
	return ss.str();
}

bool Tshirt::operator<(int length) const
{
	return this->length < length;
}