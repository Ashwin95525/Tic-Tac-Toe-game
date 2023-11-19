#include <iostream>
#include <cstdlib>
#include <ctime>

char grid[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};

char currentPlayer;

void displayGrid() {
    std::cout << "Tic-Tac-Toe\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << '\n';
    }
}

bool isValidMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return grid[row][col] == 'X' || grid[row][col] == 'O';
}

bool makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (isValidMove(move)) {
        std::cout << "Invalid move. Cell already taken. Try again.\n";
        return false;
    }

    grid[row][col] = currentPlayer;

    return true;
}

bool checkWin() {
    
    for (int i = 0; i < 3; ++i) {
        if ((grid[i][0] == currentPlayer && grid[i][1] == currentPlayer && grid[i][2] == currentPlayer) ||
            (grid[0][i] == currentPlayer && grid[1][i] == currentPlayer && grid[2][i] == currentPlayer)) {
            return true;
        }
    }

    
    if ((grid[0][0] == currentPlayer && grid[1][1] == currentPlayer && grid[2][2] == currentPlayer) ||
        (grid[0][2] == currentPlayer && grid[1][1] == currentPlayer && grid[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    std::srand(std::time(0)); 
    currentPlayer = (std::rand() % 2 == 0) ? 'X' : 'O';

    int move;
    bool gameWon = false;

    do {
        displayGrid();
        std::cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        std::cin >> move;

        if (move < 1 || move > 9) {
            std::cout << "Invalid input. Enter a number between 1 and 9.\n";
            continue;
        }

        if (makeMove(move)) {
            gameWon = checkWin();
            switchPlayer();
        }

    } while (!gameWon);

    displayGrid();
    std::cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!\n";

    return 0;
}

