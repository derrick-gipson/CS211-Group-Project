#include<iostream>
#include<iomanip>
#include "2048_helper.h"

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

void print_board(int board[][5], int numrows)
{
    //board display code goes here
}