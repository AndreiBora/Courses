#include "TshirtValidator.h"
#include <algorithm>
#include <vector>

using namespace std;

TshirtException::TshirtException(std::vector<std::string> _errors) : errors{ _errors }
{
};

std::vector<std::string> TshirtException::getErrors() const
{
	return this->errors;
}

void TshirtValidator::validate(const Tshirt & t)
{
	vector<string>sizeList{ "S","M","L","XL","XXL" };
	vector<string> errors;
	if (find(begin(sizeList), end(sizeList), t.getSize()) == end(sizeList)) {
		errors.push_back("Size doesn't exists\n");
	}
	if (t.getPrice() <= 0) {
		errors.push_back("Price must be greater than 0\n");
	}
	if (t.getQuantity() < 0) {
		errors.push_back("Quantity cannot be negative\n");
	}
	int posWww = t.getLink().find("www");
	int posHttp = t.getLink().find("http");
	if (posWww != 0 && posHttp != 0) {
		errors.push_back("The source link must start with one of the following \"www\" or \"http\"");
	}
	if (t.getLength() < 0) {
		errors.push_back("Length cannot be negative");
	}
	if (errors.size() > 0) {
		throw TshirtException(errors);
	}
}