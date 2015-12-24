#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <cubein.h>
#include <cubeout.h>

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
    void on_pushButton_clicked(); // In door button

    void on_pushButton_2_clicked(); // Out door button

private:
    Ui::MainWindow *ui;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
};

#endif // MAINWINDOW_H
