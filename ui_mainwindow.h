/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *outputText;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *i2cDeviceEdit;
    QLabel *label_2;
    QLineEdit *slaveAddressEdit;
    QLabel *label_3;
    QLineEdit *regAddressEdit;
    QLabel *label_4;
    QLineEdit *dataEdit;
    QPushButton *Configure;
    QPushButton *readButton;
    QPushButton *writeButton;
    QLabel *label_5;
    QLineEdit *blinkDelayEdit;
    QLabel *label_6;
    QLineEdit *blinkTimesEdit;
    QPushButton *blinkButton;
    QLabel *outputDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        outputText = new QTextEdit(centralwidget);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setGeometry(QRect(120, 430, 511, 91));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(190, 73, 431, 321));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        i2cDeviceEdit = new QLineEdit(widget);
        i2cDeviceEdit->setObjectName(QStringLiteral("i2cDeviceEdit"));

        gridLayout->addWidget(i2cDeviceEdit, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        slaveAddressEdit = new QLineEdit(widget);
        slaveAddressEdit->setObjectName(QStringLiteral("slaveAddressEdit"));

        gridLayout->addWidget(slaveAddressEdit, 1, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        regAddressEdit = new QLineEdit(widget);
        regAddressEdit->setObjectName(QStringLiteral("regAddressEdit"));

        gridLayout->addWidget(regAddressEdit, 2, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dataEdit = new QLineEdit(widget);
        dataEdit->setObjectName(QStringLiteral("dataEdit"));

        gridLayout->addWidget(dataEdit, 3, 2, 1, 1);

        Configure = new QPushButton(widget);
        Configure->setObjectName(QStringLiteral("Configure"));

        gridLayout->addWidget(Configure, 4, 1, 1, 2);

        readButton = new QPushButton(widget);
        readButton->setObjectName(QStringLiteral("readButton"));

        gridLayout->addWidget(readButton, 5, 0, 1, 2);

        writeButton = new QPushButton(widget);
        writeButton->setObjectName(QStringLiteral("writeButton"));

        gridLayout->addWidget(writeButton, 5, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 2);

        blinkDelayEdit = new QLineEdit(widget);
        blinkDelayEdit->setObjectName(QStringLiteral("blinkDelayEdit"));

        gridLayout->addWidget(blinkDelayEdit, 6, 2, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 2);

        blinkTimesEdit = new QLineEdit(widget);
        blinkTimesEdit->setObjectName(QStringLiteral("blinkTimesEdit"));

        gridLayout->addWidget(blinkTimesEdit, 7, 2, 1, 1);

        blinkButton = new QPushButton(widget);
        blinkButton->setObjectName(QStringLiteral("blinkButton"));

        gridLayout->addWidget(blinkButton, 8, 2, 1, 1);

        outputDisplay = new QLabel(widget);
        outputDisplay->setObjectName(QStringLiteral("outputDisplay"));

        gridLayout->addWidget(outputDisplay, 9, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "I2C Handler", 0));
        label_2->setText(QApplication::translate("MainWindow", "Slave Address", 0));
        label_3->setText(QApplication::translate("MainWindow", "reg Address", 0));
        label_4->setText(QApplication::translate("MainWindow", "data", 0));
        Configure->setText(QApplication::translate("MainWindow", "Configure I2C", 0));
        readButton->setText(QApplication::translate("MainWindow", "Read", 0));
        writeButton->setText(QApplication::translate("MainWindow", "Write", 0));
        label_5->setText(QApplication::translate("MainWindow", "Blink Delay", 0));
        label_6->setText(QApplication::translate("MainWindow", "Blink Count", 0));
        blinkButton->setText(QApplication::translate("MainWindow", "Blink", 0));
        outputDisplay->setText(QApplication::translate("MainWindow", "data from I2c", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
