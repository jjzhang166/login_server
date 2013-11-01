#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QTimer>
#include <QDataStream>
#include <QMessageBox>
#include <QCryptographicHash>
#include "TYPES.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QUdpSocket *udpsocket;
    QSqlDatabase db;
private slots:
    void setPort(int port);
    void startTcpServer();
    void closeTcpServer();
    void startUdpServer();
    void closeUdpServer();
    void newConnect();
    void readMessages();
    void processPendingDatagrams();

private:
    void initConnect();
    void initDatabase();
    void sendMessages(QString msg);
    QString GetLocalIPAddress();
    int verify(QString msg);
    int signup_check(QDataStream &in);
};

#endif // MAINWINDOW_H
