#include <iostream>
#include <random>
#include <iomanip>

using namespace std;


// Movement functions
bool move_left(int board[][5], int &pointsGained, int numrows = 5);

bool move_right(int board[][5], int &pointsGained, int numrows = 5);

bool move_up(int board[][5], int &pointsGained, int numrows = 5);

bool move_down(int board[][5], int &pointsGained, int numrows = 5);


// Print the board
void print_board(int board[][5], int numrows = 5);


// Insert a random tile
void insert_random(int board[][5], int numrows = 5);
