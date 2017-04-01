#pragma once
#include <iostream>
#include <string>

class Tshirt
{
private:
	std::string size;
	std::string color;
	double price;
	int quantity;
	std::string link;

public:
	Tshirt();
	Tshirt(const std::string& size, const std::string& color, double price, int quantity, const std::string& link);
	std::string getSize() const { return size; }
	std::string getColor() const { return color; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	std::string getLink() const { return link; }

	void setSize(std::string s) { size = s; }
	void setColor(std::string c) { color = c; }
	void setPrice(double p) { price = p; }
	void setQuantity(int q) { quantity = q; }
	void setLink(std::string lk) { link = lk; }
};

inline bool operator == (const Tshirt &x, const Tshirt &y) {
	return x.getLink() == y.getLink();
}
