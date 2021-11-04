/*
    A short program to convert numbers between bases (base 2 to 62) for educational purposes.
    Author: Christoph Pircher
    Created: 28.10.2021 (DD-MM-YYYY)
    Last edited: 04.11.2021
    Licenced under GPL-V3
*/

#include "mainwindow.h"
#include "functions.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
