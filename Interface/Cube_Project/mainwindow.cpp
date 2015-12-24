#include "mainwindow.h"
#include "ui_mainwindow.h"

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

// in door gecis
void MainWindow::on_pushButton_clicked()
{
    this->hide();
    CubeIn cubeInDoor;
    cubeInDoor.setModal(true);
    cubeInDoor.exec();
}

// out door gecis
void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    CubeOut cubeOutDoor;
    cubeOutDoor.setModal(true);
    cubeOutDoor.exec();
}
