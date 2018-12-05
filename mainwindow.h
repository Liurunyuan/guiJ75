#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QPainter>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* getInstance();
    void testPrint();
protected:
    void paintEvent(QPaintEvent *event);
private:
    static MainWindow* mainWindow;
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
