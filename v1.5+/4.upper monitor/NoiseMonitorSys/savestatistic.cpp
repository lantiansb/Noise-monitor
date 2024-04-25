#include "savestatistic.h"
#include "ui_savestatistic.h"

#include <QDebug>

#define DATA(ind) this->deviceData->at(ind)

SaveStatistic::SaveStatistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveStatistic)
{
    ui->setupUi(this);
}

SaveStatistic::~SaveStatistic()
{
    delete ui;
}

/** ***************************************************
 * @brief
 * 有个非常玄学的bug,如果一直按着窗口的标题栏,就无法接收串口
 * 数据,目前所有的研究都表明,如果主线程堵塞,无论是否使用多线
 * 程等,均会造成串口数据接收失败,因此只能删去标题栏,自定义标
 * 题栏了,所以要重新实现一遍窗口的拖动功能.
 * ************************************************* **/
QPoint saveSD_mOffset;
bool saveSD_isMove = false;

/// 鼠标按下,记录偏移量
void SaveStatistic::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint startPos = event->globalPos();
        saveSD_mOffset = startPos - this->geometry().topLeft();
        saveSD_isMove = !saveSD_isMove;
    }
    return;
}

/// 鼠标松开,记录结尾坐标,转移位置
void SaveStatistic::mouseReleaseEvent(QMouseEvent *event)
{
    if(saveSD_isMove)
    {
        QPoint endPos = event->globalPos();
        this->move(endPos - saveSD_mOffset);
        saveSD_isMove = !saveSD_isMove;
    }
    return;
}

/// 设置保存到文件中的数据和设备id值
void SaveStatistic::setDataAndId(int id, QSharedPointer<QCPGraphDataContainer>data)
{
    this->deviceID = id;
    this->deviceData = data;
}

/// 点击保存按钮,开始保存文件
void SaveStatistic::on_SaveCSV_Button_clicked()
{
    QString csvFile = this->ui->FilePath_Edit->text();
    if(csvFile.isEmpty())
        return;

    double curSeclf = (double)(QDateTime::currentMSecsSinceEpoch());
    csvFile += tr("/%1.csv").arg(curSeclf, 0, 'f', 0);

    QFile file(csvFile);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&file);

    /// 获取数据 创建表头并填写数据
    QVector<QVector<qreal>> divData;
    int index = 0;

    out << tr("参数(设备id:%1),").arg(QString::number(this->deviceID));
    for(int i = 0; i < 1 + (long)(DATA(this->deviceData->size() - 1)->key - this->deviceData->begin()->key) / 3600; ++i)
    {
        out << tr("%1~%2,").arg(QDateTime::fromSecsSinceEpoch(DATA(0)->key + i * 3600.0).toString("hh:mm:ss"), QDateTime::fromSecsSinceEpoch(DATA(0)->key + (i + 1) * 3600.0).toString("hh:mm:ss"));
        divData.append(QVector<qreal>());
        for(int j = index; j < this->deviceData->size(); ++j)
        {
            if(DATA(j)->key >= DATA(0)->key + i * 3600.0)
                divData[i].append(pow(10.0, 0.1 * DATA(j)->value));
            if(DATA(j)->key >= DATA(0)->key + (i+1) * 3600.0)
            {
                index = j;
                break;
            }
        }
    }

    /// 上面的步骤中,将每小时的数据存储在容器中,接下来只需要对每个容器单独操作,就可以得到四参数数据
    out << tr("\n") << tr("Leq,");
    for(int i = 0 ; i < divData.size(); ++i)
    {
        out << tr("%1,").arg(10.0 * log10(integral(divData[i], 1.0) / (double)divData[i].length()), 0, 'f', 4);
        std::sort(divData[i].begin(), divData[i].end());
    }

    out << tr("\n") << tr("L10,");
    for(int i = 0 ; i < divData.size(); ++i)
        out << tr("%1,").arg(10.0 * log10(divData[i][0.9 * ((double)divData[i].length())]), 0, 'f', 4);

    out << tr("\n") << tr("L50,");
    for(int i = 0 ; i < divData.size(); ++i)
        out << tr("%1,").arg(10.0 * log10(divData[i][0.5 * ((double)divData[i].length())]), 0, 'f', 4);

    out << tr("\n") << tr("L90,");
    for(int i = 0 ; i < divData.size(); ++i)
        out << tr("%1,").arg(10.0 * log10(divData[i][0.1 * ((double)divData[i].length())]), 0, 'f', 4);

    //tr("每小时数据报表提示"), tr("历史数据保存成功！")
    QMessageBox::information(nullptr, tr("Tips:"), tr("Succeed!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    file.close();

    this->close();
    return;
}
