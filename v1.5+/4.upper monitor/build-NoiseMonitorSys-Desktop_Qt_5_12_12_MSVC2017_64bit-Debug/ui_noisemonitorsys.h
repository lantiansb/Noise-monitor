/********************************************************************************
** Form generated from reading UI file 'noisemonitorsys.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISEMONITORSYS_H
#define UI_NOISEMONITORSYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_NoiseMonitorSys
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_11;
    QFrame *MainWindow_Frame;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QListView *Device_List;
    QPushButton *ChooseDevice_Button;
    QPushButton *DeviceMonitor_Button;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QPushButton *Connect_Button;
    QPushButton *Stop_Button;
    QPushButton *UpdatePlot;
    QPushButton *Start_Button;
    QPushButton *GetHisData_Button;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QFrame *MyTitle_Frame;
    QGridLayout *gridLayout_10;
    QPushButton *MaxWindow_Button;
    QPushButton *MinWindow_Button;
    QPushButton *CloseWindow_Button;
    QTabWidget *Tab_Tab;
    QWidget *tabWidget_6Page1;
    QGridLayout *gridLayout;
    QCustomPlot *HisData_Plot;
    QCustomPlot *NoiseDB_Plot;
    QWidget *tab;
    QGridLayout *gridLayout_13;
    QPushButton *PosSearch_Button;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *Longtitude_SpinBox;
    QLabel *label_15;
    QPushButton *DeviceFlag_Button;
    QDoubleSpinBox *Lantitude_SpinBox;
    QPushButton *ClearFlag_Button;
    QWebEngineView *Map_Widget;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QTextEdit *State_Edit;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *Longtitude_Label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *Latitude_Label;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_12;
    QLabel *L10_Label_H;
    QLabel *L50_Label_H;
    QLabel *Leq_Label_H;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *L90_Label_H;
    QLabel *label_13;
    QLabel *label_12;
    QListView *HisData_List;
    QHBoxLayout *horizontalLayout;
    QPushButton *CalHisData_Button;
    QPushButton *RefreshDataList_Button;
    QPushButton *SaveCSV_Button;
    QPushButton *SaveStatistic_Button;

    void setupUi(QMainWindow *NoiseMonitorSys)
    {
        if (NoiseMonitorSys->objectName().isEmpty())
            NoiseMonitorSys->setObjectName(QString::fromUtf8("NoiseMonitorSys"));
        NoiseMonitorSys->resize(1355, 939);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        NoiseMonitorSys->setFont(font);
        NoiseMonitorSys->setStyleSheet(QString::fromUtf8(""));
        NoiseMonitorSys->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(NoiseMonitorSys);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_11 = new QGridLayout(centralwidget);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        MainWindow_Frame = new QFrame(centralwidget);
        MainWindow_Frame->setObjectName(QString::fromUtf8("MainWindow_Frame"));
        MainWindow_Frame->setStyleSheet(QString::fromUtf8("#MainWindow_Frame{\n"
"	border: 3px solid rgb(134, 134, 134);\n"
"	font: 9pt \"\351\273\221\344\275\223\";\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(248, 248, 248);\n"
"}"));
        MainWindow_Frame->setFrameShape(QFrame::StyledPanel);
        MainWindow_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(MainWindow_Frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 2, -1, -1);
        frame = new QFrame(MainWindow_Frame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 0));
        frame->setMaximumSize(QSize(300, 16777215));
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        Device_List = new QListView(groupBox);
        Device_List->setObjectName(QString::fromUtf8("Device_List"));
        Device_List->setMinimumSize(QSize(0, 350));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        Device_List->setFont(font1);
        Device_List->setStyleSheet(QString::fromUtf8("#Device_List{\n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#Device_List::item{\n"
"	background-color: #ffffff;\n"
"    color: #000000;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"#Device_List::item:hover{\n"
"	background-color: #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"#Device_List::item:selected{\n"
"	background-color: #555555;\n"
"    color: white;\n"
"}"));
        Device_List->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_5->addWidget(Device_List, 0, 0, 1, 1);

        ChooseDevice_Button = new QPushButton(groupBox);
        ChooseDevice_Button->setObjectName(QString::fromUtf8("ChooseDevice_Button"));
        ChooseDevice_Button->setCursor(QCursor(Qt::PointingHandCursor));
        ChooseDevice_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_5->addWidget(ChooseDevice_Button, 1, 0, 1, 1);

        DeviceMonitor_Button = new QPushButton(groupBox);
        DeviceMonitor_Button->setObjectName(QString::fromUtf8("DeviceMonitor_Button"));
        DeviceMonitor_Button->setCursor(QCursor(Qt::PointingHandCursor));
        DeviceMonitor_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_5->addWidget(DeviceMonitor_Button, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        Connect_Button = new QPushButton(groupBox_4);
        Connect_Button->setObjectName(QString::fromUtf8("Connect_Button"));
        Connect_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Connect_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_8->addWidget(Connect_Button, 1, 0, 1, 1);

        Stop_Button = new QPushButton(groupBox_4);
        Stop_Button->setObjectName(QString::fromUtf8("Stop_Button"));
        Stop_Button->setEnabled(false);
        Stop_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Stop_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:!enabled {\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_8->addWidget(Stop_Button, 3, 0, 1, 1);

        UpdatePlot = new QPushButton(groupBox_4);
        UpdatePlot->setObjectName(QString::fromUtf8("UpdatePlot"));
        UpdatePlot->setMaximumSize(QSize(16777215, 0));

        gridLayout_8->addWidget(UpdatePlot, 0, 0, 1, 1);

        Start_Button = new QPushButton(groupBox_4);
        Start_Button->setObjectName(QString::fromUtf8("Start_Button"));
        Start_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Start_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:!enabled {\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_8->addWidget(Start_Button, 2, 0, 1, 1);

        GetHisData_Button = new QPushButton(groupBox_4);
        GetHisData_Button->setObjectName(QString::fromUtf8("GetHisData_Button"));
        GetHisData_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:!enabled {\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_8->addWidget(GetHisData_Button, 4, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(MainWindow_Frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(140, 0));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_6 = new QLabel(MainWindow_Frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        MyTitle_Frame = new QFrame(MainWindow_Frame);
        MyTitle_Frame->setObjectName(QString::fromUtf8("MyTitle_Frame"));
        MyTitle_Frame->setMaximumSize(QSize(140, 16777215));
        MyTitle_Frame->setCursor(QCursor(Qt::ArrowCursor));
        MyTitle_Frame->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));
        MyTitle_Frame->setFrameShape(QFrame::NoFrame);
        MyTitle_Frame->setFrameShadow(QFrame::Plain);
        gridLayout_10 = new QGridLayout(MyTitle_Frame);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        MaxWindow_Button = new QPushButton(MyTitle_Frame);
        MaxWindow_Button->setObjectName(QString::fromUtf8("MaxWindow_Button"));
        MaxWindow_Button->setMinimumSize(QSize(50, 0));
        MaxWindow_Button->setMaximumSize(QSize(50, 16777215));
        MaxWindow_Button->setCursor(QCursor(Qt::PointingHandCursor));
        MaxWindow_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	color: grey;\n"
"	padding: 3px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 4px 2px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}"));

        gridLayout_10->addWidget(MaxWindow_Button, 0, 2, 1, 1);

        MinWindow_Button = new QPushButton(MyTitle_Frame);
        MinWindow_Button->setObjectName(QString::fromUtf8("MinWindow_Button"));
        MinWindow_Button->setMinimumSize(QSize(50, 0));
        MinWindow_Button->setMaximumSize(QSize(50, 16777215));
        MinWindow_Button->setCursor(QCursor(Qt::PointingHandCursor));
        MinWindow_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	color: grey;\n"
"	padding: 3px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 4px 2px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_10->addWidget(MinWindow_Button, 0, 0, 1, 1);

        CloseWindow_Button = new QPushButton(MyTitle_Frame);
        CloseWindow_Button->setObjectName(QString::fromUtf8("CloseWindow_Button"));
        CloseWindow_Button->setMinimumSize(QSize(50, 0));
        CloseWindow_Button->setMaximumSize(QSize(50, 16777215));
        CloseWindow_Button->setCursor(QCursor(Qt::PointingHandCursor));
        CloseWindow_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	color: grey;\n"
"	padding: 3px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 4px 2px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #f44336;\n"
"    color: white;\n"
"}"));

        gridLayout_10->addWidget(CloseWindow_Button, 0, 3, 1, 1);


        horizontalLayout_5->addWidget(MyTitle_Frame);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 3);

        Tab_Tab = new QTabWidget(MainWindow_Frame);
        Tab_Tab->setObjectName(QString::fromUtf8("Tab_Tab"));
        Tab_Tab->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        tabWidget_6Page1 = new QWidget();
        tabWidget_6Page1->setObjectName(QString::fromUtf8("tabWidget_6Page1"));
        gridLayout = new QGridLayout(tabWidget_6Page1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        HisData_Plot = new QCustomPlot(tabWidget_6Page1);
        HisData_Plot->setObjectName(QString::fromUtf8("HisData_Plot"));

        gridLayout->addWidget(HisData_Plot, 2, 0, 1, 2);

        NoiseDB_Plot = new QCustomPlot(tabWidget_6Page1);
        NoiseDB_Plot->setObjectName(QString::fromUtf8("NoiseDB_Plot"));
        NoiseDB_Plot->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(NoiseDB_Plot, 0, 0, 1, 2);

        Tab_Tab->addTab(tabWidget_6Page1, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_13 = new QGridLayout(tab);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        PosSearch_Button = new QPushButton(tab);
        PosSearch_Button->setObjectName(QString::fromUtf8("PosSearch_Button"));
        PosSearch_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_13->addWidget(PosSearch_Button, 1, 7, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_13->addWidget(label_14, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        Longtitude_SpinBox = new QDoubleSpinBox(tab);
        Longtitude_SpinBox->setObjectName(QString::fromUtf8("Longtitude_SpinBox"));

        gridLayout_13->addWidget(Longtitude_SpinBox, 1, 4, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_13->addWidget(label_15, 1, 5, 1, 1);

        DeviceFlag_Button = new QPushButton(tab);
        DeviceFlag_Button->setObjectName(QString::fromUtf8("DeviceFlag_Button"));
        DeviceFlag_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_13->addWidget(DeviceFlag_Button, 1, 1, 1, 1);

        Lantitude_SpinBox = new QDoubleSpinBox(tab);
        Lantitude_SpinBox->setObjectName(QString::fromUtf8("Lantitude_SpinBox"));

        gridLayout_13->addWidget(Lantitude_SpinBox, 1, 6, 1, 1);

        ClearFlag_Button = new QPushButton(tab);
        ClearFlag_Button->setObjectName(QString::fromUtf8("ClearFlag_Button"));
        ClearFlag_Button->setEnabled(false);
        ClearFlag_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:!enabled {\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        gridLayout_13->addWidget(ClearFlag_Button, 1, 0, 1, 1);

        Map_Widget = new QWebEngineView(tab);
        Map_Widget->setObjectName(QString::fromUtf8("Map_Widget"));

        gridLayout_13->addWidget(Map_Widget, 0, 0, 1, 8);

        Tab_Tab->addTab(tab, QString());

        gridLayout_2->addWidget(Tab_Tab, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(MainWindow_Frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(0, 0));
        groupBox_5->setMaximumSize(QSize(16777215, 180));
        groupBox_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        State_Edit = new QTextEdit(groupBox_5);
        State_Edit->setObjectName(QString::fromUtf8("State_Edit"));
        State_Edit->setEnabled(true);
        State_Edit->setMinimumSize(QSize(0, 0));
        State_Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        State_Edit->setLineWrapMode(QTextEdit::NoWrap);
        State_Edit->setReadOnly(true);

        gridLayout_9->addWidget(State_Edit, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 2, 0, 1, 2);

        frame_3 = new QFrame(MainWindow_Frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(200, 0));
        frame_3->setMaximumSize(QSize(300, 16777215));
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 300));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        groupBox_3->setFont(font3);
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        Longtitude_Label = new QLabel(groupBox_3);
        Longtitude_Label->setObjectName(QString::fromUtf8("Longtitude_Label"));
        Longtitude_Label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        Longtitude_Label->setAlignment(Qt::AlignCenter);
        Longtitude_Label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(Longtitude_Label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        Latitude_Label = new QLabel(groupBox_3);
        Latitude_Label->setObjectName(QString::fromUtf8("Latitude_Label"));
        Latitude_Label->setFont(font3);
        Latitude_Label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        Latitude_Label->setAlignment(Qt::AlignCenter);
        Latitude_Label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(Latitude_Label);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 9999));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_4 = new QFrame(groupBox_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 150));
        frame_4->setMaximumSize(QSize(16777215, 150));
        frame_4->setStyleSheet(QString::fromUtf8("#frame_4{\n"
"	border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"	font: 14pt \"\351\273\221\344\275\223\";\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_4);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        L10_Label_H = new QLabel(frame_4);
        L10_Label_H->setObjectName(QString::fromUtf8("L10_Label_H"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setItalic(false);
        L10_Label_H->setFont(font4);
        L10_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        L10_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L10_Label_H, 1, 1, 1, 1);

        L50_Label_H = new QLabel(frame_4);
        L50_Label_H->setObjectName(QString::fromUtf8("L50_Label_H"));
        L50_Label_H->setFont(font4);
        L50_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        L50_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L50_Label_H, 2, 1, 1, 1);

        Leq_Label_H = new QLabel(frame_4);
        Leq_Label_H->setObjectName(QString::fromUtf8("Leq_Label_H"));
        Leq_Label_H->setFont(font4);
        Leq_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        Leq_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(Leq_Label_H, 0, 1, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font4);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font4);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_10, 1, 0, 1, 1);

        L90_Label_H = new QLabel(frame_4);
        L90_Label_H->setObjectName(QString::fromUtf8("L90_Label_H"));
        L90_Label_H->setFont(font4);
        L90_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        L90_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L90_Label_H, 3, 1, 1, 1);

        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font4);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_13, 3, 0, 1, 1);

        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font4);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_12, 2, 0, 1, 1);


        verticalLayout_2->addWidget(frame_4);

        HisData_List = new QListView(groupBox_2);
        HisData_List->setObjectName(QString::fromUtf8("HisData_List"));
        HisData_List->setStyleSheet(QString::fromUtf8("#HisData_List{\n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#HisData_List::item{\n"
"	background-color: #ffffff;\n"
"    color: #000000;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"#HisData_List::item:hover{\n"
"	background-color: #555555;\n"
"    color: white;\n"
"}\n"
"\n"
"#HisData_List::item:selected{\n"
"	background-color: #555555;\n"
"    color: white;\n"
"}"));
        HisData_List->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(HisData_List);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CalHisData_Button = new QPushButton(groupBox_2);
        CalHisData_Button->setObjectName(QString::fromUtf8("CalHisData_Button"));
        CalHisData_Button->setCursor(QCursor(Qt::PointingHandCursor));
        CalHisData_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"\351\273\221\344\275\223\";\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(CalHisData_Button);

        RefreshDataList_Button = new QPushButton(groupBox_2);
        RefreshDataList_Button->setObjectName(QString::fromUtf8("RefreshDataList_Button"));
        RefreshDataList_Button->setMaximumSize(QSize(30, 30));
        RefreshDataList_Button->setCursor(QCursor(Qt::PointingHandCursor));
        RefreshDataList_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"\351\273\221\344\275\223\";\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(RefreshDataList_Button);


        verticalLayout_2->addLayout(horizontalLayout);

        SaveCSV_Button = new QPushButton(groupBox_2);
        SaveCSV_Button->setObjectName(QString::fromUtf8("SaveCSV_Button"));
        SaveCSV_Button->setCursor(QCursor(Qt::PointingHandCursor));
        SaveCSV_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"\351\273\221\344\275\223\";\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        verticalLayout_2->addWidget(SaveCSV_Button);

        SaveStatistic_Button = new QPushButton(groupBox_2);
        SaveStatistic_Button->setObjectName(QString::fromUtf8("SaveStatistic_Button"));
        SaveStatistic_Button->setCursor(QCursor(Qt::PointingHandCursor));
        SaveStatistic_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"\351\273\221\344\275\223\";\n"
"	background-color: white;\n"
"	border: none;\n"
"	color: black;\n"
"	padding: 4px 1px;\n"
"	text-align: center;\n"
"	text-decoration: none;\n"
"	font-size: 16px;\n"
"	margin: 1px 1px;\n"
"    border-radius: 4px;\n"
"	border: 2px solid rgb(222, 222, 222);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color: #555555;\n"
"	border: 2px solid #555555;\n"
"    color: white;\n"
"}"));

        verticalLayout_2->addWidget(SaveStatistic_Button);


        verticalLayout_5->addWidget(groupBox_2);


        gridLayout_2->addWidget(frame_3, 1, 2, 2, 1);


        gridLayout_11->addWidget(MainWindow_Frame, 0, 0, 1, 1);

        NoiseMonitorSys->setCentralWidget(centralwidget);
        QWidget::setTabOrder(Connect_Button, Start_Button);
        QWidget::setTabOrder(Start_Button, Stop_Button);
        QWidget::setTabOrder(Stop_Button, Device_List);
        QWidget::setTabOrder(Device_List, ChooseDevice_Button);
        QWidget::setTabOrder(ChooseDevice_Button, DeviceMonitor_Button);
        QWidget::setTabOrder(DeviceMonitor_Button, State_Edit);
        QWidget::setTabOrder(State_Edit, UpdatePlot);

        retranslateUi(NoiseMonitorSys);
        QObject::connect(CloseWindow_Button, SIGNAL(clicked()), NoiseMonitorSys, SLOT(close()));
        QObject::connect(MinWindow_Button, SIGNAL(clicked()), NoiseMonitorSys, SLOT(showMinimized()));

        Tab_Tab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NoiseMonitorSys);
    } // setupUi

    void retranslateUi(QMainWindow *NoiseMonitorSys)
    {
        NoiseMonitorSys->setWindowTitle(QApplication::translate("NoiseMonitorSys", "\345\217\230\347\224\265\347\253\231\345\231\252\345\243\260\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QApplication::translate("NoiseMonitorSys", "\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        ChooseDevice_Button->setText(QApplication::translate("NoiseMonitorSys", "\351\200\211\344\270\255\346\255\244\350\256\276\345\244\207", nullptr));
        DeviceMonitor_Button->setText(QApplication::translate("NoiseMonitorSys", "\350\256\276\345\244\207\347\256\241\347\220\206\345\231\250", nullptr));
        groupBox_4->setTitle(QApplication::translate("NoiseMonitorSys", "\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        Connect_Button->setText(QApplication::translate("NoiseMonitorSys", "\347\273\210\347\253\257\350\277\236\346\216\245", nullptr));
        Stop_Button->setText(QApplication::translate("NoiseMonitorSys", "\345\201\234\346\255\242\350\277\220\350\241\214", nullptr));
        UpdatePlot->setText(QApplication::translate("NoiseMonitorSys", "\346\233\264\346\226\260\345\233\276\350\241\250", nullptr));
        Start_Button->setText(QApplication::translate("NoiseMonitorSys", "\347\233\221\346\265\213\345\274\200\345\247\213", nullptr));
        GetHisData_Button->setText(QApplication::translate("NoiseMonitorSys", "\350\216\267\345\217\226\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        label->setText(QString());
        label_6->setText(QApplication::translate("NoiseMonitorSys", "\345\217\230\347\224\265\347\253\231\345\231\252\345\243\260\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        MaxWindow_Button->setText(QApplication::translate("NoiseMonitorSys", "\342\226\240", nullptr));
        MinWindow_Button->setText(QApplication::translate("NoiseMonitorSys", "\342\226\274", nullptr));
        CloseWindow_Button->setText(QApplication::translate("NoiseMonitorSys", "\342\234\225", nullptr));
        Tab_Tab->setTabText(Tab_Tab->indexOf(tabWidget_6Page1), QApplication::translate("NoiseMonitorSys", "\346\225\260\346\215\256\345\233\276\350\241\250", nullptr));
        PosSearch_Button->setText(QApplication::translate("NoiseMonitorSys", "\346\237\245\350\257\242\347\273\217\347\272\254\345\272\246", nullptr));
        label_14->setText(QApplication::translate("NoiseMonitorSys", "\347\273\217\345\272\246:", nullptr));
        label_15->setText(QApplication::translate("NoiseMonitorSys", "\347\272\254\345\272\246:", nullptr));
        DeviceFlag_Button->setText(QApplication::translate("NoiseMonitorSys", "\345\256\232\344\275\215\344\270\213\344\275\215\346\234\272", nullptr));
        ClearFlag_Button->setText(QApplication::translate("NoiseMonitorSys", "\346\270\205\347\251\272\346\240\207\350\256\260\347\202\271", nullptr));
        Tab_Tab->setTabText(Tab_Tab->indexOf(tab), QApplication::translate("NoiseMonitorSys", "\345\234\260\345\233\276\345\256\232\344\275\215", nullptr));
        groupBox_5->setTitle(QApplication::translate("NoiseMonitorSys", "\350\277\220\350\241\214\347\212\266\346\200\201", nullptr));
        groupBox_3->setTitle(QApplication::translate("NoiseMonitorSys", "\350\256\276\345\244\207\344\275\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("NoiseMonitorSys", "\347\273\217\345\272\246\357\274\232", nullptr));
        Longtitude_Label->setText(QApplication::translate("NoiseMonitorSys", "\346\234\252\347\237\245\347\273\217\345\272\246", nullptr));
        label_3->setText(QApplication::translate("NoiseMonitorSys", "\347\272\254\345\272\246\357\274\232", nullptr));
        Latitude_Label->setText(QApplication::translate("NoiseMonitorSys", "\346\234\252\347\237\245\347\272\254\345\272\246", nullptr));
        groupBox_2->setTitle(QApplication::translate("NoiseMonitorSys", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
#ifndef QT_NO_WHATSTHIS
        frame_4->setWhatsThis(QApplication::translate("NoiseMonitorSys", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        L10_Label_H->setText(QApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        L50_Label_H->setText(QApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        Leq_Label_H->setText(QApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_8->setText(QApplication::translate("NoiseMonitorSys", "Leq =", nullptr));
        label_10->setText(QApplication::translate("NoiseMonitorSys", "L10 =", nullptr));
        L90_Label_H->setText(QApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_13->setText(QApplication::translate("NoiseMonitorSys", "L90 =", nullptr));
        label_12->setText(QApplication::translate("NoiseMonitorSys", "L50 =", nullptr));
        CalHisData_Button->setText(QApplication::translate("NoiseMonitorSys", "\346\230\276\347\244\272\345\216\206\345\217\262\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        RefreshDataList_Button->setText(QApplication::translate("NoiseMonitorSys", "\342\237\263", nullptr));
        SaveCSV_Button->setText(QApplication::translate("NoiseMonitorSys", "\345\257\274\345\207\272\350\257\246\347\273\206\346\225\260\346\215\256", nullptr));
        SaveStatistic_Button->setText(QApplication::translate("NoiseMonitorSys", "\345\257\274\345\207\272\346\257\217\345\260\217\346\227\266\347\273\237\350\256\241\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoiseMonitorSys: public Ui_NoiseMonitorSys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISEMONITORSYS_H
