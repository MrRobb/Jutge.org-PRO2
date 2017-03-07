# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#
# Si en el directorio solo hay un proyecto y un makefile, para ejecutar este
# simplemente se escribe "make"
#
# Un makefile se compone de una serie de instrucciones con la estructura:
#
#           fichero1":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#
# Esto significa: para obtener el fichero1 es necesario que existan todos
# los ficheros de la lista; si no existe o es más antiguo que alguno de ellos,
# se obtiene o actualiza con la instruccion; si no existe alguno de los
# ficheros de la lista, el proceso acaba con error
# 
# Un makefile ha de contener todas las instrucciones que sean necesarias
# para obtener los .o y .exe del proyecto.
#
# Ejemplos:
#
# La siguiente instruccion significa:
# para obtener pro2_s8.exe es necesario que exista pro2_s8.o;
# si pro2_s8.exe no existe o es mas antiguo que pro2_s8.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
pro2_s8.exe: pro2_s8.o 
	g++ -o pro2_s8.exe pro2_s8.o $(OBJECTES)/{Cubeta.o,Prenda.o,Lavadora.o}
#
# La siguiente instruccion significa:
# para obtener pro2_s8.o es necesario que exista pro2_s8.cc;
# si pro2_s8.o no existe o es mas antiguo que pro2_s8.cc,
# se obtiene con el g++ -c ... 
#
pro2_s8.o: pro2_s8.cc
	g++ -c pro2_s8.cc -I$(INCLUSIONS)
#
# Realizad las modificaciones necesarias para gestionar las clases de la
# sesión cuando os toque implementarlas a vosotros.
#
# Esta última opción sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe
