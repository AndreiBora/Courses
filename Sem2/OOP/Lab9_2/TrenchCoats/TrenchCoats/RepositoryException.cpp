#include "RepositoryException.h"

FileException::FileException(const std::string & msg) : message{ msg }
{
}
const char * FileException::what()
{
	return this->message.c_str();
}

RepositoryException::RepositoryException():exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string & msg): message{msg}
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateTshirtException::what()
{
	return "There is another tshirt with the same link";
}

const char * NotFoundTshirtException::what()
{
	return "There is no tshirt with the given link";
}

const char * NotSoldOutException::what()
{
	return "You can delete only tshirts with with quantity 0";
}
