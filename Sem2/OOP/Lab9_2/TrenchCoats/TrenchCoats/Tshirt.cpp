#include "Tshirt.h"
#include "Utils.h"
#include <sstream>
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

std::istream & operator >> (std::istream & is, Tshirt & t)
{
	string line;
	getline(is, line);

	vector<string>tokens = tokenize(line, ',');
	if (tokens.size() != 6)
		return is;
	t.size = tokens[0];
	t.color = tokens[1];
	t.price = stod(tokens[2]);
	t.quantity = stoi(tokens[3]);
	t.link = tokens[4];
	t.length = stoi(tokens[5]);

	return is;

}

std::ostream & operator<<(std::ostream & os, const Tshirt & t)
{
	os << t.size << "," << t.color << "," << t.price << "," << t.quantity << "," << t.link << "," << t.length << "\n";
	return os;
}