#pragma once
#include "Set.h"
#include <stack>
#include <memory>

class Iterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual Employee getCurrent() = 0;
	virtual bool valid() = 0;
};

class Set
{
public:
	virtual void add(Employee& e) = 0;
	virtual void remove(Employee& e) = 0;
	virtual bool find(Employee& e) = 0;
	virtual int size() = 0;
	virtual void destroy() = 0;
	virtual std::unique_ptr<Iterator> createIterator() = 0;
	virtual ~Set() {};
};

class Node
{
private:
	Employee info;
	Node* left;
	Node* right;
public:
	Node(Employee employee, Node* l, Node* r) : info{ employee }, left{ l }, right{ right } {};
	Employee getInfo() const { return info; }
	Node* getLeft() const { return left; }
	Node* getRight() const { return right; }
	void setInfo(Employee e) { this->info = e; }
	void setLeft(Node* n) { this->left = n; }
	void setRight(Node* n) { this->right = n; }
	~Node() {};
};


class BSTSet: public Set
{
private:
	Node *root;
public:
	BSTSet();
	~BSTSet();
	static BSTSet* init();
	void add(Employee& e) override;
	void remove(Employee& e)override;
	bool find(Employee& e) override;
	int size()override;
	Node* getRoot() { return this->root; }
	std::unique_ptr<Iterator> createIterator() override;
	void destroy() override;
private:
	Node* addRec(Node*p,Employee& e);
	Node* findHelper(Node* p, Employee& e);
	Node* removeHelper(Node*p, Employee& e);
	Node* findSuccesor(Node*p);
	int sizeHelper(Node*p);
	void destroyHelper(Node* p);
	void copyTree(Node* thisRoot, Node* sourceRoot);

};




class BSTSetIterator : public Iterator
{
private:
	BSTSet& set;
	Node* current;
	std::stack<Node*> stack;
public:
	BSTSetIterator(BSTSet& s);
	void first() override;
	void next() override;
	Employee getCurrent() override;
	bool valid() override;
private:
	void goDownLeft();
};

