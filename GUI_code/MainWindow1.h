#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include "PyramiGUI.h"
#include"susgui.h"
#include"wordguii.h"


namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow1 *ui;
    MainWindow *pyr;
    SUS *pyrSus;
    wordguii *pyrWordGame;

};

#endif // MAINWINDOW1_H
