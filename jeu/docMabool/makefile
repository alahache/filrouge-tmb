CC=g++
EXEC_NAME=docMabool
INTERFACE = ../../librairie
INCLUDES=-I$(INTERFACE)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopencv_core -lopencv_highgui 
OBJ_FILES = main.o Interface.o SMB.o
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
	
Main.o: main.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) main.cpp

# Pattern de compilation des modules :
%.o:%.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $<
