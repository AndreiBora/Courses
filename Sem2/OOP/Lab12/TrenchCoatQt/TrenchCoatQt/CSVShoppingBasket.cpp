#include "CSVShoppingBasket.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void CSVShoppingBasket::displayShoppingBasket() const
{
	/*char arr[] = "open";
	size_t size = strlen(arr);
	wchar_t* wArr = new wchar_t[size];
	for (size_t i = 0; i < size; ++i)
		wArr[i] = arr[i];

	char arr2[] = "C:\\Program Files (x86)\\Notepad++\\notepad++.exe";
	size_t size2 = strlen(arr);
	wchar_t* wArr2 = new wchar_t[size];
	for (size_t i = 0; i < size; ++i)
		wArr2[i] = arr2[i];

	char arr3[] = "D:\\out.txt";
	size_t size3 = strlen(arr);
	wchar_t* wArr3 = new wchar_t[size];
	for (size_t i = 0; i < size; ++i)
		wArr3[i] = arr3[i];*/

	//ShellExecute(NULL, &wArr[0], &wArr2[0], &wArr3[0], NULL, SW_SHOW);
	ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Notepad++\\notepad++.exe",this->filename.c_str(), NULL, SW_SHOW);
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