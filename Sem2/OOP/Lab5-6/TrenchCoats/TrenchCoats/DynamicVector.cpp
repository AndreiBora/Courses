#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[capacity];
	for (int i = 0; i < this->size; i++) {
		this->elems[i] = v.elems[i];
	}
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

void DynamicVector::add(const TElement & e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}


int DynamicVector::getSize() const
{
	return this->size;
}

TElement * DynamicVector::getAllElems() const
{
	return this->elems;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= factor;
	TElement* aux = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete [] this->elems;
	this->elems = aux;
}


void DynamicVector::remove(int pos) {
	for (int i = pos; i < this->size-1; i++) {
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}
