#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shortestpath.h"
//#include "network.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pathBtn_clicked();
    void on_lab2_clicked();
    void on_z23_clicked();
    void on_z06_clicked();
    void on_z11_clicked();
    void on_lab1_clicked();
    void on_kantin_clicked();
    void on_lab3_clicked();
    void on_z10_clicked();
    void on_z05_clicked();
    void on_z04_clicked();
    void on_z02_clicked();
    void on_lab4_clicked();
    void on_serverBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool drawShapes;
    int targetLocation;
    int currentLocation;
    QList<QPushButton*> list;

    void changeBtnColor(int location,char *color);
    char* qstrToChar(QString str);
    void clearBtnColor();
    void changeColor(QPushButton* btn);
    int findAngle(int c, int t);
    //boost::shared_ptr<tcp::socket> serverSocket;
};

#endif // MAINWINDOW_H
