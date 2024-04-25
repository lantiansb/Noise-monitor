
#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <QDebug>
#include <QString>
#include <QVector>
#include <math.h>

#define X_PI (3.14159265358979324 * 3000.0 / 180.0)
#define PI (3.1415926535897932384626)
#define EE (0.00669342162296594323)
#define A (6378245.0)

double integral(QVector<double>y, double h);
QVector<double> pharseStr(QString str);
QVector<double> GCJ02ToBD09(double lng, double lat);
QVector<double> WGS84ToGCJ02(double lng, double lat);

#endif // MYALGORITHM_H
