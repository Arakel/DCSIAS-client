#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <logger.h>
#include <qtemplatethread.h>
#include <tcpclient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    QSystemTrayIcon* tray;
    QMenu* trayMenu;
    QMenuBar* windowMenu;
    QAction* showFromTray, *closeFromTray, *hideToTray, *closeFromMenu;
    QTemplateThread<TcpClient> netThread;
    TcpClient *netClient;
    Logger* logger;



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
