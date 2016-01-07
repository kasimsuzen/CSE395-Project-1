#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_indoor_clicked()
{
    QProcess*   process = new QProcess();
    QString program = "C:\\Users\\haLiL\\Documents\\QTProjects\\build-CubeIndoor-Desktop_Qt_5_5_1_MinGW_32bit-Debug\\debug\\CubeIndoor.exe";
    process->start(program);
}

void MainWindow::on_outdoor_clicked()
{
    QProcess*   process = new QProcess();
    QString program = "C:\\Users\\haLiL\\Documents\\QTProjects\\build-CubeOutDoorLast-Desktop_Qt_5_5_1_MinGW_32bit-Debug\\debug\\CubeOutDoorLast.exe";
    process->start(program);
}
