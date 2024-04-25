
#include "gethisdatathread.h"

GetHisDataThread::GetHisDataThread(QObject *parent, int ms)
    : QThread{parent}
{
    this->delayms = ms;
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      重写run函数让线程根据设定的时间运行
 * ************************************************* **/
void GetHisDataThread::run(void)
{
    while(1)
    {
        this->msleep(this->delayms);
        emit this->gt_GetHisDataSingnal();
    }
}
