#include <myalgorithm.h>

/** ***************************************************
 * @param
 *      QVector<double>y:被积分数据
 *      double h:步长
 * @brief
 *      对指定数据使用复化simpson公式求积分
 * ************************************************* **/
double integral(QVector<double>y, double h)
{
    int i = 0;
    double res = 0;

    /// 复化simpson公式
    for(i = 0; (i + 2) < y.length(); i += 2)
        res += (h * (y[i] + 4*y[i+1] + y[i+2]) / 3.0);

    if(y.length()-i-1 == 1)
        res += (y[i] + y[i+1]) * h / 2.0;

    return res;
}
