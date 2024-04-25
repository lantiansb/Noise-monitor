﻿#include <myalgorithm.h>

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

/** ***************************************************
 * @param
 *      QString str: 需要被解析的字符串格式的经纬度数据
 * @brief
 *      将字符串经纬度数据转化为小数数据
 * ************************************************* **/
QVector<double> pharseStr(QString str)
{
    if(str.contains("unknown"))
        return QVector<double>{-1, -1};

    QVector<double>Pos;

    Pos.append(str.rightRef(str.size() - str.lastIndexOf(',') - 1).toDouble());
    Pos.append(str.leftRef(str.indexOf(',')).toDouble());

    return Pos;
}

/// _transformlat(double lng, double lat)
double _transformlat(double lng, double lat)
{
    double ret = 0;
    ret = -100.0 + 2.0 * lng + 3.0 * lat + 0.2 * lat * lat + 0.1 * lng * lat + 0.2 * sqrt(fabs(lng));
    ret += (20.0 * sin(6.0 * lng * PI) + 20.0 * sin(2.0 * lng * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(lat * PI) + 40.0 * sin(lat / 3.0 * PI)) * 2.0 / 3.0;
    ret += (160.0 * sin(lat / 12.0 * PI) + 320 * sin(lat * PI / 30.0)) * 2.0 / 3.0;

    return ret;
}

double _transformlng(double lng, double lat)
{
    double ret = 0;

    ret = 300.0 + lng + 2.0 * lat + 0.1 * lng * lng + 0.1 * lng * lat + 0.1 * sqrt(fabs(lng));
    ret += (20.0 * sin(6.0 * lng * PI) + 20.0 * sin(2.0 * lng * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(lng * PI) + 40.0 * sin(lng / 3.0 * PI)) * 2.0 / 3.0;
    ret += (150.0 * sin(lng / 12.0 * PI) + 300.0 * sin(lng / 30.0 * PI)) * 2.0 / 3.0;
    return ret;
}

/** ***************************************************
 * @param
 *      double lng: 原始坐标系的经度longtitude
 *      double lat: 原始坐标的纬度lantitude
 * @brief
 *      将下位机原始坐标数据转化为GCJ02
 * ************************************************* **/
QVector<double> WGS84ToGCJ02(double lng, double lat)
{
    double dlat = _transformlat(lng - 105.0, lat - 35.0);
    double dlng = _transformlng(lng - 105.0, lat - 35.0);
    double radlat = lat / 180.0 * PI;
    double magic = sin(radlat);
    magic = 1 - EE * magic * magic;
    double sqrtmagic = sqrt(magic);
    dlat = (dlat * 180.0) / ((A * (1 - EE)) / (magic * sqrtmagic) * PI);
    dlng = (dlng * 180.0) / (A / sqrtmagic * cos(radlat) * PI);
    double mglat = lat + dlat;
    double mglng = lng + dlng;

    return QVector<double>{mglng, mglat};
}

/** ***************************************************
 * @param
 *      double lng: 原始坐标系的经度longtitude
 *      double lat: 原始坐标的纬度lantitude
 * @brief
 *      将下位机传送的原始坐标(GCJ-02)格式转化为
 *      百度地图格式(BD-09)
 * ************************************************* **/
QVector<double> GCJ02ToBD09(double lng, double lat)
{
    if((lng == -1) ||(lat == -1))
        return QVector<double>{-1, -1};

    double z = sqrt(lng * lng + lat * lat) + 0.00002 * sin(lat * X_PI);
    double theta = atan2(lat, lng) + 0.000003 * cos(lng * X_PI);
    double bd_lng = z * cos(theta) + 0.0065;
    double bd_lat = z * sin(theta) + 0.006;

    return QVector<double>{bd_lng, bd_lat};
}