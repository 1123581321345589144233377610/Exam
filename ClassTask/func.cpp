#include "func.hpp"

void addName(std::string*& staffName, int count, std::string name){
	std::string* Temp = new std::string[count + 1];

	for (int i = 0; i < count; i++)	{
		*Temp = *staffName;
		Temp++;
		staffName++;
	}
	*Temp = name;
	Temp -= count;
	staffName -= count;

	delete[] staffName;

	staffName = Temp;
}

void expandingSalaryArr(int*& staffSalary, int count){
	int* Temp = new int[count + 1];

	for (int i = 0; i < count; i++){
		*Temp = *staffSalary;
		Temp++;
		staffSalary++;
	}
	*Temp = -1;
	Temp -= count;
	staffSalary -= count;

	delete[] staffSalary;

	staffSalary = Temp;
}

void addNames(std::string*& staffName, int count, std::string* otherStaffName, int otherCount){
	std::string* Temp = new std::string[count + otherCount];

	int i = 0;
	for (; i < count; i++){
		*Temp = staffName[i];
		Temp++;
	}
	for (; i < count + otherCount; i++){
		*Temp = *otherStaffName;
		Temp++;
		otherStaffName++;
	}
	Temp -= count + otherCount;

	delete[] staffName;

	staffName = Temp;
}

void addSalarys(int*& staffSalary, int count, int* otherStaffSalarys, int otherCount){																					
	int* Temp = new int[count + otherCount];

	int i = 0;
	for (; i < count; i++){
		*Temp = staffSalary[i];
		Temp++;
	}
	for (; i < count + otherCount; i++){
		*Temp = *otherStaffSalarys;
		Temp++;
		otherStaffSalarys++;
	}
	Temp -= count + otherCount;

	delete[] staffSalary;

	staffSalary = Temp;
}

void deleteName(std::string*& staffName, int count, int j){
	std::string* TempNames = new std::string[count - 1];

	int i = 0;
	for (; i < j; i++){
		*TempNames = *staffName;
		TempNames++;
		staffName++;
	}
	staffName++;
	i++;
	for (; i < count; i++){
		*TempNames = *staffName;
		TempNames++;
		staffName++;
	}
	TempNames -= count - 1;
	staffName -= count;

	delete[] staffName;

	staffName = TempNames;
}

void deleteSalary(int*& staffSalary, int count, int j){
	int* TempSalary = new int[count - 1];

	int i = 0;
	for (; i < j; i++){
		*TempSalary = *staffSalary;
		TempSalary++;
		staffSalary++;
	}
	staffSalary++;
	i++;
	for (; i < count; i++){
		*TempSalary = *staffSalary;
		TempSalary++;
		staffSalary++;
	}
	TempSalary -= count - 1;
	staffSalary -= count;

	delete[] staffSalary;

	staffSalary = TempSalary;
}


