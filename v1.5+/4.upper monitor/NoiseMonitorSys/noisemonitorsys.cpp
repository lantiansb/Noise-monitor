
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
    this->dThread = new DetectorThread(this, 500);
    this->uThread = new UpdatePlotThread(this, 1500);

    this->initBaiduMap();
    this->initNoiseDB_Plot();
    this->initHisData_Plot();
    this->initDevice_List();
    this->initHisData_List();
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

QPoint global_mOffset;
bool global_isMove = false;
bool global_isQuery = false;
bool global_isPortOpen = false;
bool global_isRunning = false;
bool global_isWebLoaded = false;

/** ***************************************************
 * @brief
 * 有个非常玄学的bug,如果一直按着窗口的标题栏,就无法接收串口
 * 数据,目前所有的研究都表明,如果主线程堵塞,无论是否使用多线
 * 程等,均会造成串口数据接收失败,因此只能删去标题栏,自定义标
 * 题栏了,所以要重新实现一遍窗口的拖动功能.
 * ************************************************* **/

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

/// 设置子函数,保证滚动只能是x轴方向伸缩
void NoiseMonitorSys::limitPlotInRange(void)
{
    this->ui->HisData_Plot->yAxis->setRange(0, 120);

    return;
}

/// 鼠标左键点击,显示提示框,显示当前点坐标,右键点击,清空所有标点
void NoiseMonitorSys::showHisPlotPoint(QMouseEvent* event)
{
    /// 存储所有坐标提示标签,方便后续全部删除
    static QList<QCPItemText*>textItems;

    if(event->button() == Qt::LeftButton)
    {
        QCPAbstractPlottable* plottable = this->ui->HisData_Plot->plottableAt(event->pos(), true);
        if(!plottable)
            return;

        double x = this->ui->HisData_Plot->xAxis->pixelToCoord(event->pos().x());
        double y = this->ui->HisData_Plot->yAxis->pixelToCoord(event->pos().y());
        double distance = plottable->selectTest(event->pos(), true);

        if(distance >= 0 && distance < 5)
        {
            QCPItemText *textLabel = new QCPItemText(this->ui->HisData_Plot);
            textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
            textLabel->position->setType(QCPItemPosition::ptPlotCoords);
            textLabel->position->setCoords(x, y);
            textLabel->setText(QString(" %1 ").arg(y));
            textLabel->setFont(QFont(font().family(), 10));
            textLabel->setPen(QPen(Qt::black));
            textItems.append(textLabel);
        }
        /// 上述代码中距离小于5像素,说明此时点击的位置与图表足够接近,可以根据需要调整
    }
    else
    {
        /// 鼠标右键点击,清空所有提示框
        foreach(QCPItemText *item, textItems)
        {
            this->ui->HisData_Plot->removeItem(item);
        }
        textItems.clear();
        this->ui->HisData_Plot->replot();
    }

    this->ui->HisData_Plot->replot();

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

    this->ui->NoiseDB_Plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
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
    this->ui->HisData_Plot->graph(0)->setName("历史数据");
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
    timer->setTickCount(5);
    timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    this->ui->HisData_Plot->xAxis->setTicker(timer);

    this->ui->HisData_Plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
    this->ui->HisData_Plot->legend->setVisible(true);
    this->ui->HisData_Plot->xAxis->setTickLabelRotation(0);
    this->ui->HisData_Plot->yAxis->setRange(0, 100);

    /// 设置图表可以被选中图层,可以鼠标拖拽,可以滚轮缩放,并设置缩放极限值,设置双击显示提示框,设置缩放后刷新图表
    this->ui->HisData_Plot->setInteractions(QCP::iSelectPlottables|QCP::iRangeDrag|QCP::iRangeZoom);
    connect(this->ui->HisData_Plot, &QCustomPlot::afterReplot, this, &NoiseMonitorSys::limitPlotInRange);
    connect(this->ui->HisData_Plot, &QCustomPlot::mouseDoubleClick, this, &NoiseMonitorSys::showHisPlotPoint);

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
                                 .arg(deviceList.value(0).toString(),
                                 deviceList.value(1).toString(),
                                 deviceList.value(2).toString()));
        this->idList.append(deviceList.value(0).toInt());

        /// 根据数据库中存储的设备数量,初始化输出缓冲区块数
        this->data.append(QVector<double>());
        this->savedData.append(QVector<double>());
        this->location.append(QVector<double>{-1, -1});
        this->timeList.append(QVector<double>());
        this->savedTimeList.append(QVector<double>());
    }

    QStringListModel* listModel = new QStringListModel(showList);
    this->ui->Device_List->setModel(listModel);

    return;
}

/// 初始化历史数据选择列表HisData_List,将数据库中有数据的天数表示出来
void NoiseMonitorSys::initHisData_List(void)
{
    QSqlQuery hisList = this->db->db_SearchSQL("SELECT name FROM sqlite_master WHERE type='table';");
    QStringList showList;

    hisList.next();
    while(hisList.next())
    {
        showList.append(QString("·%1").arg(hisList.value(0).toString()));
        this->searchList.append(hisList.value(0).toString());
    }

    QStringListModel* listModel = new QStringListModel(showList);
    this->ui->HisData_List->setModel(listModel);

    return;
}

/// 初始化串口,配置属性结构体
void NoiseMonitorSys::initNoiseSlave(void)
{
    this->m_currentSettings.name = QString("COM3");
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
        this->uThread->wait();
    });

    return;
}

/// QWebEngine初始化,加载离线百度地图
void NoiseMonitorSys::initBaiduMap(void)
{
    this->ui->Map_Widget->setUrl(QUrl("file:///D:/QtGit/NoiseMonitorSys/BD_Map_API/index.html"));
    this->ui->Map_Widget->show();

    /// 地图加载完成修改全局变量,只有加载完成才能执行相关地图操作
    connect(this->ui->Map_Widget, &QWebEngineView::loadFinished,
            this, [](){global_isWebLoaded = true;});

    return;
}

/** ***************************************************
 * @brief
 *      通过私有变量的结构体设置,打开串口,更新标记值
 * ************************************************* **/
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
        this->showState("<h4>成功打开串口！</h4>");
        global_isPortOpen = true;
        return;
    }

    this->showState("<h4>无法打开串口！</h4>");
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
    int idTemp = 0;
    double dbTemp = 0.0;
    QString locationTemp = "unknown";
    unsigned long slaveTime = 0;

    QByteArray res = this->nd->readAll();

    /// 如果首个位置上不是0xAA或者0xFF,或者第二位不是有效id值,不是有效数据,直接跳过
    if(res.length()  < 2)
        return;

    idTemp = this->idList.indexOf((int)res.at(1));

    if(((quint8)res.at(0) != (quint8)0xAA) && ((quint8)res.at(0) != (quint8)0xFF) && (idTemp == -1))
        return;

    /// 循环读取缓冲区,拼接缓冲区中的经纬度数据字符
    if((quint8)res.at(0) == 0xAA)
    {
        locationTemp.clear();
        for(int i = 2; ((char)(res.at(i)) != '\0') && (i < res.length()); ++i)
            locationTemp += tr("%1").arg(res.at(i));

        this->location[idTemp] = pharseStr(locationTemp);
        this->location[idTemp] = WGS84ToGCJ02(this->location[idTemp][0], this->location[idTemp][1]);
        this->location[idTemp] = GCJ02ToBD09(this->location[idTemp][0], this->location[idTemp][1]);
    }
    /// 0xFF打头的数据是噪声分贝值和时间戳数据
    else if((quint8)res.at(0) == 0xFF)
    {
        dbTemp = ((quint8)res.at(2) * 256.0 + (quint8)res.at(3)) / 10.0;

        /// 接收下位机发送的时间数据,时间戳需要格式化到与上位机一致
        for(int k = 3; k >= 0; --k)
        {
            slaveTime <<= 8;
            slaveTime += (quint8)(res.at(4+k));
        }
        this->globalSlaveTime = (double)(slaveTime - 28798);

        /// 保存数据,如果超过250个数据,就将其保存到缓冲区
        if(this->data[idTemp].length() > 250)
        {
            this->savedData[idTemp].append(this->data[idTemp][0]);
            this->data[idTemp].removeFirst();

            this->savedTimeList[idTemp].append(this->globalSlaveTime);
            this->timeList[idTemp].removeFirst();
        }

        this->data[idTemp].append(dbTemp);
        this->timeList[idTemp].append(this->globalSlaveTime);
    }

    this->saveDataToDB(1);

    return;
}

/** ***************************************************
 * @brief
 *      子线程控制,快速获取历史数据,一般是10ms启动一次
 * ************************************************* **/
void NoiseMonitorSys::updateHisData(void)
{

    return;
}

/** ***************************************************
 * @param
 *      int dataSize: 每冗余100个数据则存入一次数据库
 * @brief
 *      根据设定的冗余数据阈值触发自动保存到数据库,创建一个当
 *      天(tyyyy_mm_dd)的表,如果已经创建就直接提交,然后清空
 *      冗余数据存储区
 * ************************************************* **/
void NoiseMonitorSys::saveDataToDB(int dataSize)
{
    ///获取当天时间,每天创建一张表
    QString tableName = QString("t%1").arg(QDateTime::fromSecsSinceEpoch(this->globalSlaveTime).toString("yyyy_MM_dd"));
    QString SaveSQL = QString("INSERT INTO %1(id, time, db) VALUES ").arg(tableName);

    /// 如果0数据,不能执行清空缓冲区任务,否则会发生严重的错误!
    QVector<int>isValid(this->idList.length(), 0);

    for(int k = 0; k < this->idList.length(); ++k)
    {
        if(this->savedTimeList[k].length() < dataSize)
            continue;

        for(int i = 0; i < this->savedTimeList[k].length(); ++i)
        {
            SaveSQL += QString("(%1, %2, %3),").arg(QString::number(this->idList[k]),
                       QString("%1").arg(this->savedTimeList[k][i], 0, 'f', 4),
                       QString("%1").arg(this->savedData[k][i], 0, 'f', 4));
            isValid[k] = 1;
        }
    }
    if(!isValid.contains(1))
        return;

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

    SaveSQL.chop(1);
    this->db->db_WriteSQL(SaveSQL);

    /// 保存完毕,清空缓冲区
    for(int k = 0; k < this->idList.length(); ++k)
    {
        if(!isValid[k])
            continue;

        QVector<double>().swap(this->savedData[k]);
        QVector<double>().swap(this->savedTimeList[k]);
    }

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
    if(this->nowIdChoice == -1 || this->timeList[nowIdChoice].length() == 0)
        return;

    this->ui->NoiseDB_Plot->graph(0)->setData(this->timeList[this->nowIdChoice], this->data[this->nowIdChoice]);
    this->ui->NoiseDB_Plot->xAxis->setRange(this->timeList[this->nowIdChoice].back() - this->ui->NoiseDB_Plot->xAxis->range().size(),
                                            this->timeList[this->nowIdChoice].back());
    this->ui->NoiseDB_Plot->replot();

    this->ui->Position_Label->setText(tr("坐标:(%1, %2)").arg(
            QString::number(this->location[this->nowIdChoice][0], 'f', 4),
            QString::number(this->location[this->nowIdChoice][1], 'f', 4)
        ));

    return;
}

/** ***************************************************
 * @param
 *      double from & double to:时间范围
 * @brief
 *      根据选中范围内数据库数据更新历史数据图表,显示
 *      数据统计结果(四个参数Leq,L10,L50,L90)
 *
 *      用法DEMO:
 *      this->refreshHisPlot(
 *          this->ui->HisData_Plot->xAxis->range().lower,
 *          this->ui->HisData_Plot->xAxis->range().upper
 *        );
 *
 *      this->ui->HisData_Plot->replot();
 * ************************************************* **/
void NoiseMonitorSys::refreshHisPlot(double from, double to)
{
    if(this->nowHisChoice == -1)
        return;

    if(this->nowIdChoice == -1)
    {
        this->showState("未选中任何设备！");
        return;
    }

    QString tableName = this->searchList[this->nowHisChoice];

    QString sqlScpt = QString("SELECT time, db FROM %1"
                              " WHERE time >= %2 AND"
                              " time <= %3 AND id = %4").arg(
                              tableName,
                              QString("%1").arg(from, 0, 'f', 4),
                              QString("%1").arg(to, 0, 'f', 4),
                              QString::number(this->idList[this->nowIdChoice])
                              );
    QSqlQuery hisData = this->db->db_SearchSQL(sqlScpt);
    QVector<double>db;

    this->ui->HisData_Plot->removeGraph(0);
    this->ui->HisData_Plot->addGraph(0);
    this->ui->HisData_Plot->graph(0)->setName(tr("历史数据(id:%1)").arg(this->idList[this->nowIdChoice]));
    while(hisData.next())
    {
        this->ui->HisData_Plot->graph(0)->addData(hisData.value(0).toDouble(), hisData.value(1).toDouble());
        db.append(pow(10.0, 0.1 * hisData.value(1).toDouble()));
    }

    ///更新图表之后还需要更新统计结果,仅十个数据显然不能进行统计
    if(db.length() <= 10)
    {
        this->showState("<h4>选中数据量过小,无法统计！</h4>");
        this->ui->Leq_Label_H->setText("0.0000");
        this->ui->L10_Label_H->setText("0.0000");
        this->ui->L50_Label_H->setText("0.0000");
        this->ui->L90_Label_H->setText("0.0000");

        return;
    }

    this->ui->Leq_Label_H->setText(tr("%1").arg(10.0 * log10(integral(db, 1.0) / (double)db.length()), 0, 'f', 4));
    std::sort(db.begin(), db.end());
    this->ui->L10_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.9 * ((double)db.length())]), 0, 'f', 4));
    this->ui->L50_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.5 * ((double)db.length())]), 0, 'f', 4));
    this->ui->L90_Label_H->setText(tr("%1").arg(10.0 * log10(db[0.1 * ((double)db.length())]), 0, 'f', 4));

    return;
}

/** ***************************************************
 * @param
 *      QString text: 传入的状态文本
 * @brief
 *      节省代码量,修改默认的textEdit的insertHtml函数
 * ************************************************* **/
void NoiseMonitorSys::showState(QString text)
{
    this->ui->State_Edit->insertHtml(text);
    this->ui->State_Edit->insertPlainText("\n");
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
        this->showState(tr("<h4>选中设备id:%1</h4>").arg(this->idList[choice]));

        this->ui->Position_Label->setText(tr("坐标:(%1, %2)").arg(
                QString::number(this->location[this->nowIdChoice][0], 'f', 4),
                QString::number(this->location[this->nowIdChoice][1], 'f', 4)
            ));
    }

    if(global_isQuery)
        this->on_CalHisData_Button_clicked();

    return;
}

/// 槽函数:按照范围搜寻历史记录数据,第一次启动查询之后,选中设备按钮会修改图表
void NoiseMonitorSys::on_CalHisData_Button_clicked()
{
    if(this->searchList.length() == 0)
        return;

    int choice = this->ui->HisData_List->currentIndex().row();

    if(choice == -1)
        return;
    else
    {
        this->nowHisChoice = choice;
        this->showState(tr("<h4>选中时间id:%1</h4>").arg(this->searchList[choice]));
    }

    /// 如果没有选中监测设备,跳过
    if(this->nowIdChoice == -1)
    {
        this->showState("未选中任何设备！");
        return;
    }
    global_isQuery = true;

    QString tableName = this->searchList[choice];
    QString dateStr = tableName.mid(1);
    double dateTime = QDateTime::fromString(QString("%1").arg(dateStr), "yyyy_MM_dd").toMSecsSinceEpoch() / 1000.0;

    /// 根据选中的表名所在的日期的24小时范围筛选数据库数据
    double fromEpo = dateTime;
    double toEpo = dateTime + 86400;

    this->refreshHisPlot(fromEpo, toEpo);
    this->ui->HisData_Plot->xAxis->setRange(fromEpo, toEpo);
    this->ui->HisData_Plot->replot();

    return;
}

/// 保存选中数据到csv文件
void NoiseMonitorSys::on_SaveCSV_Button_clicked()
{
    /// 如果没有选中任何数据,则直接退出
    if(this->ui->HisData_Plot->graph(0)->data()->size() == 0)
        return;

    SaveDialog* dlg = new SaveDialog(nullptr);
    /// Step1
    dlg->setWindowFlags(Qt::FramelessWindowHint);

    /// Step2
    dlg->move((QApplication::desktop()->width()-dlg->width())/2,
              (QApplication::desktop()->height()-dlg->height())/2);

    dlg->setDataAndId(this->idList[this->nowIdChoice], this->ui->HisData_Plot->graph(0)->data());
    dlg->show();

    return;
}

/// 保存选中数据的各小时四参数到csv文件
void NoiseMonitorSys::on_SaveStatistic_Button_clicked()
{
    /// 如果没有选中任何数据,则直接退出
    if(this->ui->HisData_Plot->graph(0)->data()->size() == 0)
        return;

    SaveStatistic* dlg = new SaveStatistic(nullptr);
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
void NoiseMonitorSys::on_Start_Button_clicked()
{
    qreal curSeclf = QDateTime::currentMSecsSinceEpoch() / 1000.0;
    if(!global_isPortOpen)
    {
        this->showState(tr("<h4>串口无法读取，运行失败！@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));
        global_isRunning = false;
        return;
    }

    this->dThread->start();
    this->uThread->start();

    this->showState(tr("<h4>启动运行@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));
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
    this->showState(tr("<h4>停止运行@%1</h4>").arg(QDateTime::fromSecsSinceEpoch(curSeclf).toString()));

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
        this->showState("<h4>运行中无法编辑设备！</h4>");
        return;
    }

    DeviceMonitor* dm = new DeviceMonitor(nullptr);

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

/// 清空地图中的标记
void NoiseMonitorSys::on_ClearFlag_Button_clicked()
{
    if(!global_isWebLoaded)
        return;

    /// 这个离线api有点坑...没有把清除标记的方法打包进去...暂时先不做
}

/// 根据开机时得到的下位机经纬度数据在地图上显示出来
void NoiseMonitorSys::on_DeviceFlag_Button_clicked()
{
    if(!global_isWebLoaded)
        return;

    /// 循环读取保存到的下位机位置信息,若非unkown显示在地图上
    for(int i = 0; i < this->location.length(); ++i)
    {
        if(this->location[i][0] == -1 || this->location[i][1] == -1)
            continue;

        QString jsForMark = tr("addFlag(%1, %2, %3)").arg(
                QString::number(this->location[i][0], 'f', 20),
                QString::number(this->location[i][1], 'f', 20),
                QString::number(this->idList[i])
            );

        this->ui->Map_Widget->page()->runJavaScript(jsForMark, [](const QVariant&){});
    }

    this->showState(tr("<h4>已加载全部已知下位机位置数据！</h4>"));
    return;
}

/// 获取历史数据,获取历史数据时,不允许同时启动实时监控功能,读一个存一个
void NoiseMonitorSys::on_GetHisData_Button_clicked()
{
}
