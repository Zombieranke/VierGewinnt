/*
 * Board.cpp
 *
 *  Created on: 01.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include <iostream>
#include "Board.h"

const int Board::width = 8;
const int Board::height = 5;

Board::Board()
{
    int i = 0;
    int j = 0;
    field = new char[height][width];

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            field[i][j] = '.';
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
			field[i][j] = '.';
		}
	}
}

void const Board::showBoard()
{
	int i = 0;
	int j = 0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			cout << image[i][j];
		}
		cout  << endl;
	}
}

void Board::setStone(int selectedColumn,Player* active)
{
    int lastStoneColumn = selectedColumn;
    int lastStoneRow = -1; //the column may be full already so one has to check whether the first slot is free
    int i = 0;


    for(i=0;i<height;i++)
    {
        if(field[i][selectedColumn] == '.')
        {
            lastStoneRow++;
        }
    }

    if(lastStoneRow >= 0)
    {
        field[lastStoneRow][selectedColumn] = active->playerColor;
        if(checkWon(lastStoneRow,lastStoneColumn,Player* active))
        {
        	active->winCount++;
        	std::cout << "Player " << active->name <<" has won. Congratulations!" << std::endl;
        	resetBoard();
        	return;

        }
        if(checkFull())
        {
        	std::cout << "The board is full and noone has won. It's a draw" << std::endl;
        	resetBoard();
        }

    }
    else
    {
    	std::cerr << "Unallowed move: Column is full" << std::endl;
    }


}

bool const Board::checkWon(int lastStoneRow,int lastStoneColumn,Player* active)
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
            if(field[lastStoneRow][i] == active->playerColor)
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

    for(i=lastStoneRow-3;i<height && i <= (lastStoneRow+3);i++) //column check
    {
        if(i<=-1)
        {
            i = -1;
            continue;
        }
        else
        {
            if(field[i][lastStoneColumn] == active->playerColor)
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
            if(field[j][i] == active->playerColor)
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
            if(field[j][i] == active->playerColor)
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

bool const Board::checkFull()
{
	int i = 0;
	int j = 0;

	for(i=0;i<width;i++)  //one has to check only the highest row
	{
			if(field[0][i] == '.')
			{
				return false;
			}
	}

	return true;
}

Board::~Board()
{
    delete[] field;
}

















