#include "BingoCard.h"

/* Constructor: Initializes the board and marked vectors, and fills the board */
BingoCard::BingoCard(int size) : board_size(size) {
    board = new vector<vector<int>*>(board_size);
    marked = new vector<vector<bool>*>(board_size);
    
    for (int i = 0; i < board_size; ++i) {
        board->at(i) = new vector<int>(board_size);
        marked->at(i) = new vector<bool>(board_size, false);
    }
    
    fill(); // Fill the board with numbers
}

/* Converts the Bingo card to a string representation */
string BingoCard::toString() {
    stringstream ss;
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (marked->at(i)->at(j)) {
                ss << "(" << setw(2) << board->at(i)->at(j) << ") ";
            } else {
                ss << " " << setw(2) << board->at(i)->at(j) << "  ";
            }
        }
        ss << endl;
    }
    return ss.str();
}

/* Marks a number if it is found on the board */
void BingoCard::call(int num) {
    cout << "Calling " << num << endl;
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (board->at(i)->at(j) == num) {
                marked->at(i)->at(j) = true;
                return;
            }
        }
    }
}

/* Resets the marked spots on the board */
void BingoCard::clearBoard() {
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            marked->at(i)->at(j) = false;
        }
    }
}

/* Fills the board with numbers based on Bingo rules */
void BingoCard::fill() {
    vector<int> range{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    for (int col = 0; col < board_size; col++) {
        random_shuffle(range.begin(), range.end(), badRand);
        for (int row = 0; row < board_size; row++) {
            board->at(row)->at(col) = range.at(row) + (15 * col);
            marked->at(row)->at(col) = false;
        }
    }
}

/* Checks if any column has all values marked */
bool BingoCard::checkVertical() {
    for (int j = 0; j < board_size; ++j) {
        bool bingo = true;
        for (int i = 0; i < board_size; ++i) {
            if (!marked->at(i)->at(j)) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }
    return false;
}

/* Checks if any row has all values marked */
bool BingoCard::checkHorizontal() {
    for (int i = 0; i < board_size; ++i) {
        bool bingo = true;
        for (int j = 0; j < board_size; ++j) {
            if (!marked->at(i)->at(j)) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }
    return false;
}

/* Checks if either of the two main diagonals has all values marked */
bool BingoCard::checkDiagonal() {
    bool bingo = true;
    // Check main diagonal
    for (int i = 0; i < board_size; ++i) {
        if (!marked->at(i)->at(i)) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;

    // Check anti-diagonal
    bingo = true;
    for (int i = 0; i < board_size; ++i) {
        if (!marked->at(i)->at(board_size - 1 - i)) {
            bingo = false;
            break;
        }
    }
    return bingo;
}

/* Checks for a Bingo by calling the check functions */
bool BingoCard::checkBingo() {
    return checkVertical() || checkHorizontal() || checkDiagonal();
}

// Do not modify these functions.
int randomfunc(int j) {
    return rand() % j;
}

int badRand(int j) {
    return 100 % j;
}
