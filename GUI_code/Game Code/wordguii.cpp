#include "wordguii.h"
#include "ui_wordguii.h"

wordguii::wordguii(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wordguii),board(),player1("Player 1", 'X')
    , player2("Player 2", 'O')
    , currentPlayer(&player1)
{
    ui->setupUi(this);
}

wordguii::~wordguii()
{
    delete ui;
}
void wordguii::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void wordguii::checkGameOver() {
    if (board.is_win()) {
        QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(QString::fromStdString(currentPlayer->getname())));
        return;
    }
    if (board.is_draw()) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        return;
    }
}

void wordguii::on_pushButton00_clicked()
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


void wordguii::on_pushButton01_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(0, 1, currentPlayer->getsymbol())) {

        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void wordguii::on_pushButton02_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(0, 2, currentPlayer->getsymbol())) {

        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void wordguii::on_pushButton10_clicked()
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


void wordguii::on_pushButton11_clicked()
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


void wordguii::on_pushButton12_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (board.update_board(1, 2, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }
}


void wordguii::on_pushButton20_clicked()
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


void wordguii::on_pushButton21_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Update the board with the current player's symbol
    if (board.update_board(2, 1, currentPlayer->getsymbol())) {
        button->setText(QString(currentPlayer->getsymbol()));

        // Check if the game is over
        checkGameOver();

        // Switch to the next player
        switchPlayer();
    }

}


void wordguii::on_pushButton22_clicked() {
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











void wordguii::on_pushButtona_clicked()
{
    currentPlayer->setsymbol('A');
}

void wordguii::on_pushButtonb_clicked()
{
    currentPlayer->setsymbol('B');
}

void wordguii::on_pushButtonc_clicked()
{
    currentPlayer->setsymbol('C');
}

void wordguii::on_pushButtond_clicked()
{
    currentPlayer->setsymbol('D');
}

void wordguii::on_pushButtone_clicked()
{
    currentPlayer->setsymbol('E');
}

void wordguii::on_pushButtonf_clicked()
{
    currentPlayer->setsymbol('F');
}

void wordguii::on_pushButtong_clicked()
{
    currentPlayer->setsymbol('G');
}

void wordguii::on_pushButtonh_clicked()
{
    currentPlayer->setsymbol('H');
}

void wordguii::on_pushButtoni_clicked()
{
    currentPlayer->setsymbol('I');
}

void wordguii::on_pushButtonj_clicked()
{
    currentPlayer->setsymbol('J');
}
void wordguii::on_pushButtonk_clicked()
{
    currentPlayer->setsymbol('K');
}

void wordguii::on_pushButtonl_clicked()
{
    currentPlayer->setsymbol('L');
}

void wordguii::on_pushButtonm_clicked()
{
    currentPlayer->setsymbol('M');
}

void wordguii::on_pushButtonn_clicked()
{
    currentPlayer->setsymbol('N');
}

void wordguii::on_pushButtono_clicked()
{
    currentPlayer->setsymbol('O');
}

void wordguii::on_pushButtonp_clicked()
{
    currentPlayer->setsymbol('P');
}

void wordguii::on_pushButtonq_clicked()
{
    currentPlayer->setsymbol('Q');
}

void wordguii::on_pushButtonr_clicked()
{
    currentPlayer->setsymbol('R');
}

void wordguii::on_pushButtons_clicked()
{
    currentPlayer->setsymbol('S');
}

void wordguii::on_pushButtont_clicked()
{
    currentPlayer->setsymbol('T');
}

void wordguii::on_pushButtonu_clicked()
{
    currentPlayer->setsymbol('U');
}

void wordguii::on_pushButtonv_clicked()
{
    currentPlayer->setsymbol('V');
}

void wordguii::on_pushButtonw_clicked()
{
    currentPlayer->setsymbol('W');
}

void wordguii::on_pushButtonx_clicked()
{
    currentPlayer->setsymbol('X');
}

void wordguii::on_pushButtony_clicked()
{
    currentPlayer->setsymbol('Y');
}

void wordguii::on_pushButtonz_clicked()
{
    currentPlayer->setsymbol('Z');
}


