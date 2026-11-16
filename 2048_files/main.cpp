#include <iostream>
#include "2048.h"
#include "save_load.h"

using namespace std;

int main()
{
	int score = 0;
	int moveCount = 0;
	int size = 5;
	int highestTile = 0;
	int board[5][5] = {0};
	bool hasWon = false;
	bool gameOver = false;

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

		cout << "Please enter choice:{u,d,l,r,n,h,s,o,e} for UP, DOWN, LEFT, RIGHT, Exit, Help, Save, Load, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;

		//help command
		if (choice == 'h')
		{
  			cout << "\nGame Controls:" << endl;
    		cout << "u - Move Up" << endl;
  			cout << "d - Move Down" << endl;
		    cout << "l - Move Left" << endl;
 		   cout << "r - Move Right" << endl;
		    cout << "s - Save Game" << endl;
		    cout << "o - Open Saved Game" << endl;
		    cout << "n - New Game" << endl;
		    cout << "h - Help" << endl;
		    cout << "e - Exit" << endl;

		    cout << "\nMerge equal tiles to earn points." << endl;
		    cout << "Reach 2048 to win!" << endl;
		    cout << "Saving replaces the previous savegame.txt file." << endl;

		    continue;
		}

		//new game code
		if (choice == 'n')
		{
			char confirmation = 'n';

			cout << "Are you sure you want to start a new game? (y/n): ";
			cin >> confirmation;
			if (confirmation == 'y' || confirmation == 'Y')
			{
				for (int row = 0; row < size; row++)
				{
 				   for (int col = 0; col < 5; col++)
					{
 				       board[row][col] = 0;
 				    }
				}
				score = 0;
				moveCount = 0;
				hasWon = false;
				gameOver = false;

				insert_random(board, size);
				insert_random(board, size);
				highestTile = 2;
				cout << "New Game Started!" << endl;

				print_board(board);
				cout << "Score: " << score << endl;
				cout << "Successful Moves: " << moveCount << endl;
				cout << "Highest Tile: " << highestTile << endl;
			}
			else
			{
				cout << "New game canceled." << endl;
			}
			continue;
		}



		if (choice != 'u' && choice != 'd' && choice != 'l' && choice != 'r' && choice != 's' && choice != 'o' && choice != 'n' && choice != 'h' && choice != 'e')
		{
		    cout << "Invalid choice. Please try again." << endl;
 		   continue;
		}


		if (gameOver && (choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r'))
		{
    		cout << "Game Over! You cannot move any more tiles." << endl;
   	 		cout << "You can save, load, start a new game, view help, or exit." << endl;
    		continue;
		}


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

		 gameOver = true;

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
			cout << "Score at Game Over: " << score << endl;
			cout << "Total Successful Moves: " << moveCount << endl;
			cout << "You can save, load, start a new game, view help, or exit." << endl;
		}

		}

	}

	    char choice;
    cout << "Press 's' to save, 'l' to load: ";
    cin >> choice;

    if (choice == 's') {
        saveGame(board, score, 4); // Use your actual row count (e.g., 4 or 5)
    } else if (choice == 'l') {
        loadGame(board, score, 4);
    }


	return 0;
}