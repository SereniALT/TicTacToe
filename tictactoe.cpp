#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]);
bool checkWinner(char board[BOARD_SIZE][BOARD_SIZE], char player);
void playGame();
void cont(string&);

int main() {
    string start = "y";

    cout << "Tic Tac Toe by Joe\n\n";

    while (start == "y" || start == "Y") {
        playGame();
        cont(start);
    }

    return 0;
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < BOARD_SIZE - 1) {
                cout << "|";
            }
        }
        cout << endl;

        if (i < BOARD_SIZE - 1) {
            cout << "-----------" << endl;
        }
    }
}

bool checkWinner(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

void playGame() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int grid;
    char currentPlayer = 'X';

    cout << "\nFirst player is 'X' and second player is 'O'\n\n";

    for (int turn = 0; turn < BOARD_SIZE * BOARD_SIZE; ++turn) {
        displayBoard(board);

        cout << "\nPlayer " << currentPlayer << "'s turn.\n";

        // Input validation loop
        while (true) {
            cout << "Enter grid number (1-9): ";
            cin >> grid;
            cout << endl;

            // Check if the input is within the valid range
            if (grid >= 1 && grid <= 9) {
                break; // Exit the loop if the input is valid
            } else {
                cout << "\nInvalid input. Please enter a number between 1 and 9.\n\n";
                cin.clear();  // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            }
        }

        // Update the board
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == '0' + grid) {
                    board[i][j] = currentPlayer;
                }
            }
        }

        // Check for a winner
        if (checkWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            return;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }

    // If no winner is found after all turns, it's a tie
    displayBoard(board);
    cout << "\nIt's a tie!\n";
}

void cont(string& start) {
    cout << "\nContinue? (y/n): ";
    cin >> start;

    // Makes sure the user only inputs y or n
    while (start != "N" && start != "n" && start != "Y" && start != "y") {
        cout << "\n\nContinue? (y/n): ";
        cin >> start;
    }
}