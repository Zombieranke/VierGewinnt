/*
 * GameManager.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include <iostream>
#include "Board.h"
#include "Player.h"


int menu(int &numberOfRounds);

int main()
{

	int numberOfRounds = 0;

	int gameState = menu(&numberOfRounds);

	while(gameState > 0)
	{
		gameState = menu(&numberOfRounds);

		if(gameState == 2)
		{
			for(;numberOfRounds>0;numberOfRounds--)
			{
				playHumanVersusHuman;
			}
		}

		if(gameState == 3)
		{
			for(;numberOfRounds>0;numberOfRounds--)
			{
				playHumanVersusAI;
			}
		}


		if(gameState == 4)
		{
			for(;numberOfRounds>0;numberOfRounds--)
			{
				playAIVersusAI;
			}
		}


	}


}


int menu(int &numberOfRounds)
{
	int playerNumber;

	std::cout << "           WELCOME TO CONNECTFOUR!\n";
	std::cout << "            GAME OF THE YEAR 1922\n";
	std::cout << "*****************************************************\n";
	std::cout << "How many human players do you wish to have?\nPlease enter the number here: ";
	std::cin >> playerNumber;


}
