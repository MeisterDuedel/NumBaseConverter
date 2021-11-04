/*
    Constructor, destructor and button method of MainWindow
    Author: Christoph Pircher
    Created: 28.10.2021 (DD-MM-YYYY)
    Last edited: 04.11.2021
    Licenced under GPL-V3
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    input = findChild<QLineEdit *>("input");
    output = findChild<QLineEdit *>("output");
    inputBase = findChild<QSpinBox *>("inputBase");
    outputBase = findChild<QSpinBox *>("outputBase");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string istring = input->text().toStdString();
    unsigned short iBase = inputBase->value();
    unsigned short oBase = outputBase->value();
    if(istring.length() >0){
        if(iBase != oBase){
            output->setText(Convert(istring,iBase,oBase).c_str());
        }
    }
}

