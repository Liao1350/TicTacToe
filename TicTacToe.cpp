#include <iostream>
#include <vector>
#include <ctime>

bool checkWin(const std::vector<std::vector<char>>& board, int row, int column, char& winner) {
    int count{ 1 }, winCond{(int)(board[row].size())};

    for (int i = 1; i < winCond; ++i) {
        if (board[row][i] == board[row][i - 1]) {
            ++count;
        }
        else {
            break;
        }
        if (count == winCond) {
            winner = board[row][column];
            return true;
        }
    } // Row Check

    count = 1;

    for (int i = 1; i < winCond; ++i) {
        if (board[i][column] == board[i - 1][column]) {
            ++count;
        }
        else {
            break;
        }
        if (count == winCond) {
            winner = board[row][column];
            return true;
        }
    } // Column Check
    
    count = 1;

    for (int i = 1; i < winCond; ++i) {
        if (board[i][i] == '?') {
            break;
        }
        if (board[i][i] == board[i - 1][i - 1]) {
            ++count;
        }
        if (count == winCond) {
            winner = board[row][column];
            return true;
        }
    } // Diagonal Check

    count = 1;

    for (int i = 1; i < winCond; ++i) {
        if (board[i][(winCond - 1) - i] == '?') {
            break;
        }
        if (board[i][(winCond - 1) - i] == board[i - 1][(winCond - 1)- i + 1]) {
            ++count;
        }
        if (count == winCond) {
            winner = board[row][column];
            return true;
        }
    } // Reverse Diaognal Check

    return false;
}

void updateBoard(std::vector<std::vector<char>>& board, int row, int column, bool& turn) {
    turn ? board[row][column] = 'O' : board[row][column] = 'X';
    turn = !(turn);
}

void printBoard(std::vector<std::vector<char>>& board) {
    std::cout << "  ";
    for (int i = 0; i < (int)(board[0].size()); ++i) {
        std::cout << i << " ";
    }
    std::cout << "C" << "\n";

    int c{ 0 };

    for (auto& i : board) {
        std::cout << c << " ";
        ++c;
        for (auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "R\n\n";
}

int main()
{
    std::vector<std::vector<char>> board{};
    int boardSize{};
    std::string ask_again{};
    srand(time(NULL));

    while (true) {
        std::cout << "Insert board size:";
        while (std::cin >> boardSize) {
            if (boardSize >= 3) {
                break;
            }
            else {
                std::cout << "Invalid number\n" << "Insert board size:";
            }

        }
        std::cout << "\n";

        board.clear();

        for (int i = 0; i < boardSize; ++i) {
            board.push_back(std::vector<char>());
            for (int j = 0; j < boardSize; ++j) {
                board[i].push_back('?');
            }
        }

        int row{}, column{}, count{ 0 };
        char winner{ '?' };
        bool win = false;
        bool turn = ((rand() % 2) == 0);

        printBoard(board);

        while (!win) {
            if (turn) {
                std::cout << "O's turn. ";
            }
            else {
                std::cout << "X's turn. ";
            }
            std::cout << "Enter row and column:";
            std::cin >> row >> column;
            std::cout << "\n";
            if (row < boardSize && row >= 0 && column < boardSize && column >= 0 && board[row][column] == '?') {
                ++count;
                updateBoard(board, row, column, turn);
                printBoard(board);
                win = checkWin(board, row, column, winner);
                if (count == boardSize * boardSize && !(win)) {
                    std::cout << "Tied.\n";
                    break;
                }
            }
            else {
                std::cout << "Invalid input!\n";
            }
        }

        if (winner == 'O') {
            std::cout << "O wins.\n";
        }
        else if (winner == 'X') {
            std::cout << "X wins.\n";
        }

        std::cout << "Enter anything to continue, enter 'N' to end the game: ";
        std::cin >> ask_again;
        if (ask_again == "N") {
            std::cout << "\nEnding game...";
            break;
        }
        std::cout << "\nStarting new game...\n\n";
    }
}
