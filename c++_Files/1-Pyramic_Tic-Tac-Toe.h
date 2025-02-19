#ifndef _PYRAMID_TICTACTOE_H
#define _PYRAMID_TICTACTOE_H

#include "BoardGame_Classes.h"

template <typename T>
class pyramic_Board:public Board<T> {
public:
    pyramic_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class pyramic_Player : public Player<T> {
public:
    pyramic_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class pyramic_Random_Player : public RandomPlayer<T>{
public:
    pyramic_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype> 

using namespace std;
template <typename T>
pyramic_Board<T>::pyramic_Board() {
    this->rows = 3;
    this->columns = 1;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
        this->columns+=2;
    }
    this->n_moves = 0;
}
template <typename T>
bool pyramic_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

template <typename T>
void pyramic_Board<T>::display_board() {
    this->columns=1;
    int width=16;
    for (int i = 0; i < this->rows; i++) {
        cout << "\n";
        cout <<setw(width);
        for (int j = 0; j < this->columns; j++) {
            cout<< "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        this->columns+=2;
        width-=8;
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool pyramic_Board<T>::is_win() {
    // Check rows and columns
    if (
        // Check first column and diagonals
        (this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != 0) ||
        (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != 0) ||
        // Check first diagonal
        (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        // Check middle row
        (this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != 0) ||
        // Check bottom row segments
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 0) ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0)
        ) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool pyramic_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool pyramic_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------
// Constructor for pyramic_Player
template <typename T>
pyramic_Player<T>::pyramic_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void pyramic_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for pyramic_Random_Player
template <typename T>
pyramic_Random_Player<T>::pyramic_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void pyramic_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}



#endif
