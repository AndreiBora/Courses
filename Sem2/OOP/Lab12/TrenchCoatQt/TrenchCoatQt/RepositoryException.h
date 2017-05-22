#pragma once
#include <exception>
#include <string>

class FileException :public std::exception
{
public:
	std::string message;
public:
	FileException(const std::string& msg);
	virtual const char* what();
};

class RepositoryException : public std::exception
{
public:
	std::string message;
public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {};
	virtual const char* what();
};

class DuplicateTshirtException : public RepositoryException
{
public:
	const char* what();
};

class NotFoundTshirtException : public RepositoryException
{
public:
	const char* what();
};

class NotSoldOutException : public RepositoryException
{
public:
	const char* what();
};