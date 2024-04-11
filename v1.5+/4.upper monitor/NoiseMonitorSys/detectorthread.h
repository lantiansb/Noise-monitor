
#ifndef DETECTORTHREAD_H
#define DETECTORTHREAD_H
#pragma execution_character_set("utf-8")

#include <QObject>
#include <QThread>

/** 为了防止运行别的(大规模高复杂度)程序的时候线程堵塞
 *  需要设计多线程程序,此为最核心的线程:获取下位机数据
 *  基本上只要保证获取下位机数据通畅就好了,其他的卡点也无所谓 **/
class DetectorThread : public QThread
{
    Q_OBJECT
public:
    explicit DetectorThread(QObject *parent = nullptr, int ms = 100);

public:
    int delayms;

signals:
    void dt_GetDataSingnal(void);

protected:
    void run(void);

};

#endif // DETECTORTHREAD_H
