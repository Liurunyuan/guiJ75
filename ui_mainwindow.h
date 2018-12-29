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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
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
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QCustomPlot *widget;
    QFrame *frame;
    QPushButton *testbtn;
    QTextBrowser *rxDataDisplay;
    QPushButton *pushButton;
    QTextEdit *txDataInput;
    QLCDNumber *lcdNumber;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QCheckBox *hexBox;
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
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *comBox;
    QLabel *label_2;
    QComboBox *baudBox;
    QLabel *label_3;
    QComboBox *stopBox;
    QLabel *label_4;
    QComboBox *dataBox;
    QLabel *label_5;
    QComboBox *checkBox;
    QPushButton *openButton;

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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget = new QCustomPlot(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        splitter->addWidget(widget);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        testbtn = new QPushButton(frame);
        testbtn->setObjectName(QStringLiteral("testbtn"));
        testbtn->setGeometry(QRect(20, 30, 71, 31));
        rxDataDisplay = new QTextBrowser(frame);
        rxDataDisplay->setObjectName(QStringLiteral("rxDataDisplay"));
        rxDataDisplay->setGeometry(QRect(150, 20, 221, 51));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 101, 31));
        txDataInput = new QTextEdit(frame);
        txDataInput->setObjectName(QStringLiteral("txDataInput"));
        txDataInput->setGeometry(QRect(150, 80, 221, 51));
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(560, 210, 291, 41));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Raised);
        widget1 = new QWidget(frame);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(560, 20, 196, 141));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sendButton = new QPushButton(widget1);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setStyleSheet(QStringLiteral("background: transparent;"));
        sendButton->setFlat(true);

        verticalLayout_2->addWidget(sendButton);

        clearButton = new QPushButton(widget1);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        verticalLayout_2->addWidget(clearButton);

        hexBox = new QCheckBox(widget1);
        hexBox->setObjectName(QStringLiteral("hexBox"));

        verticalLayout_2->addWidget(hexBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_2 = new QCheckBox(widget1);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(widget1);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(widget1);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(widget1);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        verticalLayout->addWidget(checkBox_5);


        horizontalLayout->addLayout(verticalLayout);

        splitter->addWidget(frame);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

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
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidget->setMinimumSize(QSize(0, 0));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        widget2 = new QWidget(dockWidgetContents);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(0, 10, 134, 181));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        comBox = new QComboBox(widget2);
        comBox->setObjectName(QStringLiteral("comBox"));

        gridLayout_2->addWidget(comBox, 0, 1, 1, 1);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        baudBox = new QComboBox(widget2);
        baudBox->setObjectName(QStringLiteral("baudBox"));

        gridLayout_2->addWidget(baudBox, 1, 1, 1, 1);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        stopBox = new QComboBox(widget2);
        stopBox->setObjectName(QStringLiteral("stopBox"));

        gridLayout_2->addWidget(stopBox, 2, 1, 1, 1);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        dataBox = new QComboBox(widget2);
        dataBox->setObjectName(QStringLiteral("dataBox"));

        gridLayout_2->addWidget(dataBox, 3, 1, 1, 1);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        checkBox = new QComboBox(widget2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 4, 1, 1, 1);

        openButton = new QPushButton(dockWidgetContents);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(4, 200, 131, 31));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

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
        testbtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        hexBox->setText(QApplication::translate("MainWindow", "hex", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "help", Q_NULLPTR));
        menuLine_select->setTitle(QApplication::translate("MainWindow", "line select", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "com", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "baud", Q_NULLPTR));
        baudBox->clear();
        baudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        stopBox->clear();
        stopBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "data", Q_NULLPTR));
        dataBox->clear();
        dataBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "check", Q_NULLPTR));
        checkBox->clear();
        checkBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "none", Q_NULLPTR)
        );
        openButton->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
