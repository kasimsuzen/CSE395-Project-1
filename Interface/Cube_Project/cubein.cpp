#include "cubein.h"
#include "ui_cubein.h"
#include "cubeout.h"

CubeIn::CubeIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CubeIn)
{
    ui->setupUi(this);

    drawShapes=false;

    currentLocation=-1;

    targetLocation=-1;

    // ekran buyutme ozelligini kapat
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

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

    clearBtnColor();
}


/*
 * Target ve current buton haricinde tum butonlarÄ±n renklerini transparan yapar
 */
void CubeIn::clearBtnColor()
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
 * Serverdan current locationdan aldÄ±ÄŸÄ± yeri verilen renge boyar.
 *
*/
void CubeIn::changeBtnColor(int location,char *color)
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

char* CubeIn::qstrToChar(QString str)
{
    QByteArray ba = str.toLatin1();
    char *c_str2 = ba.data();
    return c_str2;
}

CubeIn::~CubeIn()
{
    delete ui;
}

void CubeIn::changeColor(QPushButton* btn)
{
    if(!drawShapes)
    {
        btn->setStyleSheet("QPushButton {background-color: red;color: red;}");
        sscanf(qstrToChar(btn->text()),"%d",&targetLocation);
        drawShapes = true;
    }
    else
    {
        btn->setStyleSheet("QPushButton {background-color: rgba(255, 255, 255, 0); color:rgba(255, 255, 255, 0);}");
        targetLocation=-1;
        drawShapes = false;
    }
}

void CubeIn::on_pathBtn_clicked()
{
    clearBtnColor();

    if(targetLocation ==-1 || currentLocation == -1)
    {
        qDebug() << "target or current location is unknown!";
        return;
    }

    // dijkstra algoritma sinifi
    ShortestPath sp;
    adjacency_list_t adjacency_list(30);
    // komsuluklar eklenir
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
        return;
    }

    qDebug() << "Shortest Path:";
    // shortest path cizilir. yani buton renkleri degistirilir
    for (unsigned int i = 0; i < vectorShortestPath.size(); ++i)
    {
        qDebug().resetFormat() << vectorShortestPath.at(i);
        changeBtnColor(vectorShortestPath.at(i), (char*)"yellow");
    }
    int angle = findAngle(currentLocation,nextTarget);

    qDebug() << "SENDING: next target: " << nextTarget << "angle: " << angle << "move";
    if(angle==37)
        qDebug() << "right";
    else if(angle == 85)
        qDebug() << "down";
    else if(angle == 168)
        qDebug() << "left";
    else if(angle == 350)
        qDebug() << "up";
    else
        qDebug() << "unkown angle";
    changeBtnColor(currentLocation,(char*)"blue");
    changeBtnColor(targetLocation,(char*)"red");
}


void CubeIn::on_serverBtn_clicked()
{

}

int CubeIn::findAngle(int c, int t)
{
    int leftAngle = 168; //Magneting Heading 169S
    int rightAngle = 37; //NE
    int downAngle = 85;  //E
    int upAngle = 350;   //N

    if (c == 0 && t == 1)
        return rightAngle;
    else if (c == 1 && t == 0)
        return leftAngle;
    else if (c == 0 && t == 11)
        return leftAngle;
    else if (c == 11 && t == 0)
        return rightAngle;
    else if (c == 0 && t == 12)
        return upAngle;
    else if (c == 12 && t == 0)
        return downAngle;
    else if (c == 0 && t == 13)
        return upAngle;
    else if (c == 13 && t == 0)
        return downAngle;
    else if (c == 0 && t == 10)
        return downAngle;
    else if (c == 10 && t == 0)
        return upAngle;
    else if (c == 1 && t == 2)
        return rightAngle;
    else if (c == 2 && t == 1)
        return leftAngle;
    else if (c == 1 && t == 13)
        return upAngle;
    else if (c == 13 && t == 1)
        return downAngle;
    else if (c == 2 && t == 3)
        return rightAngle;
    else if (c == 3 && t == 2)
        return leftAngle;
    else if (c == 2 && t == 14)
        return upAngle;
    else if (c == 14 && t == 2)
        return downAngle;
    else if (c == 3 && t == 14)
        return upAngle;
    else if (c == 14 && t == 3)
        return downAngle;
    else if (c == 3 && t == 15)
        return upAngle;
    else if (c == 15 && t == 3)
        return downAngle;
    else if (c == 3 && t == 16)
        return rightAngle;
    else if (c == 16 && t == 3)
        return leftAngle;
    else if (c == 3 && t == 4)
        return downAngle;
    else if (c == 4 && t == 3)
        return upAngle;
    else if (c == 4 && t == 17)
        return rightAngle;
    else if (c == 17 && t == 4)
        return leftAngle;
    else if (c == 4 && t == 5)
        return downAngle;
    else if (c == 5 && t == 4)
        return upAngle;
    else if (c == 5 && t == 18)
        return rightAngle;
    else if (c == 18 && t == 5)
        return leftAngle;
    else if (c == 5 && t == 6)
        return downAngle;
    else if (c == 6 && t == 5)
        return upAngle;
    else if (c == 6 && t == 19)
        return rightAngle;
    else if (c == 19 && t == 6)
        return leftAngle;
    else if (c == 6 && t == 7)
        return leftAngle;
    else if (c == 7 && t == 6)
        return rightAngle;
    else if (c == 7 && t == 8)
        return leftAngle;
    else if (c == 8 && t == 7)
        return rightAngle;
    else if (c == 8 && t == 20)
        return leftAngle;
    else if (c == 20 && t == 8)
        return rightAngle;
    else if (c == 8 && t == 9)
        return upAngle;
    else if (c == 9 && t == 8)
        return downAngle;
    else if (c == 9 && t == 21)
        return leftAngle;
    else if (c == 21 && t == 9)
        return rightAngle;
    else if (c == 9 && t == 10)
        return upAngle;
    else if (c == 10 && t == 9)
        return downAngle;
    else if (c == 10 && t == 22)
        return leftAngle;
    else if (c == 22 && t == 10)
        return rightAngle;
    else
        return -1;
}

void CubeIn::on_pushButton_0_clicked()  { changeColor(ui->pushButton_0); }
void CubeIn::on_pushButton_1_clicked()  { changeColor(ui->pushButton_1); }
void CubeIn::on_pushButton_2_clicked()  { changeColor(ui->pushButton_2); }
void CubeIn::on_pushButton_3_clicked()  { changeColor(ui->pushButton_3); }
void CubeIn::on_pushButton_4_clicked()  { changeColor(ui->pushButton_4); }
void CubeIn::on_pushButton_5_clicked()  { changeColor(ui->pushButton_5); }
void CubeIn::on_pushButton_6_clicked()  { changeColor(ui->pushButton_6); }
void CubeIn::on_pushButton_7_clicked()  { changeColor(ui->pushButton_7); }
void CubeIn::on_pushButton_8_clicked()  { changeColor(ui->pushButton_8); }
void CubeIn::on_pushButton_9_clicked()  { changeColor(ui->pushButton_9); }
void CubeIn::on_pushButton_10_clicked() { changeColor(ui->pushButton_10); }
void CubeIn::on_z06_clicked()           { changeColor(ui->z06);}
void CubeIn::on_lab2_clicked()          { changeColor(ui->lab2);}
void CubeIn::on_z23_clicked()           { changeColor(ui->z23);}
void CubeIn::on_z11_clicked()           { changeColor(ui->z11);}
void CubeIn::on_lab1_clicked()          { changeColor(ui->lab1);}
void CubeIn::on_kantin_clicked()        { changeColor(ui->kantin);}
void CubeIn::on_lab3_clicked()          { changeColor(ui->lab3);}
void CubeIn::on_z10_clicked()           { changeColor(ui->z10);}
void CubeIn::on_z05_clicked()           { changeColor(ui->z05);}
void CubeIn::on_z04_clicked()           { changeColor(ui->z04);}
void CubeIn::on_z02_clicked()           { changeColor(ui->z02);}
void CubeIn::on_lab4_clicked()          { changeColor(ui->lab4);}

void CubeIn::on_mekanBtn_clicked(){
    this->hide();
    CubeOut cubeOutDoor;
    cubeOutDoor.setModal(true);
    cubeOutDoor.exec();
}
