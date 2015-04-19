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
using namespace std;


int menu(Player * &p1, Player * &p2);

int main()
{
	int i = 0;
	int numberOfRounds = 0;

	Player * players[2];
	Player * activePlayer;
	Board * board = new Board();


	numberOfRounds = menu(players[0], players[1]);

	for(i = 0; i<numberOfRounds; i++)
	{
		bool over = false;
		int turn = 0;
		while(!over)
		{
			board->showBoard();
			activePlayer = players[turn];
			turn = (turn + 1) % 2;
			over = board->setStone(activePlayer->makeMove(board), activePlayer);
		}
		cout << "Statistics: " << endl;
		for( Player * p : players)
		{
			cout << p->getName() << " has won " << p->getWins() << " times" <<endl;
		}



	}
	delete players[0];
	delete players[1];
	delete board;


}


int menu(Player * &p1, Player * &p2)
{
	int numberOfRounds = 1;
	int numberOfPlayers;
	string tempPlayerName = "";
	char tempColor = ' ';

	cout << "           WELCOME TO CONNECTFOUR!" << endl;
	cout << "            GAME OF THE YEAR 1922" << endl;
	cout << "*****************************************************" << endl;
	cout << "How many human players do you wish to have?\nPlease enter the number here: ";
	cin >> numberOfPlayers;
	cout << endl;

	while(numberOfPlayers < 0 || numberOfPlayers > 2)
	{
		cout << "ConnectFour is a game for two players, please enter a value between 0 and 2 for the number of human players who participate: ";
		cin >> numberOfPlayers;
		cout << endl;
	}

	if(numberOfPlayers > 0)
	{
		cout << "Player 1, please enter your name: ";
		cin >> tempPlayerName;

		cout << "Which symbol would you like to use for your pieces?" << endl << "Enter one here: ";
		cin >> tempColor;
		cout << endl;

		while(tempColor == '.' || tempColor == ' ')
		{
			cout << "This symbol is not available. Please choose another one: ";
			cin >> tempColor;
			cout << endl;
		}

		p1 = new HumanPlayer(tempPlayerName,tempColor);

			cout << p1->getName() <<" has chosen " << p1->getColor() << "." << endl << endl;

		if(numberOfPlayers == 2)
		{
			cout << "Player 2, please enter your name: ";
			cin >> tempPlayerName;

			cout << "Which symbol would you like to use for your pieces?" << endl << "Enter one here: ";
			cin >> tempColor;
			cout << endl;


			while(tempColor == p1->getColor() || tempColor == '.' || tempColor == ' ')
			{
				cout << "This symbol is not available. Please choose another one: " << endl;
				cin >> tempColor;
				cout << endl;
			}

			p2 = new HumanPlayer(tempPlayerName, tempColor);

			cout << p2->getName() <<" has chosen " << p2->getColor() << "." << endl << endl;

		}
		else
		{
			p2 = new ComputerPlayer();

			cout << p2->getName() <<" has chosen " << p2->getColor() << "." << endl << endl;

		}
	}
	else
	{
		p1 = new ComputerPlayer();

		cout << p1->getName() <<" has chosen " << p1->getColor() << "." << endl;


		p2 = new ComputerPlayer();

		cout << p2->getName() <<" has chosen " << p2->getColor() << "." << endl;
	}

	cout << "How many rounds would you like to play? ";
	cin >> numberOfRounds;
	return numberOfRounds;

}
