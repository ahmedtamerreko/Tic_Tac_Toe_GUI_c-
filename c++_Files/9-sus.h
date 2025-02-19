#ifndef SUS_H
#define SUS_H

#include "BoardGame_Classes.h"
#include <unordered_set>
#include <string>
#include <cctype>
template <typename T>
class susPlayer;

template <typename T>
class susBoard : public Board<T> {
public:
    susBoard();
    bool update_board(int x, int y, T letter);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool is_valid_word(const std::string& word);
    bool pointadding(susPlayer <T>& s,int r,int c);




private:
    std::unordered_set<std::string> dictionary; // Set to store valid 3-letter words
    void load_dictionary();


};

template <typename T>
class susPlayer : public Player<T> {
public:
    susPlayer(std::string name, T letter);
    void getmove(int& x, int& y);
    void setsymbol(T symbol) {
        this->symbol = symbol;
    }
    T getsymbol() const {
        return this->symbol;
    }
    void add_points(int p){
        this->points+=p;
    }
    int points=0;

};


template <typename T>
class susRandomPlayer : public RandomPlayer<T> {
public:
    susRandomPlayer(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <unordered_set>

using namespace std;

// Constructor for susBoard
template <typename T>
susBoard<T>::susBoard() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '-'; // Empty cell initialized with '-'
        }
    }
    this->n_moves = 0;
    load_dictionary();  // Load valid 3-letter words
}

template <typename T>
void susBoard<T>::load_dictionary() {
    ifstream file("sus.txt");
    if (!file.is_open()) {
        throw runtime_error("Unable to open file");
    }

    string word;
    while (file >> word) {
        if (word.size() == 3) {
            dictionary.insert(word);
        }
    }
}


// Update the board with a letter
template <typename T>
bool susBoard<T>::update_board(int x, int y, T letter) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y] == '-') {
        this->n_moves++;


        this->board[x][y] = (letter); // Place the letter on the board
        return true;
    }
    return false;
}

// Display the board
template <typename T>
void susBoard<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            cout << "| " << this->board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-----------------" << endl;
    }
}

// Check if there's a valid word horizontally, vertically, or diagonally
template <typename T>
bool susBoard<T>::is_win() {
    return false;
}
template <typename T>
bool susBoard<T>::pointadding(susPlayer<T>& s, int row, int col) {
    // Check for 'S' player (horizontal, vertical, and diagonal)
    if (s.getsymbol() == 'S') {
        // Horizontal check
        string row_word = "";
        for (int j = 0; j < this->columns; j++) {
            row_word += (this->board[row][j]);
        }
        if (is_valid_word(row_word)) return true;

        // Vertical check
        string col_word = "";
        for (int i = 0; i < this->rows; i++) {
            col_word += (this->board[i][col]);
        }
        if (is_valid_word(col_word)) return true;

        // Diagonal check (top-left to bottom-right)
        if (row == col) {
            string diag1 = "";
            for (int i = 0; i < this->rows; i++) {
                diag1 += (this->board[i][i]);
            }
            if (is_valid_word(diag1)) return true;
        }

        // Diagonal check (top-right to bottom-left)
        if (row + col == this->rows - 1) {
            string diag2 = "";
            for (int i = 0; i < this->rows; i++) {
                diag2 += (this->board[i][this->columns - 1 - i]);
            }
            if (is_valid_word(diag2)) return true;
        }
    }

    // Check for 'U' player in specific positions
    else if (s.getsymbol() == 'U') {
        // Check specific positions where 'U' can form valid words
        if ((row == 0 && col == 1) || (row == 1 && col == 0) ||
            (row == 1 && col == 1) || (row == 1 && col == 2) ||
            (row == 2 && col == 1)) {

            string row_word = "";
            string col_word = "";
            string diag_word1 = "";
            string diag_word2 = "";

            // Add board content for the specific position checks
            if (row == 0 && col == 1) {
                row_word += this->board[0][0];
                row_word += this->board[0][1];
                row_word += this->board[0][2];

                if (is_valid_word(row_word)) {
                    return true;
                }
            }
            else if(row==1&&col==0){
                col_word += this->board[0][0];
                col_word += this->board[1][0];
                col_word += this->board[2][0];

                if (is_valid_word(col_word)) {
                    return true;
                }
            }
            else if(row==1&&col==2){
                col_word += this->board[0][2];
                col_word += this->board[1][2];
                col_word += this->board[2][2];

                if (is_valid_word(col_word)) {
                    return true;
                }
            }
            else if (row == 2 && col == 1) {
                row_word += this->board[2][0];
                row_word += this->board[2][1];
                row_word += this->board[2][2];

                if (is_valid_word(row_word)) {
                    return true;
                }
            }
            else{
                row_word += this->board[1][0];
                row_word += this->board[1][1];
                row_word += this->board[1][2];
                col_word += this->board[0][1];
                col_word += this->board[1][1];
                col_word += this->board[2][1];
                diag_word1+=this->board[0][0];
                diag_word1+=this->board[1][1];
                diag_word1+=this->board[2][2];
                diag_word2+=this->board[0][2];
                diag_word2+=this->board[1][1];
                diag_word2+=this->board[2][0];
                if(is_valid_word(row_word)||is_valid_word(col_word)||is_valid_word(diag_word1)||is_valid_word(diag_word2)){
                    return true;
                }



            }

            // Other position-specific checks can go here (similar to above)
        }
    }

    // No valid word found
    return false;
}



// Check if the game is a draw (no winner and board is full)
template <typename T>
bool susBoard<T>::is_draw() {
    return (this->n_moves == 9 );
}

// Check if the game is over (win or draw)
template <typename T>
bool susBoard<T>::game_is_over() {
    return is_draw();
}

// Check if the word is a valid 3-letter word
template <typename T>
bool susBoard<T>::is_valid_word(const std::string& word) {
    return dictionary.find(word) != dictionary.end();
}

//--------------------------------------


// Constructor for susPlayer
template <typename T>
susPlayer<T>::susPlayer(string name, T letter) : Player<T>(name, letter) {}

template <typename T>
void susPlayer<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (row and column) separated by spaces: ";
    cin>>x;
    cin>>y;
}

template <typename T>
susRandomPlayer<T>::susRandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void susRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random row (0-2)
    y = rand() % this->dimension;  // Random column (0-2)

}


#endif //_WORD_TIC_TAC_TOE_H
