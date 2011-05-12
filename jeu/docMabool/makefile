CC = g++
EXEC_NAME = exe
INCLUDES = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES = main.cpp SMB.h SMB.cpp
OPT_CMP=-c
OPT_EDL=-o

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OPT_EDL) $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(OPT_CMP) $(INCLUDES) $<
