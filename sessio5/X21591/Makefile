OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialize -Wno-sign-compare -std=c++11

program.exe: program.o CuaIOEstudiant.o Estudiant.o
	g++ -o program.exe program.o CuaIOEstudiant.o Estudiant.o

Estudiant.o:  Estudiant.cc Estudiant.hh 
	g++ -c Estudiant.cc $(OPCIONS)

CuaIOEstudiant.o: CuaIOEstudiant.cc CuaIOEstudiant.hh
	g++ -c CuaIOEstudiant.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
