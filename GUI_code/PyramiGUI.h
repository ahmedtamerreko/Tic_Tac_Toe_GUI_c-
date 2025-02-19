#ifndef PYRAMIGUI_H
#define PYRAMIGUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QMessageBox>
#include "Pyramic_Tic-Tac-Toe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_00_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;

    // Game Logic
    pyramic_Board<char> board;
    pyramic_Player<char> player1;
    pyramic_Player<char> player2;
    pyramic_Player<char>* currentPlayer;

    // GUI Elements
    QGridLayout *gridLayout;
    QVector<QPushButton*> buttons;

    // Helper Methods
    void switchPlayer();
    void updateUI();
    void checkGameOver();
};

#endif // PYRAMIGUI_H
