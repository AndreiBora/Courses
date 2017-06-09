#pragma once
#include <string>
class Employee
{
private:
	int id;
	std::string name;
	double salary;
public:
	Employee();
	Employee(int _id, std::string _name, double _salary);
	int getId() const { return id; }
	std::string getName() const { return name; }
	double getSalary()const { return salary; }
	std::string toString();
	bool operator<(Employee& e) const;
	bool operator>(Employee& e) const;
	void operator=(Employee e);
	friend std::ostream& operator <<(std::ostream& os, Employee& e);

	~Employee();
};

