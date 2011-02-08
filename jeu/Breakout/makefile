OPT_CMP=-c
OPT_EDL=-o

BreakOut: BreakOut.o Main.o Interface.o Balle.o GameSprite.o Game.o Barre.o
	g++ $(OPT_EDL) BreakOut Main.o Game.o GameSprite.o BreakOut.o Interface.o Balle.o Barre.o -lsfml-graphics -lsfml-window -lsfml-system

BreakOut.o: BreakOut.cpp BreakOut.h
	g++ $(OPT_CMP) BreakOut.cpp

Main.o: Main.cpp
	g++ $(OPT_CMP) Main.cpp

Interface.o: Interface.cpp Interface.h
	g++ $(OPT_CMP) Interface.cpp
	
Balle.o: Balle.cpp Balle.h
	g++ $(OPT_CMP) Balle.cpp

Barre.o: Barre.cpp Barre.h
	g++ $(OPT_CMP) Barre.cpp
	
Game.o: Game.cpp Game.h
	g++ $(OPT_CMP) Game.cpp	
	
GameSprite.o: GameSprite.cpp GameSprite.h
	g++ $(OPT_CMP) GameSprite.cpp	

clean:
	rm *.o

