OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

pro2.exe: pro2.o Sistema.o Organismo.o Celula.o
	g++ -o pro2.exe *.o 

Sistema.o: Sistema.cc Sistema.hh Organismo.hh
	g++ -c Sistema.cc $(OPCIONS) -I$(INCLUSIONS)

Organismo.o: Organismo.cc Organismo.hh Celula.hh
	g++ -c Organismo.cc $(OPCIONS) -I$(INCLUSIONS)

Celula.o: Celula.cc Celula.hh
	g++ -c Celula.cc $(OPCIONS) -I$(INCLUSIONS)

pro2.o: pro2.cc Sistema.hh Organismo.hh
	g++ -c pro2.cc $(OPCIONS) -I$(INCLUSIONS)

clean:
	rm *.o
	rm *.exe
