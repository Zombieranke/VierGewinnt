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
#include "HumanPlayer.h"
#include "Computerplayer.h"



int menu(Player * &p1, Player * &p2);

int main()
{
	int i = 0;
	int numberOfRounds = 0;

	Player * players[2];
	Player * activePlayer;
	Board * board = new Board();


	int numberOfRounds = menu(players[0], players[1]);

	for(i = 0; i<numberOfRounds; i++)
	{
		bool over = false;
		int turn = 0;
		while(!over)
		{
			activePlayer = players[turn];
			turn = (turn + 1) % 2;
			over = board->setStone(activePlayer->makeMove(board), activePlayer);
		}


	}


}


int menu(Player * &p1, Player * &p2)
{
	int numberOfRounds = 1;
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

		p1 = new HumanPlayer(tempPlayerName,tempColor);

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

			p2 = HumanPlayer(tempPlayerName, tempColor);

			std::cout << p2->getName() <<" has chosen " << p2->getColor() << "." << std::endl;

		}
		else
		{
			p2 = new ComputerPlayer();

			std::cout << p2->getName() <<" has chosen " << p2->getColor() << "." << std::endl;

		}
	}
	else
	{
		p1 = new ComputerPlayer();

		std::cout << p1->getName() <<" has chosen " << p1->getColor() << "." << std::endl;


		p2 = new ComputerPlayer();

		std::cout << p2->getName() <<" has chosen " << p2->getColor() << "." << std::endl;
	}

	std::cout << "How many rounds would you like to play?";
	std::cin >> numberOfRounds;
	return numberOfRounds;

}
