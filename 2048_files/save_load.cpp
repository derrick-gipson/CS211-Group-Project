#include <iostream>
#include <fstream>
#include "save_load.h"

using namespace std;

void saveGame(int board[][5], int score, int numrows) {
    ofstream outFile("savegame.txt");
    if (outFile.is_open()) {
        outFile << score << endl;
        for (int r = 0; r < numrows; r++) {
            for (int c = 0; c < 5; c++) {
                outFile << board[r][c] << " ";
            }
            outFile << endl;
        }
        outFile.close();
        cout << "Game saved successfully!" << endl;
    } else {
        cout << "Error: Could not save game." << endl;
    }
}

void loadGame(int board[][5], int &score, int numrows) {
    ifstream inFile("savegame.txt");
    if (inFile.is_open()) {
        inFile >> score;
        for (int r = 0; r < numrows; r++) {
            for (int c = 0; c < 5; c++) {
                inFile >> board[r][c];
            }
        }
        inFile.close();
        cout << "Game loaded successfully!" << endl;
    } else {
        cout << "Error: No save file found." << endl;
    }
}