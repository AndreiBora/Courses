#pragma once
#include "Tshirt.h"

typedef Tshirt TElement;

class DynamicVector {
private:
	TElement* elems;
	int size;
	int capacity;
public:
	//default constructor
	DynamicVector(int capacity = 10);
	//copy contructor
	DynamicVector(const DynamicVector& v);
	//destructor
	~DynamicVector();
	// Adds an element to the current DynamicVector
	void add(const TElement& e);
	//return the size of the DynamicVector
	int getSize() const;
	//return a pointer to the array
	TElement* getAllElems() const;
	void remove(int pos);
private:
	void resize(double factor = 2);
};