#include "BSTSet.h"
#include <memory>

BSTSet::BSTSet()
{
}


BSTSet::~BSTSet()
{
}

BSTSet * BSTSet::init()
{
	return new BSTSet();
}



void BSTSet::add(Employee & e)
{
	this->root = this->addRec(this->root, e);
}

bool BSTSet::find(Employee & e)
{
	if (this->findHelper(this->root, e) != nullptr) {
		return true;
	}
	return false;
}

void BSTSet::remove(Employee & e)
{
	this->root = this->removeHelper(this->root, e);
}

int BSTSet::size()
{
	return this->sizeHelper(this->root);
}

//-----------------------------------------

Node * BSTSet::addRec(Node* p,Employee & e)
{
	if (p == nullptr)
		return new Node{ e,nullptr,nullptr };
	if (e < p->getInfo())
		p->setLeft(this->addRec(p->getLeft(),e));
	else if (e > p->getInfo()) {
		p->setRight(this->addRec(p->getRight(), e));
	}
	return p;

}

Node * BSTSet::findHelper(Node * p, Employee & e)
{
	if (p == nullptr) {
		return nullptr;
	}
	else if(e < p->getInfo()) {
		return findHelper(p->getLeft(), e);
	}
	else if (e > p->getInfo()) {
		return findHelper(p->getRight(), e);
	}
	else {
		return p;
	}
}

Node * BSTSet::findSuccesor(Node * p)
{
	while (p->getLeft() != nullptr)
		p = p->getLeft();
	return p;
}

Node * BSTSet::removeHelper(Node * p, Employee & e)
{
	if (root == nullptr) {
		return root;
	}
	else if (e < p->getInfo()) {
		p->setLeft(removeHelper(p->getLeft(), e));
	}
	else if (e > p->getInfo()) {
		p->setRight(removeHelper(p->getRight(), e));
	}
	else {
		//Case 1 No child
		if (p->getLeft() == nullptr && p->getRight() == nullptr) {
			delete p;
			p = nullptr;
		}
		//Case 2:One child
		else if (p->getLeft() == nullptr) {
			Node* temp = p;
			p = p->getRight();
			delete temp;
		}
		else if (p->getRight() == nullptr) {
			Node* temp = p;
			p = p->getLeft();
			delete temp;
		}
		else {
			Node* temp = findSuccesor(p->getRight());
			p->setInfo(temp->getInfo());
			p->setRight(removeHelper(p->getRight(), temp->getInfo()));
		}
	}
	return p;
}

int BSTSet::sizeHelper(Node * p)
{
	if (p == nullptr)
		return 0;
	int leftSize = sizeHelper(p->getLeft());
	int rightSize = sizeHelper(p->getRight());
	return leftSize + rightSize + 1;

}

std::unique_ptr<Iterator> BSTSet::createIterator()
{
	return std::make_unique<BSTSetIterator>(*this);
}

void BSTSet::destroy()
{
	this->destroyHelper(this->root);
}

void BSTSet::destroyHelper(Node * p)
{
	if (p != nullptr) {
		destroyHelper(p->getLeft());
		destroyHelper(p->getRight());
		delete p;
	}
}



