#pragma once
#include "Tshirt.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector Tshirts;
public:
	//default constructor
	Repository(){}
	/*
	Add a Tshirt to the repository
	input: s- Tshirt
	*/
	void add(const Tshirt& s);
	/*
	Remove a Tshirt from a given position
	input pos-position of element
	*/
	void remove(int pos);
	/*
	Find a Tshirt in the repository
	input s - Tshirt element
	output position
	*/
	int find(const Tshirt& s);
	//return a dynamic vector of Tshirt elements
	DynamicVector getTshirts() const { return Tshirts; }
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
};