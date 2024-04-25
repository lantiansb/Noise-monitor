#ifndef DEVICEMONITOR_H
#define DEVICEMONITOR_H

#include <QDialog>
#include <QMouseEvent>
#include <QStringListModel>

#include <databaseoperator.h>

namespace Ui {
class DeviceMonitor;
}

class DeviceMonitor : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceMonitor(QWidget *parent = nullptr);
    ~DeviceMonitor();

public:
    void getDatabaseOperator(DatabaseOperator* fdb);
    void initDevice_List(void);

private slots:

    void on_AddNewDevice_Button_clicked();

private:
    Ui::DeviceMonitor *ui;

private:
    DatabaseOperator* db = nullptr;

    QVector<int>idList;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // DEVICEMONITOR_H
