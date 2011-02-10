CC = g++
CFLAGS = -Wall
EXEC_NAME = BreakOut
INCLUDES = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopencv_core -lopencv_highgui 
OBJ_FILES = Balle.o Interface.o Main.o BreakOut.o

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
