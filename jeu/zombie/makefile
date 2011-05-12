SRC_DIR=src
INC_DIR=include
CC=g++
EXEC_NAME=zombie
INCLUDES=-I $(INC_DIR)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES = ZombieGame.o Main.o Interface.o GameSprite.o Game.o AnimatedSprite.o
OPT_CMP=-c
OPT_EDL=-o

# Lancement de la chaîne de compilation :
all: $(EXEC_NAME)

# Nettoyage des fichiers .o ainsi que de l'exécutable :
mrproper: clean
	rm $(EXEC_NAME)

# Nettoyage des fichiers .o :
clean:
	rm $(OBJ_FILES)

# Edition des liens :
$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OPT_EDL) $(EXEC_NAME) $(OBJ_FILES) $(LIBS)
	
Main.o: $(SRC_DIR)/Main.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $(SRC_DIR)/Main.cpp

# Pattern de compilation des modules :
%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(OPT_CMP) $(INCLUDES) $<
