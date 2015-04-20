/*
 * Board.cpp
 *
 *  Created on: 01.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Stack.h"
#include <cstddef>


using namespace std;

Board::Board() : width(8), height(5)
{
	int i = 0;
    int j = 0;
    field = new char[height*width];

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
        	field[i*width+j] = ' ';
        }
    }

    lastMoves = NULL;
}

Board::Board(int boardHeight,int boardWidth) :  width(boardWidth), height(boardHeight)
{
    int i = 0;
    int j = 0;
    field = new char[height*width];

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            field[i*width+j] = ' ';
        }
    }

    lastMoves = NULL;
}


void Board::resetBoard()
{
	int i = 0;
	int j = 0;

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			field[i*width+j] = ' ';
		}
	}

	delete lastMoves;
	lastMoves = NULL;

}

void Board::showBoard() const
{
	int i = 0;
	int j = 0;

	cout  << endl;

	for(i=0;i<height;i++)
	{
		cout << " ";
		for(j=0;j<width;j++)
		{
			cout << "| ";
			cout << field[i*width+j];
		}
		cout << "|";
		cout  << endl;
	}

	cout << " ";
	for(j=0;j<width;j++)
	{
		cout << "---";
	}
	cout  << endl;

	cout << "  ";
	for(j=0;j<width;j++)
	{
		cout << " " << j+1 << " ";
	}

	cout << "Last Move: ";
	lastMoves->print(lastMoves);
	cout  << endl;
}

bool Board::setStone(int selectedColumn,Player* active)
{

    int lastStoneColumn = selectedColumn;
    int lastStoneRow = -1; //the column may be full already so one has to check whether the first slot is free
    int i = 0;

    if(selectedColumn < 0 || selectedColumn >= width)
    {
    	cout << "Not allowed move: Out of Bounds!";
    	return false;
    }


    for(i=0;i<height;i++)
    {
        if(field[i*width+selectedColumn] == ' ')
        {
            lastStoneRow++;
        }
        else
        {
        	break;
        }
    }

	if(lastStoneRow >= 0)
	{
		lastMoves->push(lastMoves,selectedColumn);
		field[lastStoneRow*width+selectedColumn] = active->getColor();
		if(checkWon(lastStoneRow,lastStoneColumn,active->getColor()))
		{
			showBoard();
			active->win();
			cout << "Player " << active->getName() <<" has won. Congratulations!" << endl;
			resetBoard();
			return true;

		}

		if(checkFull())
		{
			showBoard();
			cout << "The board is full and noone has won. It's a draw" << endl;
			resetBoard();
			return true;
		}
		return false;

	}
	else
	{
		cout << "Unallowed move: Column is full" << endl;
		return false;
	}

}


int Board::pcTry(int selectedColumn,char color) const
{
    int lastStoneRow = -1; //the column may be full already so one has to check whether the first slot is free
    int i = 0;


    for(i=0;i<height;i++)
    {
        if(field[i*width+selectedColumn] == ' ')
        {
            lastStoneRow++;
        }
        else
        {
        	break;
        }
    }

    return lastStoneRow;

}



bool Board::checkWon(int lastStoneRow,int lastStoneColumn,char color) const
{
	int checkSum[4];
	checkSum[0] = check(0, -1, lastStoneRow, lastStoneColumn -1, color) + 1 + check(0, 1, lastStoneRow, lastStoneColumn + 1, color);
	checkSum[1] = 1 + check(1, 0, lastStoneRow + 1, lastStoneColumn, color);
	checkSum[2] = check(-1, -1, lastStoneRow - 1, lastStoneColumn - 1, color) + 1 + check(1, 1, lastStoneRow + 1, lastStoneColumn + 1, color);
	checkSum[3] = check(-1, 1, lastStoneRow - 1, lastStoneColumn + 1, color) + 1 + check(1, -1, lastStoneRow + 1, lastStoneColumn - 1, color);

	for(int i : checkSum)
	{
		if(i>=4)
		{

			return true;
		}
	}
	return false;

}



int Board::check(int dirRow, int dirCol, int row, int col, char color)  const
{
	if(row<0 || row>=height || col<0 || col>=width)
	{
		return 0;
	}

	if(field[row*width+col] == color)
	{
		return 1 + check(dirRow, dirCol, row + dirRow, col + dirCol, color);
	}
	else
	{
		return 0;
	}
}

bool Board::checkFull()const
{
	int i = 0;

	for(i=0;i<width;i++)  //one has to check only the highest row
	{
			if(field[i] == ' ')
			{
				return false;
			}
	}

	return true;
}

bool Board::checkMove(int column) const
{
	if(column >= width || column < 0)
	{
		return false;
	}
	if(field[column] != ' ')
	{
		return false;
	}
	return true;
}

Board::~Board()
{
    delete[] field;
    delete lastMoves;
}


