#include <iostream>
#include <string>
#include <array>

// Define the number of rows and columns in the game board
const int ROWS = 3;
const int COLUMNS = 3;

// Create the game board as a 2D array of characters
std::array<std::array<char, COLUMNS>, ROWS> board{ {{' ', ' ', ' '},
                                                    {' ', ' ', ' '},
                                                    {' ', ' ', ' '}} };

// Function to print the current state of the game board
void printBoard() {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to make a move on the game board
bool makeMove(int row, int col, char player) {
    // Check if the move is valid
    if (row >= ROWS || row < 0 || col >= COLUMNS || col < 0) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    // Make the move
    board[row][col] = player;
    return true;
}

// Function to check if a player has won the game
bool hasWon(char player) {
    // Check rows for a win
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns for a win
    for (int i = 0; i < COLUMNS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    int row, col;
    char player = 'O'; // Start with player O
    bool gameOver = false;
    while (!gameOver) {
        std::cout << "Player " << player << ": Enter row and column" << std::endl;
        std::cin >> row >> col;
        if (!makeMove(row - 1, col - 1, player)) {
            std::cout << "Invalid move, try again" << std::endl;
            continue;
        }
        printBoard();
        if (hasWon(player)) {
            std::cout << "Player " << player << " has won!" << std::endl;
            gameOver = true;
            break;
        }
        player = (player == 'O') ? 'X' : 'O';
    }
    return 0;
}
