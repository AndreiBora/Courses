#include "Tests.h"
#include <vector>
using namespace std;


void Tests::testAll()
{
	testAdd();
	testRemove();
	testIterator();
}

void Tests::testAdd()
{
	BSTSet* bs =BSTSet::init();
	assert(bs->size() == 0);
	Employee e1{ 7,"Zaza",1000 };
	Employee e2{ 8,"Tyson",1000 };
	Employee e3{ 6,"JJ",1000 };
	bs->add(e1);
	assert(bs->size() == 1);
	assert(bs->find(e1));
	bs->add(e2);
	assert(bs->size() == 2);
	assert(bs->find(e2));
	bs->add(e3);
	assert(bs->size() == 3);
	assert(bs->find(e3));

}

void Tests::testRemove()
{
	BSTSet* bs = BSTSet::init();
	Employee e1{ 7,"Zaza",1000 };
	Employee e2{ 8,"Tyson",1000 };
	Employee e3{ 6,"JJ",1000 };
	bs->add(e1);
	bs->add(e2);
	bs->add(e3);
	bs->remove(e3);
	assert(bs->size() == 2);
	assert(false == bs->find(e3));
	bs->remove(e2);
	assert(bs->size() == 1);
	assert(false == bs->find(e2));
	bs->remove(e1);
	assert(bs->size() == 0);
	assert(false == bs->find(e1));

}

void Tests::testIterator()
{
	vector<Employee> v;

	BSTSet* bs = BSTSet::init();
	Employee e1{ 7,"Zaza",1000 };
	Employee e2{ 8,"Tyson",1000 };
	Employee e3{ 6,"JJ",1000 };

	v.push_back(e3);
	v.push_back(e1);
	v.push_back(e2);

	bs->add(e1);
	bs->add(e2);
	bs->add(e3);
	auto it = bs->createIterator();
	int ct = 0;
	while (!it->valid()) {
		Employee e = it->getCurrent();
		assert(v[ct].getId() == e.getId());
		ct++;
		it->next();
	}

	it->first();
	int ct1 = 0;
	while (!it->valid()) {
		Employee e = it->getCurrent();
		assert(v[ct1].getId() == e.getId());
		ct1++;
		it->next();
	}
}
Tests::Tests()
{
}


Tests::~Tests()
{
}
