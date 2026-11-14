#include <iostream>
#include "2048_helper.h"

using namespace std;

int main()
{
	int score = 0;
	int moveCount = 0;
	int size = 5;
	int highestTile = 0;
	int board[5][5] = {0};
	bool hasWon = false;

	insert_random(board, size);
	insert_random(board, size);
	//while getch == x loop for up down left right
	

	//find highest tile on initial board
	for (int row = 0; row< size; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			if (board [row][col] > highestTile)
			{
				highestTile = board[row][col];
			}
		}
	}
	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	cout << "Score: " << score << endl;
	cout << "Successful Moves: " << moveCount << endl;
	cout << "Highest Tile: " << highestTile << endl;

	char choice = 'u';	//initialized
	while (choice != 'e')
	{

		cout << "Please enter choice:{u,d,l,r,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;


		if (choice != 'e')
		{
			int pointsGained = 0;
			bool changed = false;

		if (choice == 'u')
			changed = move_up(board, pointsGained, size);
		else if (choice == 'd')
			changed = move_down(board, pointsGained, size);
		else if (choice == 'l')
			changed = move_left(board, pointsGained, size);
		else if (choice == 'r')
			changed = move_right(board, pointsGained, size);

		if(changed)
		{
			score += pointsGained;
			moveCount++;

			insert_random(board, size);
		}
		else 
		{
			cout << "The board did not change." << endl;
		}

		for (int row = 0; row< size; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				if (board [row][col] > highestTile)
				{
					highestTile = board[row][col];
				}
			}
		}

		print_board(board);

		cout << "Score: " << score << endl;
		cout << "Successful Moves: " << moveCount << endl;
		cout <<  "Highest Tile: " << highestTile << endl;

		//check for a win
		if(highestTile>= 2048 && hasWon!=true)
		{
			cout << "Congratulations! You reached 2048!" << endl;
			cout << "You can continue playing or press e to exit." << endl;
			hasWon=true;
		}

		bool gameOver = true;

		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				if (board[row][col] == 0)
				{
					gameOver = false;
				}
				if (col < 4 && board[row][col] == board[row][col+1])
				{
					gameOver = false;
				}
				if(row < size - 1 && board[row][col] == board[row+1][col])
				{
					gameOver = false;
				}
			}
		}
		if (gameOver == true)
		{
			cout << "Game Over! No more moves are possible." << endl;
			cout << "Final Score: " << score << endl;
			cout << "Total Successful Moves: " << moveCount << endl;
			break;
		}

		}

	}


	return 0;
}