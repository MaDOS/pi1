/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */


#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include "main.h"

#include <iostream>
#include <stdlib.h>

///Displays field
///
///Displays field with X for player 1 and O for player 2
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

///!...Counts all points and returns the winner
///
///!...Return 0 for draw; 1 for player 1 wins; 2 for player 2 wins
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					break;
				case 1:
					count_p1++;
					break;
				case 2:
					count_p2++;
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		}
	}

	if (count_p1 == count_p2) //Draw
	{
		return 0;
	}
	if (count_p1 < count_p2) //Player 2 wins
	{
		return 2;
	}
	else //Player 1 wins
	{
		return 1;
	}
}

bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//check if you can find an opponents stone in a neighboring field
			//then check if in this direction all stones are opponent stones until
			int tempPos_x = pos_x+i;
			int tempPos_y = pos_y+j;
			while(field[tempPos_y][tempPos_x] == opponent && tempPos_x < SIZE_X && tempPos_y < SIZE_Y && tempPos_y >= 0 && tempPos_x >= 0)
			{
				tempPos_x = tempPos_x + i;
				tempPos_y = tempPos_y + j;
				//the line is terminated by one of your own stone
				if(field[tempPos_y][tempPos_x] == player)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	if (!turn_valid(field, player, pos_x, pos_y))
	{
		return;
	}
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//use tempPos as offset positions
			int tempPos_x = pos_x+i;
			int tempPos_y = pos_y+j;
			while(field[tempPos_y][tempPos_x] == opponent && tempPos_x < SIZE_X && tempPos_y < SIZE_Y && tempPos_y >= 0 && tempPos_x >= 0)
			{
				//go forward
				tempPos_x = tempPos_x + i;
				tempPos_y = tempPos_y + j;
			}


			//end found! start going backwards
			if(field[tempPos_y][tempPos_x] == player)
			{
				while(tempPos_x != pos_x || tempPos_y != pos_y)
				{
					tempPos_x = tempPos_x - i;
					tempPos_y = tempPos_y - j;

					field[tempPos_y][tempPos_x] = player;

				}

			}

		}
	}
}

int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int valid_turns = 0;
	for(int i = 0; i <= SIZE_X; i++)
	{
		for(int j = 0; j <= SIZE_Y; j++)
		{
			if(turn_valid(field, player, i, j))
			{
				valid_turns++;
			}
		}
	}
	return valid_turns;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	std::cout << "Spieler: " << player << " ist drann!" << std::endl;
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}

void game(const int playertyp[2])
{
	/* for SIZE_X = 8 and SIZE_Y = 8 equals:
	int spielfeld[SIZE_Y][SIZE_X] = {
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,1,2,0,0,0},
			{0,0,0,2,1,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};*/

	int field[SIZE_Y][SIZE_X];
	for(int j = 0; j < SIZE_Y; j++)
	{
		for(int i = 0; i < SIZE_X; i++)
		{
			field[j][i] = 0;
		}
	}
	field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
	field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
	field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
	field[SIZE_Y / 2][SIZE_X / 2] = 1;

	int current_player = 1;
	show_field(field);
	//let each player make its moves until no further moves are possible

	while(possible_turns(field,1) > 0 || possible_turns(field,2) > 0)
	{
		show_field(field);
		//player can make a move
		if(possible_turns(field,current_player) > 0)
		{
			if(playertyp[current_player-1] == 1)//human turn
			{
				human_turn(field,current_player);
			}
			else
			{
				computer_turn(field,current_player);
			}
			togglePlayer(current_player);
		}
		else
		{//skip player
			togglePlayer(current_player);
		}
	}

	switch (winner(field))
	{
		case 1:
			std::cout << "Spieler 1 gewinnt!" << std::endl;
			break;
		case 2:
			std::cout << "Spieler 2 gewinnt!" << std::endl;
			break;
		case 0:
			std::cout << "Unentschieden!" << std::endl;
			break;
		default:
			std::cout << "Er ist tot Jim!" << std::endl;
			break;
	}

	show_field(field);
}

void togglePlayer(int &player)
{
	if(player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
}

int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	int field[SIZE_Y][SIZE_X] = {
								{0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0}, {0,0,0,1,2,0,0,0},
								{0,0,0,2,1,0,0,0}, {0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}
								};
	show_field(field);

	int typ[2] = { 1, 1 };

	std::string resetGame;
	std::string p1Typ;
	std::string p2Typ;

	bool validP1Typ = false;
	bool validP2Typ = false;

	do
	{
		while(!validP1Typ)
		{
			std::cout << "Spieler 1 ist[H/C]: " << std::endl;
			std::cin >> p1Typ;

			if(p1Typ == "H")
			{
				typ[0] = 1;
				validP1Typ = true;
			}
			else if(p1Typ == "C")
			{
				typ[0] = 2;
				validP1Typ = true;
			}
		}

		while(!validP2Typ)
		{
			std::cout << "Spieler 2 ist[H/C]: " << std::endl;
			std::cin >> p2Typ;

			if(p1Typ == "H")
			{
				typ[1] = 1;
				validP2Typ = true;
			}
			else if(p1Typ == "C")
			{
				typ[1] = 2;
				validP2Typ = true;
			}
		}

		game(typ);

		std::cout << "Soll ein weiteres Spiel gestartet werden?[y/n]: " << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cin >> resetGame;
	}while(resetGame == "y");

	return 0;
}
