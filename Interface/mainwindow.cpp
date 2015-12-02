#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    drawShapes=false;
    ui->setupUi(this);

    // make transparane
    ui->btn->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_2->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_3->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_4->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_5->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_6->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_7->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_8->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_9->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_10->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_11->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_12->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_13->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_14->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_15->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_16->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_17->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_18->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_19->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_20->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_21->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_22->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_23->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_24->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_25->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_26->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_27->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_28->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_29->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_30->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_31->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_32->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_33->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_34->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_35->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_36->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_37->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_38->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_39->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_40->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_41->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_42->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_43->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_44->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_45->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_46->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_47->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_48->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_49->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_50->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_51->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_52->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_53->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_54->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_55->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_56->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_57->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_58->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_59->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_60->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_61->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_62->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_63->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_64->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_65->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_66->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_67->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_68->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_69->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_70->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_71->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_72->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_73->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_74->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_75->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_76->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_77->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_78->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_79->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_80->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_81->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_82->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_83->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_84->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_85->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_86->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_87->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_88->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_89->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_90->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_91->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_92->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_93->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_94->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_95->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_96->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_97->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_98->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_99->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_100->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_101->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_102->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_103->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_104->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_105->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_106->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_107->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_108->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_109->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_110->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_111->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_112->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_113->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_114->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_115->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_116->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_117->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_118->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_119->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_120->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_121->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_122->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_123->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_124->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_125->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_126->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_127->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_128->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_129->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_130->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_131->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_132->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_133->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_134->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_135->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_136->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_137->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_138->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_139->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_140->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_141->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_142->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_143->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_144->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_145->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_146->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_147->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_148->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_149->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_150->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_151->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_152->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_153->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_154->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_155->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_156->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_157->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_158->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_159->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_160->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_161->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_162->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_163->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_164->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_165->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_166->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_167->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_168->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_169->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_170->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_171->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_172->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_173->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_174->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");
    ui->btn_175->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: rgba(255, 255, 255, 0);");

    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Client interface;

    if(interface.connectToHost("192.168.133.144", 6667))
        ui->label->setText("On");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(drawShapes)
    {
        QRectF rectangle(10.0, 20.0, 80.0, 60.0);
        int startAngle = 30 * 16;
        int spanAngle = 120 * 16;
        painter.drawArc(rectangle, startAngle, spanAngle);
    }
}

void MainWindow::changeColor(QPushButton* btn)
{
    if(!drawShapes)
    {
        btn->setStyleSheet("QPushButton {background-color: red;color: red;}");
        ui->info->setText(btn->text());
        drawShapes = true;
    }
    else
    {
        btn->setStyleSheet("QPushButton {background-color: rgba(255, 255, 255, 0); color:rgba(255, 255, 255, 0);}");
        ui->info->setText(btn->text());
        drawShapes = false;
    }
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
void MainWindow::on_btn_164_clicked(){ changeColor(ui->btn_163); }
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

