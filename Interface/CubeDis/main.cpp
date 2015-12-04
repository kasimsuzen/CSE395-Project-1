#include "mainwindow.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*for (int i = 182; i < 250; ++i)
    {
        sprintf(str,"list.append(ui->btn_%d);",i);
        qDebug() << str;
    }*/

    return a.exec();
}
