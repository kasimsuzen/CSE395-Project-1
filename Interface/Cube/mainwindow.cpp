#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "shortestpath.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    drawShapes=false;
    ui->setupUi(this);

    list = QList<QPushButton*>();

    list.append(ui->btn);
    list.append(ui->btn_2);
    list.append(ui->btn_3);
    list.append(ui->btn_4);
    list.append(ui->btn_5);
    list.append(ui->btn_6);
    list.append(ui->btn_7);
    list.append(ui->btn_8);
    list.append(ui->btn_9);
    list.append(ui->btn_10);
    list.append(ui->btn_11);
    list.append(ui->btn_12);
    list.append(ui->btn_13);
    list.append(ui->btn_14);
    list.append(ui->btn_15);
    list.append(ui->btn_16);
    list.append(ui->btn_17);
    list.append(ui->btn_18);
    list.append(ui->btn_19);
    list.append(ui->btn_20);
    list.append(ui->btn_21);
    list.append(ui->btn_22);
    list.append(ui->btn_23);
    list.append(ui->btn_24);
    list.append(ui->btn_25);
    list.append(ui->btn_26);
    list.append(ui->btn_27);
    list.append(ui->btn_28);
    list.append(ui->btn_29);
    list.append(ui->btn_30);
    list.append(ui->btn_31);
    list.append(ui->btn_32);
    list.append(ui->btn_33);
    list.append(ui->btn_34);
    list.append(ui->btn_35);
    list.append(ui->btn_36);
    list.append(ui->btn_37);
    list.append(ui->btn_38);
    list.append(ui->btn_39);
    list.append(ui->btn_40);
    list.append(ui->btn_41);
    list.append(ui->btn_42);
    list.append(ui->btn_43);
    list.append(ui->btn_44);
    list.append(ui->btn_45);
    list.append(ui->btn_46);
    list.append(ui->btn_47);
    list.append(ui->btn_48);
    list.append(ui->btn_49);
    list.append(ui->btn_50);
    list.append(ui->btn_51);
    list.append(ui->btn_52);
    list.append(ui->btn_53);
    list.append(ui->btn_54);
    list.append(ui->btn_55);
    list.append(ui->btn_56);
    list.append(ui->btn_57);
    list.append(ui->btn_58);
    list.append(ui->btn_59);
    list.append(ui->btn_60);
    list.append(ui->btn_61);
    list.append(ui->btn_62);
    list.append(ui->btn_63);
    list.append(ui->btn_64);
    list.append(ui->btn_65);
    list.append(ui->btn_66);
    list.append(ui->btn_67);
    list.append(ui->btn_68);
    list.append(ui->btn_69);
    list.append(ui->btn_70);
    list.append(ui->btn_71);
    list.append(ui->btn_72);
    list.append(ui->btn_73);
    list.append(ui->btn_74);
    list.append(ui->btn_75);
    list.append(ui->btn_76);
    list.append(ui->btn_77);
    list.append(ui->btn_78);
    list.append(ui->btn_79);
    list.append(ui->btn_80);
    list.append(ui->btn_81);
    list.append(ui->btn_82);
    list.append(ui->btn_83);
    list.append(ui->btn_84);
    list.append(ui->btn_85);
    list.append(ui->btn_86);
    list.append(ui->btn_87);
    list.append(ui->btn_88);
    list.append(ui->btn_89);
    list.append(ui->btn_90);
    list.append(ui->btn_91);
    list.append(ui->btn_92);
    list.append(ui->btn_93);
    list.append(ui->btn_94);
    list.append(ui->btn_95);
    list.append(ui->btn_96);
    list.append(ui->btn_97);
    list.append(ui->btn_98);
    list.append(ui->btn_99);
    list.append(ui->btn_100);
    list.append(ui->btn_101);
    list.append(ui->btn_102);
    list.append(ui->btn_103);
    list.append(ui->btn_104);
    list.append(ui->btn_105);
    list.append(ui->btn_106);
    list.append(ui->btn_107);
    list.append(ui->btn_108);
    list.append(ui->btn_109);
    list.append(ui->btn_110);
    list.append(ui->btn_111);
    list.append(ui->btn_112);
    list.append(ui->btn_113);
    list.append(ui->btn_114);
    list.append(ui->btn_115);
    list.append(ui->btn_116);
    list.append(ui->btn_117);
    list.append(ui->btn_118);
    list.append(ui->btn_119);
    list.append(ui->btn_120);
    list.append(ui->btn_121);
    list.append(ui->btn_122);
    list.append(ui->btn_123);
    list.append(ui->btn_124);
    list.append(ui->btn_125);
    list.append(ui->btn_126);
    list.append(ui->btn_127);
    list.append(ui->btn_128);
    list.append(ui->btn_129);
    list.append(ui->btn_130);
    list.append(ui->btn_131);
    list.append(ui->btn_132);
    list.append(ui->btn_133);
    list.append(ui->btn_134);
    list.append(ui->btn_135);
    list.append(ui->btn_136);
    list.append(ui->btn_137);
    list.append(ui->btn_138);
    list.append(ui->btn_139);
    list.append(ui->btn_140);
    list.append(ui->btn_141);
    list.append(ui->btn_142);
    list.append(ui->btn_143);
    list.append(ui->btn_144);
    list.append(ui->btn_145);
    list.append(ui->btn_146);
    list.append(ui->btn_147);
    list.append(ui->btn_148);
    list.append(ui->btn_149);
    list.append(ui->btn_150);
    list.append(ui->btn_151);
    list.append(ui->btn_152);
    list.append(ui->btn_153);
    list.append(ui->btn_154);
    list.append(ui->btn_155);
    list.append(ui->btn_156);
    list.append(ui->btn_157);
    list.append(ui->btn_158);
    list.append(ui->btn_159);
    list.append(ui->btn_160);
    list.append(ui->btn_161);
    list.append(ui->btn_162);
    list.append(ui->btn_163);
    list.append(ui->btn_164);
    list.append(ui->btn_165);
    list.append(ui->btn_166);
    list.append(ui->btn_167);
    list.append(ui->btn_168);
    list.append(ui->btn_169);
    list.append(ui->btn_170);
    list.append(ui->btn_171);
    list.append(ui->btn_172);
    list.append(ui->btn_173);
    list.append(ui->btn_174);
    list.append(ui->btn_175);
    list.append(ui->btn_176);
    list.append(ui->btn_177);
    list.append(ui->btn_178);
    list.append(ui->btn_179);
    list.append(ui->btn_180);
    list.append(ui->btn_181);

    clearBtnColor();

    // ekran buyutme ozelligini kapat
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    currentLocation[0]=2;
    currentLocation[1]=5;
    changeBtnColor(currentLocation[0],currentLocation[1],(char *)"blue");

    targetLocation[0]=-1;
    targetLocation[1]=-1;

}

/*
 * Target ve current buton haricinde tum butonların renklerini transparan yapar
 */
void MainWindow::clearBtnColor()
{
    for (int i = 0; i < 181; ++i)
    {
        list[i]->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    }

    changeBtnColor(currentLocation[0],currentLocation[1],(char*)"blue");
    changeBtnColor(targetLocation[0],targetLocation[1],(char*)"red");
}

/*
 * Serverdan current locationdan aldığı yeri verilen renge boyar.
 *
*/
void MainWindow::changeBtnColor(int y,int x,char *color)
{
    /*// currentlocation ve targetlocation boyanmaz
    if( y == currentLocation[0] && x == currentLocation[1] )
        return;
    if( y == targetLocation[0] && x == targetLocation[1] )
        return;*/

    char temp[256],str[10];

    sprintf(temp,"QPushButton {background-color: %s;color: %s;}",color,color);
    sprintf(str,"%d,%d",y,x);

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
        char ch;
        btn->setStyleSheet("QPushButton {background-color: red;color: red;}");
        ui->info->setText(btn->text());
        sscanf(qstrToChar(btn->text()),"%d%c%d",&targetLocation[0],&ch,&targetLocation[1]);
        drawShapes = true;
    }
    else
    {
        btn->setStyleSheet("QPushButton {background-color: rgba(255, 255, 255, 0); color:rgba(255, 255, 255, 0);}");
        ui->info->setText(btn->text());
        targetLocation[0] = targetLocation[1] = -1;
        drawShapes = false;
    }
}

void MainWindow::on_connectServer_clicked()
{
    Client interface;

    if(interface.connectToHost("192.168.133.144", 6667))
        ui->label->setText("Server: On");
}

void MainWindow::on_findPath_clicked()
{
    clearBtnColor();

    // dijkstra
    ShortestPath sp;

    adjacency_list_t adjacency_list(3000);

    // 0. satir
    sp.addEdge(adjacency_list,0,1);
    sp.addEdge(adjacency_list,0,17);
    for (int var = 1; var < 16; ++var)
    {
        sp.addEdge(adjacency_list,var,var-1);
        sp.addEdge(adjacency_list,var,var+1);
        sp.addEdge(adjacency_list,var,var+17);
    }
    sp.addEdge(adjacency_list,16,15);
    sp.addEdge(adjacency_list,16,33);

    sp.addEdge(adjacency_list,17,0);
    sp.addEdge(adjacency_list,17,18);
    sp.addEdge(adjacency_list,17,34);

    // 1. satir
    for (int i = 18; i < 23; ++i)
    {
        sp.addEdge(adjacency_list,i,i-1);
        sp.addEdge(adjacency_list,i,i+1);
        sp.addEdge(adjacency_list,i,i+17);
        sp.addEdge(adjacency_list,i,i-17);
    }

    for (int i = 0; i < 4; ++i)
    {
        sp.addEdge(adjacency_list,i+23,i+22);
        sp.addEdge(adjacency_list,i+23,i+24);
        sp.addEdge(adjacency_list,i+23,i+6);
    }

    for (int i = 27; i < 32; ++i)
    {
        sp.addEdge(adjacency_list,i,i-1);
        sp.addEdge(adjacency_list,i,i+1);
        sp.addEdge(adjacency_list,i,i+17);
        sp.addEdge(adjacency_list,i,i-17);
    }

    sp.addEdge(adjacency_list,33,16);
    sp.addEdge(adjacency_list,33,32);
    sp.addEdge(adjacency_list,33,50);

    // 2. satir
    sp.addEdge(adjacency_list,34,17);
    sp.addEdge(adjacency_list,34,35);

    sp.addEdge(adjacency_list,35,34);
    sp.addEdge(adjacency_list,35,36);
    sp.addEdge(adjacency_list,35,18);

    for (int i = 0; i < 3; ++i) {
        sp.addEdge(adjacency_list,i+36,i+36-1);
        sp.addEdge(adjacency_list,i+36,i+36+1);
        sp.addEdge(adjacency_list,i+36,i+36-17);
        sp.addEdge(adjacency_list,i+36,i+36+17);
    }

    sp.addEdge(adjacency_list,39,38);
    sp.addEdge(adjacency_list,39,22);

    // 2. satir - ikinci yari
    sp.addEdge(adjacency_list,44,27);
    sp.addEdge(adjacency_list,44,45);
    sp.addEdge(adjacency_list,45,44);
    sp.addEdge(adjacency_list,45,28);
    sp.addEdge(adjacency_list,45,46);
    for (int i = 0; i < 3; ++i) {
        sp.addEdge(adjacency_list,i+46,i+46-1);
        sp.addEdge(adjacency_list,i+46,i+46+1);
        sp.addEdge(adjacency_list,i+46,i+46-17);
        sp.addEdge(adjacency_list,i+46,i+46+17);
    }
    sp.addEdge(adjacency_list,49,48);
    sp.addEdge(adjacency_list,49,50);
    sp.addEdge(adjacency_list,49,32);
    sp.addEdge(adjacency_list,50,49);
    sp.addEdge(adjacency_list,50,33);

    // 3 ile 14. satir arası
    for (int i = 0; i < 12; ++i)
    {
        sp.addEdge(adjacency_list,53+i*17,54+i*17);
        sp.addEdge(adjacency_list,53+i*17,36+i*17);
        sp.addEdge(adjacency_list,53+i*17,70+i*17);

        sp.addEdge(adjacency_list,54+i*17,53+i*17);
        sp.addEdge(adjacency_list,54+i*17,55+i*17);
        sp.addEdge(adjacency_list,54+i*17,37+i*17);
        sp.addEdge(adjacency_list,54+i*17,71+i*17);

        sp.addEdge(adjacency_list,55+i*17,54+i*17);
        sp.addEdge(adjacency_list,55+i*17,38+i*17);
        sp.addEdge(adjacency_list,55+i*17,72+i*17);

        sp.addEdge(adjacency_list,63+i*17,64+i*17);
        sp.addEdge(adjacency_list,63+i*17,46+i*17);
        sp.addEdge(adjacency_list,63+i*17,80+i*17);

        sp.addEdge(adjacency_list,64+i*17,63+i*17);
        sp.addEdge(adjacency_list,64+i*17,65+i*17);
        sp.addEdge(adjacency_list,64+i*17,47+i*17);
        sp.addEdge(adjacency_list,64+i*17,81+i*17);

        sp.addEdge(adjacency_list,65+i*17,64+i*17);
        sp.addEdge(adjacency_list,65+i*17,48+i*17);
        sp.addEdge(adjacency_list,65+i*17,82+i*17);
    }

    // ara cikinti - sol taraf
    sp.addEdge(adjacency_list,107,106);
    sp.addEdge(adjacency_list,106,107);
    sp.addEdge(adjacency_list,107,124);

    for (int i = 0; i < 3; ++i)
    {
        sp.addEdge(adjacency_list,124+i*17,123+i*17);
        sp.addEdge(adjacency_list,124+i*17,107+i*17);
        sp.addEdge(adjacency_list,124+i*17,141+i*17);
        sp.addEdge(adjacency_list,123+i*17,124+i*17);
    }

    sp.addEdge(adjacency_list,175,174);
    sp.addEdge(adjacency_list,174,175);
    sp.addEdge(adjacency_list,175,158);

    // ara cikinti - sag taraf
    sp.addEdge(adjacency_list,113,114);
    sp.addEdge(adjacency_list,113,130);
    sp.addEdge(adjacency_list,114,113);
    for (int i = 0; i < 3; ++i)
    {
        sp.addEdge(adjacency_list,130+i*17,131+i*17);
        sp.addEdge(adjacency_list,130+i*17,113+i*17);
        sp.addEdge(adjacency_list,130+i*17,147+i*17);
        sp.addEdge(adjacency_list,131+i*17,130+i*17);
    }

    sp.addEdge(adjacency_list,181,182);
    sp.addEdge(adjacency_list,181,164);
    sp.addEdge(adjacency_list,182,181);

    // 15. satir
    sp.addEdge(adjacency_list,257,258);
    sp.addEdge(adjacency_list,257,240);
    sp.addEdge(adjacency_list,257,274);

    sp.addEdge(adjacency_list,258,259);
    sp.addEdge(adjacency_list,258,257);
    sp.addEdge(adjacency_list,258,241);
    sp.addEdge(adjacency_list,258,275);

    sp.addEdge(adjacency_list,259,260);
    sp.addEdge(adjacency_list,259,258);
    sp.addEdge(adjacency_list,259,242);
    sp.addEdge(adjacency_list,259,276);

    for (int i = 0; i < 7; ++i)
    {
        sp.addEdge(adjacency_list,260+i,260+i+1);
        sp.addEdge(adjacency_list,260+i,260+i-1);
        sp.addEdge(adjacency_list,260+i,260+i+17);
    }

    sp.addEdge(adjacency_list,267,268);
    sp.addEdge(adjacency_list,267,266);
    sp.addEdge(adjacency_list,267,284);
    sp.addEdge(adjacency_list,267,250);

    sp.addEdge(adjacency_list,268,269);
    sp.addEdge(adjacency_list,268,267);
    sp.addEdge(adjacency_list,268,285);
    sp.addEdge(adjacency_list,268,251);

    sp.addEdge(adjacency_list,269,268);
    sp.addEdge(adjacency_list,269,252);
    sp.addEdge(adjacency_list,269,286);

    // 16. ve 17. satir
    sp.addEdge(adjacency_list,274,257);
    sp.addEdge(adjacency_list,274,275);
    sp.addEdge(adjacency_list,274,291);

    sp.addEdge(adjacency_list,291,274);
    sp.addEdge(adjacency_list,291,292);
    sp.addEdge(adjacency_list,291,308);

    for (int i = 0; i < 11; ++i)
    {
        sp.addEdge(adjacency_list,275+i,276+i);
        sp.addEdge(adjacency_list,275+i,274+i);
        sp.addEdge(adjacency_list,275+i,292+i);
        sp.addEdge(adjacency_list,275+i,258+i);

        sp.addEdge(adjacency_list,275+i+17,276+i+17);
        sp.addEdge(adjacency_list,275+i+17,274+i+17);
        sp.addEdge(adjacency_list,275+i+17,292+i+17);
        sp.addEdge(adjacency_list,275+i+17,258+i+17);
    }

    sp.addEdge(adjacency_list,286,285);
    sp.addEdge(adjacency_list,286,269);
    sp.addEdge(adjacency_list,286,303);

    sp.addEdge(adjacency_list,303,302);
    sp.addEdge(adjacency_list,303,286);
    sp.addEdge(adjacency_list,303,320);

    // son satir 18. satir

    sp.addEdge(adjacency_list,308,291);
    sp.addEdge(adjacency_list,308,309);

    for (int i = 0; i < 11; ++i)
    {
        sp.addEdge(adjacency_list,309+i,308+i);
        sp.addEdge(adjacency_list,309+i,310+i);
        sp.addEdge(adjacency_list,309+i,292+i);
    }

    sp.addEdge(adjacency_list,320,319);
    sp.addEdge(adjacency_list,320,303);

    int current=currentLocation[0]*17+currentLocation[1];
    int target=targetLocation[0]*17+targetLocation[1];

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    sp.DijkstraComputePaths(current, adjacency_list, min_distance, previous);
    std::cout << "Distance from "<<current<<" to "<<target<<": " << min_distance[target] << std::endl;
    std::list<vertex_t> path = sp.DijkstraGetShortestPathTo(target, previous);
    //qDebug() << path.size();
    while(!path.empty())
    {
        int x, y;
        x = path.front() % 17;
        y = path.front() / 17;
        changeBtnColor(y,x, (char*)"yellow");

        //qDebug() << path.front() << "-";
        path.pop_front();
    }

    changeBtnColor(currentLocation[0],currentLocation[1],(char*)"blue");
    changeBtnColor(targetLocation[0],targetLocation[1],(char*)"red");
}

void MainWindow::on_btn_clicked(){ changeColor(ui->btn); }
void MainWindow::on_btn_2_clicked(){ changeColor(ui->btn_2); }
void MainWindow::on_btn_3_clicked(){ changeColor(ui->btn_3); }
void MainWindow::on_btn_4_clicked(){ changeColor(ui->btn_4); }
void MainWindow::on_btn_5_clicked(){ changeColor(ui->btn_5); }
void MainWindow::on_btn_6_clicked(){ changeColor(ui->btn_6); }
void MainWindow::on_btn_7_clicked(){ changeColor(ui->btn_7); }
void MainWindow::on_btn_8_clicked(){ changeColor(ui->btn_8); }
void MainWindow::on_btn_9_clicked(){ changeColor(ui->btn_9); }
void MainWindow::on_btn_10_clicked(){ changeColor(ui->btn_10); }
void MainWindow::on_btn_11_clicked(){ changeColor(ui->btn_11); }
void MainWindow::on_btn_12_clicked(){ changeColor(ui->btn_12); }
void MainWindow::on_btn_13_clicked(){ changeColor(ui->btn_13); }
void MainWindow::on_btn_14_clicked(){ changeColor(ui->btn_14); }
void MainWindow::on_btn_15_clicked(){ changeColor(ui->btn_15); }
void MainWindow::on_btn_16_clicked(){ changeColor(ui->btn_16); }
void MainWindow::on_btn_17_clicked(){ changeColor(ui->btn_17); }
void MainWindow::on_btn_18_clicked(){ changeColor(ui->btn_18); }
void MainWindow::on_btn_19_clicked(){ changeColor(ui->btn_19); }
void MainWindow::on_btn_20_clicked(){ changeColor(ui->btn_20); }
void MainWindow::on_btn_21_clicked(){ changeColor(ui->btn_21); }
void MainWindow::on_btn_22_clicked(){ changeColor(ui->btn_22); }
void MainWindow::on_btn_23_clicked(){ changeColor(ui->btn_23); }
void MainWindow::on_btn_24_clicked(){ changeColor(ui->btn_24); }
void MainWindow::on_btn_25_clicked(){ changeColor(ui->btn_25); }
void MainWindow::on_btn_26_clicked(){ changeColor(ui->btn_26); }
void MainWindow::on_btn_27_clicked(){ changeColor(ui->btn_27); }
void MainWindow::on_btn_28_clicked(){ changeColor(ui->btn_28); }
void MainWindow::on_btn_29_clicked(){ changeColor(ui->btn_29); }
void MainWindow::on_btn_30_clicked(){ changeColor(ui->btn_30); }
void MainWindow::on_btn_31_clicked(){ changeColor(ui->btn_31); }
void MainWindow::on_btn_32_clicked(){ changeColor(ui->btn_32); }
void MainWindow::on_btn_33_clicked(){ changeColor(ui->btn_33); }
void MainWindow::on_btn_34_clicked(){ changeColor(ui->btn_34); }
void MainWindow::on_btn_35_clicked(){ changeColor(ui->btn_35); }
void MainWindow::on_btn_36_clicked(){ changeColor(ui->btn_36); }
void MainWindow::on_btn_37_clicked(){ changeColor(ui->btn_37); }
void MainWindow::on_btn_38_clicked(){ changeColor(ui->btn_38); }
void MainWindow::on_btn_39_clicked(){ changeColor(ui->btn_39); }
void MainWindow::on_btn_40_clicked(){ changeColor(ui->btn_40); }
void MainWindow::on_btn_41_clicked(){ changeColor(ui->btn_41); }
void MainWindow::on_btn_42_clicked(){ changeColor(ui->btn_42); }
void MainWindow::on_btn_43_clicked(){ changeColor(ui->btn_43); }
void MainWindow::on_btn_44_clicked(){ changeColor(ui->btn_44); }
void MainWindow::on_btn_45_clicked(){ changeColor(ui->btn_45); }
void MainWindow::on_btn_46_clicked(){ changeColor(ui->btn_46); }
void MainWindow::on_btn_47_clicked(){ changeColor(ui->btn_47); }
void MainWindow::on_btn_48_clicked(){ changeColor(ui->btn_48); }
void MainWindow::on_btn_49_clicked(){ changeColor(ui->btn_49); }
void MainWindow::on_btn_50_clicked(){ changeColor(ui->btn_50); }
void MainWindow::on_btn_51_clicked(){ changeColor(ui->btn_51); }
void MainWindow::on_btn_52_clicked(){ changeColor(ui->btn_52); }
void MainWindow::on_btn_53_clicked(){ changeColor(ui->btn_53); }
void MainWindow::on_btn_54_clicked(){ changeColor(ui->btn_54); }
void MainWindow::on_btn_55_clicked(){ changeColor(ui->btn_55); }
void MainWindow::on_btn_56_clicked(){ changeColor(ui->btn_56); }
void MainWindow::on_btn_57_clicked(){ changeColor(ui->btn_57); }
void MainWindow::on_btn_58_clicked(){ changeColor(ui->btn_58); }
void MainWindow::on_btn_59_clicked(){ changeColor(ui->btn_59); }
void MainWindow::on_btn_60_clicked(){ changeColor(ui->btn_60); }
void MainWindow::on_btn_61_clicked(){ changeColor(ui->btn_61); }
void MainWindow::on_btn_62_clicked(){ changeColor(ui->btn_62); }
void MainWindow::on_btn_63_clicked(){ changeColor(ui->btn_63); }
void MainWindow::on_btn_64_clicked(){ changeColor(ui->btn_64); }
void MainWindow::on_btn_65_clicked(){ changeColor(ui->btn_65); }
void MainWindow::on_btn_66_clicked(){ changeColor(ui->btn_66); }
void MainWindow::on_btn_67_clicked(){ changeColor(ui->btn_67); }
void MainWindow::on_btn_68_clicked(){ changeColor(ui->btn_68); }
void MainWindow::on_btn_69_clicked(){ changeColor(ui->btn_69); }
void MainWindow::on_btn_70_clicked(){ changeColor(ui->btn_70); }
void MainWindow::on_btn_71_clicked(){ changeColor(ui->btn_71); }
void MainWindow::on_btn_72_clicked(){ changeColor(ui->btn_72); }
void MainWindow::on_btn_73_clicked(){ changeColor(ui->btn_73); }
void MainWindow::on_btn_74_clicked(){ changeColor(ui->btn_74); }
void MainWindow::on_btn_75_clicked(){ changeColor(ui->btn_75); }
void MainWindow::on_btn_76_clicked(){ changeColor(ui->btn_76); }
void MainWindow::on_btn_77_clicked(){ changeColor(ui->btn_77); }
void MainWindow::on_btn_78_clicked(){ changeColor(ui->btn_78); }
void MainWindow::on_btn_79_clicked(){ changeColor(ui->btn_79); }
void MainWindow::on_btn_80_clicked(){ changeColor(ui->btn_80); }
void MainWindow::on_btn_81_clicked(){ changeColor(ui->btn_81); }
void MainWindow::on_btn_82_clicked(){ changeColor(ui->btn_82); }
void MainWindow::on_btn_83_clicked(){ changeColor(ui->btn_83); }
void MainWindow::on_btn_84_clicked(){ changeColor(ui->btn_84); }
void MainWindow::on_btn_85_clicked(){ changeColor(ui->btn_85); }
void MainWindow::on_btn_86_clicked(){ changeColor(ui->btn_86); }
void MainWindow::on_btn_87_clicked(){ changeColor(ui->btn_87); }
void MainWindow::on_btn_88_clicked(){ changeColor(ui->btn_88); }
void MainWindow::on_btn_89_clicked(){ changeColor(ui->btn_89); }
void MainWindow::on_btn_90_clicked(){ changeColor(ui->btn_90); }
void MainWindow::on_btn_91_clicked(){ changeColor(ui->btn_91); }
void MainWindow::on_btn_92_clicked(){ changeColor(ui->btn_92); }
void MainWindow::on_btn_93_clicked(){ changeColor(ui->btn_93); }
void MainWindow::on_btn_94_clicked(){ changeColor(ui->btn_94); }
void MainWindow::on_btn_95_clicked(){ changeColor(ui->btn_95); }
void MainWindow::on_btn_96_clicked(){ changeColor(ui->btn_96); }
void MainWindow::on_btn_97_clicked(){ changeColor(ui->btn_97); }
void MainWindow::on_btn_98_clicked(){ changeColor(ui->btn_98); }
void MainWindow::on_btn_99_clicked(){ changeColor(ui->btn_99); }
void MainWindow::on_btn_100_clicked(){ changeColor(ui->btn_100); }
void MainWindow::on_btn_101_clicked(){ changeColor(ui->btn_101); }
void MainWindow::on_btn_102_clicked(){ changeColor(ui->btn_102); }
void MainWindow::on_btn_103_clicked(){ changeColor(ui->btn_103); }
void MainWindow::on_btn_104_clicked(){ changeColor(ui->btn_104); }
void MainWindow::on_btn_105_clicked(){ changeColor(ui->btn_105); }
void MainWindow::on_btn_106_clicked(){ changeColor(ui->btn_106); }
void MainWindow::on_btn_107_clicked(){ changeColor(ui->btn_107); }
void MainWindow::on_btn_108_clicked(){ changeColor(ui->btn_108); }
void MainWindow::on_btn_109_clicked(){ changeColor(ui->btn_109); }
void MainWindow::on_btn_110_clicked(){ changeColor(ui->btn_110); }
void MainWindow::on_btn_111_clicked(){ changeColor(ui->btn_111); }
void MainWindow::on_btn_112_clicked(){ changeColor(ui->btn_112); }
void MainWindow::on_btn_113_clicked(){ changeColor(ui->btn_113); }
void MainWindow::on_btn_114_clicked(){ changeColor(ui->btn_114); }
void MainWindow::on_btn_115_clicked(){ changeColor(ui->btn_115); }
void MainWindow::on_btn_116_clicked(){ changeColor(ui->btn_116); }
void MainWindow::on_btn_117_clicked(){ changeColor(ui->btn_117); }
void MainWindow::on_btn_118_clicked(){ changeColor(ui->btn_118); }
void MainWindow::on_btn_119_clicked(){ changeColor(ui->btn_119); }
void MainWindow::on_btn_120_clicked(){ changeColor(ui->btn_120); }
void MainWindow::on_btn_121_clicked(){ changeColor(ui->btn_121); }
void MainWindow::on_btn_122_clicked(){ changeColor(ui->btn_122); }
void MainWindow::on_btn_123_clicked(){ changeColor(ui->btn_123); }
void MainWindow::on_btn_124_clicked(){ changeColor(ui->btn_124); }
void MainWindow::on_btn_125_clicked(){ changeColor(ui->btn_125); }
void MainWindow::on_btn_126_clicked(){ changeColor(ui->btn_126); }
void MainWindow::on_btn_127_clicked(){ changeColor(ui->btn_127); }
void MainWindow::on_btn_128_clicked(){ changeColor(ui->btn_128); }
void MainWindow::on_btn_129_clicked(){ changeColor(ui->btn_129); }
void MainWindow::on_btn_130_clicked(){ changeColor(ui->btn_130); }
void MainWindow::on_btn_131_clicked(){ changeColor(ui->btn_131); }
void MainWindow::on_btn_132_clicked(){ changeColor(ui->btn_132); }
void MainWindow::on_btn_133_clicked(){ changeColor(ui->btn_133); }
void MainWindow::on_btn_134_clicked(){ changeColor(ui->btn_134); }
void MainWindow::on_btn_135_clicked(){ changeColor(ui->btn_135); }
void MainWindow::on_btn_136_clicked(){ changeColor(ui->btn_136); }
void MainWindow::on_btn_137_clicked(){ changeColor(ui->btn_137); }
void MainWindow::on_btn_138_clicked(){ changeColor(ui->btn_138); }
void MainWindow::on_btn_139_clicked(){ changeColor(ui->btn_139); }
void MainWindow::on_btn_140_clicked(){ changeColor(ui->btn_140); }
void MainWindow::on_btn_141_clicked(){ changeColor(ui->btn_141); }
void MainWindow::on_btn_142_clicked(){ changeColor(ui->btn_142); }
void MainWindow::on_btn_143_clicked(){ changeColor(ui->btn_143); }
void MainWindow::on_btn_144_clicked(){ changeColor(ui->btn_144); }
void MainWindow::on_btn_145_clicked(){ changeColor(ui->btn_145); }
void MainWindow::on_btn_146_clicked(){ changeColor(ui->btn_146); }
void MainWindow::on_btn_147_clicked(){ changeColor(ui->btn_147); }
void MainWindow::on_btn_148_clicked(){ changeColor(ui->btn_148); }
void MainWindow::on_btn_149_clicked(){ changeColor(ui->btn_149); }
void MainWindow::on_btn_150_clicked(){ changeColor(ui->btn_150); }
void MainWindow::on_btn_151_clicked(){ changeColor(ui->btn_151); }
void MainWindow::on_btn_152_clicked(){ changeColor(ui->btn_152); }
void MainWindow::on_btn_153_clicked(){ changeColor(ui->btn_153); }
void MainWindow::on_btn_154_clicked(){ changeColor(ui->btn_154); }
void MainWindow::on_btn_155_clicked(){ changeColor(ui->btn_155); }
void MainWindow::on_btn_156_clicked(){ changeColor(ui->btn_156); }
void MainWindow::on_btn_157_clicked(){ changeColor(ui->btn_157); }
void MainWindow::on_btn_158_clicked(){ changeColor(ui->btn_158); }
void MainWindow::on_btn_159_clicked(){ changeColor(ui->btn_159); }
void MainWindow::on_btn_160_clicked(){ changeColor(ui->btn_160); }
void MainWindow::on_btn_161_clicked(){ changeColor(ui->btn_161); }
void MainWindow::on_btn_162_clicked(){ changeColor(ui->btn_162); }
void MainWindow::on_btn_163_clicked(){ changeColor(ui->btn_163); }
void MainWindow::on_btn_164_clicked(){ changeColor(ui->btn_164); }
void MainWindow::on_btn_165_clicked(){ changeColor(ui->btn_165); }
void MainWindow::on_btn_166_clicked(){ changeColor(ui->btn_166); }
void MainWindow::on_btn_167_clicked(){ changeColor(ui->btn_167); }
void MainWindow::on_btn_168_clicked(){ changeColor(ui->btn_168); }
void MainWindow::on_btn_169_clicked(){ changeColor(ui->btn_169); }
void MainWindow::on_btn_170_clicked(){ changeColor(ui->btn_170); }
void MainWindow::on_btn_171_clicked(){ changeColor(ui->btn_171); }
void MainWindow::on_btn_172_clicked(){ changeColor(ui->btn_172); }
void MainWindow::on_btn_173_clicked(){ changeColor(ui->btn_173); }
void MainWindow::on_btn_174_clicked(){ changeColor(ui->btn_174); }
void MainWindow::on_btn_175_clicked(){ changeColor(ui->btn_175); }
void MainWindow::on_btn_176_clicked(){ changeColor(ui->btn_176); }
void MainWindow::on_btn_177_clicked(){ changeColor(ui->btn_177); }
void MainWindow::on_btn_178_clicked(){ changeColor(ui->btn_178); }
void MainWindow::on_btn_179_clicked(){ changeColor(ui->btn_179); }
void MainWindow::on_btn_180_clicked(){ changeColor(ui->btn_180); }
void MainWindow::on_btn_181_clicked(){ changeColor(ui->btn_181); }
