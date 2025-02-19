#include "susgui.h"
#include "ui_susgui.h"

SUS::SUS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SUS),board()
    ,player1("Player 1", 'S')
    , player2("Player 2", 'U')
    , currentPlayer(&player1)
{
    ui->setupUi(this);
}

SUS::~SUS()
{
    delete ui;
}

void SUS::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void SUS::checkGameOver(int r,int c) {

    if (board.pointadding(*currentPlayer, r, c)) {
        // Increment player points
        currentPlayer->add_points(1);

        // Check the player's symbol
        if (currentPlayer->getsymbol() == 'S') { // Ensure the method name is correct

            // Ensure ui->textEdit_2 is initialized properly
            if (ui->textEdit_2) {
                QTextCursor cursor = ui->textEdit_2->textCursor();
                cursor.select(QTextCursor::Document);
                cursor.removeSelectedText();

                // Get the format and set the font size
                QTextCharFormat format = cursor.charFormat();
                format.setFontPointSize(36);

                // Insert the text with the specified format
                cursor.insertText(QString("%1").arg(QString::number(currentPlayer->points)), format);
            }

        }

    else if (currentPlayer->getsymbol() == 'U') { // Ensure the method name is correct

        // Ensure ui->textEdit_2 is initialized properly
        if (ui->textEdit_3) {
            QTextCursor cursor = ui->textEdit_3->textCursor();
            cursor.select(QTextCursor::Document);
            cursor.removeSelectedText();

            // Get the format and set the font size
            QTextCharFormat format = cursor.charFormat();
            format.setFontPointSize(36);

            // Insert the text with the specified format
            cursor.insertText(QString("%1").arg(QString::number(currentPlayer->points)), format);
        }
    }
    }


    if (board.is_draw()) {
        if(player1.points>player2.points){
            QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(QString::fromStdString(player1.getname())));
        }
        else if(player2.points>player1.points){
            QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(QString::fromStdString(player2.getname())));
        }
        else{

            QMessageBox::information(this, "Game Over", "It's a draw!");
        }
        return;
    }
}




void SUS::on_pushButton00_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(0, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(0,0);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton01_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(0, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(0,1);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton02_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(0, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(0,2);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton10_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(1, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(1,0);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton11_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(1, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(1,1);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton12_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(1, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(1,2);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton20_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(2, 0, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(2,0);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton21_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(2, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(2,1);

        // Switch to the next player
        switchPlayer();
    }
}


void SUS::on_pushButton22_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    // Update the board with the current player's symbol
    if (board.update_board(2, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver(2,2);

        // Switch to the next player
        switchPlayer();
    }
}

