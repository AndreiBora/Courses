#include "tester.h"
#include "dynamicvector.h"
#include <cassert>
#include "repository.h"
#include "controller.h"

Tester::Tester()
{
	testdynamicvector();
	testrepo();
	testcontroller();
}


void Tester::testdynamicvector()
{
	DynamicVector<Tshirt> v{ 2 };
	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
	v.add(t1);
	assert(v.getSize() == 1);
	v.add(t2);
	assert(v.getSize() == 2);
	v.remove(0);
	assert(v.getSize() == 1);

}

void Tester::testrepo()
{
	Repository repo{};
	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
	repo.add(t1);
	assert(repo.getTshirts().getSize() == 1);
	repo.add(t2);
	assert(repo.getTshirts().getSize() == 2);
	repo.remove(0);
	assert(repo.getTshirts().getSize() == 1);
	assert(repo.find(t2) == 0);
	
}

void Tester::testcontroller()
{
	Repository repo{};
	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
	repo.add(t1);
	repo.add(t2);
	Controller ctrl{repo};
	//try to add a tshirt twice
	bool result = ctrl.addTshirt("s", "blue", 129, 0, "https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71);
	assert(result ==  false);
	//delete a tshirt that exist
	result = ctrl.deleteTshirt("https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html");
	
	assert(result == true);
	//delete a tshirt that doesn't exist;
	result = ctrl.deleteTshirt("nu exista");
	assert(result == false);
}
