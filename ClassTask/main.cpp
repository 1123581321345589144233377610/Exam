#include "SalaryDB.hpp"

int main(){
    SalaryDB db;
    db["Аносов"] = 31000;
    db["Иванов"] = 20000;
    db["Петров"] = 14000;
    db["Сидоров"] = 30000;

    std::cout << "Сотрудники:\n" << db;

    std::cout << "Сотрудники с окладом от 20000 до 30000:\n";
    db.outputInLimit(20000, 30000);
    std::cout << "db == db: " << (db == db) << "\n";
    std::cout << "db != db: " << (db != db) << "\n";
    SalaryDB db1;
    db1["Щукин"] = 900000;
    db1["Якин"] = 777777;
    SalaryDB db2;
    db2 += db;
    std::cout << "db2 += db:\n" << db2 << "\n";
    db2 += db1;
    std::cout << "db2 += db1:\n" << db2 << "\n";
    return EXIT_SUCCESS;
}
