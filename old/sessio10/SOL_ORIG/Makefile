pro2.exe: pro2.o Sistema.o Organismo.o Celula.o
	g++ -o pro2.exe *.o 

Sistema.o: Sistema.cc Sistema.hh Organismo.hh
	g++ -c Sistema.cc -I$(INCLUSIONS)

Organismo.o: Organismo.cc Organismo.hh Celula.hh
	g++ -c Organismo.cc -I$(INCLUSIONS)

Celula.o: Celula.cc Celula.hh
	g++ -c Celula.cc -I$(INCLUSIONS)

pro2.o: pro2.cc Sistema.hh Organismo.hh
	g++ -c pro2.cc -I$(INCLUSIONS)

clean:
	rm *.o
	rm *.exe
