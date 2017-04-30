#pragma once
#include "Tshirt.h"
#include <vector>
class Repository
{
private:
	std::vector<Tshirt> Tshirts;
	std::string filename;
public:
	//default constructor
	Repository() {};

	//one argument repository
	Repository(const std::string& filename);
	/*
	Add a Tshirt to the repository
	input: s- Tshirt
	*/
	void add(const Tshirt& s);
	/*
	Remove a Tshirt from a given position
	input pos-position of element
	*/
	void remove(const Tshirt& t);
	/*
	Find a Tshirt in the repository
	input s - Tshirt element
	output position
	*/
	int find(const Tshirt& s);
	//return a dynamic vector of Tshirt elements
	std::vector<Tshirt> getTshirts() const { return Tshirts; }
	/*
	Return a Tshirt element from a given position
	input: pos-position of element
	output: element found or -1 otherwise
	*/
	Tshirt getElementAtPos(int pos);
	/*
	Change the characteristics of a Tshirt element
	input: s- Tshirt element
	*/
	void update(const Tshirt& s);

	/*
	Finds a tshirt by link
	input tshirt
	output tshirt if was found or "empty" tshirt if was not found
	*/
	Tshirt findByLink(const std::string& link) const;
private:
	void readFromFile();
	void writeToFile();
};