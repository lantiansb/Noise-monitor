
#include "noisemonitorsys.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /** ***************************************************
     * 程序,启动! 但是启动前需要先做一些基础配置
     *  1. 隐藏软件的标题栏,防止串口堵塞
     *  2. 让软件显示位置居中
     *  3. 设置程序的外边距为0
     * ************************************************* **/
    NoiseMonitorSys w;

    /// Step1
    w.setWindowFlags(Qt::FramelessWindowHint);

    QDesktopWidget* desktop = QApplication::desktop();
    QWidget* mainScreen = desktop->screen(0);
    /// Step2

    w.move((mainScreen->width()-w.width())/2,
           (mainScreen->height()-w.height())/2);

    /// Step3
    w.centralWidget()->layout()->setMargin(0);

    w.show();

    return a.exec();
}
