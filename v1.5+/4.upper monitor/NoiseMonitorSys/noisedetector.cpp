
#include "noisedetector.h"

#include <QDebug>
#include <QRandomGenerator>

NoiseDetector::NoiseDetector(QObject *parent)
    : QObject{parent}
{
    this->m_serial = new QSerialPort(this);
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      初始化串口配置:COM3,波特率115200,数据帧8bit
 *      无校验位,停止位1位...
 * ************************************************* **/
void NoiseDetector::nd_InitSettings(void)
{
    this->m_currentSettings.name = QString("COM4");
    this->m_currentSettings.baudRate = QSerialPort::Baud115200;
    this->m_currentSettings.dataBits = QSerialPort::Data8;
    this->m_currentSettings.parity = QSerialPort::NoParity;
    this->m_currentSettings.stopBits = QSerialPort::OneStop;
    this->m_currentSettings.flowControl = QSerialPort::NoFlowControl;
    this->m_currentSettings.localEchoEnabled = true;
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      开启串口
 * ************************************************* **/
bool NoiseDetector::nd_OpenPort(void)
{
    this->m_serial->setPortName(this->m_currentSettings.name);
    this->m_serial->setBaudRate(this->m_currentSettings.baudRate);
    this->m_serial->setDataBits(this->m_currentSettings.dataBits);
    this->m_serial->setParity(this->m_currentSettings.parity);
    this->m_serial->setStopBits(this->m_currentSettings.stopBits);
    this->m_serial->setFlowControl(this->m_currentSettings.flowControl);

    if(m_serial->open(QIODevice::ReadWrite))
    {
        return true;
    }
    qDebug() << "Open com error!";
    return false;
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      关闭串口
 * ************************************************* **/
void NoiseDetector::nd_CloseSerialPort()
{
    if (this->m_serial->isOpen())
        this->m_serial->close();
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      读取串口数据
 * ************************************************* **/
QByteArray NoiseDetector::nd_ReadData()
{
    const QByteArray data = this->m_serial->readAll();
    return data;
}

/** ***************************************************
 * @param
 *      none
 * @brief
 *      向串口发送数据
 * ************************************************* **/
void NoiseDetector::nd_SendData(const char* script)
{
    this->m_serial->write(script);
    this->m_serial->waitForBytesWritten();
}

/** ***************************************************
 * @param
 *      int id:下位机id,获取指定id的数据
 * @brief
 *      获取下位机的数据,两份数据应该是一起发送的
 *      因为如果是分步传送的话,可能会造成时序混乱
 * ************************************************* **/
double NoiseDetector::nd_GetData(int id)
{
//    char buf[] = {0, 'M', 'A', 'S', 'T', 'E', 'R', ' ', 'P', 'C', '\r', '\n', '\0'};
//    buf[0] = char(id);

//    this->nd_SendData(buf);
//    this->m_serial->waitForBytesWritten();
//    QByteArray rec = this->nd_ReadData();

//    return QString(rec).toDouble();
    return 1.0;
}

/// 执行析构函数关闭串口,清空指针
NoiseDetector::~NoiseDetector(void)
{
    this->nd_CloseSerialPort();
    delete this->m_serial;
}
