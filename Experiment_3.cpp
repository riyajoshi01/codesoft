#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; 
char currentPlayer = 'X'; 
void displayBoard() {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
}

bool checkWinner() {
 
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}
void makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove(); // Retry the move
    } else {
        board[row][col] = currentPlayer; 
    }
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();

    while (true) {
        makeMove();
        displayBoard();
        if (checkWinner()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

 
        switchPlayer();
    }

    return 0;
}