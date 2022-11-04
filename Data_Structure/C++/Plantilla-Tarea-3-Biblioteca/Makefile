SRC_CORRE=	Elemento.cpp  \
			testi.cpp

OBJ_CORRE=	Elemento.o \
			testi.o

SRC=Elemento.cpp \
	Pila.cpp \

OBJ=Elemento.o \
	Pila.o

all:
	g++ -c ${SRC}
	g++ ${OBJ} main.cpp -g -o main
corre:
	g++ -c -g ${SRC_CORRE}
	g++ -g ${OBJ_CORRE} Pila.cpp -g -o corrector

