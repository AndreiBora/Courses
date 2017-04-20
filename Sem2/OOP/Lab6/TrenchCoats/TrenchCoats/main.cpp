#include "Tshirt.h"
#include "UI.h"
#include <Windows.h>
#include "Tester.h"

using namespace std;

int main() {

	system("color f4");
	Tester t;

	Repository repo{};
	//add Tshirts
	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html",56 };
	Tshirt t2{ "S","blue",172,1,"https://www.originals.ro/tricou-barbati-adidas-originals-adi-polo-bk5865-p-16610.html",60 };
	Tshirt t3{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html",61};
	repo.add(t1);
	repo.add(t2);
	repo.add(t3);
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}