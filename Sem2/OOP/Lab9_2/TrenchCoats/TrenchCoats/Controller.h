#pragma once
#include "Repository.h"
#include "TshirtList.h"
#include "ShoppingBasket.h"
#include "TshirtValidator.h"
#include "FileShoppingBasket.h"

class Controller
{
private:
	Repository repo;
	TshirtList tshirtList;
	FileShoppingBasket* shoppingBasket;
	TshirtValidator validator;
public:
	
	Controller(const Repository&r, FileShoppingBasket* sb, TshirtValidator v) :repo{ r }, shoppingBasket{sb}, validator { v } {}

	Repository getRepo() const { return repo; }
	/*
	Add a Tshirt element in the respository.If the element is already in repository the element will not be added.
	input size:-size Tshirt
		color: ex blue, red
		price:
		quantity: nr of Tshirts in the repository
		link - web link to a picture of the Tshirt.
	output: true- if is added
			false-otherwise
	*/
	void addTshirt(const std::string& size, const std::string& color, double price, int quantity, const std::string& link,int length);
	/*
	Delete a Tshirt from repo if it exist and it is sold out
	input: link - web link to a picture of the Tshirt.
	output: true- if is deleted
			false-otherwise
	*/
	void deleteTshirt(const std::string& link);
	/*
	Update a Tshirt element in the respository.If the element is not in repository the element will not be updated
	input size:-size Tshirt
	color: ex blue, red
	price:
	quantity: nr of Tshirts in the repository
	link - web link to a picture of the Tshirt.
	output: true- if is updated
			false-otherwise
	*/
	void updateTshirt(const std::string& size, const std::string& color, double price, int quantity, const std::string& link,int length);

	bool createTshirtList(std::string size);

	bool startTshirtList();
	Tshirt& displayCurrent();
	Tshirt& displayNext();
	Tshirt& getCurrentTshirt();
	void buyTshirt(const Tshirt& tshirt);
	ShoppingBasket* getShoppingBascket() const { return shoppingBasket; };
	std::vector<Tshirt> filterByLength(int length);
	void saveShoppingBasketToFile(const std::string& filename);
	void openShoppingBasket() const;
};