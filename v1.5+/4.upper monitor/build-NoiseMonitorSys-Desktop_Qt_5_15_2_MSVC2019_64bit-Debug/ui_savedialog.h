/********************************************************************************
** Form generated from reading UI file 'savedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDIALOG_H
#define UI_SAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SaveDialog
{
public:
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *Quit_Button;
    QLabel *label;
    QPushButton *SaveCSV_Button;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *FilePath_Edit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *FileName_Edit;
    QFrame *line;

    void setupUi(QDialog *SaveDialog)
    {
        if (SaveDialog->objectName().isEmpty())
            SaveDialog->setObjectName(QString::fromUtf8("SaveDialog"));
        SaveDialog->resize(457, 286);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        SaveDialog->setFont(font);
        SaveDialog->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 9pt \"\351\273\221\344\275\223\";\n"
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
"#SaveDialog{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color:rgb(248, 248, 248);\n"
"	font: 9pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	font: 9pt \"\351\273\221\344\275\223\";\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QGroupBox{\n"
"	color: rgb(0, 0, 0);\n"
"	font: 9pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"#frame{\n"
"	border: 2px solid rgb(134, 134, 134);\n"
"}"));
        gridLayout_4 = new QGridLayout(SaveDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(SaveDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Quit_Button = new QPushButton(frame);
        Quit_Button->setObjectName(QString::fromUtf8("Quit_Button"));
        Quit_Button->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(Quit_Button, 5, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        SaveCSV_Button = new QPushButton(frame);
        SaveCSV_Button->setObjectName(QString::fromUtf8("SaveCSV_Button"));

        gridLayout->addWidget(SaveCSV_Button, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(364, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FilePath_Edit = new QLineEdit(groupBox);
        FilePath_Edit->setObjectName(QString::fromUtf8("FilePath_Edit"));

        gridLayout_2->addWidget(FilePath_Edit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 3, 0, 1, 3);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FileName_Edit = new QLineEdit(groupBox_2);
        FileName_Edit->setObjectName(QString::fromUtf8("FileName_Edit"));
        FileName_Edit->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout_3->addWidget(FileName_Edit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 3);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("color: rgb(181, 181, 181);\n"
"background-color: rgb(129, 129, 129);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);

        QWidget::setTabOrder(FileName_Edit, FilePath_Edit);
        QWidget::setTabOrder(FilePath_Edit, SaveCSV_Button);

        retranslateUi(SaveDialog);
        QObject::connect(Quit_Button, SIGNAL(clicked()), SaveDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(SaveDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveDialog)
    {
        SaveDialog->setWindowTitle(QCoreApplication::translate("SaveDialog", "\344\277\235\345\255\230\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        Quit_Button->setText(QCoreApplication::translate("SaveDialog", "\345\205\263\351\227\255", nullptr));
        label->setText(QCoreApplication::translate("SaveDialog", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        SaveCSV_Button->setText(QCoreApplication::translate("SaveDialog", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SaveDialog", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        FilePath_Edit->setText(QCoreApplication::translate("SaveDialog", "D:\\QtGit\\FileTest", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SaveDialog", "\346\226\207\344\273\266\345\220\215", nullptr));
        FileName_Edit->setText(QCoreApplication::translate("SaveDialog", "data.csv", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveDialog: public Ui_SaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDIALOG_H
