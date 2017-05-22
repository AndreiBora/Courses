#include "trenchcoatqt.h"
#include <QtWidgets/QApplication>
#include <iostream>
#

using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "tshirts.txt" };
	CSVShoppingBasket* sb = new CSVShoppingBasket{};
	Controller ctrl{ repo, sb, TshirtValidator{} };
	TrenchCoatQt w{ ctrl };
	w.show();
	return a.exec();
}
