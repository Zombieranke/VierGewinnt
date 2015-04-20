
CC=g++
CFLAGS=-std=c++11 -Wall -O

all: VierGewinnt

VierGewinnt: GameManager.o Player.o ComputerPlayer.o HumanPlayer.o Board.o Stack.o
	${CC} ${CFLAGS} -o VierGewinnt GameManager.o Player.o ComputerPlayer.o HumanPlayer.o Board.o Stack.o

GameManager.o: GameManager.cpp Player.h ComputerPlayer.h HumanPlayer.h Board.h
	${CC} ${CFLAGS} -c -o GameManager.o GameManager.cpp

Player.o: Player.cpp Player.h
	${CC} ${CFLAGS} -c -o Player.o Player.cpp

ComputerPlayer.o: ComputerPlayer.cpp ComputerPlayer.h Player.h
	${CC} ${CFLAGS} -c -o ComputerPlayer.o ComputerPlayer.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h Player.h
	${CC} ${CFLAGS} -c -o HumanPlayer.o HumanPlayer.cpp

Board.o: Board.cpp Board.h Player.h Stack.h
	${CC} ${CFLAGS} -c -o Board.o Board.cpp

Stack.o: Stack.cpp Stack.h
	${CC} ${CFLAGS} -c -o Stack.o Stack.cpp

clean:
	rm -f GameManager.o Player.o ComputerPlayer.o HumanPlayer.o Board.o Stack.o GameManager