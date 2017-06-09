#pragma once
#include "BSTSet.h"
#include <cassert>
#include "Employee.h"

class Tests
{
public:
	static void testAll();
	Tests();
	~Tests();
private:
	static void testAdd();
	static void testRemove();
	static void testIterator();
};

