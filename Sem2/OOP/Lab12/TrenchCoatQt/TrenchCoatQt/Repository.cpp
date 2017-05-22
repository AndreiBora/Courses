#include "Repository.h"
#include "RepositoryException.h"
#include <string>
#include <fstream>

using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);
	if(!file.is_open())
		throw FileException("The file could not be opened!");
	Tshirt t;
	while (file >> t)
		this->Tshirts.push_back(t);
	file.close();
}

void Repository::add(const Tshirt& t) {
	Tshirt tFound = this->findByLink(t.getLink());
	if (tFound.getColor() != "")
		throw DuplicateTshirtException();
	this->Tshirts.push_back(t);
	this->writeToFile();
}

Tshirt Repository::findByLink(const std::string & link) const
{
	for (auto t : this->Tshirts) {
		if (t.getLink() == link)
			return t;
	}
	return Tshirt{};
}

void Repository::remove(const Tshirt& t) {
	Tshirt tFound = this->findByLink(t.getLink());
	if (tFound.getColor() == "" && tFound.getPrice() == 0)
		throw NotFoundTshirtException();
	if (tFound.getQuantity() != 0) {
		throw NotSoldOutException();
	}
	//find position
	int pos = this->find(tFound);
	this->Tshirts.erase(this->Tshirts.begin()+pos);
	this->writeToFile();
}

void Repository::update(const Tshirt & t)
{
	//check if is in the repository
	Tshirt tFound = this->findByLink(t.getLink());
	if (tFound.getColor() == "" && tFound.getPrice() == 0)
		throw NotFoundTshirtException();

	//update
	for (int i = 0; i < this->getTshirts().size(); i++) {
		if (this->getElementAtPos(i) == t)
			this->Tshirts[i] = t;
	}
	this->writeToFile();
}
int Repository::find(const Tshirt & s)
{
	std::vector<Tshirt> v = this->getTshirts();
		if (v.size() == 0)
			return 0;
		for (int i = 0; i < v.size(); i++) {
			if (s == v[i])
				return i;
		}
	
	return -1;
}

Tshirt  Repository::getElementAtPos(int pos)
{	
	std::vector<Tshirt> v = this->getTshirts();
	return v[pos];
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");
	for (auto t : this->Tshirts) {
		file << t;
	}

	file.close();
}