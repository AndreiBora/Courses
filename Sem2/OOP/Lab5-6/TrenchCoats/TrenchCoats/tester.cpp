#include "Tester.h"
#include "DynamicVector.h"
#include <cassert>
#include "Repository.h"
#include "Controller.h"
Tester::Tester()
{
	testDynamicVector();
	testRepo();
	testController();
}

void Tester::testDynamicVector()
{
	DynamicVector v{ 2 };
	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html" };
	Tshirt t2{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html" };
	v.add(t1);
	assert(v.getSize() == 1);
	v.add(t2);
	assert(v.getSize() == 2);
	v.remove(0);
	assert(v.getSize() == 1);

}

void Tester::testRepo()
{
	Repository repo{};
	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html" };
	Tshirt t2{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html" };
	repo.add(t1);
	assert(repo.getTshirts().getSize() == 1);
	repo.add(t2);
	assert(repo.getTshirts().getSize() == 2);
	repo.remove(0);
	assert(repo.getTshirts().getSize() == 1);
	assert(repo.find(t2) == 0);
	
}

void Tester::testController()
{
	Repository repo{};
	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html" };
	Tshirt t2{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html" };
	repo.add(t1);
	repo.add(t2);
	Controller ctrl{repo};
	//try to add a Tshirt twice
	bool result = ctrl.addTshirt("S", "blue", 129, 0, "https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html");
	assert(result ==  false);
	//delete a Tshirt that exist
	result = ctrl.deleteTshirt("https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html");
	
	assert(result == true);
	//delete a Tshirt that doesn't exist;
	result = ctrl.deleteTshirt("Nu exista");
	assert(result == false);
}
