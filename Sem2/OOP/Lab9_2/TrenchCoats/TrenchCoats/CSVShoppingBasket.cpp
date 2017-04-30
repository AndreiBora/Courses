#include "CSVShoppingBasket.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void CSVShoppingBasket::displayShoppingBasket() const
{
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Notepad++\\notepad++.exe", filename.c_str(), NULL, SW_SHOW);
}

void CSVShoppingBasket::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto t : this->Tshirts)
		f << t;

	f.close();

}