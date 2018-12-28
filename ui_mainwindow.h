/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_how_to_use;
    QAction *actionDisplacement;
    QAction *actionMotor_speed;
    QAction *actionMotor_accel;
    QAction *actionCurrent;
    QAction *actionBus_voltage;
    QWidget *centralWidget;
    QTextBrowser *rxDataDisplay;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QPushButton *openButton;
    QCheckBox *hexBox;
    QTextEdit *txDataInput;
    QComboBox *baudBox;
    QComboBox *stopBox;
    QComboBox *dataBox;
    QComboBox *checkBox;
    QComboBox *comBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *testbtn;
    QCustomPlot *widget;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuLine_select;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 605);
        MainWindow->setAutoFillBackground(true);
        actionAbout_how_to_use = new QAction(MainWindow);
        actionAbout_how_to_use->setObjectName(QStringLiteral("actionAbout_how_to_use"));
        actionAbout_how_to_use->setCheckable(true);
        actionAbout_how_to_use->setChecked(false);
        actionDisplacement = new QAction(MainWindow);
        actionDisplacement->setObjectName(QStringLiteral("actionDisplacement"));
        actionMotor_speed = new QAction(MainWindow);
        actionMotor_speed->setObjectName(QStringLiteral("actionMotor_speed"));
        actionMotor_accel = new QAction(MainWindow);
        actionMotor_accel->setObjectName(QStringLiteral("actionMotor_accel"));
        actionCurrent = new QAction(MainWindow);
        actionCurrent->setObjectName(QStringLiteral("actionCurrent"));
        actionBus_voltage = new QAction(MainWindow);
        actionBus_voltage->setObjectName(QStringLiteral("actionBus_voltage"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        rxDataDisplay = new QTextBrowser(centralWidget);
        rxDataDisplay->setObjectName(QStringLiteral("rxDataDisplay"));
        rxDataDisplay->setGeometry(QRect(140, 420, 201, 51));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(900, 400, 101, 31));
        sendButton->setStyleSheet(QStringLiteral("background: transparent;"));
        sendButton->setFlat(true);
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(900, 460, 101, 31));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(900, 430, 101, 31));
        hexBox = new QCheckBox(centralWidget);
        hexBox->setObjectName(QStringLiteral("hexBox"));
        hexBox->setGeometry(QRect(900, 500, 99, 26));
        txDataInput = new QTextEdit(centralWidget);
        txDataInput->setObjectName(QStringLiteral("txDataInput"));
        txDataInput->setGeometry(QRect(670, 430, 221, 41));
        baudBox = new QComboBox(centralWidget);
        baudBox->setObjectName(QStringLiteral("baudBox"));
        baudBox->setGeometry(QRect(60, 410, 71, 31));
        stopBox = new QComboBox(centralWidget);
        stopBox->setObjectName(QStringLiteral("stopBox"));
        stopBox->setGeometry(QRect(60, 440, 71, 31));
        dataBox = new QComboBox(centralWidget);
        dataBox->setObjectName(QStringLiteral("dataBox"));
        dataBox->setGeometry(QRect(60, 470, 71, 31));
        checkBox = new QComboBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 500, 71, 31));
        comBox = new QComboBox(centralWidget);
        comBox->setObjectName(QStringLiteral("comBox"));
        comBox->setGeometry(QRect(60, 380, 71, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 380, 31, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 410, 41, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 440, 41, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 470, 41, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 500, 51, 21));
        testbtn = new QPushButton(centralWidget);
        testbtn->setObjectName(QStringLiteral("testbtn"));
        testbtn->setGeometry(QRect(140, 380, 71, 31));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 931, 351));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(480, 430, 161, 41));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 490, 101, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(970, 20, 101, 124));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        verticalLayout->addWidget(checkBox_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 27));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuLine_select = new QMenu(menuBar);
        menuLine_select->setObjectName(QStringLiteral("menuLine_select"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLine_select->menuAction());
        menuHelp->addAction(actionAbout_how_to_use);
        menuHelp->addSeparator();
        menuLine_select->addAction(actionDisplacement);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionMotor_speed);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionMotor_accel);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionCurrent);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionBus_voltage);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAbout_how_to_use->setText(QApplication::translate("MainWindow", "about how to use", Q_NULLPTR));
        actionDisplacement->setText(QApplication::translate("MainWindow", "displacement", Q_NULLPTR));
        actionMotor_speed->setText(QApplication::translate("MainWindow", "motor speed", Q_NULLPTR));
        actionMotor_accel->setText(QApplication::translate("MainWindow", "motor accel", Q_NULLPTR));
        actionCurrent->setText(QApplication::translate("MainWindow", "current", Q_NULLPTR));
        actionBus_voltage->setText(QApplication::translate("MainWindow", "bus voltage", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        openButton->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        hexBox->setText(QApplication::translate("MainWindow", "hex", Q_NULLPTR));
        baudBox->clear();
        baudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        stopBox->clear();
        stopBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        dataBox->clear();
        dataBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        checkBox->clear();
        checkBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "none", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "com", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "baud", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "data", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "check", Q_NULLPTR));
        testbtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "help", Q_NULLPTR));
        menuLine_select->setTitle(QApplication::translate("MainWindow", "line select", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
