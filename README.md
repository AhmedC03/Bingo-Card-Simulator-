# 🎲 Bingo Game (C++)

This is a console-based Bingo game built in C++. It simulates a 5x5 Bingo card with randomized numbers, allows you to call numbers, and checks if a Bingo (complete row, column, or diagonal) has been achieved. 🎉

## Features ✨
- Generates a randomized Bingo card following standard Bingo column rules
- Call numbers and automatically mark them on the board
- Checks for Bingo in rows, columns, and diagonals
- Resets the board between rounds for continuous play
- Displays the board with marked numbers wrapped in parentheses

## File Overview 📂
- `main.cpp` – Handles test calls and displays the game output
- `BingoCard.h` – Declares the `BingoCard` class and its methods
- `BingoCard.cpp` – Implements the game logic and Bingo checks

## How to Run 🚀
```bash
g++ main.cpp BingoCard.cpp -o BingoGame
./BingoGame
```

## Sample Output 🎮

Calling 12
Calling 25
Calling 61
Calling 64
Bingo! 🎉
(12) 25  37  61
...


## 👨‍💻 Author

Ahmed Chowdhury

