#include "Repository.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}


void Repository::addEmployee( Employee & e)
{
	if (this->employees.find(e) == true) {
		throw runtime_error("Duplicate employee ID");
	}
	this->employees.add(e);
}

void Repository::readFromFile()
{
	string line;
	ifstream fin(filename);
	if (!fin.is_open()) {
		throw runtime_error("Cannot open the file");
	}
	else {
		while (getline(fin, line)) {
			stringstream streamLine(line);
			vector<string> tokens;
			string word;
			while (getline(streamLine, word, ',')) {
				tokens.push_back(word);
			}
			Employee e{ stoi(tokens[0]),tokens[1],stod(tokens[2]) };
			this->employees.add(e);
		}
	}
}

void Repository::writeToFile()
{
	ofstream fout(this->filename);
	if (!fout.is_open()) {
		throw runtime_error("The file could not be opened!");
	}
	std::unique_ptr<Iterator>it =  employees.createIterator();
	while (!it->valid()) {
		Employee e = it->getCurrent();
		fout << e;
		it->next();
	}
	fout.close();
}


int Repository::getSize()
{
	return this->employees.size();
}

void Repository::removeEmployee(Employee & e)
{
	this->employees.remove(e);
}

