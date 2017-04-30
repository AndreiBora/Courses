#include "HTMLShoppingBasket.h"
#include "RepositoryException.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void HTMLShoppingBasket::writeToFile()
{

	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	string head = "<!DOCTYPE html>\n\t<html>\n\t<head>\n\t<title>Shopping Basket</title></head><body><table border=\"1\">";
	string tail = "</table>\n</body>\n</html>";
	string firstLine = "<tr><td>Size</td><td>Color</td><td>Price</td><td>Link</td><td>Length</td></tr>\n";
	f << head;
	f << firstLine;

	for (auto t : this->Tshirts) {
		f << "<tr>\n";
		f << "<td>" << t.getSize() << "</td>\n";
		f << "<td>" << t.getColor() << "</td>\n";
		f << "<td>" << t.getPrice() << "</td>\n";
		f << "<td>" <<"<a href=\""<< t.getLink() <<"\">Link"<<"</a>"<<"</td>\n";
		f << "<td>" << t.getLength() << "</td>\n";
		f << "</tr>\n";
	}
	f << tail;
}

void HTMLShoppingBasket::displayShoppingBasket() const
{
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", filename.c_str(), NULL, SW_SHOW);
}