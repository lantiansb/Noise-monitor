
#ifndef UPDATEPLOTTHREAD_H
#define UPDATEPLOTTHREAD_H


#include <QObject>
#include <QThread>

class UpdatePlotThread : public QThread
{
    Q_OBJECT
public:
    explicit UpdatePlotThread(QObject *parent = nullptr, int ms = 500);

public:
    int delayms;

signals:
    void ut_UpdatePlotSingnal(void);

protected:
    void run(void);
};

#endif // UPDATEPLOTTHREAD_H
