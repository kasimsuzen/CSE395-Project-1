#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <vector>
#include <QThread>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "location.h"
#include <cstdio>
#include <QCloseEvent>
#include "ui_mainwindow.h"
#include "shortestpath.h"

using namespace std;
using namespace boost;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void onProgressChanged(QString info);

public:
    explicit MainWindow(QWidget *parent = 0);

    void setCurrentLocation(int data);
    int getCurrentLocation();
    void changeBtnColor(int location,char *color);
    void clearBtnColor();
    char* qstrToChar(QString str);
    void selectTarget(QPushButton* btn);
    int findAngle(int c, int t);

    ~MainWindow();

private slots:
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
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_55_clicked();
    void on_pushButton_56_clicked();

    void closeEvent(QCloseEvent *event);
    void on_pathBtn_clicked();
    void on_serverBtn_clicked();


    void on_forceConnectBtn_clicked();

private:
    Ui::MainWindow *ui;
    int targetLocation;
    int currentLocation;
    Location** locationArray;
    QList<QPushButton*> list;
    ShortestPath sp;
    adjacency_list_t adjacency_list;

};

class WorkerThread : public QThread {
    Q_OBJECT
    void run()
    {
        while(1)
        {
            usleep(50000);
            emit progressChanged("");
        }
    }
signals:
    void progressChanged(QString info);
};

#endif // MAINWINDOW_H
