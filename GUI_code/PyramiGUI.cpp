#include "PyramiGUI.h"
#include "ui_PyramiGUI.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , board()
    , player1("Player 1", 'X')
    , player2("Player 2", 'O')
    , currentPlayer(&player1)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void MainWindow::checkGameOver() {
    if (board.is_win()) {
        QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(QString::fromStdString(currentPlayer->getname())));
        return;
    }
    if (board.is_draw()) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        return;
    }
}
void MainWindow::on_pushButton_00_clicked()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(0, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }


}

void MainWindow::on_pushButton_10_clicked()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(1, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(1, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }

}


void MainWindow::on_pushButton_12_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(1, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void MainWindow::on_pushButton_21_clicked()
{    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }

}


void MainWindow::on_pushButton_22_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 3, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void MainWindow::on_pushButton_24_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 4, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}
