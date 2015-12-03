#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_btn_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_10_clicked();
    void on_btn_11_clicked();
    void on_btn_12_clicked();
    void on_btn_13_clicked();
    void on_btn_14_clicked();
    void on_btn_15_clicked();
    void on_btn_16_clicked();
    void on_btn_17_clicked();
    void on_btn_18_clicked();
    void on_btn_19_clicked();
    void on_btn_20_clicked();
    void on_btn_21_clicked();
    void on_btn_22_clicked();
    void on_btn_23_clicked();
    void on_btn_24_clicked();
    void on_btn_25_clicked();
    void on_btn_26_clicked();
    void on_btn_27_clicked();
    void on_btn_28_clicked();
    void on_btn_29_clicked();
    void on_btn_30_clicked();
    void on_btn_31_clicked();
    void on_btn_32_clicked();
    void on_btn_33_clicked();
    void on_btn_34_clicked();
    void on_btn_35_clicked();
    void on_btn_36_clicked();
    void on_btn_37_clicked();
    void on_btn_38_clicked();
    void on_btn_39_clicked();
    void on_btn_40_clicked();
    void on_btn_41_clicked();
    void on_btn_42_clicked();
    void on_btn_43_clicked();
    void on_btn_44_clicked();
    void on_btn_45_clicked();
    void on_btn_46_clicked();
    void on_btn_47_clicked();
    void on_btn_48_clicked();
    void on_btn_49_clicked();
    void on_btn_50_clicked();
    void on_btn_51_clicked();
    void on_btn_52_clicked();
    void on_btn_53_clicked();
    void on_btn_54_clicked();
    void on_btn_55_clicked();
    void on_btn_56_clicked();
    void on_btn_57_clicked();
    void on_btn_58_clicked();
    void on_btn_59_clicked();
    void on_btn_60_clicked();
    void on_btn_61_clicked();
    void on_btn_62_clicked();
    void on_btn_63_clicked();
    void on_btn_64_clicked();
    void on_btn_65_clicked();
    void on_btn_66_clicked();
    void on_btn_67_clicked();
    void on_btn_68_clicked();
    void on_btn_69_clicked();
    void on_btn_70_clicked();
    void on_btn_71_clicked();
    void on_btn_72_clicked();
    void on_btn_73_clicked();
    void on_btn_74_clicked();
    void on_btn_75_clicked();
    void on_btn_76_clicked();
    void on_btn_77_clicked();
    void on_btn_78_clicked();
    void on_btn_79_clicked();
    void on_btn_80_clicked();
    void on_btn_81_clicked();
    void on_btn_82_clicked();
    void on_btn_83_clicked();
    void on_btn_84_clicked();
    void on_btn_85_clicked();
    void on_btn_86_clicked();
    void on_btn_87_clicked();
    void on_btn_88_clicked();
    void on_btn_89_clicked();
    void on_btn_90_clicked();
    void on_btn_91_clicked();
    void on_btn_92_clicked();
    void on_btn_93_clicked();
    void on_btn_94_clicked();
    void on_btn_95_clicked();
    void on_btn_96_clicked();
    void on_btn_97_clicked();
    void on_btn_98_clicked();
    void on_btn_99_clicked();
    void on_btn_100_clicked();
    void on_btn_101_clicked();
    void on_btn_102_clicked();
    void on_btn_103_clicked();
    void on_btn_104_clicked();
    void on_btn_105_clicked();
    void on_btn_106_clicked();
    void on_btn_107_clicked();
    void on_btn_108_clicked();
    void on_btn_109_clicked();
    void on_btn_110_clicked();
    void on_btn_111_clicked();
    void on_btn_112_clicked();
    void on_btn_113_clicked();
    void on_btn_114_clicked();
    void on_btn_115_clicked();
    void on_btn_116_clicked();
    void on_btn_117_clicked();
    void on_btn_118_clicked();
    void on_btn_119_clicked();
    void on_btn_120_clicked();
    void on_btn_121_clicked();
    void on_btn_122_clicked();
    void on_btn_123_clicked();
    void on_btn_124_clicked();
    void on_btn_125_clicked();
    void on_btn_126_clicked();
    void on_btn_127_clicked();
    void on_btn_128_clicked();
    void on_btn_129_clicked();
    void on_btn_130_clicked();
    void on_btn_131_clicked();
    void on_btn_132_clicked();
    void on_btn_133_clicked();
    void on_btn_134_clicked();
    void on_btn_135_clicked();
    void on_btn_136_clicked();
    void on_btn_137_clicked();
    void on_btn_138_clicked();
    void on_btn_139_clicked();
    void on_btn_140_clicked();
    void on_btn_141_clicked();
    void on_btn_142_clicked();
    void on_btn_143_clicked();
    void on_btn_144_clicked();
    void on_btn_145_clicked();
    void on_btn_146_clicked();
    void on_btn_147_clicked();
    void on_btn_148_clicked();
    void on_btn_149_clicked();
    void on_btn_150_clicked();
    void on_btn_151_clicked();
    void on_btn_152_clicked();
    void on_btn_153_clicked();
    void on_btn_154_clicked();
    void on_btn_155_clicked();
    void on_btn_156_clicked();
    void on_btn_157_clicked();
    void on_btn_158_clicked();
    void on_btn_159_clicked();
    void on_btn_160_clicked();
    void on_btn_161_clicked();
    void on_btn_162_clicked();
    void on_btn_163_clicked();
    void on_btn_164_clicked();
    void on_btn_165_clicked();
    void on_btn_166_clicked();
    void on_btn_167_clicked();
    void on_btn_168_clicked();
    void on_btn_169_clicked();
    void on_btn_170_clicked();
    void on_btn_171_clicked();
    void on_btn_172_clicked();
    void on_btn_173_clicked();
    void on_btn_174_clicked();
    void on_btn_175_clicked();

private:
    Ui::MainWindow *ui;
    bool drawShapes;
    void changeColor(QPushButton* btn);

};

#endif // MAINWINDOW_H