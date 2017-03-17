OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o PilaIOParInt.o ParInt.o
	g++ -o program.exe program.o PilaIOParInt.o ParInt.o

ParInt.o:  ParInt.cc ParInt.hh 
	g++ -c ParInt.cc $(OPCIONS)

PilaIOParInt.o:  PilaIOParInt.cc PilaIOParInt.hh ParInt.hh 
	g++ -c PilaIOParInt.cc $(OPCIONS)

program.o: program.cc PilaIOParInt.hh ParInt.hh 
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
