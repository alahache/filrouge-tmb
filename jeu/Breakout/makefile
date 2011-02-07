OPT_CMP=-c
OPT_EDL=-o

BreakOut: BreakOut.o Main.o Interface.o Balle.o
	g++ $(OPT_EDL) BreakOut BreakOut.o Main.o Interface.o Balle.o -lsfml-graphics -lsfml-window -lsfml-system

BreakOut.o: BreakOut.cpp BreakOut.h
	g++ $(OPT_CMP) BreakOut.cpp

Main.o: Main.cpp
	g++ $(OPT_CMP) Main.cpp

Interface.o: Interface.cpp Interface.h
	g++ $(OPT_CMP) Interface.cpp
	
Balle.o: Balle.cpp Balle.h
	g++ $(OPT_CMP) Balle.cpp

clean:
	rm *.o

