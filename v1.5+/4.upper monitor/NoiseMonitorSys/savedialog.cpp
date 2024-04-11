#include "savedialog.h"
#include "ui_savedialog.h"

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);
}

SaveDialog::~SaveDialog()
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
QPoint saveD_mOffset;
bool saveD_isMove = false;

/// 鼠标按下,记录偏移量
void SaveDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint startPos = event->globalPos();
        saveD_mOffset = startPos - this->geometry().topLeft();
        saveD_isMove = !saveD_isMove;
    }
    return;
}

/// 鼠标松开,记录结尾坐标,转移位置
void SaveDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(saveD_isMove)
    {
        QPoint endPos = event->globalPos();
        this->move(endPos - saveD_mOffset);
        saveD_isMove = !saveD_isMove;
    }
    return;
}

/// 设置保存到文件中的数据和设备id值
void SaveDialog::setDataAndId(int id, QSharedPointer<QCPGraphDataContainer>data)
{
    this->deviceID = id;
    this->deviceData = data;
}

/// 点击保存按钮,开始保存文件
void SaveDialog::on_SaveCSV_Button_clicked()
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
    out << tr("时间,") << tr("噪声强度(dB),") << tr("设备id=%1,\n").arg(QString::number(this->deviceID));

    for(int i = 0; i < this->deviceData->size(); ++i)
        /// 将时间保存为可读的格式,噪声强度数据以四位小数保存
        out << tr("%1,").arg(QDateTime::fromSecsSinceEpoch(this->deviceData->at(i)->key).toString("yyyy-MM-dd hh:mm:ss")) << tr("%1,\n").arg(QString::number(this->deviceData->at(i)->value, 'f', 4));

    QMessageBox::information(nullptr, tr("数据报表提示"), tr("历史数据保存成功！"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    file.close();

    this->close();
    return;
}

