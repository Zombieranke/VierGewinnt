/*
 * GameManager.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include <iostream>
#include <string>
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
	int numberOfPlayers;
	std::string tempPlayerName = "";
	char tempColor = ' ';

	std::cout << "           WELCOME TO CONNECTFOUR!" << std::endl;
	std::cout << "            GAME OF THE YEAR 1922" << std::endl;
	std::cout << "*****************************************************" << std::endl;
	std::cout << "How many human players do you wish to have?\nPlease enter the number here: ";
	std::cin >> numberOfPlayers;
	std::cout << std::endl;
	while(numberOfPlayers < 0 || numberOfPlayers > 2)
	{
		std::cout << "ConnectFour is a game for two players, please enter a value between 0 and 2 for the number of human players who participate: ";
		std::cin >> numberOfPlayers;
		std::cout << std::endl;
	}

	if(numberOfPlayers > 0)
	{
		std::cout << "Player 1, please enter your name: " << std::endl;
		std::cin >> tempPlayerName;
		std::cout << std::endl;

		std::cout << "Which symbol would you like to use for your pieces?" << std::endl << "Enter one here: " << std::endl;
		std::cin >> tempColor;
		std::cout << std::endl;

		while(tempColor == '.' || tempColor == ' ')
		{
			std::cout << "This symbol is not available. Please choose another one: " << std::endl;
			std::cin >> tempColor;
			std::cout << std::endl;
		}

		Human* p1 = Player(tempPlayerName,tempColor);

			std::cout << p1->getName() <<" has chosen " << p1->getColor() << "." << std::endl;

		if(numberOfPlayers == 2)
		{
			std::cout << "Player 2, please enter your name: " << std::endl;
			std::cin >> tempPlayerName;
			std::cout << std::endl;

			std::cout << "Which symbol would you like to use for your pieces?" << std::endl << "Enter one here: " << std::endl;
			std::cin >> tempColor;
			std::cout << std::endl;


			while(tempColor == p1->getColor() || tempColor == '.' || tempColor == ' ')
			{
				std::cout << "This symbol is not available. Please choose another one: " << std::endl;
				std::cin >> tempColor;
				std::cout << std::endl;
			}

			Human* p2 = Player(tempPlayerName, tempColor);

			std::cout << p2->getName() <<" has chosen " << p2->getColor() << "." << std::endl;

		}
		else
		{
			ComputerPlayer* c1 = new ComputerPlayer();

			std::cout << c1->getName() <<" has chosen " << c1->getColor() << "." << std::endl;

		}
	}
	else
	{
		ComputerPlayer* c1 = new ComputerPlayer();

		std::cout << c1->getName() <<" has chosen " << c1->getColor() << "." << std::endl;

		ComputerPlayer* c2 = new ComputerPlayer();

		std::cout << c2->getName() <<" has chosen " << c2->getColor() << "." << std::endl;
	}


}
