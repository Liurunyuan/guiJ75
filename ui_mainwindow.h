/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QAction *actionMotor_speed;
    QAction *actionSystem_config;
    QAction *actionCurve_config;
    QAction *actionDuty;
    QAction *actionTargetSpeed;
    QAction *actionCurrent_2;
    QAction *actionTemp;
    QAction *actionVol;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *widget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_17;
    QSpinBox *MotorSpeed;
    QLabel *label_6;
    QSpinBox *currentDuty;
    QLabel *label_15;
    QLineEdit *alarmInfo;
    QLabel *label_14;
    QSpinBox *targetSpeedSpinBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *SendBtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *clearButton;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1228, 576);
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setIconSize(QSize(10, 24));
        actionAbout_how_to_use = new QAction(MainWindow);
        actionAbout_how_to_use->setObjectName(QStringLiteral("actionAbout_how_to_use"));
        actionAbout_how_to_use->setCheckable(true);
        actionAbout_how_to_use->setChecked(false);
        actionMotor_speed = new QAction(MainWindow);
        actionMotor_speed->setObjectName(QStringLiteral("actionMotor_speed"));
        actionMotor_speed->setCheckable(true);
        actionMotor_speed->setChecked(false);
        actionSystem_config = new QAction(MainWindow);
        actionSystem_config->setObjectName(QStringLiteral("actionSystem_config"));
        actionSystem_config->setCheckable(true);
        actionSystem_config->setChecked(true);
        actionCurve_config = new QAction(MainWindow);
        actionCurve_config->setObjectName(QStringLiteral("actionCurve_config"));
        actionCurve_config->setCheckable(true);
        actionCurve_config->setChecked(true);
        actionDuty = new QAction(MainWindow);
        actionDuty->setObjectName(QStringLiteral("actionDuty"));
        actionDuty->setCheckable(true);
        actionTargetSpeed = new QAction(MainWindow);
        actionTargetSpeed->setObjectName(QStringLiteral("actionTargetSpeed"));
        actionTargetSpeed->setCheckable(true);
        actionCurrent_2 = new QAction(MainWindow);
        actionCurrent_2->setObjectName(QStringLiteral("actionCurrent_2"));
        actionCurrent_2->setCheckable(true);
        actionTemp = new QAction(MainWindow);
        actionTemp->setObjectName(QStringLiteral("actionTemp"));
        actionTemp->setCheckable(true);
        actionVol = new QAction(MainWindow);
        actionVol->setObjectName(QStringLiteral("actionVol"));
        actionVol->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QCustomPlot(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(widget);

        tabWidget->addTab(tab, QString());
        splitter->addWidget(tabWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_5->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_5->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_5->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_5->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout_5->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(frame);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout_5->addWidget(lineEdit_6);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_4->addWidget(label_17);

        MotorSpeed = new QSpinBox(frame);
        MotorSpeed->setObjectName(QStringLiteral("MotorSpeed"));
        MotorSpeed->setMaximum(20000);

        verticalLayout_4->addWidget(MotorSpeed);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        currentDuty = new QSpinBox(frame);
        currentDuty->setObjectName(QStringLiteral("currentDuty"));
        currentDuty->setReadOnly(true);
        currentDuty->setMaximum(2000);

        verticalLayout_4->addWidget(currentDuty);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_4->addWidget(label_15);

        alarmInfo = new QLineEdit(frame);
        alarmInfo->setObjectName(QStringLiteral("alarmInfo"));
        alarmInfo->setReadOnly(true);

        verticalLayout_4->addWidget(alarmInfo);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_4->addWidget(label_14);

        targetSpeedSpinBox = new QSpinBox(frame);
        targetSpeedSpinBox->setObjectName(QStringLiteral("targetSpeedSpinBox"));
        targetSpeedSpinBox->setMinimum(500);
        targetSpeedSpinBox->setMaximum(10000);

        verticalLayout_4->addWidget(targetSpeedSpinBox);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        SendBtn = new QPushButton(frame);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));

        verticalLayout_3->addWidget(SendBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        clearButton = new QPushButton(frame);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        verticalLayout_3->addWidget(clearButton);


        horizontalLayout->addLayout(verticalLayout_3);

        splitter->addWidget(frame);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1228, 21));
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
        dockWidget->setMinimumSize(QSize(91, 42));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        layoutWidget = new QWidget(dockWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 142, 181));
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
        layoutWidget1->setGeometry(QRect(0, 10, 101, 136));
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

        menuBar->addAction(menuLine_select->menuAction());
        menuBar->addAction(menuDockwidget->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_how_to_use);
        menuHelp->addSeparator();
        menuLine_select->addAction(actionTargetSpeed);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionMotor_speed);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionDuty);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionCurrent_2);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionTemp);
        menuLine_select->addSeparator();
        menuLine_select->addAction(actionVol);
        menuDockwidget->addAction(actionSystem_config);
        menuDockwidget->addSeparator();
        menuDockwidget->addAction(actionCurve_config);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout_how_to_use->setText(QApplication::translate("MainWindow", "about how to use", 0));
        actionMotor_speed->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\275\254\351\200\237\346\233\262\347\272\277", 0));
        actionSystem_config->setText(QApplication::translate("MainWindow", "system config", 0));
        actionCurve_config->setText(QApplication::translate("MainWindow", "curve config", 0));
        actionDuty->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\345\215\240\347\251\272\346\257\224", 0));
        actionTargetSpeed->setText(QApplication::translate("MainWindow", "\346\214\207\344\273\244\350\275\254\351\200\237", 0));
        actionCurrent_2->setText(QApplication::translate("MainWindow", "\347\224\265\346\265\201", 0));
        actionTemp->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", 0));
        actionVol->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        label_17->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\275\254\351\200\237\345\217\215\351\246\210\346\230\276\347\244\272", 0));
        label_6->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\215\240\347\251\272\346\257\224\346\230\276\347\244\272", 0));
        label_15->setText(QApplication::translate("MainWindow", "\346\212\245\350\255\246\344\277\241\346\201\257\346\230\276\347\244\272", 0));
        label_14->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\350\275\254\351\200\237\350\256\276\347\275\256", 0));
        SendBtn->setText(QApplication::translate("MainWindow", "Start", 0));
        clearButton->setText(QApplication::translate("MainWindow", "clear", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menuLine_select->setTitle(QApplication::translate("MainWindow", "\346\233\262\347\272\277\351\200\211\346\213\251", 0));
        menuDockwidget->setTitle(QApplication::translate("MainWindow", "\346\265\256\345\212\250\347\252\227\345\217\243", 0));
        label->setText(QApplication::translate("MainWindow", "COM", 0));
        label_2->setText(QApplication::translate("MainWindow", "BAUD", 0));
        baudBox->clear();
        baudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "STOP", 0));
        stopBox->clear();
        stopBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "DATA", 0));
        dataBox->clear();
        dataBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "CHECK", 0));
        checkBox->clear();
        checkBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "none", 0)
        );
        openButton->setText(QApplication::translate("MainWindow", "open", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\224\265\346\265\201", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\275\254\351\200\237", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\233\256\346\240\207\350\275\254\351\200\237", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\215\240\347\251\272\346\257\224", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
