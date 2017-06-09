#include "Iterator.h"



BSTSetIterator::BSTSetIterator(BSTSet & s): set{s}
{
	this->current = this->set.getRoot();
	this->goDownLeft();
}

void BSTSetIterator::first()
{
	while (!stack.empty())
		stack.pop();
	this->current = this->set.getRoot();
	this->goDownLeft();
}

void BSTSetIterator::next()
{
	this->goDownLeft();
}

Employee BSTSetIterator::getCurrent()
{
	if (!this->stack.empty()) {
		this->current = this->stack.top();
		this->stack.pop();
	}
	Employee e = this->current->getInfo();
	this->current = this->current->getRight();
	return e;
}

bool BSTSetIterator::valid()
{
	return this->stack.empty();
}

void BSTSetIterator::goDownLeft()
{
	while (this->current != nullptr)
	{
		stack.push(this->current);
		this->current = this->current->getLeft();
	}
}
