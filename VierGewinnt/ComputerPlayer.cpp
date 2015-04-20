/*
 * ComputerPlayer.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Christine
 */
#include "ComputerPlayer.h"
#include "Board.h"
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <math.h>
using namespace std;

ComputerPlayer::ComputerPlayer(const char &otherPlayerColor) :Player()
{
	name = "Marvin";
	playerColor = 'x';
	this->otherPlayerColor = otherPlayerColor;

}

ComputerPlayer::ComputerPlayer(int number) :Player()
{
	if(number == 1)
	{
		name = "Marvin";
		playerColor = 'x';
		otherPlayerColor = 'o';
	}
	else if(number == 2)
	{
		name = "Peter";
		playerColor = 'o';
		otherPlayerColor = 'x';
	}
}


ComputerPlayer::ComputerPlayer(const string &name, const char &color, const char &otherPlayerColor)
{
	this->name = name;
	this->playerColor = color;
	this->otherPlayerColor = otherPlayerColor;
}


int ComputerPlayer::makeMove(Board * board) const
{
	bool canWin = false; //if he can win everything stops immediately
	bool wouldLose = false; //if he would lose he will defend on the very same spot instead of using any algorithm

	int i = 0;
	int lastStoneRow = 0;

	for(i=0; i < board->width;i++)
	{
		if(board->checkMove(i))
		{
			lastStoneRow = board->pcTry(i,playerColor);
			if(lastStoneRow >=0)
			{
				canWin = board->checkWon(lastStoneRow,i,playerColor);
			}

			if(canWin)
			{
				return i;
			}
		}
	}

	for(i=0; i < board->width;i++)
	{
		if(board->checkMove(i))
		{
			lastStoneRow = board->pcTry(i,otherPlayerColor);
			if(lastStoneRow >=0)
			{
				wouldLose = board->checkWon(lastStoneRow,i,otherPlayerColor);
			}

			if(wouldLose)
			{
				return i;
			}
		}
	}

	int myMove = -1;	// -1 instead of 0 as 0 is a valid column
	int lastMove = -1;	// -1 instead of 0 as 0 is a valid column
	int secondLastMove = -1;  // -1 instead of 0 as 0 is a valid column
	int differenceBetweenMoves = 0;

	if(board->lastMoves != NULL)
	{
		lastMove = board->lastMoves->value;

		if(board->lastMoves->next != NULL && board->lastMoves->next->next != NULL)
		{
			secondLastMove = board->lastMoves->next->next->value;
		}
	}


	//*** ALGORITHM STARTS HERE ***

	if(lastMove == -1)
	{
		myMove = (int) floor(board->width/2);
		return myMove;
	}
	else
	{
		if(secondLastMove == -1)
		{
			myMove = lastMove;
			return myMove;
		}
		else
		{
			differenceBetweenMoves = lastMove - secondLastMove;
			if(abs(differenceBetweenMoves) == 1)
			{
				myMove = lastMove + differenceBetweenMoves;
				if(board->checkMove(myMove))
				{
					return myMove;
				}
				else
				{
					myMove = lastMove;
					if(board->checkMove(myMove))
					{
						return myMove;
					}
					else
					{
						myMove = secondLastMove;
						if(board->checkMove(myMove))
						{
							return myMove;
						}
						else
						{
							for(i=0;i<board->width;i++)
							{
								myMove = i;
								if(board->checkMove(myMove))
								{
									return myMove;
								}
							}
						}
					}
				}

			}
			else if(abs(differenceBetweenMoves) == 2)
			{
				myMove = secondLastMove + differenceBetweenMoves/2;
				if(board->checkMove(myMove))
				{
					return myMove;
				}
				else
				{
					myMove = lastMove;
					if(board->checkMove(myMove))
					{
						return myMove;
					}
					else
					{
						myMove = secondLastMove;
						if(board->checkMove(myMove))
						{
							return myMove;
						}
						else
						{
							for(i=0;i<board->width;i++)
							{
								myMove = i;
								if(board->checkMove(myMove))
								{
									return myMove;
								}
							}
						}
					}
				}
			}
			else
			{

				myMove = lastMove;
				if(board->checkMove(myMove))
				{
					return myMove;
				}

				myMove = secondLastMove;

				if(board->checkMove(myMove))
				{
					return myMove;
				}

				for(i = 0; i<board->width; i++)
				{
					myMove = i;
					if(board->checkMove(myMove))
					{
						return myMove;
					}
				}
			}
		}
	}

	// *** END OF ALGORITHM ***

	cerr << "Algorithm did not work properly" << endl;
	return -1;
}

ComputerPlayer::~ComputerPlayer()
{}


