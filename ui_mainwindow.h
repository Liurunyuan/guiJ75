/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
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
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *SendBtn;
    QPushButton *clearButton;
    QLCDNumber *lcdNumber;
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
        MainWindow->resize(1228, 576);
        MainWindow->setAutoFillBackground(true);
        actionAbout_how_to_use = new QAction(MainWindow);
        actionAbout_how_to_use->setObjectName(QStringLiteral("actionAbout_how_to_use"));
        actionAbout_how_to_use->setCheckable(true);
        actionAbout_how_to_use->setChecked(false);
        actionDisplacement = new QAction(MainWindow);
        actionDisplacement->setObjectName(QStringLiteral("actionDisplacement"));
        actionDisplacement->setCheckable(true);
        actionDisplacement->setChecked(false);
        actionMotor_speed = new QAction(MainWindow);
        actionMotor_speed->setObjectName(QStringLiteral("actionMotor_speed"));
        actionMotor_speed->setCheckable(true);
        actionMotor_speed->setChecked(false);
        actionMotor_accel = new QAction(MainWindow);
        actionMotor_accel->setObjectName(QStringLiteral("actionMotor_accel"));
        actionMotor_accel->setCheckable(true);
        actionMotor_accel->setChecked(false);
        actionCurrent = new QAction(MainWindow);
        actionCurrent->setObjectName(QStringLiteral("actionCurrent"));
        actionCurrent->setCheckable(true);
        actionCurrent->setChecked(false);
        actionBus_voltage = new QAction(MainWindow);
        actionBus_voltage->setObjectName(QStringLiteral("actionBus_voltage"));
        actionBus_voltage->setCheckable(true);
        actionBus_voltage->setChecked(false);
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
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget2 = new QCustomPlot(tab_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(250);
        sizePolicy2.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(widget2);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 72)
            tableWidget->setRowCount(72);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(26, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(27, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(28, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(29, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(30, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(31, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(32, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(33, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(34, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(35, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(36, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(37, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(38, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(39, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(40, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(41, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(42, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(43, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(44, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(45, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(46, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(47, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(48, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(49, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(50, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(51, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(52, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(53, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(54, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(55, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(56, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(57, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(58, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(59, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(60, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(61, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(62, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(63, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(64, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(65, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(66, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(67, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(68, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(69, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(70, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(71, __qtablewidgetitem73);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(430, 0));
        tableWidget->setMaximumSize(QSize(407, 16777215));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        tableWidget->setAutoScroll(false);
        tableWidget->setGridStyle(Qt::DotLine);
        tableWidget->horizontalHeader()->setVisible(true);

        horizontalLayout->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(frame);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem75);
        if (tableWidget_2->rowCount() < 15)
            tableWidget_2->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(6, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(7, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(8, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(9, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(10, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(11, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(12, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(13, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(14, __qtablewidgetitem90);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(430, 0));
        tableWidget_2->setMaximumSize(QSize(407, 16777215));
        tableWidget_2->setBaseSize(QSize(0, 0));
        tableWidget_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        tableWidget_2->setAutoScroll(false);
        tableWidget_2->setGridStyle(Qt::DotLine);
        tableWidget_2->horizontalHeader()->setVisible(true);

        horizontalLayout->addWidget(tableWidget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        SendBtn = new QPushButton(frame);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));

        verticalLayout_3->addWidget(SendBtn);

        clearButton = new QPushButton(frame);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        verticalLayout_3->addWidget(clearButton);

        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy3);
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(lcdNumber);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout);

        splitter->addWidget(frame);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1228, 22));
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
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy4);
        dockWidget->setMinimumSize(QSize(73, 41));
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
        xComConfigDockWidget = new QDockWidget(MainWindow);
        xComConfigDockWidget->setObjectName(QStringLiteral("xComConfigDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        layoutWidget_2 = new QWidget(dockWidgetContents_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 142, 181));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout_how_to_use->setText(QApplication::translate("MainWindow", "about how to use", 0));
        actionDisplacement->setText(QApplication::translate("MainWindow", "displacement", 0));
        actionMotor_speed->setText(QApplication::translate("MainWindow", "motor speed", 0));
        actionMotor_accel->setText(QApplication::translate("MainWindow", "motor accel", 0));
        actionCurrent->setText(QApplication::translate("MainWindow", "current", 0));
        actionBus_voltage->setText(QApplication::translate("MainWindow", "bus voltage", 0));
        actionSystem_config->setText(QApplication::translate("MainWindow", "system config", 0));
        actionCurve_config->setText(QApplication::translate("MainWindow", "curve config", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\250\252\346\273\232\345\217\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\344\277\257\344\273\260\345\217\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\346\234\200\345\244\247\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2541\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2542\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2543\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2544\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2545\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2546\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2547\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2548\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2549\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2541\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2542\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2543\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2544\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2545\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2546\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2547\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2548\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2549\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\346\234\200\345\244\247\346\223\215\347\272\265\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\346\234\200\345\244\247\346\223\215\344\275\234\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2541\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2542\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2543\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2544\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2545\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2546\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2547\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2548\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\254\2549\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(30);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2541\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(31);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2542\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(32);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2543\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(33);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2544\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(34);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2545\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(35);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2546\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->verticalHeaderItem(36);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2547\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->verticalHeaderItem(37);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2548\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->verticalHeaderItem(38);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\254\2549\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->verticalHeaderItem(39);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\346\234\200\345\244\247\346\223\215\347\272\265\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->verticalHeaderItem(40);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\345\220\257\345\212\250\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->verticalHeaderItem(41);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\345\220\257\345\212\250\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->verticalHeaderItem(42);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\345\214\272\345\237\237\345\211\215\346\216\250\346\221\251\346\223\246\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->verticalHeaderItem(43);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\345\214\272\345\237\237\345\220\216\346\213\211\346\221\251\346\223\246\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(44);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\345\214\272\345\237\237\345\211\215\346\216\250\346\221\251\346\223\246\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(45);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\345\214\272\345\237\237\345\220\216\346\213\211\346\221\251\346\223\246\345\212\233", 0));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->verticalHeaderItem(46);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\347\251\272\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->verticalHeaderItem(47);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\347\251\272\350\241\214\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->verticalHeaderItem(48);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "\351\230\273\345\260\274\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->verticalHeaderItem(49);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "\357\274\210\350\207\252\346\214\257\357\274\211\351\242\221\347\216\207", 0));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->verticalHeaderItem(50);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "\347\255\211\346\225\210\350\264\250\351\207\217\357\274\210\346\203\257\351\207\217\357\274\211", 0));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->verticalHeaderItem(51);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "\345\267\246\345\211\215\351\205\215\345\271\263\350\214\203\345\233\264", 0));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->verticalHeaderItem(52);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\216\351\205\215\345\271\263\350\214\203\345\233\264", 0));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->verticalHeaderItem(53);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWindow", "\351\205\215\345\271\263\347\233\256\346\240\207\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->verticalHeaderItem(54);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWindow", "\351\205\215\345\271\263/\346\224\271\345\271\263\346\214\207\344\273\244", 0));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->verticalHeaderItem(55);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\345\273\266\350\277\237", 0));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->verticalHeaderItem(56);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\214\207\344\273\244\357\274\210\351\232\217\345\212\250\357\274\214\345\206\260\345\206\273\357\274\214\344\270\273\345\212\250\357\274\211", 0));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->verticalHeaderItem(57);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->verticalHeaderItem(58);
        ___qtablewidgetitem60->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260\344\270\212\351\231\220\345\257\271\345\272\224\350\257\257\345\267\256\351\227\250\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->verticalHeaderItem(59);
        ___qtablewidgetitem61->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->verticalHeaderItem(60);
        ___qtablewidgetitem62->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->verticalHeaderItem(61);
        ___qtablewidgetitem63->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\345\211\215\351\246\210\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->verticalHeaderItem(62);
        ___qtablewidgetitem64->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\350\265\267\345\247\213\350\257\257\345\267\256\344\270\213\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->verticalHeaderItem(63);
        ___qtablewidgetitem65->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\350\265\267\345\247\213\350\257\257\345\267\256\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget->verticalHeaderItem(64);
        ___qtablewidgetitem66->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\351\245\261\345\222\214\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget->verticalHeaderItem(65);
        ___qtablewidgetitem67->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\351\245\261\345\222\214\344\270\213\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget->verticalHeaderItem(66);
        ___qtablewidgetitem68->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget->verticalHeaderItem(67);
        ___qtablewidgetitem69->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\347\247\257\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget->verticalHeaderItem(68);
        ___qtablewidgetitem70->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget->verticalHeaderItem(69);
        ___qtablewidgetitem71->setText(QApplication::translate("MainWindow", "\345\244\226\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget->verticalHeaderItem(70);
        ___qtablewidgetitem72->setText(QApplication::translate("MainWindow", "\345\244\226\347\216\257\347\247\257\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget->verticalHeaderItem(71);
        ___qtablewidgetitem73->setText(QApplication::translate("MainWindow", "\345\244\226\347\216\257\345\276\256\345\210\206\346\264\227\346\274\261", 0));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem74->setText(QApplication::translate("MainWindow", "\346\250\252\346\273\232\345\217\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem75->setText(QApplication::translate("MainWindow", "\344\277\257\344\273\260\345\217\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem76->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem77->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260\344\270\212\351\231\220\345\257\271\345\272\224\350\257\257\345\267\256\351\227\250\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem78->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem79->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem80->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\345\211\215\351\246\210\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem81->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\351\245\261\345\222\214\344\270\213\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_2->verticalHeaderItem(6);
        ___qtablewidgetitem82->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\351\245\261\345\222\214\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_2->verticalHeaderItem(7);
        ___qtablewidgetitem83->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\350\265\267\345\247\213\350\257\257\345\267\256\344\270\213\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_2->verticalHeaderItem(8);
        ___qtablewidgetitem84->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\347\247\257\345\210\206\350\265\267\345\247\213\350\257\257\345\267\256\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_2->verticalHeaderItem(9);
        ___qtablewidgetitem85->setText(QApplication::translate("MainWindow", "\345\206\205\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_2->verticalHeaderItem(10);
        ___qtablewidgetitem86->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_2->verticalHeaderItem(11);
        ___qtablewidgetitem87->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_2->verticalHeaderItem(12);
        ___qtablewidgetitem88->setText(QApplication::translate("MainWindow", "\344\270\255\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_2->verticalHeaderItem(13);
        ___qtablewidgetitem89->setText(QApplication::translate("MainWindow", "\345\244\226\347\216\257\346\257\224\344\276\213\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_2->verticalHeaderItem(14);
        ___qtablewidgetitem90->setText(QApplication::translate("MainWindow", "\345\244\226\347\216\257\345\276\256\345\210\206\347\263\273\346\225\260", 0));
        SendBtn->setText(QApplication::translate("MainWindow", "Send", 0));
        clearButton->setText(QApplication::translate("MainWindow", "clear", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "help", 0));
        menuLine_select->setTitle(QApplication::translate("MainWindow", "line select", 0));
        menuDockwidget->setTitle(QApplication::translate("MainWindow", "dockwidget", 0));
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
        checkBox_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\233\262\347\272\2771", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\233\262\347\272\2772", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\233\262\347\272\2773", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\233\262\347\272\2774", 0));
        label_6->setText(QApplication::translate("MainWindow", "COM", 0));
        label_7->setText(QApplication::translate("MainWindow", "BAUD", 0));
        baudBox_2->clear();
        baudBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "BAUD", 0));
        stopBox_2->clear();
        stopBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
        );
        label_9->setText(QApplication::translate("MainWindow", "DATA", 0));
        dataBox_2->clear();
        dataBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_10->setText(QApplication::translate("MainWindow", "CHECK", 0));
        checkBox_6->clear();
        checkBox_6->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "none", 0)
        );
        openButton_2->setText(QApplication::translate("MainWindow", "open", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
