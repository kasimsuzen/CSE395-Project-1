#include "mainwindow.h"
#include "network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>
#include <unistd.h>

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
    WorkerThread *workerThread = new WorkerThread;
    connect(workerThread, SIGNAL(progressChanged(QString)),
            SLOT(onProgressChanged(QString)));
    connect(workerThread, SIGNAL(finished()),
            workerThread, SLOT(deleteLater()));
    workerThread->start();

    ui->setupUi(this);

    currentLocation = -1;

    targetLocation=-1;

    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint); // ekran buyutme ozelligini kapat

    list = QList<QPushButton*>();
    // yol cizme butonları eklenir
    list = QList<QPushButton*>();
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
    list.append(ui->pushButton_11);
    list.append(ui->pushButton_12);
    list.append(ui->pushButton_13);
    list.append(ui->pushButton_14);
    list.append(ui->pushButton_15);
    list.append(ui->pushButton_16);
    list.append(ui->pushButton_17);
    list.append(ui->pushButton_18);
    list.append(ui->pushButton_19);
    list.append(ui->pushButton_20);
    list.append(ui->pushButton_21);
    list.append(ui->pushButton_22);
    list.append(ui->pushButton_23);
    list.append(ui->pushButton_24);
    list.append(ui->pushButton_25);
    list.append(ui->pushButton_26);
    list.append(ui->pushButton_27);
    list.append(ui->pushButton_28);
    list.append(ui->pushButton_29);
    list.append(ui->pushButton_30);
    list.append(ui->pushButton_31);
    list.append(ui->pushButton_32);
    list.append(ui->pushButton_33);
    list.append(ui->pushButton_34);
    list.append(ui->pushButton_35);
    list.append(ui->pushButton_36);
    list.append(ui->pushButton_37);
    list.append(ui->pushButton_38);
    list.append(ui->pushButton_39);
    list.append(ui->pushButton_40);
    list.append(ui->pushButton_41);
    list.append(ui->pushButton_42);
    list.append(ui->pushButton_43);
    list.append(ui->pushButton_44);
    list.append(ui->pushButton_45);
    list.append(ui->pushButton_46);
    list.append(ui->pushButton_47);
    list.append(ui->pushButton_48);
    list.append(ui->pushButton_49);
    list.append(ui->pushButton_50);
    list.append(ui->pushButton_51);
    list.append(ui->pushButton_52);
    list.append(ui->pushButton_53);
    list.append(ui->pushButton_54);
    list.append(ui->pushButton_55);
    list.append(ui->pushButton_56);

    // komsuluklar eklenir
    adjacency_list = adjacency_list_t (300);
    sp.addEdge(adjacency_list,24,1,2);
    sp.addEdge(adjacency_list,24,31,1);
    sp.addEdge(adjacency_list,1,24,2);
    sp.addEdge(adjacency_list,1,22,2);
    sp.addEdge(adjacency_list,22,1,2);
    sp.addEdge(adjacency_list,22,47,1);
    sp.addEdge(adjacency_list,22,6,2);
    sp.addEdge(adjacency_list,6,22,2);
    sp.addEdge(adjacency_list,6,14,3);
    sp.addEdge(adjacency_list,14,6,3);
    sp.addEdge(adjacency_list,14,2,4);
    sp.addEdge(adjacency_list,2,14,5);
    sp.addEdge(adjacency_list,2,15,3);
    sp.addEdge(adjacency_list,15,2,6);
    sp.addEdge(adjacency_list,15,23,3);
    sp.addEdge(adjacency_list,23,15,4);
    sp.addEdge(adjacency_list,23,18,4);
    sp.addEdge(adjacency_list,23,4,4);
    sp.addEdge(adjacency_list,4,23,4);
    sp.addEdge(adjacency_list,4,52,4);
    sp.addEdge(adjacency_list,52,4,5);
    sp.addEdge(adjacency_list,52,36,5);
    sp.addEdge(adjacency_list,36,52,4);
    sp.addEdge(adjacency_list,36,37,5);
    sp.addEdge(adjacency_list,37,36,5);
    sp.addEdge(adjacency_list,37,13,3);
    sp.addEdge(adjacency_list,13,37,3);
    sp.addEdge(adjacency_list,13,11,3);
    sp.addEdge(adjacency_list,18,23,4);
    sp.addEdge(adjacency_list,11,13,3);
    sp.addEdge(adjacency_list,11,32,2);
    sp.addEdge(adjacency_list,11,20,2);
    sp.addEdge(adjacency_list,32,11,4);
    sp.addEdge(adjacency_list,32,55,4);
    sp.addEdge(adjacency_list,55,32,7);
    sp.addEdge(adjacency_list,55,3,5);
    sp.addEdge(adjacency_list,3,55,8);
    sp.addEdge(adjacency_list,3,34,4);
    sp.addEdge(adjacency_list,34,3,4);
    sp.addEdge(adjacency_list,34,18,3);
    sp.addEdge(adjacency_list,18,34,3);
    sp.addEdge(adjacency_list,34,16,1);
    sp.addEdge(adjacency_list,34,26,3);
    sp.addEdge(adjacency_list,16,34,1);
    sp.addEdge(adjacency_list,16,41,1);
    sp.addEdge(adjacency_list,41,16,1);
    //sp.addEdge(adjacency_list,41,26,2);
    sp.addEdge(adjacency_list,12,16,2);
    sp.addEdge(adjacency_list,12,40,2);
    sp.addEdge(adjacency_list,40,12,2);
    sp.addEdge(adjacency_list,40,45,1);
    sp.addEdge(adjacency_list,45,40,1);
    sp.addEdge(adjacency_list,45,38,1);
    sp.addEdge(adjacency_list,38,45,1);
    sp.addEdge(adjacency_list,38,5,1);
    sp.addEdge(adjacency_list,5,38,1);
    sp.addEdge(adjacency_list,5,46,1);
    sp.addEdge(adjacency_list,46,5,1);
    sp.addEdge(adjacency_list,46,54,1);
    sp.addEdge(adjacency_list,54,46,1);
    sp.addEdge(adjacency_list,54,56,1);
    sp.addEdge(adjacency_list,56,54,1);
    sp.addEdge(adjacency_list,56,48,1);
    sp.addEdge(adjacency_list,56,42,1);
    sp.addEdge(adjacency_list,42,56,1);
    sp.addEdge(adjacency_list,42,44,1);
    sp.addEdge(adjacency_list,44,42,1);
    sp.addEdge(adjacency_list,44,39,1);
    sp.addEdge(adjacency_list,39,44,1);
    sp.addEdge(adjacency_list,39,47,1);
    sp.addEdge(adjacency_list,47,39,1);
    sp.addEdge(adjacency_list,47,22,1);
    sp.addEdge(adjacency_list,48,56,1);
    sp.addEdge(adjacency_list,48,49,1);
    sp.addEdge(adjacency_list,49,48,1);
    sp.addEdge(adjacency_list,49,25,1);
    sp.addEdge(adjacency_list,25,49,1);
    sp.addEdge(adjacency_list,25,29,1);
    sp.addEdge(adjacency_list,25,30,2);
    sp.addEdge(adjacency_list,29,25,1);
    sp.addEdge(adjacency_list,29,53,1);
    sp.addEdge(adjacency_list,53,29,1);
    sp.addEdge(adjacency_list,53,31,1);
    sp.addEdge(adjacency_list,31,24,1);
    sp.addEdge(adjacency_list,31,53,1);
    sp.addEdge(adjacency_list,30,25,2);
    sp.addEdge(adjacency_list,30,28,2);
    sp.addEdge(adjacency_list,28,30,2);
    sp.addEdge(adjacency_list,28,19,1);
    sp.addEdge(adjacency_list,19,28,1);
    sp.addEdge(adjacency_list,26,41,2);
    sp.addEdge(adjacency_list,26,34,3);
    sp.addEdge(adjacency_list,26,35,3);
    sp.addEdge(adjacency_list,35,26,3);
    sp.addEdge(adjacency_list,35,8,1);
    sp.addEdge(adjacency_list,35,7,3);
    sp.addEdge(adjacency_list,8,33,1);
    sp.addEdge(adjacency_list,8,35,1);
    sp.addEdge(adjacency_list,33,8,1);
    sp.addEdge(adjacency_list,33,27,1);
    sp.addEdge(adjacency_list,33,9,1);
    sp.addEdge(adjacency_list,27,33,1);
    sp.addEdge(adjacency_list,9,33,1);
    sp.addEdge(adjacency_list,7,35,3);
    sp.addEdge(adjacency_list,7,51,5);
    sp.addEdge(adjacency_list,51,7,5);
    sp.addEdge(adjacency_list,51,17,5);
    sp.addEdge(adjacency_list,17,51,5);
    sp.addEdge(adjacency_list,17,43,3);
    sp.addEdge(adjacency_list,43,17,3);
    sp.addEdge(adjacency_list,43,10,1);
    sp.addEdge(adjacency_list,10,43,1);
    sp.addEdge(adjacency_list,10,21,1);
    sp.addEdge(adjacency_list,21,50,1);
    sp.addEdge(adjacency_list,21,10,1);
    sp.addEdge(adjacency_list,21,20,1);
    sp.addEdge(adjacency_list,20,21,1);
    sp.addEdge(adjacency_list,50,21,1);
    sp.addEdge(adjacency_list,20,11,2);


    // butonlara paralel location arrayi olustulur
    locationArray = new Location*[list.size()];
    for (int i = 0; i < list.size(); ++i) {
        locationArray[i] = new Location[2]; // 0-leftUp , 1-rightDown
    }

    locationArray[0][0].setLocation(40.808532, 29.355852); // //
    locationArray[0][1].setLocation(40.808336, 29.356565); // //

    locationArray[21][0].setLocation(40.808413, 29.356506); // //
    locationArray[21][1].setLocation(40.808291, 29.356721); // //

    locationArray[23][0].setLocation(40.808507, 29.355737); // //
    locationArray[23][1].setLocation(40.808421, 29.355828); // //

    locationArray[5][0].setLocation(40.808363, 29.356709); // //
    locationArray[5][1].setLocation(40.808217, 29.357031); // //

    locationArray[13][0].setLocation(40.808297, 29.357042); // //
    locationArray[13][1].setLocation(40.808131, 29.357593); // //

    locationArray[1][0].setLocation(40.808185, 29.357578); // //
    locationArray[1][1].setLocation(40.807947, 29.358518); // //

    locationArray[14][0].setLocation(40.808053, 29.358507); //
    locationArray[14][1].setLocation(40.807728, 29.359757); //

    locationArray[22][0].setLocation(40.807874, 29.359612); //
    locationArray[22][1].setLocation(40.807578, 29.360004); //

    locationArray[3][0].setLocation(40.807829, 29.359854); //
    locationArray[3][1].setLocation(40.807448, 29.361152); //

    locationArray[51][0].setLocation(40.807602, 29.361002); //
    locationArray[51][1].setLocation(40.807289, 29.361924); //

    locationArray[35][0].setLocation(40.807427, 29.361892); //
    locationArray[35][1].setLocation(40.806940, 29.363373); //

    locationArray[36][0].setLocation(40.807180, 29.363287); //
    locationArray[36][1].setLocation(40.806721, 29.363694); //

    locationArray[30][0].setLocation(40.808465, 29.355586); //
    locationArray[30][1].setLocation(40.808183, 29.355725); //

    locationArray[46][0].setLocation(40.808294, 29.356553); // //
    locationArray[46][1].setLocation(40.808154, 29.356607); // //

    locationArray[38][0].setLocation(40.808145, 29.356463); // //
    locationArray[38][1].setLocation(40.808025, 29.356581); // //

    locationArray[43][0].setLocation(40.808054, 29.356448); // //
    locationArray[43][1].setLocation(40.807850, 29.356536); // //

    locationArray[41][0].setLocation(40.807864, 29.356369); // //
    locationArray[41][1].setLocation(40.807752, 29.356482); // //

    locationArray[55][0].setLocation(40.807758, 29.356346); // //
    locationArray[55][1].setLocation(40.807655, 29.356444); // //

    locationArray[53][0].setLocation(40.807640, 29.356319); // //
    locationArray[53][1].setLocation(40.807504, 29.356373); // //

    locationArray[45][0].setLocation(40.807465, 29.356263); // //
    locationArray[45][1].setLocation(40.807356, 29.356335); // //

    locationArray[47][0].setLocation(40.807798, 29.355994); // //
    locationArray[47][1].setLocation(40.807704, 29.356229); // //

    locationArray[52][0].setLocation(40.808238, 29.355535); //
    locationArray[52][1].setLocation(40.808037, 29.355648); //

    locationArray[28][0].setLocation(40.808110, 29.355502); //
    locationArray[28][1].setLocation(40.807889, 29.355588); //

    locationArray[24][0].setLocation(40.807888, 29.355458); // //
    locationArray[24][1].setLocation(40.807753, 29.355572); // //

    locationArray[48][0].setLocation(40.807853, 29.355622); // //
    locationArray[48][1].setLocation(40.807695, 29.355922); // //

    locationArray[29][0].setLocation(40.807773, 29.355358); //
    locationArray[29][1].setLocation(40.807266, 29.355383); //

    locationArray[27][0].setLocation(40.807323, 29.355238); //
    locationArray[27][1].setLocation(40.807124, 29.355366); //

    locationArray[18][0].setLocation(40.807262, 29.355382); //
    locationArray[18][1].setLocation(40.806990, 29.356184); //

    locationArray[4][0].setLocation(40.807425, 29.356365); // //
    locationArray[4][1].setLocation(40.807267, 29.356816); // //

    locationArray[37][0].setLocation(40.807336, 29.356881); // //
    locationArray[37][1].setLocation(40.807178, 29.357363); // //

    locationArray[44][0].setLocation(40.807230, 29.357448); // //
    locationArray[44][1].setLocation(40.807075, 29.357948); // //

    locationArray[39][0].setLocation(40.807127, 29.358011); // //
    locationArray[39][1].setLocation(40.806984, 29.358437); // //

    locationArray[11][0].setLocation(40.807055, 29.358445); // //
    locationArray[11][1].setLocation(40.806901, 29.358894); // //

    locationArray[15][0].setLocation(40.806958, 29.358916); // //
    locationArray[15][1].setLocation(40.806796, 29.359418); // //

    locationArray[17][0].setLocation(40.807662, 29.359612); //
    locationArray[17][1].setLocation(40.806803, 29.359624); //

    locationArray[12][0].setLocation(40.806820, 29.363386); //
    locationArray[12][1].setLocation(40.806109, 29.363447); //

    locationArray[33][0].setLocation(40.806867, 29.359442); // //
    locationArray[33][1].setLocation(40.806770, 29.359549); // //

    locationArray[2][0].setLocation(40.806854, 29.359556); //
    locationArray[2][1].setLocation(40.806416, 29.361267); //

    locationArray[54][0].setLocation(40.806553, 29.361224); //
    locationArray[54][1].setLocation(40.806242, 29.362161); //

    locationArray[31][0].setLocation(40.806385, 29.362109); //
    locationArray[31][1].setLocation(40.806056, 29.363286); //

    locationArray[10][0].setLocation(40.806216, 29.363220); //
    locationArray[10][1].setLocation(40.806003, 29.363429); //

    locationArray[40][0].setLocation(40.806781, 29.359181); // //
    locationArray[40][1].setLocation(40.806624, 29.359329); // //

    locationArray[25][0].setLocation(40.806761, 29.359384); //
    locationArray[25][1].setLocation(40.805951, 29.359310); //

    locationArray[34][0].setLocation(40.806020, 29.359118); //
    locationArray[34][1].setLocation(40.805819, 29.359308); //

    locationArray[7][0].setLocation(40.805888, 29.359080); //
    locationArray[7][1].setLocation(40.805607, 29.359149); //

    locationArray[26][0].setLocation(40.805785, 29.358839); //
    locationArray[26][1].setLocation(40.805539, 29.358975); //

    locationArray[32][0].setLocation(40.805682, 29.359058); //
    locationArray[32][1].setLocation(40.805499, 29.359127); //

    locationArray[8][0].setLocation(40.805674, 29.359210); //
    locationArray[8][1].setLocation(40.805493, 29.359278); //

    locationArray[6][0].setLocation(40.805969, 29.359312); //
    locationArray[6][1].setLocation(40.805648, 29.360328); //

    locationArray[50][0].setLocation(40.805752, 29.360396); //
    locationArray[50][1].setLocation(40.805442, 29.361541); //

    locationArray[16][0].setLocation(40.805536, 29.361520); //
    locationArray[16][1].setLocation(40.805187, 29.362926); //

    locationArray[42][0].setLocation(40.805336, 29.362948); //
    locationArray[42][1].setLocation(40.805159, 29.363122); //

    locationArray[9][0].setLocation(40.805571, 29.363067); //
    locationArray[9][1].setLocation(40.805250, 29.363144); //

    locationArray[20][0].setLocation(40.805787, 29.363088); //
    locationArray[20][1].setLocation(40.805500, 29.363263); //

    locationArray[49][0].setLocation(40.805810, 29.362839); //
    locationArray[49][1].setLocation(40.805553, 29.363048); //

    locationArray[19][0].setLocation(40.806096, 29.363214); //
    locationArray[19][1].setLocation(40.805719, 29.363308); //

    clearBtnColor();
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
        char latitude[100], longitude[100];
        char tempBuf[256], tempBuf2[256];

        sscanf(recvMessage.c_str(),"%s %s %s %s",tempBuf,tempBuf2,latitude,longitude);

        int temp = MainWindow::currentLocation;
        bool flag=true;
        for (int i = 0; i < list.size(); ++i)
        {
            if(strcmp(latitude,locationArray[i][0].getLatitude())<=0 && strcmp(latitude,locationArray[i][1].getLatitude())>=0)
            {
                if(strcmp(longitude,locationArray[i][0].getLongitude())>=0 && strcmp(longitude,locationArray[i][1].getLongitude())<=0)
                {
                    flag=false;
                    currentLocation = i + 1;
                    if(temp!=currentLocation)
                    {
                        MainWindow::changeBtnColor(temp, (char*)"rgba(255, 255, 255, 0)");
                        on_pathBtn_clicked();
                        qDebug() << "currentLocation changed to:" << currentLocation;
                    }
                    else
                        qDebug() << "you have aldreay in this coordinate.";
                    break;
                }
            }
        }
        if(flag)
            qDebug() << "received msg is not in a button coordinate";
        recvMessage.clear();
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
        closeSocket();
    }

}

void MainWindow::on_serverBtn_clicked()
{
    clientCube();
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
    if(vectorShortestPath.size()>1)
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

    //qDebug() << "SENDING: next target: " << nextTarget << "angle: " << angle;

    char tempString[256];
    double upLongitude,downLongitude, upLatitude,downLatitude;

    sscanf(locationArray[nextTarget-1][0].getLongitude(),"%lf",&upLongitude);
    sscanf(locationArray[nextTarget-1][1].getLongitude(),"%lf",&downLongitude);
    sscanf(locationArray[nextTarget-1][0].getLatitude(),"%lf",&upLatitude);
    sscanf(locationArray[nextTarget-1][1].getLatitude(),"%lf",&downLatitude);

    sprintf(tempString, "d %lf %lf %d",(upLatitude+downLatitude)/2.0,(upLongitude+downLongitude)/2.0, angle);

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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_forceConnectBtn_clicked()
{
    mainMutex.lock();
    sendMessage.clear();
    sendMessage.append("yes");
    mainMutex.unlock();
}

int MainWindow::findAngle(int c, int t)
{
    int l = 350; //Magneting Heading 169S //
    int r = 170; //NE
    int d = 47;  //E
    int u = 290;   //N

    // yanlis
    if (c == 24 && t == 1)
        return r;
    else if (c == 24 && t == 31)
        return d;
    else if (c == 1 && t == 24)
        return l;
    else if (c == 1 && t == 22)
        return r;
    else if (c == 22 && t == 1)
        return l;
    else if (c == 22 && t == 6)
        return r;
    else if (c == 22 && t == 47)
        return d;
    else if (c == 6 && t == 14)
        return r;
    else if (c == 6 && t == 22)
        return l;
    else if (c == 14 && t == 6)
        return l;
    else if (c == 14 && t == 2)
        return r;
    else if (c == 2 && t == 14)
        return l;
    else if (c == 2 && t == 15)
        return r;
    else if (c == 15 && t == 2)
        return l;
    else if (c == 15 && t == 23)
        return r;
    else if (c == 23 && t == 15)
        return l;
    else if (c == 23 && t == 18)
        return d;
    else if (c == 23 && t == 4)
        return r;
    else if (c == 4 && t == 23)
        return l;
    else if (c == 4 && t == 52)
        return r;
    else if (c == 18 && t == 23)
        return u;
    else if (c == 18 && t == 34)
        return d;
    else if (c == 34 && t == 18)
        return u;
    else if (c == 34 && t == 3)
        return r;
    else if (c == 34 && t == 26)
        return d;
    else if (c == 34 && t == 16)
        return l;
    else if (c == 16 && t == 34)
        return r;
    else if (c == 16 && t == 41)
        return d;
    else if (c == 16 && t == 12)
        return l;
    else if (c == 41 && t == 16)
        return u;
    else if (c == 12 && t == 16)
        return r;
    else if (c == 12 && t == 40)
        return l;
    else if (c == 40 && t == 12)
        return r;
    else if (c == 40 && t == 45)
        return l;
    else if (c == 45 && t == 40)
        return r;
    else if (c == 45 && t == 38)
        return l;
    else if (c == 38 && t == 45)
        return r;
    else if (c == 38 && t == 5)
        return l;
    else if (c == 5 && t == 38)
        return r;
    else if (c == 5 && t == 46)
        return l;
    else if (c == 46 && t == 5)
        return l;
    else if (c == 46 && t == 54)
        return u;
    else if (c == 54 && t == 46)
        return d;
    else if (c == 54 && t == 56)
        return u;
    else if (c == 56 && t == 54)
        return d;
    else if (c == 56 && t == 48)
        return l;
    else if (c == 56 && t == 42)
        return u;
    else if (c == 42 && t == 56)
        return d;
    else if (c == 42 && t == 44)
        return u;
    else if (c == 44 && t == 42)
        return d;
    else if (c == 44 && t == 39)
        return u;
    else if (c == 39 && t == 44)
        return d;
    else if (c == 39 && t == 47)
        return u;
    else if (c == 47 && t == 39)
        return d;
    else if (c == 47 && t == 22)
        return u;
    else if (c == 48 && t == 56)
        return r;
    else if (c == 48 && t == 49)
        return l;
    else if (c == 49 && t == 48)
        return r;
    else if (c == 49 && t == 25)
        return l;
    else if (c == 25 && t == 49)
        return r;
    else if (c == 25 && t == 30)
        return d;
    else if (c == 25 && t == 29)
        return u;
    else if (c == 29 && t == 25)
        return d;
    else if (c == 29 && t == 53)
        return u;
    else if (c == 53 && t == 29)
        return d;
    else if (c == 53 && t == 31)
        return u;
    else if (c == 31 && t == 53)
        return d;
    else if (c == 31 && t == 24)
        return u;
    else if (c == 30 && t == 25)
        return u;
    else if (c == 30 && t == 28)
        return d;
    else if (c == 28 && t == 30)
        return u;
    else if (c == 28 && t == 19)
        return r;
    else if (c == 19 && t == 28)
        return l;
    else if (c == 26 && t == 34)
        return u;
    else if (c == 26 && t == 35)
        return d;
    else if (c == 35 && t == 26)
        return u;
    else if (c == 35 && t == 7)
        return r;
    else if (c == 35 && t == 8)
        return d;
    else if (c == 8 && t == 35)
        return u;
    else if (c == 8 && t == 33)
        return d;
    else if (c == 33 && t == 8)
        return u;
    else if (c == 33 && t == 9)
        return r;
    else if (c == 33 && t == 27)
        return l;
    else if (c == 27 && t == 33)
        return r;
    else if (c == 9 && t == 33)
        return l;
    else if (c == 7 && t == 35)
        return l;
    else if (c == 7 && t == 51)
        return r;
    else if (c == 52 && t == 4)
        return l;
    else if (c == 52 && t == 36)
        return r;
    else if (c == 36 && t == 52)
        return l;
    else if (c == 36 && t == 37)
        return r;
    else if (c == 37 && t == 36)
        return l;
    else if (c == 37 && t == 13)
        return d;
    else if (c == 13 && t == 37)
        return u;
    else if (c == 13 && t == 11)
        return d;
    else if (c == 11 && t == 13)
        return u;
    else if (c == 11 && t == 32)
        return l;
    else if (c == 11 && t == 20)
        return d;
    else if (c == 3 && t == 34)
        return l;
    else if (c == 3 && t == 55)
        return r;
    else if (c == 55 && t == 3)
        return l;
    else if (c == 55 && t == 32)
        return r;
    else if (c == 32 && t == 55)
        return l;
    else if (c == 32 && t == 11)
        return r;
    else if (c == 20 && t == 11)
        return u;
    else if (c == 20 && t == 21)
        return d;
    else if (c == 21 && t == 20)
        return u;
    else if (c == 21 && t == 10)
        return d;
    else if (c == 21 && t == 50)
        return l;
    else if (c == 10 && t == 21)
        return u;
    else if (c == 10 && t == 43)
        return d;
    else if (c == 43 && t == 10)
        return u;
    else if (c == 43 && t == 17)
        return l;
    else if (c == 17 && t == 43)
        return r;
    else if (c == 17 && t == 51)
        return l;
    else if (c == 51 && t == 17)
        return r;
    else if (c == 51 && t == 7)
        return l;
    else
        return -1;
}


void MainWindow::on_pushButton_1_clicked(){ selectTarget(ui->pushButton_1); }
void MainWindow::on_pushButton_2_clicked(){ selectTarget(ui->pushButton_2); }
void MainWindow::on_pushButton_3_clicked(){ selectTarget(ui->pushButton_3); }
void MainWindow::on_pushButton_4_clicked(){ selectTarget(ui->pushButton_4); }
void MainWindow::on_pushButton_5_clicked(){ selectTarget(ui->pushButton_5); }
void MainWindow::on_pushButton_6_clicked(){ selectTarget(ui->pushButton_6); }
void MainWindow::on_pushButton_7_clicked(){ selectTarget(ui->pushButton_7); }
void MainWindow::on_pushButton_8_clicked(){ selectTarget(ui->pushButton_8); }
void MainWindow::on_pushButton_9_clicked(){ selectTarget(ui->pushButton_9); }
void MainWindow::on_pushButton_10_clicked(){ selectTarget(ui->pushButton_10); }
void MainWindow::on_pushButton_11_clicked(){ selectTarget(ui->pushButton_11); }
void MainWindow::on_pushButton_12_clicked(){ selectTarget(ui->pushButton_12); }
void MainWindow::on_pushButton_13_clicked(){ selectTarget(ui->pushButton_13); }
void MainWindow::on_pushButton_14_clicked(){ selectTarget(ui->pushButton_14); }
void MainWindow::on_pushButton_15_clicked(){ selectTarget(ui->pushButton_15); }
void MainWindow::on_pushButton_16_clicked(){ selectTarget(ui->pushButton_16); }
void MainWindow::on_pushButton_17_clicked(){ selectTarget(ui->pushButton_17); }
void MainWindow::on_pushButton_18_clicked(){ selectTarget(ui->pushButton_18); }
void MainWindow::on_pushButton_19_clicked(){ selectTarget(ui->pushButton_19); }
void MainWindow::on_pushButton_20_clicked(){ selectTarget(ui->pushButton_20); }
void MainWindow::on_pushButton_21_clicked(){ selectTarget(ui->pushButton_21); }
void MainWindow::on_pushButton_22_clicked(){ selectTarget(ui->pushButton_22); }
void MainWindow::on_pushButton_23_clicked(){ selectTarget(ui->pushButton_23); }
void MainWindow::on_pushButton_24_clicked(){ selectTarget(ui->pushButton_24); }
void MainWindow::on_pushButton_25_clicked(){ selectTarget(ui->pushButton_25); }
void MainWindow::on_pushButton_26_clicked(){ selectTarget(ui->pushButton_26); }
void MainWindow::on_pushButton_27_clicked(){ selectTarget(ui->pushButton_27); }
void MainWindow::on_pushButton_28_clicked(){ selectTarget(ui->pushButton_28); }
void MainWindow::on_pushButton_29_clicked(){ selectTarget(ui->pushButton_29); }
void MainWindow::on_pushButton_30_clicked(){ selectTarget(ui->pushButton_30); }
void MainWindow::on_pushButton_31_clicked(){ selectTarget(ui->pushButton_31); }
void MainWindow::on_pushButton_32_clicked(){ selectTarget(ui->pushButton_32); }
void MainWindow::on_pushButton_33_clicked(){ selectTarget(ui->pushButton_33); }
void MainWindow::on_pushButton_34_clicked(){ selectTarget(ui->pushButton_34); }
void MainWindow::on_pushButton_35_clicked(){ selectTarget(ui->pushButton_35); }
void MainWindow::on_pushButton_36_clicked(){ selectTarget(ui->pushButton_36); }
void MainWindow::on_pushButton_37_clicked(){ selectTarget(ui->pushButton_37); }
void MainWindow::on_pushButton_38_clicked(){ selectTarget(ui->pushButton_38); }
void MainWindow::on_pushButton_39_clicked(){ selectTarget(ui->pushButton_39); }
void MainWindow::on_pushButton_40_clicked(){ selectTarget(ui->pushButton_40); }
void MainWindow::on_pushButton_41_clicked(){ selectTarget(ui->pushButton_41); }
void MainWindow::on_pushButton_42_clicked(){ selectTarget(ui->pushButton_42); }
void MainWindow::on_pushButton_43_clicked(){ selectTarget(ui->pushButton_43); }
void MainWindow::on_pushButton_44_clicked(){ selectTarget(ui->pushButton_44); }
void MainWindow::on_pushButton_45_clicked(){ selectTarget(ui->pushButton_45); }
void MainWindow::on_pushButton_46_clicked(){ selectTarget(ui->pushButton_46); }
void MainWindow::on_pushButton_47_clicked(){ selectTarget(ui->pushButton_47); }
void MainWindow::on_pushButton_48_clicked(){ selectTarget(ui->pushButton_48); }
void MainWindow::on_pushButton_49_clicked(){ selectTarget(ui->pushButton_49); }
void MainWindow::on_pushButton_50_clicked(){ selectTarget(ui->pushButton_50); }
void MainWindow::on_pushButton_51_clicked(){ selectTarget(ui->pushButton_51); }
void MainWindow::on_pushButton_52_clicked(){ selectTarget(ui->pushButton_52); }
void MainWindow::on_pushButton_53_clicked(){ selectTarget(ui->pushButton_53); }
void MainWindow::on_pushButton_54_clicked(){ selectTarget(ui->pushButton_54); }
void MainWindow::on_pushButton_55_clicked(){ selectTarget(ui->pushButton_55); }
void MainWindow::on_pushButton_56_clicked(){ selectTarget(ui->pushButton_56); }
