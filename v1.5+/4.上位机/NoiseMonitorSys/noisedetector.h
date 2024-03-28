
#ifndef NOISEDETECTOR_H
#define NOISEDETECTOR_H
#pragma execution_character_set("utf-8")

#include <QObject>

#include <QSerialPortInfo>
#include <QSerialPort>

/** ***************************************************
 * 此NoiseDetector类是转门用来接收下位机数据的
 * 按照老师的说法,似乎频谱变化也是在下位机直接完成的
 * 因此这个类至少应该包含一个基本方法:获取原始和变化后的数据
 * ************************************************* **/
class NoiseDetector : public QObject
{
    Q_OBJECT
public:
    explicit NoiseDetector(QObject *parent = nullptr);
    ~NoiseDetector(void);

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

public:
    bool nd_OpenPort(void);
    void nd_InitSettings(void);
    QByteArray nd_ReadData();
    void nd_SendData(const char* script);
    void nd_CloseSerialPort(void);

    double nd_GetData(int id);

public slots:

private:
    QSerialPort* m_serial = nullptr;
    struct Settings m_currentSettings;

signals:

};

#endif // NOISEDETECTOR_H
