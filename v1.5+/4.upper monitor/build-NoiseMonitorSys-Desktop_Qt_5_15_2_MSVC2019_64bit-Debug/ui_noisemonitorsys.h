/********************************************************************************
** Form generated from reading UI file 'noisemonitorsys.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISEMONITORSYS_H
#define UI_NOISEMONITORSYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

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
    QPushButton *Start_Button;
    QPushButton *Connect_Button;
    QPushButton *Stop_Button;
    QPushButton *UpdatePlot;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QFrame *MyTitle_Frame;
    QGridLayout *gridLayout_10;
    QPushButton *MaxWindow_Button;
    QPushButton *MinWindow_Button;
    QPushButton *CloseWindow_Button;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout;
    QCustomPlot *NoiseDB_Plot;
    QCustomPlot *HisData_Plot;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *Date_Edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTimeEdit *From_Edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTimeEdit *To_Edit;
    QPushButton *CalHisData_Button;
    QFrame *frame_4;
    QGridLayout *gridLayout_12;
    QLabel *L90_Label_H;
    QLabel *L10_Label_H;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *L50_Label_H;
    QLabel *Leq_Label_H;
    QLabel *label_10;
    QPushButton *SaveCSV_Button;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *TimeRange_Edit;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QLabel *label_5;
    QLabel *Leq_Label;
    QLabel *label_7;
    QLabel *L10_Label;
    QLabel *label_9;
    QLabel *L50_Label;
    QLabel *label_11;
    QLabel *L90_Label;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QTextEdit *State_Edit;

    void setupUi(QMainWindow *NoiseMonitorSys)
    {
        if (NoiseMonitorSys->objectName().isEmpty())
            NoiseMonitorSys->setObjectName(QString::fromUtf8("NoiseMonitorSys"));
        NoiseMonitorSys->resize(1428, 945);
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


        gridLayout_4->addWidget(groupBox_4, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(MainWindow_Frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";\n"
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

        groupBox_6 = new QGroupBox(MainWindow_Frame);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        gridLayout = new QGridLayout(groupBox_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        NoiseDB_Plot = new QCustomPlot(groupBox_6);
        NoiseDB_Plot->setObjectName(QString::fromUtf8("NoiseDB_Plot"));
        NoiseDB_Plot->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(NoiseDB_Plot, 0, 0, 1, 1);

        HisData_Plot = new QCustomPlot(groupBox_6);
        HisData_Plot->setObjectName(QString::fromUtf8("HisData_Plot"));

        gridLayout->addWidget(HisData_Plot, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 1, 1, 1, 1);

        frame_3 = new QFrame(MainWindow_Frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(200, 0));
        frame_3->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 385));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 4, -1, 4);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Date_Edit = new QDateEdit(groupBox_2);
        Date_Edit->setObjectName(QString::fromUtf8("Date_Edit"));

        horizontalLayout_2->addWidget(Date_Edit);


        gridLayout_6->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 4, -1, 4);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        From_Edit = new QTimeEdit(groupBox_2);
        From_Edit->setObjectName(QString::fromUtf8("From_Edit"));

        horizontalLayout_3->addWidget(From_Edit);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 4, -1, 4);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        To_Edit = new QTimeEdit(groupBox_2);
        To_Edit->setObjectName(QString::fromUtf8("To_Edit"));

        horizontalLayout_4->addWidget(To_Edit);


        gridLayout_6->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        CalHisData_Button = new QPushButton(groupBox_2);
        CalHisData_Button->setObjectName(QString::fromUtf8("CalHisData_Button"));
        CalHisData_Button->setCursor(QCursor(Qt::PointingHandCursor));
        CalHisData_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        gridLayout_6->addWidget(CalHisData_Button, 3, 0, 1, 1);

        frame_4 = new QFrame(groupBox_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 0));
        frame_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_4);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        L90_Label_H = new QLabel(frame_4);
        L90_Label_H->setObjectName(QString::fromUtf8("L90_Label_H"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        L90_Label_H->setFont(font2);
        L90_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L90_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L90_Label_H, 3, 1, 1, 1);

        L10_Label_H = new QLabel(frame_4);
        L10_Label_H->setObjectName(QString::fromUtf8("L10_Label_H"));
        L10_Label_H->setFont(font2);
        L10_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L10_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L10_Label_H, 1, 1, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_8, 0, 0, 1, 1);

        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_12, 2, 0, 1, 1);

        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_13, 3, 0, 1, 1);

        L50_Label_H = new QLabel(frame_4);
        L50_Label_H->setObjectName(QString::fromUtf8("L50_Label_H"));
        L50_Label_H->setFont(font2);
        L50_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L50_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(L50_Label_H, 2, 1, 1, 1);

        Leq_Label_H = new QLabel(frame_4);
        Leq_Label_H->setObjectName(QString::fromUtf8("Leq_Label_H"));
        Leq_Label_H->setFont(font2);
        Leq_Label_H->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Leq_Label_H->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(Leq_Label_H, 0, 1, 1, 1);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_10, 1, 0, 1, 1);


        gridLayout_6->addWidget(frame_4, 4, 0, 1, 1);

        SaveCSV_Button = new QPushButton(groupBox_2);
        SaveCSV_Button->setObjectName(QString::fromUtf8("SaveCSV_Button"));
        SaveCSV_Button->setCursor(QCursor(Qt::PointingHandCursor));
        SaveCSV_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        gridLayout_6->addWidget(SaveCSV_Button, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        TimeRange_Edit = new QSpinBox(groupBox_3);
        TimeRange_Edit->setObjectName(QString::fromUtf8("TimeRange_Edit"));
        TimeRange_Edit->setFont(font3);
        TimeRange_Edit->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        TimeRange_Edit->setMinimum(10);
        TimeRange_Edit->setMaximum(200);

        horizontalLayout->addWidget(TimeRange_Edit);


        verticalLayout->addLayout(horizontalLayout);

        frame_2 = new QFrame(groupBox_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        Leq_Label = new QLabel(frame_2);
        Leq_Label->setObjectName(QString::fromUtf8("Leq_Label"));
        Leq_Label->setFont(font2);
        Leq_Label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Leq_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Leq_Label, 0, 1, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_7, 1, 0, 1, 1);

        L10_Label = new QLabel(frame_2);
        L10_Label->setObjectName(QString::fromUtf8("L10_Label"));
        L10_Label->setFont(font2);
        L10_Label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L10_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(L10_Label, 1, 1, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_9, 2, 0, 1, 1);

        L50_Label = new QLabel(frame_2);
        L50_Label->setObjectName(QString::fromUtf8("L50_Label"));
        L50_Label->setFont(font2);
        L50_Label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L50_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(L50_Label, 2, 1, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_11, 3, 0, 1, 1);

        L90_Label = new QLabel(frame_2);
        L90_Label->setObjectName(QString::fromUtf8("L90_Label"));
        L90_Label->setFont(font2);
        L90_Label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        L90_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(L90_Label, 3, 1, 1, 1);


        verticalLayout->addWidget(frame_2);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_3, 1, 2, 1, 1);

        groupBox_5 = new QGroupBox(MainWindow_Frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        State_Edit = new QTextEdit(groupBox_5);
        State_Edit->setObjectName(QString::fromUtf8("State_Edit"));
        State_Edit->setMinimumSize(QSize(0, 150));
        State_Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        State_Edit->setReadOnly(true);

        gridLayout_9->addWidget(State_Edit, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 2, 0, 1, 3);


        gridLayout_11->addWidget(MainWindow_Frame, 0, 0, 1, 1);

        NoiseMonitorSys->setCentralWidget(centralwidget);
        QWidget::setTabOrder(Connect_Button, Start_Button);
        QWidget::setTabOrder(Start_Button, Stop_Button);
        QWidget::setTabOrder(Stop_Button, Device_List);
        QWidget::setTabOrder(Device_List, ChooseDevice_Button);
        QWidget::setTabOrder(ChooseDevice_Button, DeviceMonitor_Button);
        QWidget::setTabOrder(DeviceMonitor_Button, TimeRange_Edit);
        QWidget::setTabOrder(TimeRange_Edit, State_Edit);
        QWidget::setTabOrder(State_Edit, Date_Edit);
        QWidget::setTabOrder(Date_Edit, From_Edit);
        QWidget::setTabOrder(From_Edit, To_Edit);
        QWidget::setTabOrder(To_Edit, CalHisData_Button);
        QWidget::setTabOrder(CalHisData_Button, SaveCSV_Button);
        QWidget::setTabOrder(SaveCSV_Button, UpdatePlot);

        retranslateUi(NoiseMonitorSys);
        QObject::connect(CloseWindow_Button, SIGNAL(clicked()), NoiseMonitorSys, SLOT(close()));
        QObject::connect(MinWindow_Button, SIGNAL(clicked()), NoiseMonitorSys, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(NoiseMonitorSys);
    } // setupUi

    void retranslateUi(QMainWindow *NoiseMonitorSys)
    {
        NoiseMonitorSys->setWindowTitle(QCoreApplication::translate("NoiseMonitorSys", "\345\217\230\347\224\265\347\253\231\345\231\252\345\243\260\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        ChooseDevice_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\351\200\211\344\270\255\346\255\244\350\256\276\345\244\207", nullptr));
        DeviceMonitor_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\350\256\276\345\244\207\347\256\241\347\220\206\345\231\250", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        Start_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\347\233\221\346\265\213\345\274\200\345\247\213", nullptr));
        Connect_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\347\273\210\347\253\257\350\277\236\346\216\245", nullptr));
        Stop_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\345\201\234\346\255\242\350\277\220\350\241\214", nullptr));
        UpdatePlot->setText(QCoreApplication::translate("NoiseMonitorSys", "\346\233\264\346\226\260\345\233\276\350\241\250", nullptr));
        label_6->setText(QCoreApplication::translate("NoiseMonitorSys", "\345\217\230\347\224\265\347\253\231\345\231\252\345\243\260\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        MaxWindow_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\342\226\240", nullptr));
        MinWindow_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\342\226\274", nullptr));
        CloseWindow_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\342\234\225", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\346\225\260\346\215\256\345\233\276\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("NoiseMonitorSys", "\346\237\245\350\257\242\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("NoiseMonitorSys", "\346\227\266\351\227\264\350\214\203\345\233\264\344\273\216", nullptr));
        From_Edit->setDisplayFormat(QCoreApplication::translate("NoiseMonitorSys", "HH:mm:ss", nullptr));
        label_4->setText(QCoreApplication::translate("NoiseMonitorSys", "\346\227\266\351\227\264\350\214\203\345\233\264\345\210\260", nullptr));
        To_Edit->setDisplayFormat(QCoreApplication::translate("NoiseMonitorSys", "HH:mm:ss", nullptr));
        CalHisData_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\346\230\276\347\244\272\345\216\206\345\217\262\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
#if QT_CONFIG(whatsthis)
        frame_4->setWhatsThis(QCoreApplication::translate("NoiseMonitorSys", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        L90_Label_H->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        L10_Label_H->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_8->setText(QCoreApplication::translate("NoiseMonitorSys", "Leq =", nullptr));
        label_12->setText(QCoreApplication::translate("NoiseMonitorSys", "L50 =", nullptr));
        label_13->setText(QCoreApplication::translate("NoiseMonitorSys", "L90 =", nullptr));
        L50_Label_H->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        Leq_Label_H->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_10->setText(QCoreApplication::translate("NoiseMonitorSys", "L10 =", nullptr));
        SaveCSV_Button->setText(QCoreApplication::translate("NoiseMonitorSys", "\345\257\274\345\207\272\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\345\256\236\346\227\266\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("NoiseMonitorSys", "\347\273\237\350\256\241\345\221\250\346\234\237(\347\247\222)", nullptr));
#if QT_CONFIG(whatsthis)
        frame_2->setWhatsThis(QCoreApplication::translate("NoiseMonitorSys", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_5->setText(QCoreApplication::translate("NoiseMonitorSys", "Leq =", nullptr));
        Leq_Label->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_7->setText(QCoreApplication::translate("NoiseMonitorSys", "L10 =", nullptr));
        L10_Label->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_9->setText(QCoreApplication::translate("NoiseMonitorSys", "L50 =", nullptr));
        L50_Label->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        label_11->setText(QCoreApplication::translate("NoiseMonitorSys", "L90 =", nullptr));
        L90_Label->setText(QCoreApplication::translate("NoiseMonitorSys", "0.0000", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("NoiseMonitorSys", "\350\277\220\350\241\214\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoiseMonitorSys: public Ui_NoiseMonitorSys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISEMONITORSYS_H
