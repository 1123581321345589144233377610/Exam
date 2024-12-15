#pragma once
#include <iostream>
#include <cstring>
#include "func.hpp"

class SalaryDB{
private:
	int count;			
	std::string* surnames;	
	int* salaries;	
	int minWage = 15000;
public:
	SalaryDB();
	SalaryDB(int count, std::string* staffName, int* staffSalary);
	~SalaryDB();
	SalaryDB(SalaryDB& other);
	bool deleteStaff(std::string staffName);
	void outputInLimit(int minimum, int maximum);
	SalaryDB& operator=(SalaryDB other);
	SalaryDB operator+(SalaryDB other);
	SalaryDB& operator+=(SalaryDB other);
	SalaryDB& operator[](std::string name);
	bool operator=(int salary);
	bool operator==(SalaryDB other);
	bool operator!=(SalaryDB other);
	friend SalaryDB& sortSalaryDataBase(SalaryDB& dataBase);
	friend std::ostream& operator<<(std::ostream& out, SalaryDB dataBase);
};
