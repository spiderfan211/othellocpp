SRC = src
INC = include
OBJ = obj
BIN = ./bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -I./$(INC) -c

#*******************All***************************************

all: $(OBJ) $(BIN) othello

#*****************Compilación de módulos**********************
$(OBJ)/Jugador.o: $(SRC)/Jugador.cpp $(INC)/Jugador.h
	$(CXX) $(CPPFLAGS) $(SRC)/Jugador.cpp -o $@

$(OBJ)/Tablero.o: $(SRC)/Tablero.cpp $(INC)/Tablero.h
	$(CXX) $(CPPFLAGS) $(SRC)/Tablero.cpp -o $@

$(OBJ)/Clasematriz.o: $(SRC)/Clasematriz.cpp $(INC)/Clasematriz.h
	$(CXX) $(CPPFLAGS) $(SRC)/Clasematriz.cpp -o $@

$(OBJ)/othello.o : $(SRC)/othello.cpp $(INC)/Jugador.h $(INC)/Tablero.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/othello.o $(SRC)/othello.cpp

othello: $(OBJ)/othello.o $(OBJ)/Jugador.o $(OBJ)/Clasematriz.o $(OBJ)/Tablero.o
	$(CXX) -g -o $(BIN)/othello $(OBJ)/othello.o $(OBJ)/Jugador.o $(OBJ)/Clasematriz.o $(OBJ)/Tablero.o

#************Creación de directorios**************************

$(OBJ):
		mkdir obj

$(BIN):
		mkdir bin

# ******************Limpieza**********************************
clean :
	-rm  $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
