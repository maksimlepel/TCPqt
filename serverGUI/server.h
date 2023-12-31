#ifndef SERVER_H
#define SERVER_H
#include <QDataStream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QPixmap>
#include "mainwindow.h"
#include <map>
class Server: public QTcpServer
{
    Q_OBJECT
public:
    MainWindow* _w;
    explicit Server(MainWindow *w);
    QTcpSocket *socket;
private:
QVector <QTcpSocket*> Sockets;
QByteArray Data;
void SendToClient(QPixmap pm);
public slots:
void incomingConnection(qintptr socketDescriptor);
void slotReadyRead();
};
#endif // SERVER_H
