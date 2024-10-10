#include <iostream>
#include <vector>

// class represents a TicTacToe game
class TicTacToe {
public:
    // constructor initializes the TicTacToe board and sets the current player to 'X'
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    // function to start and manage the game until a winner is found or the board is full
    void playGame() {
        int row, col;
        while (true) {
            printBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (in the format \"row column\"): ";
            std::cin >> row >> col;
            if (makeMove(row, col) && !isWinner() && !isBoardFull()) {
                switchPlayer();
            } else if (isWinner()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a tie! Try again.\n";
                break;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }

private:
    // 2D vector to represent the board
    std::vector< std::vector<char> > board;
    // character to represent the current player
    char currentPlayer;

    // function that outputs the board to the user
    void printBoard() {
        std::cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "  -----\n";
        }
    }

    // function that lets the current player make their move
    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    // function that switches the current player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // function that checks if the current player has won
    bool isWinner() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    // function that checks if the TicTacToe board is full
    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    game.playGame();

    return 0;
} 