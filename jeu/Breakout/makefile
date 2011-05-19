CC = g++
INTERFACE = ../../librairie
EXEC_NAME = BreakOut
INCLUDES = -I$(INTERFACE)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopencv_core -lopencv_highgui 
OBJ_FILES = BreakOut.o Main.o Balle.o GameSprite.o Game.o Barre.o Brique.o Interface.o
OPT_CMP=-c -Wall -Werror -pedantic
OPT_EDL=-Wall -Werror -pedantic -o

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OPT_EDL) $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

Interface.o: $(INTERFACE)/Interface.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $(INTERFACE)/Interface.cpp

%.o: %.cpp
	$(CC) $(OPT_CMP) -I $(INTERFACE) $<
