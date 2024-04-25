
#ifndef NOISEMONITORSYS_H
#define NOISEMONITORSYS_H
#pragma execution_character_set("utf-8")

#include <QUrl>
#include <QVariant>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMainWindow>

#include <databaseoperator.h>
#include <detectorthread.h>
#include <updateplotthread.h>
#include <gethisdatathread.h>
#include <savedialog.h>
#include <devicemonitor.h>
#include <savestatistic.h>

#include <math.h>
#include <myalgorithm.h>

QT_BEGIN_NAMESPACE
namespace Ui { class NoiseMonitorSys; }
QT_END_NAMESPACE

class NoiseMonitorSys : public QMainWindow

{
    Q_OBJECT

public:
    NoiseMonitorSys(QWidget *parent = nullptr);
    ~NoiseMonitorSys();

public:
    void limitPlotInRange(void);
    void showHisPlotPoint(QMouseEvent *event);

    void initNoiseDB_Plot(void);
    void initHisData_Plot(void);
    void initDevice_List(void);
    void initHisData_List(void);
    void initNoiseSlave(void);
    void initThreadConnect(void);
    void initBaiduMap(void);

public:
    void saveDataToDB(int dataSize);
    void updataData(void);
    void updateHisData(void);
    void updatePlotSlot(void);
    void refreshHisPlot(double from, double to);
    void openPort(void);
    void closePort(void);
    void showState(QString text);

private slots:
    void on_ChooseDevice_Button_clicked();
    void on_CalHisData_Button_clicked();
    void on_SaveCSV_Button_clicked();
    void on_SaveStatistic_Button_clicked();
    void on_Start_Button_clicked();
    void on_Stop_Button_clicked();
    void on_Connect_Button_clicked();
    void on_DeviceMonitor_Button_clicked();
    void on_MaxWindow_Button_clicked();
    void on_ClearFlag_Button_clicked();
    void on_DeviceFlag_Button_clicked();
    void on_GetHisData_Button_clicked();
public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
        bool localEchoEnabled;
    };

private:
    Ui::NoiseMonitorSys *ui;

private:
    QSerialPort* nd = nullptr;
    DatabaseOperator* db = nullptr;
    DetectorThread* dThread = nullptr;
    UpdatePlotThread* uThread = nullptr;
    GetHisDataThread* gThread = nullptr;

    QVector<int>idList;
    QVector<QString>searchList;

    QVector<QVector<double>>location;
    QVector<QVector<double>>data;
    QVector<QVector<double>>savedData;
    QVector<QVector<double>>timeList;
    QVector<QVector<double>>savedTimeList;

    QVector<QVector<double>>dataHis;
    QVector<QVector<double>>savedDataHis;
    QVector<QVector<double>>timeListHis;
    QVector<QVector<double>>savedTimeListHis;

    struct Settings m_currentSettings;

    int nowIdChoice = -1;
    int nowHisChoice = -1;
    double tmpBuf = 0;
    double lstValid = 0;
    double globalSlaveTime = 0.0;
    double globalSlaveTimeHis = 0.0;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // NOISEMONITORSYS_H
