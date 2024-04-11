
#include "noisemonitorsys.h"
#include "ui_noisemonitorsys.h"

#include <QDebug>

NoiseMonitorSys::NoiseMonitorSys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoiseMonitorSys)
{
    ui->setupUi(this);

    this->db = new DatabaseOperator();
    this->nd = new QSerialPort(this);
    this->dThread = new DetectorThread(this, 1000);
    this->uThread = new UpdatePlotThread(this, 1200);

    this->initNoiseDB_Plot();
    this->initHisData_Plot();
    this->initDevice_List();
    this->initDateTime_Edit();
    this->initNoiseSlave();
    this->initThreadConnect();

    this->initNoiseSlave();
    this->openPort();
}

NoiseMonitorSys::~NoiseMonitorSys()
{
    this->closePort();
    delete ui;
}

/** ***************************************************
 * @brief
 * 有个非常玄学的bug,如果一直按着窗口的标题栏,就无法接收串口
 * 数据,目前所有的研究都表明,如果主线程堵塞,无论是否使用多线
 * 程等,均会造成串口数据接收失败,因此只能删去标题栏,自定义标
 * 题栏了,所以要重新实现一遍窗口的拖动功能.
 * ************************************************* **/
QPoint global_mOffset;
bool global_isMove = false;

/// 鼠标按下,记录偏移量
void NoiseMonitorSys::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint startPos = event->globalPos();
        global_mOffset = startPos - this->geometry().topLeft();
        global_isMove = !global_isMove;
    }
    return;
}

/// 鼠标松开,记录结尾坐标,转移位置
void NoiseMonitorSys::mouseReleaseEvent(QMouseEvent *event)
{
    if(global_isMove)
    {
        QPoint endPos = event->globalPos();
        this->move(endPos - global_mOffset);
        global_isMove = !global_isMove;
    }
    return;
}

/// 初始化实时更新的NoiseDB_Plot图表
void NoiseMonitorSys::initNoiseDB_Plot(void)
{
    QFont font;
    font.setPixelSize(16);
    font.setFamily("黑体");
    this->ui->NoiseDB_Plot->legend->setFont(font);
    this->ui->NoiseDB_Plot->xAxis->setLabelFont(font);
    this->ui->NoiseDB_Plot->yAxis->setLabelFont(font);

    this->ui->NoiseDB_Plot->addGraph(0);
    this->ui->NoiseDB_Plot->graph(0)->setName("未知设备");
    this->ui->NoiseDB_Plot->xAxis->setLabel("时间（秒）");
    this->ui->NoiseDB_Plot->yAxis->setLabel("噪声强度（分贝）");

    /// 创建警报参考线(昼:60DB警报, 夜50DB警报)
    QCPItemStraightLine* rDayLine = new QCPItemStraightLine(this->ui->NoiseDB_Plot);
    rDayLine->setPen(QPen(Qt::red, 3, Qt::DotLine));
    rDayLine->point1->setCoords(0, 60);
    rDayLine->point2->setCoords(1, 60);

    QCPItemStraightLine* rNightLine = new QCPItemStraightLine(this->ui->NoiseDB_Plot);
    rNightLine->setPen(QPen(Qt::yellow, 3, Qt::DotLine));
    rNightLine->point1->setCoords(0, 50);
    rNightLine->point2->setCoords(1, 50);

    QSharedPointer<QCPAxisTickerDateTime> timer(new QCPAxisTickerDateTime);
    timer->setDateTimeFormat("hh:mm:ss");
    timer->setTickCount(10);
    timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    this->ui->NoiseDB_Plot->xAxis->setTicker(timer);

    this->ui->NoiseDB_Plot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignLeft);
    this->ui->NoiseDB_Plot->legend->setVisible(true);
    this->ui->NoiseDB_Plot->xAxis->setTickLabelRotation(25);
    this->ui->NoiseDB_Plot->xAxis->setRange(0, 200);
    this->ui->NoiseDB_Plot->yAxis->setRange(0, 100);
    this->ui->NoiseDB_Plot->replot();

    return;
}

/// 初始化显示历史数据的NoiseDB_Plot图表
void NoiseMonitorSys::initHisData_Plot(void)
{
    QFont font;
    font.setPixelSize(16);
    font.setFamily("黑体");
    this->ui->HisData_Plot->legend->setFont(font);
    this->ui->HisData_Plot->xAxis->setLabelFont(font);
    this->ui->HisData_Plot->yAxis->setLabelFont(font);

    this->ui->HisData_Plot->addGraph(0);
    this->ui->HisData_Plot->graph(0)->setName("未知设备");
    this->ui->HisData_Plot->xAxis->setLabel("时间（秒）");
    this->ui->HisData_Plot->yAxis->setLabel("噪声强度（分贝）");

    QCPItemStraightLine* rDayLine = new QCPItemStraightLine(this->ui->HisData_Plot);
    rDayLine->setPen(QPen(Qt::red, 3, Qt::DotLine));
    rDayLine->point1->setCoords(0, 60);
    rDayLine->point2->setCoords(1, 60);

    QCPItemStraightLine* rNightLine = new QCPItemStraightLine(this->ui->HisData_Plot);
    rNightLine->setPen(QPen(Qt::yellow, 3, Qt::DotLine));
    rNightLine->point1->setCoords(0, 50);
    rNightLine->point2->setCoords(1, 50);

    QSharedPointer<QCPAxisTickerDateTime> timer(new QCPAxisTickerDateTime);
    timer->setDateTimeFormat("hh:mm:ss");
    timer->setTickCount(10);
    timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    this->ui->HisData_Plot->xAxis->setTicker(timer);

    this->ui->HisData_Plot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignLeft);
    this->ui->HisData_Plot->legend->setVisible(true);
    this->ui->HisData_Plot->xAxis->setTickLabelRotation(25);
    this->ui->HisData_Plot->yAxis->setRange(0, 100);
    this->ui->HisData_Plot->replot();

    return;
}

/// 初始化设备选择列表Device_List
void NoiseMonitorSys::initDevice_List(void)
{
    QSqlQuery deviceList = this->db->db_SearchSQL("SELECT id, name, comments from devices;");
    QStringList showList;

    while(deviceList.next())
    {
        showList.append(QString("·ID:%1\n·名称:%2\n·注释:%3\n")\
                                .arg(deviceList.value(0).toString(),\
                                deviceList.value(1).toString(),\
                                deviceList.value(2).toString()));
        this->idList.append(deviceList.value(0).toInt());

        this->data.append(QVector<double>());
        this->savedData.append(QVector<double>());
    }

    QStringListModel* listModel = new QStringListModel(showList);
    this->ui->Device_List->setModel(listModel);

    return;
}

/// 初始化历史数据选择中的时间输入编辑框(提升用户体验)
void NoiseMonitorSys::initDateTime_Edit(void)
{
    double curSeclf = (double)(QDateTime::currentMSecsSinceEpoch()) / 1000.0;

    this->ui->Date_Edit->setDateTime(QDateTime::fromSecsSinceEpoch(curSeclf));
    this->ui->To_Edit->setDateTime(QDateTime::fromSecsSinceEpoch(curSeclf));

    return;
}

/// 初始化串口,配置属性结构体
void NoiseMonitorSys::initNoiseSlave(void)
{
    this->m_currentSettings.name = QString("COM5");
    this->m_currentSettings.baudRate = QSerialPort::Baud115200;
    this->m_currentSettings.dataBits = QSerialPort::Data8;
    this->m_currentSettings.parity = QSerialPort::NoParity;
    this->m_currentSettings.stopBits = QSerialPort::OneStop;
    this->m_currentSettings.flowControl = QSerialPort::NoFlowControl;
    this->m_currentSettings.localEchoEnabled = true;

    return;
}

/// 连接线程初始化
void NoiseMonitorSys::initThreadConnect(void)
{
    this->connect(this->dThread, &DetectorThread::dt_GetDataSingnal,
                  this, &NoiseMonitorSys::updataData);
    this->connect(this->uThread, &UpdatePlotThread::ut_UpdatePlotSingnal,
                  this, &NoiseMonitorSys::updatePlotSlot);

    connect(this, &NoiseMonitorSys::destroyed, this, [=](void){
        this->dThread->terminate();
        this->dThread->quit();
        this->dThread->wait();

        this->uThread->terminate();
        this->uThread->quit();
        this->dThread->wait();
    });

    return;
}

/** ***************************************************
 * @brief
 *      通过私有变量的结构体设置,打开串口,更新标记值
 * ************************************************* **/
bool global_isPortOpen = false;
void NoiseMonitorSys::openPort(void)
{
    this->nd->setPortName(this->m_currentSettings.name);
    this->nd->setBaudRate(this->m_currentSettings.baudRate);
    this->nd->setDataBits(this->m_currentSettings.dataBits);
    this->nd->setParity(this->m_currentSettings.parity);
    this->nd->setStopBits(this->m_currentSettings.stopBits);
    this->nd->setFlowControl(this->m_currentSettings.flowControl);

    if(this->nd->open(QIODevice::ReadWrite))
    {
        this->ui->State_Edit->insertHtml("<h4>成功打开串口！</h4>");
        global_isPortOpen = true;
        return;
    }

    this->ui->State_Edit->insertHtml("<h4>无法打开串口！</h4>");
    global_isPortOpen = false;

    return;
}

/** ***************************************************
 * @brief
 *      非常简单的方法,仅是用来关闭串口
 * ************************************************* **/
void NoiseMonitorSys::closePort(void)
{
    if(this->nd->isOpen())
        this->nd->close();
}

/** ***************************************************
 * @brief
 *      为了保证获取数据的实时性,用额外的线程获取下位机数据
 *      防止主程序做了繁杂的任务而错过数据
 * ************************************************* **/
void NoiseMonitorSys::updataData(void)
{
    static QVector<double>lastData(this->idList.length()+1, 0);
    QVector<double>noiseData(this->idList.length()+1, 0);
    QByteArray res;
    int idTemp = 0;
    double dbTemp = 0.0;

    /// 尝试通过读取到的数据填充noiseData,最多允许重试3次
    int retry = 0;
    while((noiseData.indexOf(0) != -1) && retry <= 3)
    {
        res = this->nd->readAll();
        for(int i = 0; i+3 < res.length(); ++i)
        {
            if((quint8)res.at(i) != 0xff)
                continue;

            dbTemp = ((quint8)res.at(i+2) * 256.0 + (quint8)res.at(i+3)) / 10.0;
            idTemp = this->idList.indexOf((int)res.at(i+1));
            noiseData[idTemp != -1 ? idTemp : this->idList.length()] = dbTemp;
        }
        ++retry;
    }

    /// 通讯总会有异常的0值,0显然是不合理的,因此需要延续上一个值
    for(int k = 0; k < noiseData.length(); ++k)
        lastData[k] = (noiseData[k] != 0) ? noiseData[k] : lastData[k];

    /// 干正事,记录数据,供后面的画图
    for(int i = 0; i < this->idList.length(); ++i)
    {
        this->data[i].append(lastData[i]);
        if(this->data[i].length() > 250)
        {
            this->savedData[i].append(this->data[i][0]);
            this->data[i].removeFirst();
        }
    }

    qreal curSeclf = QDateTime::currentMSecsSinceEpoch() / 1000.0;

    this->timeList.append(curSeclf);
    if(this->timeList.length() > 250)
    {
        this->savedTimeList.append(curSeclf);
        this->timeList.removeFirst();
    }

    this->saveDataToDB(100);
    return;
}

/** ***************************************************
 * @param
 *      dataSize:冗余数据超出dataSize时自动触发保存到数据库
 * @brief
 *      根据设定的冗余数据阈值触发自动保存到数据库,创建一个当
 *      天(tyyyy_mm_dd)的表,如果已经创建就直接提交,然后清空
 *      冗余数据存储区
 * ************************************************* **/
void NoiseMonitorSys::saveDataToDB(int dataSize)
{
    if(this->savedTimeList.length() < dataSize)
        return;

    ///获取当天时间,每天创建一张表
    QString tableName = QString("t%1").arg(QDateTime::fromSecsSinceEpoch(this->timeList.back()).toString("yyyy_MM_dd"));

    ///查询是否已经创建了今天的表,如果没有就创建一个
    if(!this->db->db_SearchSQL(QString("SELECT name FROM sqlite_master "
                                        "WHERE type='table' "
                                        "AND name='%1';").arg(tableName)).next())
    {
        this->db->db_WriteSQL(QString("create table %1("
                                      "id   integer not null,"
                                      "time REAL    not null,"
                                      "db   REAL    not null);").arg(tableName));
    }
    QString SaveSQL = QString("INSERT INTO %1(id, time, db) VALUES ").arg(tableName);
    for(int i = 0; i < dataSize; ++i)
    {
        for(int k = 0; k < this->idList.length(); ++k)
        {
            SaveSQL += QString("(%1, %2, %3),").arg(QString::number(this->idList[k]),
                       QString("%1").arg(this->savedTimeList[i], 0, 'f', 0),
                       QString("%1").arg(this->savedData[k][i], 0, 'f', 4));
        }
    }
    SaveSQL.chop(1);
    this->db->db_WriteSQL(SaveSQL);

    //// 保存完毕,清空缓冲区
    QVector<QVector<double>>().swap(this->savedData);
    QVector<qreal>().swap(this->savedTimeList);
    for(int j = 0; j < this->idList.length(); ++j)
        this->savedData.append(QVector<double>());

    return;
}

/** ***************************************************
 * @brief
 *      更新图表,图表更新速度比下位机获取速度慢一些
 *      实时计算指定的最近n秒内的Leq,L10,L50,L90
 * ************************************************* **/
void NoiseMonitorSys::updatePlotSlot(void)
{
    /// 没有选中任何设备,直接跳过
    if(this->nowIdChoice == -1)
        return;

    this->ui->NoiseDB_Plot->graph(0)->setData(this->timeList, this->data[this->nowIdChoice]);
    this->ui->NoiseDB_Plot->xAxis->setRange(this->timeList.back() - this->ui->NoiseDB_Plot->xAxis->range().size(), this->timeList.back());
    this->ui->NoiseDB_Plot->replot();

    /// 获取最近n秒的数据进行四参数计算,如果数据还不够10个,直接跳过
    int nSecs = this->ui->TimeRange_Edit->value();
    int dLen = this->data[this->nowIdChoice].length();

    if(dLen <= nSecs)
        return;

    QVector<double>dataTemp;
    for(int i = 0; i < nSecs; ++i)
        dataTemp.append(pow(10.0, 0.1 * this->data[this->nowIdChoice][dLen-i-1]));

    this->ui->Leq_Label->setText(tr("%1").arg(10.0 * log10(integral(dataTemp, 1.0) / nSecs), 0, 'f', 4));
    std::sort(dataTemp.begin(), dataTemp.end());
    this->ui->L10_Label->setText(tr("%1").arg(10.0 * log10(dataTemp[(int)(nSecs * 0.9)]), 0, 'f', 4));
    this->ui->L50_Label->setText(tr("%1").arg(10.0 * log10(dataTemp[(int)(nSecs * 0.5)]), 0, 'f', 4));
    this->ui->L90_Label->setText(tr("%1").arg(10.0 * log10(dataTemp[(int)(nSecs * 0.1)]), 0, 'f', 4));

    return;
}

/** ***************************************************
 * @param
 *      QsqlQuery& hisData:查询数据的引用,这样传参节省性能
 * @brief
 *      根据选中范围内数据库数据更新历史数据图表,显示
 *      数据统计结果(四个参数Leq,L10,L50,L90)
 * ************************************************* **/
void NoiseMonitorSys::updateHisPlot(QSqlQuery& hisData)
{
    if(this->nowIdChoice == -1)
        return;

    QVector<double>db;

    this->ui->HisData_Plot->removeGraph(0);
    this->ui->HisData_Plot->addGraph(0);
    this->ui->HisData_Plot->graph(0)->setName(tr("历史数据(id:%1)").arg(this->idList[this->nowIdChoice]));
    while(hisData.next())
    {
        this->ui->HisData_Plot->graph(0)->addData(hisData.value(0).toDouble(), hisData.value(1).toDouble());
        db.append(pow(10.0, 0.1 * hisData.value(1).toDouble()));
    }
    this->ui->HisData_Plot->replot();

    ///更新图表之后还需要更新统计结果,仅十个数据显然不能进行统计
    if(db.length() <= 10)
    {
        this->ui->State_Edit->insertPlainText("选中数据量过小,无法统计！");
        return;
    }

    this->ui->Leq_Label_H->setText(tr("%1").arg(10.0 * log10(integral(db, 1.0) / (double)db.length()), 0, 'f', 4));
    std::sort(db.begin(), db.end());
    this->ui->L10_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.9 * ((double)db.length())]), 0, 'f', 4));
    this->ui->L50_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.5 * ((double)db.length())]), 0, 'f', 4));
    this->ui->L90_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.1 * ((double)db.length())]), 0, 'f', 4));

    return;
}

/// 槽函数:确认监控某个设备
void NoiseMonitorSys::on_ChooseDevice_Button_clicked()
{
    if(this->idList.length() == 0)
        return;

    int choice = this->ui->Device_List->currentIndex().row();

    if(choice == -1)
        return;
    else
    {
        this->nowIdChoice = choice;
        this->ui->NoiseDB_Plot->removeGraph(0);
        this->ui->NoiseDB_Plot->addGraph(0);
        this->ui->NoiseDB_Plot->graph(0)->setName(QString("实时数据(id:%1)").arg(this->idList[choice]));
        this->ui->NoiseDB_Plot->replot();
    }
    return;
}

/// 槽函数:按照范围搜寻历史记录数据
void NoiseMonitorSys::on_CalHisData_Button_clicked()
{
    QString dateStr = this->ui->Date_Edit->date().toString("yyyy_MM_dd");
    QString tableName = QString("t%1").arg(dateStr);

    /// 根据选中的表名和日期范围筛选数据库数据
    double fromEpo = QDateTime::fromString(QString("%1 %2").arg(dateStr, this->ui->From_Edit->time().toString()), "yyyy_MM_dd hh:mm:ss").toMSecsSinceEpoch() / 1000.0;
    double toEpo = QDateTime::fromString(QString("%1 %2").arg(dateStr, this->ui->To_Edit->time().toString()), "yyyy_MM_dd hh:mm:ss").toMSecsSinceEpoch() / 1000.0;

    /// 如果没有选中监测设备,跳过
    if(this->nowIdChoice == -1)
        return;

    /// 生成数据库查询语句,查询数据,并更新历史数据图表
    QString sqlScpt   = QString("SELECT time, db FROM %1"
                                " WHERE time >= %2 AND"
                                " time <= %3 AND id = %4").arg(
                                tableName,
                                QString("%1").arg(fromEpo, 0, 'f', 0),
                                QString("%1").arg(toEpo, 0, 'f', 0),
                                QString::number(this->idList[this->nowIdChoice])
                                );
    this->ui->HisData_Plot->xAxis->setRange(fromEpo, toEpo);
    QSqlQuery hisData = this->db->db_SearchSQL(sqlScpt);
    this->updateHisPlot(hisData);

    return;
}

/// 保存选中数据到csv文件
void NoiseMonitorSys::on_SaveCSV_Button_clicked()
{
    /// 如果没有选中任何数据,则直接退出
    if(this->ui->HisData_Plot->graph(0)->data()->size() == 0)
        return;

    SaveDialog* dlg = new SaveDialog(this);
    /// Step1
    dlg->setWindowFlags(Qt::FramelessWindowHint);

    /// Step2
    dlg->move((QApplication::desktop()->width()-dlg->width())/2,
              (QApplication::desktop()->height()-dlg->height())/2);

    dlg->setDataAndId(this->idList[this->nowIdChoice], this->ui->HisData_Plot->graph(0)->data());
    dlg->show();

    return;
}

/// 点击启动按钮,才开始运行程序
bool global_isRunning = false;
void NoiseMonitorSys::on_Start_Button_clicked()
{
    qreal curSeclf = QDateTime::currentMSecsSinceEpoch() / 1000.0;
    if(!global_isPortOpen)
    {
        this->ui->State_Edit->insertHtml(tr("<h4>串口无法读取，运行失败！@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));
        global_isRunning = false;
        return;
    }

    this->dThread->start();
    this->uThread->start();

    this->ui->State_Edit->insertHtml(tr("<h4>启动运行@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));
    this->ui->Start_Button->setEnabled(false);
    this->ui->Stop_Button->setEnabled(true);
    global_isRunning = true;

    return;
}

/// 点击停止按钮,停止程序
void NoiseMonitorSys::on_Stop_Button_clicked()
{
    if(!global_isRunning)
        return;

    global_isRunning = !global_isRunning;
    this->dThread->terminate();
    this->dThread->quit();
    this->dThread->wait();

    this->uThread->terminate();
    this->uThread->quit();
    this->dThread->wait();

    qreal curSeclf = QDateTime::currentMSecsSinceEpoch() / 1000.0;
    this->ui->State_Edit->insertHtml(tr("<h4>停止运行@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));

    this->ui->Stop_Button->setEnabled(false);
    this->ui->Start_Button->setEnabled(true);

    return;
}

/// 点击与下位机通讯,更新串口连接信息
void NoiseMonitorSys::on_Connect_Button_clicked()
{
    this->closePort();
    this->initNoiseSlave();
    this->openPort();

    return;
}

/// 使用设备管理器,调出设备管理器窗口
void NoiseMonitorSys::on_DeviceMonitor_Button_clicked()
{
    if(global_isRunning)
    {
        this->ui->State_Edit->insertHtml("<h4>运行中无法编辑设备！</h4>");
        return;
    }

    DeviceMonitor* dm = new DeviceMonitor(this);

    /// Step1
    dm->setWindowFlags(Qt::FramelessWindowHint);

    /// Step2
    dm->move((QApplication::desktop()->width()-dm->width())/2,
             (QApplication::desktop()->height()-dm->height())/2);

    dm->getDatabaseOperator(this->db);
    dm->initDevice_List();
    dm->show();
    return;
}

/// 添加flag,如果窗口已经最大化,则恢复原样,否则窗口最大化
void NoiseMonitorSys::on_MaxWindow_Button_clicked()
{
    static bool winFlag = false;

    if(!winFlag)
    {
        this->showMaximized();
        this->ui->MaxWindow_Button->setText(tr("❒"));
    }
    else
    {
        this->showNormal();
        this->ui->MaxWindow_Button->setText(tr("■"));
    }
    winFlag = !winFlag;

    return;
}

