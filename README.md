# TIC-TAC-TOE

A terminal-based, two-player **Tic-Tac-Toe** game built with **C++**. The program uses a 2D array (`3x3`) to represent the game board, featuring custom player names, occupied-cell validation, and automatic win detection.

## Key Features

- **Custom Player Names**: Player 1 (`X`) and Player 2 (`O`) can enter their own names before the match starts.
- **Interactive Game Board**: Displays a numbered `1–9` grid (`3x3`) in the console that updates in real time after every turn.
- **Occupied Cell Validation**: Alerts the player if the chosen box is already taken by `X` or `O` and prompts them to choose another box.
- **Automatic Win Detection**: Checks all horizontal, vertical, and diagonal combinations via the `checkWinner()` function.

## Console Preview

```text
--------------------
TIC-TAC TOE 
--------------------

 |---|---|---|
 | 1 | 2 | 3 | 
 |---|---|---|
 | 4 | 5 | 6 | 
 |---|---|---|
 | 7 | 8 | 9 | 
 |---|---|---|
enter player 1 name[X] :Alice
enter player 2 name[O] :Bob

choose a number 1-9 to fill (Alice[X]'s turn)
```

## Code Structure

All game logic is contained in a single source file (`main.cpp`):

- `displayBoard()` — Renders the current `3x3` board state to the console.
- `checkWinner()` — Evaluates all rows, columns, and diagonals to check if a player has won.
- `main()` — Manages the game loop, player name input, turn switching (`X` and `O`), mapping cell numbers (`1–9`) to `arr` indices, and displaying the winner banner.

## Compilation & Execution

Make sure you have a C++ compiler (such as `g++`) installed on your system.

```bash
# Compile the source code
g++ main.cpp -o tictactoe

# Run the program (Linux/macOS)
./tictactoe

# Run the program (Windows)
tictactoe.exe
```

## How to Play

1. Run the compiled program in your terminal.
2. Enter names for **Player 1 (`X`)** and **Player 2 (`O`)** *(single word without spaces)*.
3. On each turn, enter a number from **`1` to `9`** corresponding to an empty box on the board.
4. The first player to align three matching symbols horizontally, vertically, or diagonally wins the game.

## Future Improvements

- [ ] Add a **draw condition** when all 9 boxes are filled with no winner
- [ ] Validate out-of-range inputs (`< 1` or `> 9`) and non-numeric inputs
- [ ] Add a **play again** option without restarting the program

