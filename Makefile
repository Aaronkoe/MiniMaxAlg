GCC=g++

main: Othello.o AbstractGame.o
	$(GCC) main.cpp Othello.o AbstractGame.o

Othllo.o:
	$(GCC) -c Othello.cpp

AbstractGame.o:
	$(GCC) -c AbstractGame.cpp
