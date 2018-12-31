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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *actionSystem_config;
    QAction *actionCurve_config;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *widget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *widget2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuLine_select;
    QMenu *menuDockwidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QWidget *layoutWidget;
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
    QDockWidget *systemconfig;
    QWidget *dockWidgetContents_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QDockWidget *xComConfigDockWidget;
    QWidget *dockWidgetContents_3;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QComboBox *comBox_2;
    QLabel *label_7;
    QComboBox *baudBox_2;
    QLabel *label_8;
    QComboBox *stopBox_2;
    QLabel *label_9;
    QComboBox *dataBox_2;
    QLabel *label_10;
    QComboBox *checkBox_6;
    QPushButton *openButton_2;

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
        actionDisplacement->setCheckable(true);
        actionDisplacement->setChecked(true);
        actionMotor_speed = new QAction(MainWindow);
        actionMotor_speed->setObjectName(QStringLiteral("actionMotor_speed"));
        actionMotor_speed->setCheckable(true);
        actionMotor_speed->setChecked(true);
        actionMotor_accel = new QAction(MainWindow);
        actionMotor_accel->setObjectName(QStringLiteral("actionMotor_accel"));
        actionMotor_accel->setCheckable(true);
        actionMotor_accel->setChecked(true);
        actionCurrent = new QAction(MainWindow);
        actionCurrent->setObjectName(QStringLiteral("actionCurrent"));
        actionCurrent->setCheckable(true);
        actionCurrent->setChecked(true);
        actionBus_voltage = new QAction(MainWindow);
        actionBus_voltage->setObjectName(QStringLiteral("actionBus_voltage"));
        actionBus_voltage->setCheckable(true);
        actionBus_voltage->setChecked(true);
        actionSystem_config = new QAction(MainWindow);
        actionSystem_config->setObjectName(QStringLiteral("actionSystem_config"));
        actionSystem_config->setCheckable(true);
        actionSystem_config->setChecked(true);
        actionCurve_config = new QAction(MainWindow);
        actionCurve_config->setObjectName(QStringLiteral("actionCurve_config"));
        actionCurve_config->setCheckable(true);
        actionCurve_config->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QCustomPlot(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(250);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget2 = new QCustomPlot(tab_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setEnabled(true);
        sizePolicy.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(widget2);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(frame);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        horizontalSpacer_3 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

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
        menuDockwidget = new QMenu(menuBar);
        menuDockwidget->setObjectName(QStringLiteral("menuDockwidget"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy2);
        dockWidget->setMinimumSize(QSize(73, 41));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        layoutWidget = new QWidget(dockWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 134, 181));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        comBox = new QComboBox(layoutWidget);
        comBox->setObjectName(QStringLiteral("comBox"));

        gridLayout_2->addWidget(comBox, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        baudBox = new QComboBox(layoutWidget);
        baudBox->setObjectName(QStringLiteral("baudBox"));

        gridLayout_2->addWidget(baudBox, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        stopBox = new QComboBox(layoutWidget);
        stopBox->setObjectName(QStringLiteral("stopBox"));

        gridLayout_2->addWidget(stopBox, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        dataBox = new QComboBox(layoutWidget);
        dataBox->setObjectName(QStringLiteral("dataBox"));

        gridLayout_2->addWidget(dataBox, 3, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        checkBox = new QComboBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 4, 1, 1, 1);

        openButton = new QPushButton(dockWidgetContents);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(4, 200, 131, 31));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        systemconfig = new QDockWidget(MainWindow);
        systemconfig->setObjectName(QStringLiteral("systemconfig"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        layoutWidget1 = new QWidget(dockWidgetContents_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 101, 124));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(layoutWidget1);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(layoutWidget1);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(layoutWidget1);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(layoutWidget1);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        verticalLayout->addWidget(checkBox_5);

        systemconfig->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), systemconfig);
        xComConfigDockWidget = new QDockWidget(MainWindow);
        xComConfigDockWidget->setObjectName(QStringLiteral("xComConfigDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        layoutWidget_2 = new QWidget(dockWidgetContents_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 10, 134, 181));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        comBox_2 = new QComboBox(layoutWidget_2);
        comBox_2->setObjectName(QStringLiteral("comBox_2"));

        gridLayout_3->addWidget(comBox_2, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        baudBox_2 = new QComboBox(layoutWidget_2);
        baudBox_2->setObjectName(QStringLiteral("baudBox_2"));

        gridLayout_3->addWidget(baudBox_2, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        stopBox_2 = new QComboBox(layoutWidget_2);
        stopBox_2->setObjectName(QStringLiteral("stopBox_2"));

        gridLayout_3->addWidget(stopBox_2, 2, 1, 1, 1);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        dataBox_2 = new QComboBox(layoutWidget_2);
        dataBox_2->setObjectName(QStringLiteral("dataBox_2"));

        gridLayout_3->addWidget(dataBox_2, 3, 1, 1, 1);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 4, 0, 1, 1);

        checkBox_6 = new QComboBox(layoutWidget_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        gridLayout_3->addWidget(checkBox_6, 4, 1, 1, 1);

        openButton_2 = new QPushButton(dockWidgetContents_3);
        openButton_2->setObjectName(QStringLiteral("openButton_2"));
        openButton_2->setGeometry(QRect(10, 190, 131, 31));
        xComConfigDockWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), xComConfigDockWidget);

        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLine_select->menuAction());
        menuBar->addAction(menuDockwidget->menuAction());
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
        menuDockwidget->addAction(actionSystem_config);
        menuDockwidget->addSeparator();
        menuDockwidget->addAction(actionCurve_config);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


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
        actionSystem_config->setText(QApplication::translate("MainWindow", "system config", Q_NULLPTR));
        actionCurve_config->setText(QApplication::translate("MainWindow", "curve config", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "help", Q_NULLPTR));
        menuLine_select->setTitle(QApplication::translate("MainWindow", "line select", Q_NULLPTR));
        menuDockwidget->setTitle(QApplication::translate("MainWindow", "dockwidget", Q_NULLPTR));
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
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "com", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "baud", Q_NULLPTR));
        baudBox_2->clear();
        baudBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        stopBox_2->clear();
        stopBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWindow", "data", Q_NULLPTR));
        dataBox_2->clear();
        dataBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("MainWindow", "check", Q_NULLPTR));
        checkBox_6->clear();
        checkBox_6->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "none", Q_NULLPTR)
        );
        openButton_2->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
