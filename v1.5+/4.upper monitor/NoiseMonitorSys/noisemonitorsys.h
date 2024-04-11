
#ifndef NOISEMONITORSYS_H
#define NOISEMONITORSYS_H
#pragma execution_character_set("utf-8")

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMainWindow>

#include <databaseoperator.h>
#include <detectorthread.h>
#include <updateplotthread.h>
#include <savedialog.h>
#include <devicemonitor.h>

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
    void initNoiseDB_Plot(void);
    void initHisData_Plot(void);
    void initDevice_List(void);
    void initDateTime_Edit(void);
    void initNoiseSlave(void);
    void initThreadConnect(void);

public:
    void saveDataToDB(int dataSize);
    void updataData(void);
    void updatePlotSlot(void);
    void updateHisPlot(QSqlQuery& hisData);
    void openPort(void);
    void closePort(void);

private slots:
    void on_ChooseDevice_Button_clicked();
    void on_CalHisData_Button_clicked();
    void on_SaveCSV_Button_clicked();
    void on_Start_Button_clicked();
    void on_Stop_Button_clicked();
    void on_Connect_Button_clicked();
    void on_DeviceMonitor_Button_clicked();
    void on_MaxWindow_Button_clicked();

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

    QVector<int>idList;
    QVector<QVector<double>>data;
    QVector<QVector<double>>savedData;
    QVector<qreal>timeList;
    QVector<qreal>savedTimeList;
    struct Settings m_currentSettings;

    int nowIdChoice = -1;
    double tmpBuf = 0;
    double lstValid = 0;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // NOISEMONITORSYS_H
