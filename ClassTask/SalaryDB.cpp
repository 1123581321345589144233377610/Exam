#include "SalaryDB.hpp"

SalaryDB::SalaryDB(){
	this->count = 0;
	this->surnames = nullptr;
	this->salaries = nullptr;
}

SalaryDB::SalaryDB(int count, std::string * staffName, int* staffSalary) {
	this->count = count;														
	this->surnames = staffName;
	this->salaries = staffSalary;
}

SalaryDB::~SalaryDB(){
	delete[] surnames;
	delete[] salaries;
}

SalaryDB::SalaryDB(SalaryDB& other){
	this->count = other.count;

	this->surnames = new std::string[other.count];
	for (int i = 0; i < other.count; i++){
		this->surnames[i] = other.surnames[i];
	}

	this->salaries = new int[other.count];
	for (int i = 0; i < other.count; i++){
		this->salaries[i] = other.salaries[i];
	}
}

bool SalaryDB::deleteStaff(std::string staffName){
	bool f = false;

	int j = 0;
	for (; j < this->count; j++){
		if (staffName == *this->surnames){
			f = true;
			break;
		}
		this->surnames++;
	}
	this->surnames -= j;

	if (f){
		if (this->count == 1){
			this->count = 0;
			delete[] this->surnames;
			delete[] this->salaries;
			this->surnames = nullptr;
			this->salaries = nullptr;
		}
		else{
			deleteName(this->surnames, this->count, j);
			deleteSalary(this->salaries, this->count, j);
			this->count--;
		}
	}
	else{
		std::cout << "This staff is not in the database\n";
		return false;
	}

	return true;
}

void SalaryDB::outputInLimit(int minimum, int maximum){
	sortSalaryDataBase(*this);

	for (int i = 0; i < this->count; i++){
		if ((minimum <= this->salaries[i]) && (this->salaries[i] <= maximum)){
			std::cout << this->surnames[i] << ": " << this->salaries[i]  << " RUB" << std::endl;
		}
	}
}

SalaryDB& SalaryDB::operator=(SalaryDB other){
	if (this->surnames){
		delete[] this->surnames;
		delete[] this->salaries;
	}

	this->surnames = nullptr;
	this->salaries = nullptr;
	this->count = other.count;

	if (other.surnames){
		this->surnames = new std::string[other.count];
		for (int i = 0; i < other.count; i++){
			this->surnames[i] = other.surnames[i];
		}

		this->salaries = new int[other.count];
		for (int i = 0; i < other.count; i++){
			this->salaries[i] = other.salaries[i];
		}
	}

	return *this;
}

SalaryDB SalaryDB::operator+(SalaryDB other){
	int newCount = this->count + other.count;
	std::string* tempStaffName = new std::string[newCount];
	int* tempStaffSalary = new int[newCount];

	int i = 0;
	for (; i < this->count; i++){
		*tempStaffName = this->surnames[i];
		tempStaffName++;
	}
	for (; i < newCount; i++){
		*tempStaffName = *other.surnames;
		tempStaffName++;
	}

	i = 0;
	for (; i < this->count; i++){
		*tempStaffSalary = this->salaries[i];
		tempStaffSalary++;
	}
	for (; i < newCount; i++){
		*tempStaffSalary = *other.salaries;
		tempStaffSalary++;
	}
	tempStaffName -= newCount;
	tempStaffSalary -= newCount;

	SalaryDB Temp(newCount, tempStaffName, tempStaffSalary);

	return Temp;
}

SalaryDB& SalaryDB::operator+=(SalaryDB other){
	addNames(this->surnames, this->count, other.surnames, other.count);
	addSalarys(this->salaries, this->count, other.salaries, other.count);
	this->count += other.count;
	return *this;
}

SalaryDB& SalaryDB::operator[](std::string name){
	addName(this->surnames, this->count, name);
	expandingSalaryArr(this->salaries, this->count);
	this->count++;
	return *this;
}

bool SalaryDB::operator=(int salary){
	if (salary < minWage){
		deleteStaff(this->surnames[count - 1]);
		return false;
	}
	this->salaries[count - 1] = salary;
	return true;
}

bool SalaryDB::operator==(SalaryDB other){
	sortSalaryDataBase(*this);
	sortSalaryDataBase(other);
	if (this->count != other.count){
		return false;
	}

	for (int i = 0; i < count; i++){
		if (*this->surnames != *other.surnames || *this->salaries != *other.salaries){
			return false;
		}
		this->surnames++;
		this->salaries++;
		other.surnames++;
		other.salaries++;
	}
	this->surnames -= count;
	this->salaries -= count;
	other.surnames -= count;
	other.salaries -= count;

	return true;
}

bool SalaryDB::operator!=(SalaryDB other){
	return !(operator==(other));
}

std::ostream& operator<<(std::ostream& out, SalaryDB dataBase){
	sortSalaryDataBase(dataBase);
	for (int i = 0; i < dataBase.count; i++){
		out << dataBase.surnames[i] << ": " << dataBase.salaries[i] << " RUB" << std::endl;
	}
	return out;
}

SalaryDB& sortSalaryDataBase(SalaryDB& dataBase){
	for (int i = 0; i < dataBase.count; i++){
		for (int j = 0; j < dataBase.count - 1; j++){
			if (strcmp(dataBase.surnames[j].data(), dataBase.surnames[j + 1].data()) > 0){																				
				std::string TempString;												
				int TempInt;
				TempString = dataBase.surnames[j];
				TempInt = dataBase.salaries[j];
				dataBase.surnames[j] = dataBase.surnames[j + 1];
				dataBase.surnames[j + 1] = TempString;
				dataBase.salaries[j] = dataBase.salaries[j + 1];
				dataBase.salaries[j + 1] = TempInt;
			}
		}
	}
	return dataBase;
}
