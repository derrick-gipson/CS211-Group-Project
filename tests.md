# CS211 Group Project - Testing Results

**Group:** 31
**Course:** CS 211 - Fall 2026
**Team Members:** Derrick Gipson and Ethan Schrandt

## Testing Overview

Both programs were manually tested to verify their functionality.

The 2048 game was tested for tile movement, merging, scoring,
game controls, and save/load functionality.

The Luhn validator was tested to verify that it correctly
identifies valid and invalid inputs.

Both programs compiled and ran successfully.

## Part A: 2048 Game Testing

| Test | Expected Result | Actual Result | Status |
|------|-----------------|---------------|--------|
| Game initialization | A 5x5 board appears with two starting tiles | Board initialized correctly | Pass |
| Move left | Tiles move left and matching tiles merge | Movement worked correctly | Pass |
| Move right | Tiles move right and matching tiles merge | Movement worked correctly | Pass |
| Move up | Tiles move upward and matching tiles merge | Movement worked correctly | Pass |
| Move down | Tiles move downward and matching tiles merge | Movement worked correctly | Pass |
| Tile merging | Matching tiles combine into one tile with double the value | Tiles merged correctly | Pass |
| Score tracking | Score increases by the value of merged tiles | Score updated correctly | Pass |
| Move counter | Counter increases after a successful move | Counter updated correctly | Pass |
| Random tile generation | A new tile appears after a successful move | New tiles generated correctly | Pass |
| New game | Board, score, and move count reset | New game started correctly | Pass |
| Help command | Available commands and instructions appear | Help information displayed correctly | Pass |
| Save game | Current game information is written to a save file | Game saved successfully | Pass |
| Load game | Previously saved game information is restored | Saved game loaded successfully | Pass |
| Exit command | Program terminates | Program exited successfully | Pass |

## Part B: Luhn Validation Testing

| Test | Expected Result | Actual Result | Status |
|------|-----------------|---------------|--------|
| Valid 16-digit number | Checksum passes | Valid number accepted | Pass |
| Invalid 16-digit number | Checksum fails | Invalid number rejected | Pass |
| Input shorter than 16 digits | Error message appears | Input rejected correctly | Pass |
| Input longer than 16 digits | Error message appears | Input rejected correctly | Pass |
| Input containing letters | Error message appears | Input rejected correctly | Pass |
| Multiple inputs | Program continues accepting numbers | Multiple inputs processed correctly | Pass |
| Exit command | Program terminates | Program exited successfully | Pass |

## Testing Summary

Both the 2048 game and the Luhn checksum validator compiled
and executed successfully.

The tested gameplay controls, tile movements, merging,
scoring, and save/load features produced the expected results.

The Luhn validator correctly distinguished between valid
and invalid inputs and handled incorrect input formats.

All recorded tests passed.