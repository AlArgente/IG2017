# fichero Makefile
#

INCLUDE = include
SRC = src
BIN = bin
OBJ = obj

# nombre del fichero ejecutable
#
TARGETS= practica2

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I/usr/include -I$(INCLUDE)
CXXFLAGS=  -g -I/usr/include -std=c++11 -I$(INCLUDE) 

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++ -O2

# definicion de objetos
#
OBJECTS= $(OBJ)/practica2.o $(OBJ)/escena.o $(OBJ)/ejes.o $(OBJ)/tetraedro.o $(OBJ)/cubo.o $(OBJ)/object3d.o
# orden que sera ejecutada por defecto
#

OBJECTSC++ = $(SRC)/object3d.cc $(SRC)/cubo.cc $(SRC)/tetraedro.cc $(SRC)/escena.cc $(SRC)/ejes.cc $(SRC)/practica2.cc $(SRC)/piramide.cc $(SRC)/octaedro.cc $(SRC)/prismahex.cc $(SRC)/file_ply_stl.cc $(SRC)/plyobject.cc $(SRC)/objectperfil.cc

default: $(BIN)/$(TARGETS)

# regla de ejecucion
#
#$(TARGETS) : $(OBJ)/$(OBJECTS)
#	$(CC) -o $(BIN)/$@ $(CXXFLAGS) $(OBJ)/$(OBJECTS) $(LDFLAGS)


$(BIN)/$(TARGETS): 
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTSC++) $(LDFLAGS)

#$(BIN)/$(TARGETS):
#	$(CC) -o $@ $(CXXFLAGS) $(SRC)/object3d.cc $(SRC)/cubo.cc $(SRC)/tetraedro.cc $(SRC)/escena.cc $(SRC)/ejes.cc $(SRC)/practica1.cc $(LDFLAGS)


#
#
clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/$(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f $(OBJ)/*.o
	rm *~
	rm -f $(BIN)/$(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(BIN)/$(TARGETS)
	tar -zcvf $(BIN)/$(TARGETS).tgz *
