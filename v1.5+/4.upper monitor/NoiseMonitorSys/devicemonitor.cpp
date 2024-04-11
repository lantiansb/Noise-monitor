#include "devicemonitor.h"
#include "ui_devicemonitor.h"

DeviceMonitor::DeviceMonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceMonitor)
{
    ui->setupUi(this);
}

DeviceMonitor::~DeviceMonitor()
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
QPoint deviceM_mOffset;
bool deviceM_isMove = false;

/// 鼠标按下,记录偏移量
void DeviceMonitor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint startPos = event->globalPos();
        deviceM_mOffset = startPos - this->geometry().topLeft();
        deviceM_isMove = !deviceM_isMove;
    }
    return;
}

/// 鼠标松开,记录结尾坐标,转移位置
void DeviceMonitor::mouseReleaseEvent(QMouseEvent *event)
{
    if(deviceM_isMove)
    {
        QPoint endPos = event->globalPos();
        this->move(endPos - deviceM_mOffset);
        deviceM_isMove = !deviceM_isMove;
    }
    return;
}

/** ***************************************************
 * @param
 *      DatabaseOperator& db: 数据库管理员权限
 * @brief
 *      这个窗口的作用是修改device表,所以直接给数据库权限
 * ************************************************* **/
void DeviceMonitor::getDatabaseOperator(DatabaseOperator* fdb)
{
    this->db = fdb;
    return;
}

/// 初始化设备选择列表Device_List
void DeviceMonitor::initDevice_List(void)
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
    }

    QStringListModel* listModel = new QStringListModel(showList);
    this->ui->Device_List->setModel(listModel);

    return;
}

/// 给device表添加新的设备
void DeviceMonitor::on_AddNewDevice_Button_clicked()
{

}

