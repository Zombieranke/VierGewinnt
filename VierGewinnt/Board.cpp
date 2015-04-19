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
}

bool Board::setStone(int selectedColumn,Player* active)
{

    int lastStoneColumn = selectedColumn;
    int lastStoneRow = -1; //the column may be full already so one has to check whether the first slot is free
    int i = 0;


    for(i=0;i<height;i++)
    {
        if(field[i*width+selectedColumn] == ' ')
        {
            lastStoneRow++;
        }
    }

    if(lastStoneRow >= 0)
    {
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


bool Board::checkWon(int lastStoneRow,int lastStoneColumn,Player* active) const
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
            if(field[lastStoneRow*width+i] == active->getColor())
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
    	if(field[i*width+lastStoneColumn] == active->getColor())
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
            if(field[j*width+i] == active->getColor())
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
            if(field[j*width+i] == active->getColor())
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
	return true;
}

Board::~Board()
{
    delete[] field;
}


