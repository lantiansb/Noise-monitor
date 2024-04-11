/********************************************************************************
** Form generated from reading UI file 'devicemonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEMONITOR_H
#define UI_DEVICEMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceMonitor
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *Quit_Button;
    QListView *Device_List;
    QPushButton *DeleteDevice_Button;
    QPushButton *AddNewDevice_Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *EditDevice_Button;
    QLabel *label;

    void setupUi(QDialog *DeviceMonitor)
    {
        if (DeviceMonitor->objectName().isEmpty())
            DeviceMonitor->setObjectName(QString::fromUtf8("DeviceMonitor"));
        DeviceMonitor->resize(366, 562);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        DeviceMonitor->setFont(font);
        DeviceMonitor->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"#Device_List{\n"
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
"}\n"
"\n"
"#DeviceMonitor{\n"
"	background-color:rgb(248, 248, 248);\n"
"}"));
        verticalLayout = new QVBoxLayout(DeviceMonitor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DeviceMonitor);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"	border: 2px solid rgb(134, 134, 134);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Quit_Button = new QPushButton(frame);
        Quit_Button->setObjectName(QString::fromUtf8("Quit_Button"));
        Quit_Button->setMinimumSize(QSize(60, 0));
        Quit_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(Quit_Button, 5, 1, 1, 1);

        Device_List = new QListView(frame);
        Device_List->setObjectName(QString::fromUtf8("Device_List"));

        gridLayout_2->addWidget(Device_List, 1, 0, 1, 2);

        DeleteDevice_Button = new QPushButton(frame);
        DeleteDevice_Button->setObjectName(QString::fromUtf8("DeleteDevice_Button"));
        DeleteDevice_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(DeleteDevice_Button, 4, 0, 1, 2);

        AddNewDevice_Button = new QPushButton(frame);
        AddNewDevice_Button->setObjectName(QString::fromUtf8("AddNewDevice_Button"));
        AddNewDevice_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(AddNewDevice_Button, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 5, 0, 1, 1);

        EditDevice_Button = new QPushButton(frame);
        EditDevice_Button->setObjectName(QString::fromUtf8("EditDevice_Button"));
        EditDevice_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(EditDevice_Button, 3, 0, 1, 2);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color : rgb(0, 0, 0);\n"
"font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(DeviceMonitor);
        QObject::connect(Quit_Button, SIGNAL(clicked()), DeviceMonitor, SLOT(close()));

        QMetaObject::connectSlotsByName(DeviceMonitor);
    } // setupUi

    void retranslateUi(QDialog *DeviceMonitor)
    {
        DeviceMonitor->setWindowTitle(QCoreApplication::translate("DeviceMonitor", "\350\256\276\345\244\207\347\256\241\347\220\206\345\231\250", nullptr));
        Quit_Button->setText(QCoreApplication::translate("DeviceMonitor", "\345\205\263\351\227\255", nullptr));
        DeleteDevice_Button->setText(QCoreApplication::translate("DeviceMonitor", "\345\210\240\351\231\244\346\255\244\350\256\276\345\244\207", nullptr));
        AddNewDevice_Button->setText(QCoreApplication::translate("DeviceMonitor", "\346\267\273\345\212\240\346\226\260\350\256\276\345\244\207", nullptr));
        EditDevice_Button->setText(QCoreApplication::translate("DeviceMonitor", "\347\274\226\350\276\221\346\255\244\350\256\276\345\244\207", nullptr));
        label->setText(QCoreApplication::translate("DeviceMonitor", "\350\256\276\345\244\207\347\256\241\347\220\206\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceMonitor: public Ui_DeviceMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEMONITOR_H
