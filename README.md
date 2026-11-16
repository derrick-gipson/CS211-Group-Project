# CS211 Group Project - Group 31

## Project Information

**Course:** Introduction to Programming (CS 211)

**Section:** CS-211-14127-Fall 2026

**Class Time:** Monday/Wednesday, 5:35 PM

**Group Number:** 31

**Team Members:**
- Derrick Gipson - [derrick-gipson](https://github.com/derrick-gipson)
- Ethan Schrandt - [Ethan-Schrandt](https://github.com/Ethan-Schrandt)

**GitHub Repository:** [CS211-Group-Project](https://github.com/derrick-gipson/CS211-Group-Project)

---

## Project Overview

This project consists of two separate C++ console applications
developed for CS211: Introduction to Programming.

**Part A:** A 5x5 version of the 2048 game.

**Part B:** A 16-digit Luhn checksum validator.

Both programs use standard C++ programming concepts,
including loops, conditional statements, functions,
arrays, and input/output operations.

---

# Part A: 2048 Game

## Description

The 2048 game is played on a 5x5 board containing numbered tiles.

The player moves tiles up, down, left, or right. When two
matching tiles collide, they merge into a single tile
with double the original value.

The value of each newly merged tile is added to the
player's score.

The objective is to create a tile with the value 2048.

## Features

The 2048 program includes:

- 5x5 game board
- Movement in four directions
- Tile merging
- Score tracking
- Successful move counting
- Highest tile tracking
- Random tile generation
- Win detection
- Game-over detection
- New game functionality
- Help menu
- Save and load functionality
- Exit command

## Game Controls

| Key | Action |
|-----|--------|
| u | Move Up |
| d | Move Down |
| l | Move Left |
| r | Move Right |
| n | Start New Game |
| h | Display Help Menu |
| s | Save Game |
| o | Open Saved Game |
| e | Exit Game |

## Gameplay Rules

1. The game begins with two numbered tiles on a 5x5 board.
2. The player selects a direction using the keyboard.
3. Tiles move as far as possible in the selected direction.
4. Two matching tiles merge into one tile with double the value.
5. Each merged tile contributes points to the player's score.
6. A new tile is generated after a successful movement.
7. The successful move counter increases when the board changes.
8. Reaching a tile value of 2048 displays a winning message.
9. Players may continue playing after reaching 2048.
10. Game over occurs when no additional moves are possible.

## New Game

Press `n` to start a new game.

The program asks the player to confirm the decision.

If confirmed, the board is cleared, two new starting
tiles are generated, and the score and move counter
are reset to zero.

## Save and Load Functionality

The game supports saving and loading progress using
a text file named `savegame.txt`.

### Saving a Game

Press `s` during gameplay to save the current game.

The save file contains:

- The player's current score
- All 25 values of the 5x5 board

Saving again overwrites the previous save file.

A confirmation message is displayed when the save
operation succeeds.

### Loading a Game

Press `o` during gameplay to load a previously saved game.

The program reads the saved score and board values
from `savegame.txt`.

The loaded board and score are then displayed.

If no save file exists, the program displays an
error message.

### Save File Limitations

The save file stores the board and score only.

The successful move counter, highest tile statistic,
and win/game-over status are not preserved in the file.

The highest tile is recalculated during subsequent
gameplay.

The save/load implementation does not fully validate
the contents of an incorrectly formatted save file.

The save file is created in the program's current
working directory.

---

# Part B: Luhn Checksum Validator

## Description

The Luhn checksum validator determines whether a
16-digit number satisfies the Luhn checksum algorithm.

The program accepts numerical input, checks its format,
and calculates the checksum.

It then reports whether the checksum passes or fails.

## Features

The Luhn validator includes:

- Input of 16-digit numbers
- Input length validation
- Rejection of nonnumeric characters
- Luhn checksum calculation
- Pass/fail result display
- Ability to check multiple numbers
- Exit command

## Luhn Algorithm

The program implements the Luhn algorithm using
the following steps:

1. Begin with the rightmost digit.
2. Move from right to left.
3. Double every second digit.
4. If a doubled value exceeds 9, subtract 9.
5. Add all resulting digits together.
6. Determine whether the sum is divisible by 10.

If the sum is divisible by 10, the number passes
the Luhn checksum.

Otherwise, the number fails.

Passing the Luhn checksum does not guarantee that
a number represents a real or active account.

## Using the Luhn Validator

1. Run the Luhn program.
2. Enter a 16-digit number.
3. The program checks the input format.
4. If the input is valid, the checksum is calculated.
5. The program displays whether the checksum passes or fails.
6. Enter another number to perform another check.
7. Type `exit` to terminate the program.

---

# Compiling and Running the Programs

Both programs can be compiled using a C++17-compatible
compiler such as g++.

The following commands are intended for the terminal
in Visual Studio Code on Windows.

Open the terminal in the main `CS211-Group-Project` folder.

## Part A: Compile and Run 2048

Compile the program:

```powershell
g++ -std=c++17 2048_files/main.cpp 2048_files/2048.cpp 2048_files/save_load.cpp -o game2048.exe
```

Run the program:

```powershell
.\game2048.exe
```

## Part B: Compile and Run Luhn

Compile the program:

```powershell
g++ -std=c++17 luhn_files/main.cpp luhn_files/luhn.cpp -o luhn.exe
```

Run the program:

```powershell
.\luhn.exe
```

The two programs are compiled and executed separately.

---

# Project File Organization

The project is organized into separate folders
for the 2048 game and Luhn validator.

## 2048 Files

| File | Description |
|------|-------------|
| main.cpp | Main gameplay loop and user interaction |
| 2048.cpp | Movement algorithms, tile merging, random tile generation, and board display |
| 2048.h | Function declarations for the 2048 game |
| save_load.cpp | Functions for saving and loading game information |
| save_load.h | Function declarations for save/load functionality |

## Luhn Files

| File | Description |
|------|-------------|
| main.cpp | User input and program interaction |
| luhn.cpp | Luhn checksum calculation and input validation |
| luhn.h | Function declarations for the Luhn validator |

---

# Development Environment

**Programming Language:** C++

**Language Standard:** C++17

**Development Environment:** Visual Studio Code

**Compiler:** g++ (GCC)

**Version Control:** Git and GitHub

**Repository:** https://github.com/derrick-gipson/CS211-Group-Project