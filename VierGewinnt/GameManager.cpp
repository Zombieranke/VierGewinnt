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
#include "Menu.h"


int main()
{

	int numberOfBotGames = 0;
	bool playAgain = false;

	int gameState = Menu(&numberOfBotGames);

	while(gameState > 0)
	{
		if(playAgain == false && numberOfBotGames <= 0)
		{
			gameState = Menu(&numberOfBotGames);
		}


		if(gameState == 2)
		{
			playAgain = playHumanVersusHuman
		}


		if(gameState == 3)
		{
			playAgain = playHumanVersusAI
		}


		if(gameState == 4)
		{
			for(;numberOfBotGames>0;numberOfBotGames--)
			{
				playAIVersusAI
			}
			playAgain = false;
		}


	}
}
