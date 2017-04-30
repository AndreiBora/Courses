//#include "tester.h"
//#include <cassert>
//#include "repository.h"
//#include "controller.h"
//#include <iostream>
//
//Tester::Tester()
//{
//	testdynamicvector();
//	testrepo();
//	testcontroller();
//	testShoppingBasket();
//	testTshirt();
//	testTshirtList();
//	testController2();
//}
//
//
//void Tester::testdynamicvector()
//{
//	std::vector<Tshirt> v;
//	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
//	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	v.push_back(t1);
//	assert(v.size() == 1);
//	v.push_back(t2);
//	assert(v.size() == 2);
//	v.erase(v.begin());
//	assert(v.size() == 1);
//
//}
//
//void Tester::testrepo()
//{
//	Repository repo{};
//	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
//	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	repo.add(t1);
//	assert(repo.getTshirts().size() == 1);
//	repo.add(t2);
//	assert(repo.getTshirts().size() == 2);
//	repo.remove(0);
//	assert(repo.getTshirts().size() == 1);
//	assert(repo.find(t2) == 0);
//	Tshirt t3{ "m","black",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	repo.update(t3);
//
//	//test find with empty repo
//	Repository repo2{};
//	assert(repo2.find(t3)==0);
//}
//
//void Tester::testcontroller()
//{
//	Repository repo{};
//	Tshirt t1{ "s","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
//	Tshirt t2{ "m","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	Tshirt t3{ "L","black",112,30,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16500.html",70 };
//	repo.add(t1);
//	repo.add(t2);
//	Controller ctrl{repo};
//	ctrl.getShoppingBascket();
//	//try to add a tshirt twice
//	bool result = ctrl.addTshirt("s", "blue", 129, 0, "https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71);
//	assert(result ==  false);
//	//delete a tshirt that exist
//	result = ctrl.deleteTshirt("https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html");
//	
//	assert(result == true);
//	//delete a tshirt that doesn't exist;
//	result = ctrl.deleteTshirt("nu exista");
//	assert(result == false);
//	
//	//add a Tshirt through controller
//	result = ctrl.addTshirt("L","black",112,30,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16500.html",70);
//	assert(result == true);
//	//update a tshirt that doesn't exist
//	result = ctrl.updateTshirt("L", "black", 112, 30, "https://www.nuexista.ro",60);
//	assert(result == false);
//	//update a tshirt that exists
//	result = ctrl.updateTshirt("XL", "black", 112, 30, "https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16500.html", 70);
//	assert(result == true);
//
//	result = ctrl.createTshirtList("XL");
//	assert(result == true);
//
//
//	Repository repo2{};
//	Controller ctrl2{ repo2 };
//	result = ctrl2.createTshirtList("XL");
//	assert(result == false);
//	result = ctrl2.startTshirtList();
//	assert(result == false);
//}
//
//void Tester::testShoppingBasket() {
//	ShoppingBasket sb{1};
//	assert(sb.getTotalSum() == 1);
//}
//
//void Tester::testTshirt()
//{
//	Tshirt t1{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	Tshirt t2{ "L","black",112,30,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",70 };
//	assert(t1.getSize() == "M");
//	assert(t1.getColor() == "white");
//	assert(t1.getPrice() == 117);
//	t1.setQuantity(10);
//	assert(t1.getQuantity() == 10);
//	assert("Tshirt\ncolor:white\nsize: M\nprice: 117\n" == t1.toString());
//	t1.display();
//	assert(t1 < 70);
//}
//
//void Tester::testTshirtList()
//{
//	TshirtList tl;
//	Tshirt t1{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	bool result = tl.start();
//	assert(result == false);
//	tl.display();
//	tl.displayNext();
//	//add an element
//	tl.add(t1);
//	//test get size
//	assert(tl.getSize() == 1);
//	//test start
//	result = tl.start();
//	assert(result == true);
//	tl.display();
//	tl.displayNext();
//	//get current
//	Tshirt& t = tl.getCurrent();
//	tl.clear();
//
//}
//
//void Tester::testController2()
//{
//	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",71 };
//	Tshirt t2{ "S","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",60 };
//	Repository repo{};
//	repo.add(t1);
//	repo.add(t2);
//	Controller ctrl{repo};
//	ctrl.createTshirtList("S");
//	Tshirt& t19 = ctrl.getCurrentTshirt();
//	assert(t19.getLink() == t1.getLink());
//	Tshirt& t3 = ctrl.displayCurrent();
//	assert(t3.getLink() == t1.getLink());
//	
//	Tshirt& t4 = ctrl.displayNext();
//	assert(t4.getLink() == t2.getLink());
//
//	ctrl.buyTshirt(t1);
//	//filter 
//	std::vector<Tshirt>v = ctrl.filterByLength(100);
//	assert(v[0].getLink() == t1.getLink());
//	assert(v[1].getLink() == t2.getLink());
//	
//}