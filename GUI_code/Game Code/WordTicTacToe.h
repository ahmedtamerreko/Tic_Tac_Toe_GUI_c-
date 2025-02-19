#ifndef _WORD_TIC_TAC_TOE_H
#define _WORD_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <unordered_set>
#include <string>

template <typename T>
class WordBoard : public Board<T> {
public:
    WordBoard();
    bool update_board(int x, int y, T letter);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool is_valid_word(const std::string& word);

private:
    std::unordered_set<std::string> dictionary; // Set to store valid 3-letter words
    void load_dictionary();
};

template <typename T>
class WordPlayer : public Player<T> {
public:
    WordPlayer(std::string name, T letter);
    void getmove(int& x, int& y);
};

template <typename T>
class WordRandomPlayer : public RandomPlayer<T> {
public:
    WordRandomPlayer(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <unordered_set>

using namespace std;

// Constructor for WordBoard
template <typename T>
WordBoard<T>::WordBoard() {
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

// Load the dictionary from file
template <typename T>
void WordBoard<T>::load_dictionary() {
    ifstream file("dic.txt");
    string word;
    while (file >> word) {
        if (word.size() == 3) {
            dictionary.insert(word); // Add only valid 3-letter words
        }
    }
}

// Update the board with a letter
template <typename T>
bool WordBoard<T>::update_board(int x, int y, T letter) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y] == '-') {
        this->n_moves++;
        this->board[x][y] = letter; // Place the letter on the board
        return true;
    }
    return false;
}

// Display the board
template <typename T>
void WordBoard<T>::display_board() {
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
bool WordBoard<T>::is_win() {
    // Check rows and columns for valid words
    for (int i = 0; i < this->rows; i++) {
        string row_word = "", col_word = "";
        for (int j = 0; j < this->columns; j++) {
            row_word += this->board[i][j];
            col_word += this->board[j][i];
        }
        if (is_valid_word(row_word) || is_valid_word(col_word)) {
            return true;
        }
    }

    // Check diagonals for valid words
    string diag1 = "", diag2 = "";
    for (int i = 0; i < this->rows; i++) {
        diag1 += this->board[i][i];
        diag2 += this->board[i][this->columns - 1 - i];
    }
    return is_valid_word(diag1) || is_valid_word(diag2);
}

// Check if the game is a draw (no winner and board is full)
template <typename T>
bool WordBoard<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

// Check if the game is over (win or draw)
template <typename T>
bool WordBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

// Check if the word is a valid 3-letter word
template <typename T>
bool WordBoard<T>::is_valid_word(const std::string& word) {
    return dictionary.find(word) != dictionary.end();
}

//--------------------------------------

// Constructor for WordPlayer
template <typename T>
WordPlayer<T>::WordPlayer(string name, T letter) : Player<T>(name, letter) {}

template <typename T>
void WordPlayer<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (row and column) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for WordRandomPlayer
template <typename T>
WordRandomPlayer<T>::WordRandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void WordRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}

#endif //_WORD_TIC_TAC_TOE_H
