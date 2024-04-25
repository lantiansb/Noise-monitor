#ifndef SAVESTATISTIC_H
#define SAVESTATISTIC_H

#pragma execution_character_set("utf-8")

#include <QDialog>
#include <qcustomplot.h>
#include <QFileDialog.h>
#include <QMouseEvent>

#include <math.h>
#include <myalgorithm.h>

namespace Ui {
class SaveStatistic;
}

class SaveStatistic : public QDialog
{
    Q_OBJECT

public:
    explicit SaveStatistic(QWidget *parent = nullptr);
    ~SaveStatistic();

private:
    Ui::SaveStatistic *ui;

public:
    void setDataAndId(int id, QSharedPointer<QCPGraphDataContainer>data);

private slots:
    void on_SaveCSV_Button_clicked();

private:
    int deviceID = -1;
    QSharedPointer<QCPGraphDataContainer>deviceData;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SAVESTATISTIC_H
