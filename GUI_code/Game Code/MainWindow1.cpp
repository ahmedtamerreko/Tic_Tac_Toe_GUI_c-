#include "MainWindow1.h"
#include "ui_MainWindow1.h"
#include"PyramiGUI.h"

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{
    pyr=new MainWindow(this);
    pyr->show();
}

