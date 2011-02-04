BreakOut: BreakOut.o Main.o Interface.o Balle.o
	g++ -o BreakOut BreakOut.o Main.o Interface.o Balle.o -lsfml-graphics -lsfml-window -lsfml-system

BreakOut.o: BreakOut.cpp BreakOut.h
	g++ -c BreakOut.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

Interface.o: Interface.cpp Interface.h
	g++ -c Interface.cpp
	
Balle.o: Balle.cpp Balle.h
	g++ -c Balle.cpp

clean:
	rm *.o

