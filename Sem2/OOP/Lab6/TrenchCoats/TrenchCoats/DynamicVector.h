#pragma once
#include "Tshirt.h"


template <typename T>
class DynamicVector {
private:
	T* elems;
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
	void add(const T& e);
	//return the size of the DynamicVector
	int getSize() const;
	//return a pointer to the array
	T* getAllElems() const;
	void remove(int pos);
	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);
	void operator-(int pos);
	void removeAll();
private:
	void resize(double factor = 2);
	
	
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[capacity];
	for (int i = 0; i < this->size; i++) {
		this->elems[i] = v.elems[i];
	}
}
template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}


template <typename T>
void DynamicVector<T>::add(const T & e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const
{
	return this->elems;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

template <typename T>
void DynamicVector<T>::remove(int pos) {
	*this - pos;
}

template <typename T>
void DynamicVector<T>::operator-(int pos)
{
	for (int i = pos; i < this->size - 1; i++) {
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}


template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];

}

template <typename T>
void DynamicVector<T>::removeAll() {
	this->size = 0;
}
