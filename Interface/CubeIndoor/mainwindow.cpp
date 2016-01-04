#include "mainwindow.h"
#include "network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

extern string recvMessage;
extern string sendMessage;
extern boost::mutex mainMutex;
int __serverStatus = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // server mesajini alip parse edip gerekli buton boyamalarini yapan thread, program boyunca calisir, sonsuz dongude
    WorkerThread *workerThread = new WorkerThread;
    connect(workerThread, SIGNAL(progressChanged(QString)),
            SLOT(onProgressChanged(QString)));
    connect(workerThread, SIGNAL(finished()),
            workerThread, SLOT(deleteLater()));
    workerThread->start();

    ui->setupUi(this);

    targetLocation=-1;

    currentLocation=-1;

    list = QList<QPushButton*>();

    list.append(ui->pushButton_0);
    list.append(ui->pushButton_1);
    list.append(ui->pushButton_2);
    list.append(ui->pushButton_3);
    list.append(ui->pushButton_4);
    list.append(ui->pushButton_5);
    list.append(ui->pushButton_6);
    list.append(ui->pushButton_7);
    list.append(ui->pushButton_8);
    list.append(ui->pushButton_9);
    list.append(ui->pushButton_10);
    list.append(ui->z02);
    list.append(ui->z04);
    list.append(ui->z05);
    list.append(ui->z06);
    list.append(ui->z10);
    list.append(ui->z11);
    list.append(ui->z23);
    list.append(ui->kantin);
    list.append(ui->lab1);
    list.append(ui->lab2);
    list.append(ui->lab3);
    list.append(ui->lab4);

    // komsuluklar eklenir
    adjacency_list = adjacency_list_t(300);
    sp.addEdge(adjacency_list,0,1);
    sp.addEdge(adjacency_list,1,0);
    sp.addEdge(adjacency_list,1,2);
    sp.addEdge(adjacency_list,2,1);
    sp.addEdge(adjacency_list,2,3);
    sp.addEdge(adjacency_list,3,2);
    sp.addEdge(adjacency_list,3,4);
    sp.addEdge(adjacency_list,4,3);
    sp.addEdge(adjacency_list,4,5);
    sp.addEdge(adjacency_list,5,4);
    sp.addEdge(adjacency_list,5,6);
    sp.addEdge(adjacency_list,6,5);
    sp.addEdge(adjacency_list,6,7);
    sp.addEdge(adjacency_list,7,6);
    sp.addEdge(adjacency_list,7,8);
    sp.addEdge(adjacency_list,8,7);
    sp.addEdge(adjacency_list,8,9);
    sp.addEdge(adjacency_list,9,8);
    sp.addEdge(adjacency_list,9,10);
    sp.addEdge(adjacency_list,10,9);
    sp.addEdge(adjacency_list,10,0);
    sp.addEdge(adjacency_list,0,10);
    sp.addEdge(adjacency_list,0,11);
    sp.addEdge(adjacency_list,11,0);
    sp.addEdge(adjacency_list,0,12);
    sp.addEdge(adjacency_list,12,0);
    sp.addEdge(adjacency_list,0,13);
    sp.addEdge(adjacency_list,13,0);
    sp.addEdge(adjacency_list,13,1);
    sp.addEdge(adjacency_list,1,13);
    sp.addEdge(adjacency_list,14,2);
    sp.addEdge(adjacency_list,2,14);
    sp.addEdge(adjacency_list,14,3);
    sp.addEdge(adjacency_list,3,14);
    sp.addEdge(adjacency_list,15,3);
    sp.addEdge(adjacency_list,3,15);
    sp.addEdge(adjacency_list,3,16);
    sp.addEdge(adjacency_list,16,3);
    sp.addEdge(adjacency_list,4,17);
    sp.addEdge(adjacency_list,17,4);
    sp.addEdge(adjacency_list,5,18);
    sp.addEdge(adjacency_list,18,5);
    sp.addEdge(adjacency_list,6,19);
    sp.addEdge(adjacency_list,19,6);
    sp.addEdge(adjacency_list,20,8);
    sp.addEdge(adjacency_list,8,20);
    sp.addEdge(adjacency_list,21,9);
    sp.addEdge(adjacency_list,9,21);
    sp.addEdge(adjacency_list,10,22);
    sp.addEdge(adjacency_list,22,10);

    clearBtnColor();

    // ekran buyutme ozelligini kapat
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

void MainWindow::on_serverBtn_clicked()
{
    //boost::thread guiThread(clientCube);
    clientCube();
    //usleep(500000);
    if(__serverStatus==1)
    {
        //ui->pathBtn->setEnabled(true);
        ui->serverStatus->setText("Server:ON");
    }
}

/*
 * Target ve current buton haricinde tum butonların renklerini transparan yapar
 */
void MainWindow::clearBtnColor()
{
    for (int i = 0; i < list.size(); ++i)
    {
        list[i]->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    }

    if(currentLocation!=-1)
        changeBtnColor(currentLocation,(char*)"blue");
    if(targetLocation!=-1)
        changeBtnColor(targetLocation,(char*)"red");
}

void MainWindow::onProgressChanged(QString info)
{
    int btnNum=-1;
    char tempBuf[100];

    if(targetLocation ==-1 || currentLocation == -1)
        ui->pathBtn->setEnabled(false);
    else
        ui->pathBtn->setEnabled(true);


    if(strcmp(recvMessage.c_str(), "") != 0 && sscanf(recvMessage.c_str(),"%s %d",tempBuf,&btnNum)>1)
    {
        if(btnNum != MainWindow::currentLocation)
        {
            MainWindow::changeBtnColor(MainWindow::currentLocation, (char*)"rgba(255, 255, 255, 0)");

            MainWindow::currentLocation = btnNum;


            on_pathBtn_clicked();
        }
    }
    else if(strcmp(recvMessage.c_str(),"exit")==0)
    {
        qDebug() << "server closed";
        recvMessage.clear();
        ui->serverStatus->setText("Server:OFF");
        ui->pathBtn->setEnabled(false);
        currentLocation = -1;
        targetLocation=-1;
        clearBtnColor();
        //closeSocket();
    }
}

/*
 * Serverdan current locationdan aldığı yeri verilen renge boyar.
 *
*/
void MainWindow::changeBtnColor(int location,char *color)
{
    char temp[256],str[10];

    sprintf(temp,"QPushButton {background-color: %s;color: %s; border:none}",color,color);
    sprintf(str,"%d",location);

    for (int i = 0; i < list.size(); ++i)
    {
        if(strcmp(qstrToChar(list[i]->text()),str)==0)
            list[i]->setStyleSheet(temp);
    }
}

char* MainWindow::qstrToChar(QString str)
{
    QByteArray ba = str.toLatin1();
    char *c_str2 = ba.data();
    return c_str2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectTarget(QPushButton* btn)
{
    sscanf(qstrToChar(btn->text()),"%d",&targetLocation);
    qDebug() << "Target changed to :" << targetLocation;
    clearBtnColor();
}

void MainWindow::on_pathBtn_clicked()
{
    clearBtnColor();

    if(targetLocation ==-1 || currentLocation == -1)
    {
        qDebug() << "target or current location is unknown!";
        return;
    }

    int current=currentLocation;
    int target=targetLocation;

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;

    sp.DijkstraComputePaths(current, adjacency_list, min_distance, previous);
    std::list<vertex_t> path = sp.DijkstraGetShortestPathTo(target, previous);


    // liste vectore donusturulur
    std::vector<vertex_t> vectorShortestPath;
    for (; !path.empty();)
    {
        vectorShortestPath.push_back(path.front());
        path.pop_front();
    }
    // server'a gidecegi siradaki input hesaplanir
    int nextTarget = -1;
    if((vectorShortestPath.size()>1 && targetLocation<=10) || (vectorShortestPath.size()>2 && targetLocation>10))
        nextTarget=vectorShortestPath.at(1);
    else
    {
        qDebug() << "you are in target!";
        changeBtnColor(targetLocation,(char*)"green");
        mainMutex.lock();
        sendMessage.clear();
        sendMessage.append("finish");
        mainMutex.unlock();
        return;
    }

    //qDebug() << "Shortest Path:";
    // shortest path cizilir. yani buton renkleri degistirilir
    for (unsigned int i = 0; i < vectorShortestPath.size(); ++i)
    {
        //qDebug().resetFormat() << vectorShortestPath.at(i);
        changeBtnColor(vectorShortestPath.at(i), (char*)"yellow");
    }
    int angle = findAngle(currentLocation,nextTarget);

    qDebug() << "SENDING: next target: " << nextTarget << "angle: " << angle;

    char tempString[256];
    sprintf(tempString, "%d %d", nextTarget, angle);

    mainMutex.lock();
    sendMessage.clear();
    sendMessage.append(tempString);
    mainMutex.unlock();

    /*usleep(500000);

    mainMutex.lock();
    sendMessage.append(tempString);
    mainMutex.unlock();*/


    changeBtnColor(currentLocation,(char*)"blue");
    changeBtnColor(targetLocation,(char*)"red");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "closed widget";
    mainMutex.lock();
    sendMessage.clear();
    sendMessage.append("exit");
    mainMutex.unlock();
    //closeSocket();
}

int MainWindow::findAngle(int c, int t)
{
    if (c == 0 && t == 1)
        return 312;
    else if (c == 0 && t == 10)
        return 165;
    else if (c == 1 && t == 0)
        return 52;
    else if (c == 1 && t == 2)
        return 320;
    else if (c == 2 && t == 1)
        return 43;
    else if (c == 2 && t == 3)
        return 283;
    else if (c == 3 && t == 2)
        return 38;
    else if (c == 3 && t == 4)
        return 230;
    else if (c == 4 && t == 3)
        return 310;
    else if (c == 4 && t == 5)
        return 208;
    else if (c == 5 && t == 4)
        return 355;
    else if (c == 5 && t == 6)
        return 190;
    else if (c == 6 && t == 5)
        return 339;
    else if (c == 6 && t == 7)
        return 46;
    else if (c == 7 && t == 6)
        return 282;
    else if (c == 7 && t == 8)
        return 37;
    else if (c == 8 && t == 7)
        return 263;
    else if (c == 8 && t == 9)
        return 328;
    else if (c == 9 && t == 8)
        return 205;
    else if (c == 9 && t == 10)
        return 352;
    else if (c == 10 && t == 9)
        return 165;
    else if (c == 10 && t == 0)
        return 340;
    else
        return -1;
}

void MainWindow::on_pushButton_0_clicked()  { selectTarget(ui->pushButton_0); }
void MainWindow::on_pushButton_1_clicked()  { selectTarget(ui->pushButton_1); }
void MainWindow::on_pushButton_2_clicked()  { selectTarget(ui->pushButton_2); }
void MainWindow::on_pushButton_3_clicked()  { selectTarget(ui->pushButton_3); }
void MainWindow::on_pushButton_4_clicked()  { selectTarget(ui->pushButton_4); }
void MainWindow::on_pushButton_5_clicked()  { selectTarget(ui->pushButton_5); }
void MainWindow::on_pushButton_6_clicked()  { selectTarget(ui->pushButton_6); }
void MainWindow::on_pushButton_7_clicked()  { selectTarget(ui->pushButton_7); }
void MainWindow::on_pushButton_8_clicked()  { selectTarget(ui->pushButton_8); }
void MainWindow::on_pushButton_9_clicked()  { selectTarget(ui->pushButton_9); }
void MainWindow::on_pushButton_10_clicked() { selectTarget(ui->pushButton_10); }
void MainWindow::on_z06_clicked()           { selectTarget(ui->z06);}
void MainWindow::on_lab2_clicked()          { selectTarget(ui->lab2);}
void MainWindow::on_z23_clicked()           { selectTarget(ui->z23);}
void MainWindow::on_z11_clicked()           { selectTarget(ui->z11);}
void MainWindow::on_lab1_clicked()          { selectTarget(ui->lab1);}
void MainWindow::on_kantin_clicked()        { selectTarget(ui->kantin);}
void MainWindow::on_lab3_clicked()          { selectTarget(ui->lab3);}
void MainWindow::on_z10_clicked()           { selectTarget(ui->z10);}
void MainWindow::on_z05_clicked()           { selectTarget(ui->z05);}
void MainWindow::on_z04_clicked()           { selectTarget(ui->z04);}
void MainWindow::on_z02_clicked()           { selectTarget(ui->z02);}
void MainWindow::on_lab4_clicked()          { selectTarget(ui->lab4);}

void MainWindow::on_forceConnectBtn_clicked()
{
    mainMutex.lock();
    sendMessage.clear();
    sendMessage.append("yes");
    mainMutex.unlock();
}
