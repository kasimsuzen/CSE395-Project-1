#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <unistd.h>
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <vector>
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
public:
    explicit MainWindow(QWidget *parent = 0);

    void changeBtnColor(int location,char *color);
    void clearBtnColor();
    char* qstrToChar(QString str);
    void selectTarget(QPushButton* btn);
    int findAngle(int c, int t);

    ~MainWindow();

public slots:
    void onProgressChanged(QString info);

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

    void on_pathBtn_clicked();
    void on_serverBtn_clicked();
    void closeEvent(QCloseEvent *event);

    void on_forceConnectBtn_clicked();

private:
    Ui::MainWindow *ui;
    int targetLocation;
    int currentLocation;
    ShortestPath sp;
    adjacency_list_t adjacency_list;
    QList<QPushButton*> list;
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
