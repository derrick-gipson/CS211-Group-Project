#include<iostream>
#include<iomanip>
#include "2048.h"
#include <cstdlib>

using namespace std;

//moves tiles to the left
bool move_left(int board[][5], int &pointsGained, int numrows)
{
    //movement alg goes here
    // there are 3 steps in this function- slide (all numbers sliding), merge(combine the tiles which are supposed to combine), update (copy the results back to the board and determine changes)
    bool boardChanged = false; // we assume nothing moves until we detect a change
    pointsGained = 0; // assume no points are gained unless specified otherwise 

   
    // outer loop: Go through the rows
    for (int row = 0; row< numrows; row++)
    {
        // step 1: Slide all nonzero tiles left
        int compressed[5] = {0,0,0,0,0}; // this is a temporary array which stores all nonzero tiles form a row without any gaps in between
        int count = 0; // tracks how many nonzero values are in row
        
        //this goes through the columns
        for (int col =0; col < 5; col++) // this loop fills the compressed array with non zero values
        {
            if (board[row][col] !=0) 
            {
                compressed[count] = board[row][col];
                count++;
            }
        }
    
        // Step 2: Merge Equal Tiles
        int result[5] = {0,0,0,0,0}; //stores tiles after moving
        int position = 0; //stores where next tile goes in result
        for (int i = 0; i < count; )
        {
            if (i + 1 < count && compressed [i] == compressed [i+1]) // if the current position and the one to its right are nonzero and equal
            {
                result[position] = compressed[i] * 2; // the new number @ that left spot between the match is now doubled
                pointsGained += result[position]; // the number produced by merging those is added to the score
                i+=2;
            }
            else
            {
                result[position] = compressed[i];
                i++;
            }
            position++;
        }


        //Step 3: Copy the results back 

        for (int col = 0; col < 5; col++)
        {
            if (board[row][col] != result[col]) // if this number doesnt match, there was a change
            {
                boardChanged = true;
            }

            board[row][col] = result[col]; // save the new row values from result to the board
        }
    
    }
    return boardChanged;
}

bool move_right(int board[][5], int &pointsGained, int numrows)
{

    bool boardChanged = false;
    pointsGained = 0;

    //Go through each row
    for (int row = 0; row < numrows; row++)
    {
        //Collect nonzero tiles from right to left
        int compressed[5] = {0,0,0,0,0};
        int count = 0;

        
        for(int col = 4; col>=0; col--)
        {
            if (board[row][col] !=0)
            {
                compressed[count] = board[row][col];
                count++;
            }
        }
        //Merging equal tiles
        int result[5] = {0,0,0,0,0};
        int position = 0;

        for (int i = 0; i<count; )
        {
            if(i + 1 < count && compressed[i] == compressed[i + 1])
            {
                result[position] = compressed[i] *2;
                pointsGained += result[position];
                i+=2;
            }
            else{
                result[position] = compressed[i];
                i++;
            }
            position++;

        }

        //Copy the results back from right to left
        for(int col = 0; col < 5; col++)
        {
            if (board[row][4-col] != result[col])
            {
                //4-col reverses the column index so results are placed right to left
                boardChanged = true;
            }
            board[row][4-col] = result[col];
        }

    }
    return boardChanged;

}


bool move_up(int board[][5], int &pointsGained, int numrows)
{
    bool boardChanged = false;
    pointsGained = 0;
    //go thru each column
    for(int col = 0; col<5; col++)
    {
        //collect nonzero tiles from top to bottom
        int compressed[5] = {0,0,0,0,0};
        int count = 0;

        for(int row = 0; row<numrows; row++)
        {
            if (board[row][col] !=0)
            {
                compressed[count] = board[row][col];
                count++;
            }
        }

        //merge equal tiles
        int result[5] = {0,0,0,0,0};
        int position = 0;

        for(int i = 0; i<count; )
        {
            if (i+1 < count && compressed[i] == compressed[i+1])
            {
                result[position] = compressed[i] * 2;
                pointsGained += result[position];
                i+=2;
            }
            else
            {
                result[position] = compressed[i];
                i++;
            }
            position++;
        }

        //copy results back into the column
        for (int row = 0; row < numrows; row++)
        {
            if (board[row][col] != result[row])
            {
                boardChanged = true;
            }
            board[row][col] = result[row];
        }

    }
    return boardChanged;
}

//moves tiles downward
bool move_down(int board[][5], int &pointsGained, int numrows)
{
    bool boardChanged = false;
    pointsGained = 0;

    //go through each column
    for (int col = 0; col < 5; col++)
    {
        //collect nonzero tiles from bottom to top
        int compressed[5] = {0, 0, 0, 0, 0};
        int count = 0;

        for (int row = numrows - 1; row >= 0; row--)
        {
            if (board[row][col] != 0)
            {
                compressed[count] = board[row][col];
                count++;
            }
        }

        //merge equal tiles
        int result[5] = {0, 0, 0, 0, 0};
        int position = 0;

        for (int i = 0; i < count; )
        {
            if (i + 1 < count && compressed[i] == compressed[i + 1])
            {
                result[position] = compressed[i] * 2;
                pointsGained += result[position];
                i += 2;
            }
            else
            {
                result[position] = compressed[i];
                i++;
            }

            position++;
        }

        //copy the results back from bottom to top
        for (int row = 0; row < numrows; row++)
        {
            if (board[numrows - 1 - row][col] != result[row])
            {
                boardChanged = true;
            }

            board[numrows - 1 - row][col] = result[row];
        }
    }

    return boardChanged;
}


void insert_random(int board[][5], int numrows)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//insert a 2 into the selected empty position
				board[r][c] = 2;
				break;
			}
		}

	}
}


void print_board(int board[][5], int numrows)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}