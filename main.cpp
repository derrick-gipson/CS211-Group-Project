#include <iostream>
#include "2048_helper.h"

using namespace std;

int main()
{
	int score = 0;
	int moveCount = 0;
	int size = 5;
	int board[5][5] = {0};
	insert_random(board, size);
	insert_random(board, size);
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	cout << "Score: " << score << endl;
	cout << "Successfull Moves: " << moveCount << endl;

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

		
		print_board(board);

		cout << "Score: " << score << endl;
		cout << "Successful Moves: " << moveCount << endl;
		}

	}


	return 0;
}