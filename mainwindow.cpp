#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tray = new QSystemTrayIcon(QIcon("System.png"));
    trayMenu = new QMenu;
    showFromTray = trayMenu->addAction(QString("Show"));
    closeFromTray = trayMenu->addAction(QString("Close"));
    tray->setContextMenu(trayMenu);
    tray->show();
    windowMenu = new QMenuBar;
    QMenu* localMenu = new QMenu;
    hideToTray = localMenu->addAction(QString("Hide"));
    closeFromMenu = localMenu->addAction(QString("Close"));
    windowMenu->addMenu(localMenu);
    localMenu->setTitle(QString("Menu"));
    this->setMenuBar(windowMenu);
    ui->tabWidget->setTabText(0,QString("Main"));
    ui->tabWidget->setTabText(1,QString("Setting"));

    netThread.start();
    while(netThread.isReady())
    {
        QApplication::processEvents();
        if(netThread.isFinished())
        {
            break;
        }
    }
    netClient = netThread.getPtr();
    logger = new Logger(QString("TaskLog.txt"));



    connect(hideToTray,SIGNAL(triggered()),this,SLOT(hide()));
    connect(closeFromMenu,SIGNAL(triggered()),this,SLOT(close()));
    connect(showFromTray,SIGNAL(triggered()),this,SLOT(show()));
    connect(closeFromTray,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
