#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:
	
	Controller(const Repository&r) :repo(r) {}

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
	bool addTshirt(const std::string& size, const std::string& color, double price, int quantity, const std::string& link);
	/*
	Delete a Tshirt from repo if it exist and it is sold out
	input: link - web link to a picture of the Tshirt.
	output: true- if is deleted
			false-otherwise
	*/
	bool deleteTshirt(const std::string& link);
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
	bool updateTshirt(const std::string& size, const std::string& color, double price, int quantity, const std::string& link);

};