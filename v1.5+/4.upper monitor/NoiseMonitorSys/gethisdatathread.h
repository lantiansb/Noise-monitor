
#ifndef GETHISDATATHREAD_H
#define GETHISDATATHREAD_H


#include <QObject>
#include <QThread>

class GetHisDataThread : public QThread
{
    Q_OBJECT
public:
    explicit GetHisDataThread(QObject *parent = nullptr, int ms = 500);

public:
    int delayms;

signals:
    void gt_GetHisDataSingnal(void);

protected:
    void run(void);
};

#endif // GETHISDATATHREAD_H
