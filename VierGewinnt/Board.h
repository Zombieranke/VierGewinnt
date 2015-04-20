/*
 * Board.h
 *
 *  Created on: 01.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */


#ifndef BOARD_H_
#define BOARD_H_

#include "Stack.h"

class Player;

class Board
{
	friend class ComputerPlayer;

public:
	bool setStone(int selectedColumn, Player * active);
	int pcTry(int selectedColumn, char color);
	bool checkWon(int lastStoneRow,int lastStoneColumn,char color) const;
	void undo(int selectedColumn);
	void showBoard() const;
	bool checkMove(int column) const;
	Board();
	Board(int boardHeight, int boardWidth);
	~Board();

private:
	bool checkWon(int lastStoneRow,int lastStoneColumn,Player * active) const;
	int check(int dirRow, int dirCol, int row, int col, Player * active) const;
	bool checkFull() const;
	const int width;
	const int height;
	char * field;
	void resetBoard();
	Stack* lastMoves;
};

#endif /* BOARD_H_ */
