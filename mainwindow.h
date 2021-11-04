/*
    Definition of MainWindow
    Author: Christoph Pircher
    Created: 28.10.2021 (DD-MM-YYYY)
    Last edited: 04.11.2021
    Licenced under GPL-V3
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include "functions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit * input;
    QLineEdit * output;
    QSpinBox * inputBase;
    QSpinBox * outputBase;
};
#endif // MAINWINDOW_H
