#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#pragma execution_character_set("utf-8")

#include <QDialog>
#include <qcustomplot.h>
#include <QFileDialog.h>
#include <QMouseEvent>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = nullptr);
    ~SaveDialog();

public:
    void setDataAndId(int id, QSharedPointer<QCPGraphDataContainer>data);

private slots:
    void on_SaveCSV_Button_clicked();

private:
    Ui::SaveDialog *ui;

private:
    int deviceID = -1;
    QSharedPointer<QCPGraphDataContainer>deviceData;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SAVEDIALOG_H
