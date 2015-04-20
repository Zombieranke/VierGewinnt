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
    	cerr << "Not allowed move: Out of Bounds!";
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
		if(checkWon(lastStoneRow,lastStoneColumn,active))
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
		cerr << "Unallowed move: Column is full" << endl;
		return false;
	}

}


int Board::pcTry(int selectedColumn,char color)
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

    field[lastStoneRow*width+selectedColumn] = color;

    return lastStoneRow;

}


void Board::undo(int selectedColumn)
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
    lastStoneRow++;

    field[lastStoneRow*width+selectedColumn] = ' ';
}


bool Board::checkWon(int lastStoneRow,int lastStoneColumn,Player* active) const
{
	int checkSum[4];
	checkSum[0] = check(0, -1, lastStoneRow, lastStoneColumn -1, active) + 1 + check(0, 1, lastStoneRow, lastStoneColumn + 1, active);
	checkSum[1] = 1 + check(1, 0, lastStoneRow + 1, lastStoneColumn, active);
	checkSum[2] = check(-1, -1, lastStoneRow - 1, lastStoneColumn - 1, active) + 1 + check(1, 1, lastStoneRow + 1, lastStoneColumn + 1, active);
	checkSum[3] = check(-1, 1, lastStoneRow - 1, lastStoneColumn + 1, active) + 1 + check(1, -1, lastStoneRow + 1, lastStoneColumn - 1, active);

	for(int i : checkSum)
	{
		if(i>=4)
		{

			return true;
		}
	}
	return false;

}


bool Board::checkWon(int lastStoneRow,int lastStoneColumn,char color) const
{
	int i = 0;
    int j = 0;
    int rowCount = 0;		//actually one variable would be enough but i decided to have matching names
    int columnCount = 0;
    int diagonalCount = 0;

    for(i=lastStoneColumn-3;i<width && i <= (lastStoneColumn+3);i++) //row check
    {
        if(i<=-1)
        {
            i = -1;
            continue;
        }
        else
        {
            if(field[lastStoneRow*width+i] == color)
            {
                rowCount++;
                if(rowCount == 4)
                {
                    return true;
                }
            }
            else
            {
                rowCount = 0;
            }
        }
    }

    for(i=lastStoneRow;i<height && i <= (lastStoneRow+3);i++) //column check
    {
    	if(field[i*width+lastStoneColumn] == color)
    	{
    		columnCount++;
    		if(columnCount == 4)
    		{
    			return true;
    		}
    	}
    	else
    	{
    		columnCount = 0;
    	}

    }


    j = lastStoneRow-4; //it's minus 4 because it's immediately incremented in the first loop cycle

    for(i=lastStoneColumn-3;i<width && i <= (lastStoneColumn+3);i++) //the top-left to bottom-right diagonal is checked here
    {
        j++;
        if(i <= -1)
        {
            continue;
        }
        else
        {
            if(field[j*width+i] == color)
            {
                diagonalCount++;
                if(diagonalCount >= 4)
                {
                    return true;
                }
            }
            else
            {
                diagonalCount = 0;
            }
        }
    }



    j = lastStoneRow+4; //it's plus 4 because it's immediately decremented in the first loop cycle

    for(i=lastStoneColumn-3;i<width && i <= (lastStoneColumn+3);i++) //the bottom-left to top-right diagonal is checked here
    {
        j--;
        if(i <= -1)
        {
            continue;
        }
        else
        {
            if(field[j*width+i] == color)
            {
                diagonalCount++;
                if(diagonalCount >= 4)
                {
                    return true;
                }
            }
            else
            {
                diagonalCount = 0;
            }
        }
    }
    return false;

}

int Board::check(int dirRow, int dirCol, int row, int col, Player * active)  const
{
	if(row<0 || row>=height || col<0 || col>=width)
	{
		return 0;
	}

	if(field[row*width+col] == active->getColor())
	{
		return 1 + check(dirRow, dirCol, row + dirRow, col + dirCol, active);
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
	if(column > width || column < 0)
	{
		cout << "Unallowed move: column out of range" << endl;
		return false;
	}
	if(field[column] != ' ')
	{
		cout << "The chosen column is full. Please select another column" << endl;
		return false;
	}
	return true;
}

Board::~Board()
{
    delete[] field;
}


