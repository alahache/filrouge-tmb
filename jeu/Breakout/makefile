BreakOut: BreakOut.o Main.o Interface.o
	g++ -o BreakOut BreakOut.o Main.o Interface.o -lsfml-graphics -lsfml-window -lsfml-system

BreakOut.o: BreakOut.cpp BreakOut.h
	g++ -c BreakOut.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

Interface.o: Interface.cpp Interface.h
	g++ -c Interface.cpp

clean:
	rm *.o

