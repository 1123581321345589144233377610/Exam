a.exe: main.o SalaryDB.o func.o
	g++ main.o SalaryDB.o func.o

main.o: main.cpp
	g++ -c main.cpp

SalaryDB.o: SalaryDB.cpp SalaryDB.hpp
	g++ -c SalaryDB.cpp

func.o: func.cpp func.hpp
	g++ -c func.cpp

clean:
	del *.o a.exe

