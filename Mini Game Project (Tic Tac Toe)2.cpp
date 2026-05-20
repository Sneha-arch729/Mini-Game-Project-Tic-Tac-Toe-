#include <iostream>

using namespace std;

// Function to draw the current game board layout dynamically using array indexing
void displayBoard(const char board[]) {
    cout << "\n=====================================";
    cout << "\n           TIC TAC TOE GAME          ";
    cout << "\n=====================================" << endl;
    cout << "             |     |     " << endl;
    cout << "          " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "        _____|_____|_____" << endl;
    cout << "             |     |     " << endl;
    cout << "          " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "        _____|_____|_____" << endl;
    cout << "             |     |     " << endl;
    cout << "          " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "             |     |     " << endl;
    cout << "\n=====================================\n";
}

// Function to check if a player has achieved a winning combination
bool checkWin(const char board[], char player) {
    // 1. Check Horizontal rows
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player)) {
        return true;
    }
    // 2. Check Vertical columns
    if ((board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player)) {
        return true;
    }
    // 3. Check Diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is completely full (Draw condition)
bool checkDraw(const char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // Found an empty spot, not a draw yet
        }
    }
    return true;
}

// Core Game Loop execution handler
void playGame() {
    // Initialize standard array with tracking numbers 1 to 9 (Fixes the C++11 Vector Error)
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameEnded = false;
    int choice;

    while (!gameEnded) {
        displayBoard(board);
        
        cout << "Player [" << currentPlayer << "], enter your move (1-9): ";
        cin >> choice;

        // Validation for array boundaries and overlapping placement moves
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            cout << "\n? Invalid move! Spot already occupied or out of bounds. Try again.\n";
            continue;
        }

        // Apply grid selection change based on checked entry index
        board[choice - 1] = currentPlayer;

        // Verify conditional state configurations
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "\n?? CONGRATULATIONS! Player [" << currentPlayer << "] wins the game!\n";
            gameEnded = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "\n?? It's a DRAW! Better luck next time.\n";
            gameEnded = true;
        } else {
            // Swap turns sequentially across valid loop cycles
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char replayChoice;

    // Outer shell tracking continuous replay inputs
    do {
        playGame();
        
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replayChoice;
        
    } while (replayChoice == 'Y' || replayChoice == 'y');

    cout << "\nThank you for playing! Have a great day.\n";
    return 0;
}
