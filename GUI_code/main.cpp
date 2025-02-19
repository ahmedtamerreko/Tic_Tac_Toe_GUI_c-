#include "PyramiGUI.h"
#include "BoardGame_Classes.h"
#include <QApplication>
#include"MainWindow1.h"
#include"wordguii.h"

#include "Pyramic_Tic-Tac-Toe.h"
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow1 d;
    d.show();

    return a.exec();
}
