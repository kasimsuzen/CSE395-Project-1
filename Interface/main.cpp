#include "mainwindow.h"
#include "map.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
/*int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();

    window->setWindowTitle(QString::fromUtf8("QT - Capture Mouse Move"));
    window->resize(300, 250);

    QWidget *centralWidget = new QWidget(window);
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);

    Map* CoordinateLabel = new Map();
    layout->addWidget(CoordinateLabel);

    window->setCentralWidget(centralWidget);

    window->show();

    qDebug( "C Style Debug Message" );

    return app.exec();
}*/
