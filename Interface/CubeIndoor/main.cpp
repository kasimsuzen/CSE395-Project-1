#include "mainwindow.h"
#include <QApplication>
#include "network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    boost::thread_group thread;
    thread.create_thread(boost::bind(clientCube));
    thread.join_all();
    return a.exec();
}
