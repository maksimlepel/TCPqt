#include "server.h"
#include <QPixmap>
Server::Server(MainWindow *w)
{
    _w=w;
    if(this->listen(QHostAddress::Any,2323))
    {
        qDebug()<<"Start";
    }
    else
    {
         qDebug()<<"Error";
    }
}
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket=new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead,this,&Server::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    Sockets.push_back(socket);
    _w->setConnectionStatus("client connected"/*+QString(socketDescriptor)*/);
    qDebug()<<"client connected, descr:"<<socketDescriptor;
}
void Server::slotReadyRead()
{
    socket->waitForReadyRead();
    Data=socket->readAll();
    QDataStream in( Data );

    QPixmap myPixmap;
    QString myString;
    QString color;
    int size;

    in >> myPixmap>>myString>>color>>size;
    _w->setPixmap(myPixmap);
    _w->setText(myString);


    QPainter painter;
    qDebug()<<Qt::green;
    painter.begin(&myPixmap);
    painter.setPen(color);


    painter.setFont(QFont("Tahoma", size));
    painter.drawText(myPixmap.rect(), Qt::AlignCenter, myString);
    painter.end();

    this->SendToClient(myPixmap);

;

}
void Server::SendToClient(QPixmap pm)
{
     Data.clear();
     QDataStream out(&Data,QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_6);
     out<<pm;
     socket->write(Data);
}
