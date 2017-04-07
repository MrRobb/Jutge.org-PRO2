# MAKEFILE: emplearemos esta utilidad para preparar ejecutables en los que 
# intervienen varias clases, de forma que con una unica instruccion 
# se compilan o linkan los ficheros estrictamente necesarios.
#
# Si en el directorio solo hay un proyecto y un makefile, para ejecutar este
# simplemente se escribe "make"
#
# Nuestros makefile se componen de una creación de variables seguida de
# una serie de instrucciones con la estructura:
#
#           fichero1":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#
#           fichero2":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#        
#           etc
#
# Esto significa: para obtener el fichero1 es necesario que existan todos
# los ficheros de su lista; si no existe o es más antiguo que alguno de
# ellos, se obtiene o actualiza con su instruccion; si no existe alguno de
# los ficheros de la lista, el proceso acaba con error; lo mismo para el
# fichero2, etc
# 
# Mediante este esquema, cada uno de nuestros makefile ha de contener todas
# las instrucciones que sean necesarias para obtener los .o y .exe del
# proyecto correspondiente.
#
# Ejemplos:
#
# La siguiente instruccion define una variable de entorno local, para compilar
# con las opciones habituales: 
#
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
#
# La siguiente instruccion significa:
# para obtener pro2_s8.exe es necesario que exista pro2_s8.o;
# si pro2_s8.exe no existe o es mas antiguo que pro2_s8.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
pro2_s8.exe: pro2_s8.o 
	g++ -o pro2_s8.exe pro2_s8.o /Users/Roberto/Documents/School/Universidad/Year1/Q2/PRO2/Jutge.org-PRO2/objectes/{Cubeta.o,Prenda.o,Lavadora.o}
#
# La siguiente instruccion significa:
# para obtener pro2_s8.o es necesario que exista pro2_s8.cc;
# si pro2_s8.o no existe o es mas antiguo que pro2_s8.cc,
# se obtiene con el g++ -c ... 
#
pro2_s8.o: pro2_s8.cc
	g++ -c pro2_s8.cc $(OPCIONS) -I$ /Users/Roberto/Documents/School/Universidad/Year1/Q2/PRO2/Jutge.org-PRO2/inclusions
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
