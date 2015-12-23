#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shortestpath.h"
#include "location.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    drawShapes=false;

    ui->setupUi(this);

    list = QList<QPushButton*>();

    list.append(ui->pushButton);
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


    // clearBtnColor();
    // ekran buyutme ozelligini kapat
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    currentLocation=0;

    changeBtnColor(currentLocation,(char *)"blue");

    targetLocation=5;

    // butonlara paralel location arrayi olustulur
    Location** locationArray = new Location*[list.size()];
    for (int i = 0; i < list.size(); ++i) {
        locationArray[i] = new Location[2]; // 0-leftUp , 1-rightDown
    }

    locationArray[0][0].setLocation(40.808550, 29.355683);
    locationArray[0][1].setLocation(40.808368, 29.356546);

    locationArray[1][0].setLocation(40.808250, 29.357603);
    locationArray[1][1].setLocation(40.807698, 29.359931);

    locationArray[2][0].setLocation(40.806951 , 29.359642);
    locationArray[2][1].setLocation(40.806366 , 29.362066);

    locationArray[3][0].setLocation(40.807795 , 29.360017);
    locationArray[3][1].setLocation(40.807381 , 29.361863);

    locationArray[4][0].setLocation(40.807479 , 29.356359);
    locationArray[4][1].setLocation(40.807284 , 29.356895);

    locationArray[5][0].setLocation(40.808461 , 29.356627);
    locationArray[5][1].setLocation(40.808169 , 29.357571);

    locationArray[6][0].setLocation(40.806453 , 29.356904);
    locationArray[6][1].setLocation(40.805917 , 29.359253);

    locationArray[7][0].setLocation(40.805934 , 29.359135);
    locationArray[7][1].setLocation(40.805536 , 29.359118);

    locationArray[8][0].setLocation(40.805650 , 29.359150);
    locationArray[8][1].setLocation(40.805512 , 29.359246);

    locationArray[9][0].setLocation(40.806214 , 29.363323);
    locationArray[9][1].setLocation(40.805313 , 29.363140);

    locationArray[10][0].setLocation(40.804582 , 29.361853);
    locationArray[10][1].setLocation(40.804492 , 29.361949);

    locationArray[11][0].setLocation(40.807132 , 29.358344);
    locationArray[11][1].setLocation(40.806848 , 29.359407);

    locationArray[12][0].setLocation(40.806848 , 29.363473);
    locationArray[12][1].setLocation(40.806182 , 29.363398);

    locationArray[13][0].setLocation(40.806596 , 29.356166);
    locationArray[13][1].setLocation(40.806352 , 29.356832);

    locationArray[14][0].setLocation(40.805483 , 29.358988);
    locationArray[14][1].setLocation(40.804460 , 29.358795);

    locationArray[15][0].setLocation(40.805134 , 29.355308);
    locationArray[15][1].setLocation(40.804411 , 29.358653);

    locationArray[16][0].setLocation(40.805968 , 29.359253);
    locationArray[16][1].setLocation(40.805201 , 29.362939);

    locationArray[17][0].setLocation(40.807767 , 29.359720);
    locationArray[17][1].setLocation(40.806874 , 29.359111);

    locationArray[18][0].setLocation(40.807268 , 29.355345);
    locationArray[18][1].setLocation(40.807449 , 29.356096);

    locationArray[19][0].setLocation(40.804697 , 29.362248);
    locationArray[19][1].setLocation(40.804632 , 29.362353);

    locationArray[20][0].setLocation(40.804803 , 29.362553);
    locationArray[20][1].setLocation(40.804697 , 29.362602);

    locationArray[21][0].setLocation(40.805373 , 29.355041);
    locationArray[21][1].setLocation(40.805268 , 29.355170);

    locationArray[22][0].setLocation(40.805219 , 29.355105);
    locationArray[22][1].setLocation(40.805089 , 29.355223);

    locationArray[23][0].setLocation(40.805536 , 29.354955);
    locationArray[23][1].setLocation(40.805438 , 29.355105);

    locationArray[24][0].setLocation(40.805739 , 29.354869);
    locationArray[24][1].setLocation(40.805576 , 29.355009);

    locationArray[25][0].setLocation(40.806811 , 29.359440);
    locationArray[25][1].setLocation(40.805950 , 29.359225);

    locationArray[26][0].setLocation(40.805649 , 29.358952);
    locationArray[26][1].setLocation(40.805531 , 29.359021);

    locationArray[27][0].setLocation(40.804451 , 29.358710);
    locationArray[27][1].setLocation(40.804058 , 29.360395);

    locationArray[28][0].setLocation(40.807286 , 29.355266);
    locationArray[28][1].setLocation(40.806059 , 29.354939);

    locationArray[29][0].setLocation(40.808175 , 29.355567);
    locationArray[29][1].setLocation(40.807294 , 29.355357);

    locationArray[30][0].setLocation(40.808508 , 29.355652);
    locationArray[30][1].setLocation(40.808187 , 29.355636);

    locationArray[31][0].setLocation(40.806386 , 29.362173);
    locationArray[31][1].setLocation(40.806114 , 29.363235);

    locationArray[32][0].setLocation(40.804463 , 29.361535);
    locationArray[32][1].setLocation(40.804353 , 29.361589);

    locationArray[33][0].setLocation(40.804325 , 29.361197);
    locationArray[33][1].setLocation(40.804219 , 29.361315);

    locationArray[34][0].setLocation(40.804186 , 29.360800);
    locationArray[34][1].setLocation(40.804117 , 29.360875);

    locationArray[35][0].setLocation(40.807426 , 29.361910);
    locationArray[35][1].setLocation(40.807065 , 29.363347);

    locationArray[36][0].setLocation(40.807028 , 29.363455);
    locationArray[36][1].setLocation(40.806031 , 29.363535);

    locationArray[37][0].setLocation(40.807349 , 29.356915);
    locationArray[37][1].setLocation(40.807146 , 29.357607);

    locationArray[38][0].setLocation(40.808132 , 29.356499);
    locationArray[38][1].setLocation(40.808084 , 29.356564);

    locationArray[39][0].setLocation(40.807174 , 29.357797);
    locationArray[39][1].setLocation(40.807012 , 29.358286);

    locationArray[40][0].setLocation(40.806849 , 29.359160);
    locationArray[40][1].setLocation(40.806634 , 29.359321);

    locationArray[41][0].setLocation(40.807844 , 29.353660);
    locationArray[41][1].setLocation(40.807730 , 29.356456);

    locationArray[42][0].setLocation(40.807739 , 29.356188);
    locationArray[42][1].setLocation(40.807710 , 29.356247);

    locationArray[43][0].setLocation(40.808017 , 29.356419);
    locationArray[43][1].setLocation(40.807972 , 29.356499);

    locationArray[44][0].setLocation(40.807976 , 29.356378);
    locationArray[44][1].setLocation(40.807933 , 29.356454);

    locationArray[45][0].setLocation(40.807428 , 29.356263);
    locationArray[45][1].setLocation(40.807363 , 29.356322);

    locationArray[46][0].setLocation(40.808343 , 29.356542);
    locationArray[46][1].setLocation(40.808183 , 29.356569);

    locationArray[47][0].setLocation(40.807797 , 29.355976);
    locationArray[47][1].setLocation(40.807735 , 29.356078);

    locationArray[48][0].setLocation(40.807875 , 29.355550);
    locationArray[48][1].setLocation(40.807753 , 29.355901);

    locationArray[49][0].setLocation(40.805783 , 29.362866);
    locationArray[49][1].setLocation(40.805544 , 29.363086);

    locationArray[50][0].setLocation(40.808235 , 29.356854);
    locationArray[50][1].setLocation(40.808125 , 29.356951);

    locationArray[51][0].setLocation(40.808174 , 29.356731);
    locationArray[51][1].setLocation(40.808090 , 29.356803);

    locationArray[52][0].setLocation(40.808103 , 29.358440);
    locationArray[52][1].setLocation(40.808023 , 29.358571);

    locationArray[53][0].setLocation(40.807507 , 29.356293);
    locationArray[53][1].setLocation(40.807424 , 29.356328);

    locationArray[54][0].setLocation(40.805251 , 29.363003);
    locationArray[54][1].setLocation(40.804853 , 29.362904);

    locationArray[55][0].setLocation(40.807756 , 29.356374);
    locationArray[55][1].setLocation(40.807608 , 29.356414);

}


/*
 * Target ve current buton haricinde tum butonların renklerini transparan yapar
 */
void MainWindow::clearBtnColor()
{
    for (int i = 0; i < list.size(); ++i)
    {
        list[i]->setStyleSheet("background-color: red; color: rgba(255, 255, 255, 0);");
    }

    changeBtnColor(currentLocation,(char*)"blue");
    changeBtnColor(targetLocation,(char*)"red");
}

/*
 * Serverdan current locationdan aldığı yeri verilen renge boyar.
 *
*/
void MainWindow::changeBtnColor(int location,char *color)
{
    char temp[256],str[10];

    sprintf(temp,"QPushButton {background-color: %s;color: %s;}",color,color);
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

void MainWindow::changeColor(QPushButton* btn)
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

void MainWindow::on_pathBtn_clicked()
{
    clearBtnColor();

    // dijkstra
    ShortestPath sp;

    adjacency_list_t adjacency_list(30);

    // komsuluklar eklenir
    sp.addEdge(adjacency_list,0,1);


    int current=currentLocation;
    int target=targetLocation;

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    sp.DijkstraComputePaths(current, adjacency_list, min_distance, previous);
    std::cout << "Distance from "<<current<<" to "<<target<<": " << min_distance[target] << std::endl;
    std::list<vertex_t> path = sp.DijkstraGetShortestPathTo(target, previous);

    while(!path.empty())
    {
        changeBtnColor(path.front(), (char*)"yellow");
        path.pop_front();
    }

    changeBtnColor(currentLocation,(char*)"blue");
    changeBtnColor(targetLocation,(char*)"red");
}

void MainWindow::on_pushButton_clicked(){ changeColor(ui->pushButton); }
void MainWindow::on_pushButton_2_clicked(){ changeColor(ui->pushButton_2); }
void MainWindow::on_pushButton_3_clicked(){ changeColor(ui->pushButton_3); }
void MainWindow::on_pushButton_4_clicked(){ changeColor(ui->pushButton_4); }
void MainWindow::on_pushButton_5_clicked(){ changeColor(ui->pushButton_5); }
void MainWindow::on_pushButton_6_clicked(){ changeColor(ui->pushButton_6); }
void MainWindow::on_pushButton_7_clicked(){ changeColor(ui->pushButton_7); }
void MainWindow::on_pushButton_8_clicked(){ changeColor(ui->pushButton_8); }
void MainWindow::on_pushButton_9_clicked(){ changeColor(ui->pushButton_9); }
void MainWindow::on_pushButton_10_clicked(){ changeColor(ui->pushButton_10); }
void MainWindow::on_pushButton_11_clicked(){ changeColor(ui->pushButton_11); }
void MainWindow::on_pushButton_12_clicked(){ changeColor(ui->pushButton_12); }
void MainWindow::on_pushButton_13_clicked(){ changeColor(ui->pushButton_13); }
void MainWindow::on_pushButton_14_clicked(){ changeColor(ui->pushButton_14); }
void MainWindow::on_pushButton_15_clicked(){ changeColor(ui->pushButton_15); }
void MainWindow::on_pushButton_16_clicked(){ changeColor(ui->pushButton_16); }
void MainWindow::on_pushButton_17_clicked(){ changeColor(ui->pushButton_17); }
void MainWindow::on_pushButton_18_clicked(){ changeColor(ui->pushButton_18); }
void MainWindow::on_pushButton_19_clicked(){ changeColor(ui->pushButton_19); }
void MainWindow::on_pushButton_20_clicked(){ changeColor(ui->pushButton_20); }
void MainWindow::on_pushButton_21_clicked(){ changeColor(ui->pushButton_21); }
void MainWindow::on_pushButton_22_clicked(){ changeColor(ui->pushButton_22); }
void MainWindow::on_pushButton_23_clicked(){ changeColor(ui->pushButton_23); }
void MainWindow::on_pushButton_24_clicked(){ changeColor(ui->pushButton_24); }
void MainWindow::on_pushButton_25_clicked(){ changeColor(ui->pushButton_25); }
void MainWindow::on_pushButton_26_clicked(){ changeColor(ui->pushButton_26); }
void MainWindow::on_pushButton_27_clicked(){ changeColor(ui->pushButton_27); }
void MainWindow::on_pushButton_28_clicked(){ changeColor(ui->pushButton_28); }
void MainWindow::on_pushButton_29_clicked(){ changeColor(ui->pushButton_29); }
void MainWindow::on_pushButton_30_clicked(){ changeColor(ui->pushButton_30); }
void MainWindow::on_pushButton_31_clicked(){ changeColor(ui->pushButton_31); }
void MainWindow::on_pushButton_32_clicked(){ changeColor(ui->pushButton_32); }
void MainWindow::on_pushButton_33_clicked(){ changeColor(ui->pushButton_33); }
void MainWindow::on_pushButton_34_clicked(){ changeColor(ui->pushButton_34); }
void MainWindow::on_pushButton_35_clicked(){ changeColor(ui->pushButton_35); }
void MainWindow::on_pushButton_36_clicked(){ changeColor(ui->pushButton_36); }
void MainWindow::on_pushButton_37_clicked(){ changeColor(ui->pushButton_37); }
void MainWindow::on_pushButton_38_clicked(){ changeColor(ui->pushButton_38); }
void MainWindow::on_pushButton_39_clicked(){ changeColor(ui->pushButton_39); }
void MainWindow::on_pushButton_40_clicked(){ changeColor(ui->pushButton_40); }
void MainWindow::on_pushButton_41_clicked(){ changeColor(ui->pushButton_41); }
void MainWindow::on_pushButton_42_clicked(){ changeColor(ui->pushButton_42); }
void MainWindow::on_pushButton_43_clicked(){ changeColor(ui->pushButton_43); }
void MainWindow::on_pushButton_44_clicked(){ changeColor(ui->pushButton_44); }
void MainWindow::on_pushButton_45_clicked(){ changeColor(ui->pushButton_45); }
void MainWindow::on_pushButton_46_clicked(){ changeColor(ui->pushButton_46); }
void MainWindow::on_pushButton_47_clicked(){ changeColor(ui->pushButton_47); }
void MainWindow::on_pushButton_48_clicked(){ changeColor(ui->pushButton_48); }
void MainWindow::on_pushButton_49_clicked(){ changeColor(ui->pushButton_49); }
void MainWindow::on_pushButton_50_clicked(){ changeColor(ui->pushButton_50); }
void MainWindow::on_pushButton_51_clicked(){ changeColor(ui->pushButton_51); }
void MainWindow::on_pushButton_52_clicked(){ changeColor(ui->pushButton_52); }
void MainWindow::on_pushButton_53_clicked(){ changeColor(ui->pushButton_53); }
void MainWindow::on_pushButton_54_clicked(){ changeColor(ui->pushButton_54); }
void MainWindow::on_pushButton_55_clicked(){ changeColor(ui->pushButton_55); }
void MainWindow::on_pushButton_56_clicked(){ changeColor(ui->pushButton_56); }
