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
	Tshirt t1{ "S","blue",129,0,"https://www.originals.ro/tricou-barbati-adidas-performance-ultra-boost-bk2799-p-16597.html" };
	Tshirt t2{ "M","white",117,20,"https://www.originals.ro/tricou-barbati-adidas-performance-intnl-taste-bk2832-p-16599.html" };
	repo.add(t1);
	repo.add(t2);
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}