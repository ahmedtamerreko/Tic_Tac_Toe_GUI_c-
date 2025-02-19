#ifndef WORDGUII_H
#define WORDGUII_H
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QMessageBox>
#include "WordTicTacToe.h"
#include <QMainWindow>
#include<QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class wordguii;
}
QT_END_NAMESPACE
class wordguii : public QMainWindow
{
    Q_OBJECT

public:
    explicit wordguii(QWidget *parent = nullptr);
    ~wordguii();

private slots:
    void on_pushButton00_clicked();

    void on_pushButton01_clicked();

    void on_pushButton02_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_pushButton20_clicked();

    void on_pushButton21_clicked();

    void on_pushButton22_clicked();

    void on_pushButtona_clicked();
    void on_pushButtonb_clicked();
    void on_pushButtonc_clicked();
    void on_pushButtond_clicked();
    void on_pushButtone_clicked();
    void on_pushButtonf_clicked();
    void on_pushButtong_clicked();
    void on_pushButtonh_clicked();
    void on_pushButtoni_clicked();
    void on_pushButtonj_clicked();
    void on_pushButtonk_clicked();
    void on_pushButtonl_clicked();
    void on_pushButtonm_clicked();
    void on_pushButtonn_clicked();
    void on_pushButtono_clicked();
    void on_pushButtonp_clicked();
    void on_pushButtonq_clicked();
    void on_pushButtonr_clicked();
    void on_pushButtons_clicked();
    void on_pushButtont_clicked();
    void on_pushButtonu_clicked();
    void on_pushButtonv_clicked();
    void on_pushButtonw_clicked();
    void on_pushButtonx_clicked();
    void on_pushButtony_clicked();
    void on_pushButtonz_clicked();


private:
    Ui::wordguii *ui;
    // Game Logic
    WordBoard<char> board;
    WordPlayer<char> player1;
    WordPlayer<char> player2;
    WordPlayer<char>* currentPlayer;
    // GUI Elements
    QGridLayout *gridLayout;
    QVector<QPushButton*> buttons;

    // Helper Methods
    void switchPlayer();
    void updateUI();
    void checkGameOver();

};

#endif // WORDGUII_H
