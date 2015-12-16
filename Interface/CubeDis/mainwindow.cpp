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
    list.append(ui->btn_7);
    list.append(ui->btn_11);
    list.append(ui->btn_19);
    list.append(ui->btn_20);
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
    list.append(ui->btn_60);
    list.append(ui->btn_61);
    list.append(ui->btn_62);
    list.append(ui->btn_63);
    list.append(ui->btn_66);
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
    list.append(ui->btn_182);
    list.append(ui->btn_183);
    list.append(ui->btn_188);
    list.append(ui->btn_189);
    list.append(ui->btn_190);
    list.append(ui->btn_191);
    list.append(ui->btn_192);
    list.append(ui->btn_193);
    list.append(ui->btn_194);
    list.append(ui->btn_195);
    list.append(ui->btn_196);
    list.append(ui->btn_197);
    list.append(ui->btn_198);
    list.append(ui->btn_199);
    list.append(ui->btn_200);
    list.append(ui->btn_201);
    list.append(ui->btn_202);
    list.append(ui->btn_203);
    list.append(ui->btn_204);
    list.append(ui->btn_205);
    list.append(ui->btn_206);
    list.append(ui->btn_207);
    list.append(ui->btn_208);
    list.append(ui->btn_209);
    list.append(ui->btn_210);
    list.append(ui->btn_211);
    list.append(ui->btn_212);
    list.append(ui->btn_213);
    list.append(ui->btn_214);
    list.append(ui->btn_215);
    list.append(ui->btn_216);
    list.append(ui->btn_217);
    list.append(ui->btn_218);
    list.append(ui->btn_219);
    list.append(ui->btn_221);
    list.append(ui->btn_222);
    list.append(ui->btn_223);
    list.append(ui->btn_224);
    list.append(ui->btn_246);
    list.append(ui->btn_247);
    list.append(ui->btn_248);
    list.append(ui->btn_249);

    // ekran buyutme ozelligini kapat
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    clearBtnColor();


    targetLocation[0]=-1;
    targetLocation[1]=-1;

    // default current location
    currentLocation[0]=1;
    currentLocation[1]=7;
    changeBtnColor(currentLocation[0],currentLocation[1],(char *)"blue");

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
        //ui->info->setText(btn->text());
        sscanf(qstrToChar(btn->text()),"%d%c%d",&targetLocation[0],&ch,&targetLocation[1]);
        drawShapes = true;
    }
    else
    {
        btn->setStyleSheet("QPushButton {background-color: rgba(255, 255, 255, 0); color:rgba(255, 255, 255, 0);}");
        //ui->info->setText(btn->text());
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
    sp.addEdge(adjacency_list,0,43);

    sp.addEdge(adjacency_list,1,0);
    sp.addEdge(adjacency_list,1,2);

    sp.addEdge(adjacency_list,2,1);
    sp.addEdge(adjacency_list,2,3);
    sp.addEdge(adjacency_list,2,45);

    for (int i = 3; i < 7; ++i)
    {
        sp.addEdge(adjacency_list,i,i-1);
        sp.addEdge(adjacency_list,i,i+1);
    }

    for (int i = 0; i < 3; ++i)
    {
        sp.addEdge(adjacency_list,7+i,6+i);
        sp.addEdge(adjacency_list,7+i,8+i);
        sp.addEdge(adjacency_list,7+i,7+43+i);
    }

    for (int i = 10; i < 35; ++i)
    {
        sp.addEdge(adjacency_list,i,i-1);
        sp.addEdge(adjacency_list,i,i+1);
    }

    // en sol dikey cizgi
    for (int i = 1; i < 21; ++i)
    {
        sp.addEdge(adjacency_list,43*i,43*(i-1));
        sp.addEdge(adjacency_list,43*i,43*(i+1));
    }

    //bilgisayar bolgesi
    sp.addEdge(adjacency_list,7,7+43);
    sp.addEdge(adjacency_list,50,7);
    sp.addEdge(adjacency_list,50,93);

    sp.addEdge(adjacency_list,93,50);
    sp.addEdge(adjacency_list,93,93+43);

    sp.addEdge(adjacency_list,93+43,93);
    sp.addEdge(adjacency_list,93+43,93+43+1);

    sp.addEdge(adjacency_list,137,136);
    sp.addEdge(adjacency_list,137,180);

    sp.addEdge(adjacency_list,180,137);
    sp.addEdge(adjacency_list,180,223);

    sp.addEdge(adjacency_list,223,180);
    sp.addEdge(adjacency_list,223,224);


    // bilgisayar ve kutuphane arasi duz hat
    for (int i = 9; i < 35; ++i)
    {
        sp.addEdge(adjacency_list,43*5+i,43*5+i+1);
        sp.addEdge(adjacency_list,43*5+i,43*5+i-1);
    }

    // yukardan kutphaneye
    sp.addEdge(adjacency_list,35,34);
    sp.addEdge(adjacency_list,35,78);

    for (int i = 1; i < 25; ++i)
    {
        sp.addEdge(adjacency_list,35+43*i,35+43*(i-1));
        sp.addEdge(adjacency_list,35+43*i,35+43*(i+1));
    }

    sp.addEdge(adjacency_list,43*5+35,43*5+35-1);

    sp.addEdge(adjacency_list,43*7+33,43*7+33+1);

    sp.addEdge(adjacency_list,43*7+34,43*7+33);
    sp.addEdge(adjacency_list,43*7+34,43*7+35);

    sp.addEdge(adjacency_list,43*7+35,43*7+34);

    sp.addEdge(adjacency_list,43*11,43*11+1);

    for (int i = 1; i < 35; ++i)
    {
        sp.addEdge(adjacency_list,43*11+i,43*11+i+1);
        sp.addEdge(adjacency_list,43*11+i,43*11+i-1);
    }

    sp.addEdge(adjacency_list,43*11+35,43*11+34);


    int current=currentLocation[0]*43+currentLocation[1];
    int target=targetLocation[0]*43+targetLocation[1];

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    sp.DijkstraComputePaths(current, adjacency_list, min_distance, previous);
    std::cout << "Distance from "<<current<<" to "<<target<<": " << min_distance[target] << std::endl;
    std::list<vertex_t> path = sp.DijkstraGetShortestPathTo(target, previous);
    //qDebug() << path.size();
    while(!path.empty())
    {
        int x, y;
        x = path.front()%43;
        y = path.front()/43;
        changeBtnColor(y,x, (char*)"yellow");

        //qDebug() << path.front();
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
void MainWindow::on_btn_7_clicked(){ changeColor(ui->btn_7); }
void MainWindow::on_btn_11_clicked(){ changeColor(ui->btn_11); }
void MainWindow::on_btn_19_clicked(){ changeColor(ui->btn_19); }
void MainWindow::on_btn_20_clicked(){ changeColor(ui->btn_20); }
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
void MainWindow::on_btn_60_clicked(){ changeColor(ui->btn_60); }
void MainWindow::on_btn_61_clicked(){ changeColor(ui->btn_61); }
void MainWindow::on_btn_62_clicked(){ changeColor(ui->btn_62); }
void MainWindow::on_btn_63_clicked(){ changeColor(ui->btn_63); }
void MainWindow::on_btn_66_clicked(){ changeColor(ui->btn_66); }
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
void MainWindow::on_btn_182_clicked(){ changeColor(ui->btn_182); }
void MainWindow::on_btn_183_clicked(){ changeColor(ui->btn_183); }
void MainWindow::on_btn_185_clicked(){ changeColor(ui->btn_185); }
void MainWindow::on_btn_188_clicked(){ changeColor(ui->btn_188); }
void MainWindow::on_btn_189_clicked(){ changeColor(ui->btn_189); }
void MainWindow::on_btn_190_clicked(){ changeColor(ui->btn_190); }
void MainWindow::on_btn_191_clicked(){ changeColor(ui->btn_191); }
void MainWindow::on_btn_192_clicked(){ changeColor(ui->btn_192); }
void MainWindow::on_btn_193_clicked(){ changeColor(ui->btn_193); }
void MainWindow::on_btn_194_clicked(){ changeColor(ui->btn_194); }
void MainWindow::on_btn_195_clicked(){ changeColor(ui->btn_195); }
void MainWindow::on_btn_196_clicked(){ changeColor(ui->btn_196); }
void MainWindow::on_btn_197_clicked(){ changeColor(ui->btn_197); }
void MainWindow::on_btn_198_clicked(){ changeColor(ui->btn_198); }
void MainWindow::on_btn_199_clicked(){ changeColor(ui->btn_199); }
void MainWindow::on_btn_200_clicked(){ changeColor(ui->btn_200); }
void MainWindow::on_btn_201_clicked(){ changeColor(ui->btn_201); }
void MainWindow::on_btn_202_clicked(){ changeColor(ui->btn_202); }
void MainWindow::on_btn_203_clicked(){ changeColor(ui->btn_203); }
void MainWindow::on_btn_204_clicked(){ changeColor(ui->btn_204); }
void MainWindow::on_btn_205_clicked(){ changeColor(ui->btn_205); }
void MainWindow::on_btn_206_clicked(){ changeColor(ui->btn_206); }
void MainWindow::on_btn_207_clicked(){ changeColor(ui->btn_207); }
void MainWindow::on_btn_208_clicked(){ changeColor(ui->btn_208); }
void MainWindow::on_btn_209_clicked(){ changeColor(ui->btn_209); }
void MainWindow::on_btn_210_clicked(){ changeColor(ui->btn_210); }
void MainWindow::on_btn_211_clicked(){ changeColor(ui->btn_211); }
void MainWindow::on_btn_212_clicked(){ changeColor(ui->btn_212); }
void MainWindow::on_btn_213_clicked(){ changeColor(ui->btn_213); }
void MainWindow::on_btn_214_clicked(){ changeColor(ui->btn_214); }
void MainWindow::on_btn_215_clicked(){ changeColor(ui->btn_215); }
void MainWindow::on_btn_216_clicked(){ changeColor(ui->btn_216); }
void MainWindow::on_btn_217_clicked(){ changeColor(ui->btn_217); }
void MainWindow::on_btn_218_clicked(){ changeColor(ui->btn_218); }
void MainWindow::on_btn_219_clicked(){ changeColor(ui->btn_219); }
void MainWindow::on_btn_221_clicked(){ changeColor(ui->btn_221); }
void MainWindow::on_btn_222_clicked(){ changeColor(ui->btn_222); }
void MainWindow::on_btn_223_clicked(){ changeColor(ui->btn_223); }
void MainWindow::on_btn_224_clicked(){ changeColor(ui->btn_224); }
void MainWindow::on_btn_246_clicked(){ changeColor(ui->btn_246); }
void MainWindow::on_btn_247_clicked(){ changeColor(ui->btn_247); }
void MainWindow::on_btn_248_clicked(){ changeColor(ui->btn_248); }
void MainWindow::on_btn_249_clicked(){ changeColor(ui->btn_249); }
