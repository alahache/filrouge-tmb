CC = g++
EXEC_NAME = BreakOut
INCLUDES = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
OBJ_FILES = BreakOut.o Main.o Interface.o Balle.o GameSprite.o Game.o Barre.o Brique.o
OPT_CMP=-c -Wall -Werror -pedantic
OPT_EDL=-Wall -Werror -pedantic -o

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OPT_EDL) $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $<
