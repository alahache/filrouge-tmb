SRC_DIR=src
INC_DIR=include
CC=g++
EXEC_NAME=zombie
INTERFACE = ../../librairie
INCLUDES=-I$(INC_DIR) -I$(INTERFACE)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopencv_core -lopencv_highgui 
OBJ_FILES = ZombieGame.o Main.o Interface.o GameSprite.o Game.o Camera.o AnimatedSprite.o Zombie.o Bombe.o Catapulte.o Explosion.o
OPT_CMP=-c -ggdb
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
	
Interface.o: $(INTERFACE)/Interface.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $(INTERFACE)/Interface.cpp
	
Main.o: $(SRC_DIR)/Main.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $(SRC_DIR)/Main.cpp

# Pattern de compilation des modules :
%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(OPT_CMP) $(INCLUDES) $<
