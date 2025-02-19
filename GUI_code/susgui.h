#ifndef SUSGUI_H
#define SUSGUI_H
#include"sus.h"
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QMessageBox>
#include <QMainWindow>
#include<QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class SUS;
}
QT_END_NAMESPACE
class SUS : public QMainWindow
{
    Q_OBJECT

public:
    explicit SUS(QWidget *parent = nullptr);
    ~SUS();

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

private:
    Ui::SUS *ui;
    susBoard <char> board;
    susPlayer<char>* currentPlayer;
    susPlayer<char> player1;
    susPlayer<char> player2;
    // GUI Elements
    QGridLayout *gridLayout;
    QVector<QPushButton*> buttons;

    // Helper Methods
    void switchPlayer();
    void updateUI();
    void checkGameOver(int r,int c);

};

#endif // SUSGUI_H

