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
    qDebug()<<"client connected, descr:"<<socketDescriptor;
}
void Server::slotReadyRead()
{
    socket->waitForReadyRead();
_w->dataFromServer.clear();
 _w->dataFromServer=socket->readAll();;

}
void Server::SendToClient(QPixmap pm)
{
     Data.clear();
     QDataStream out(&Data,QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_6);
     out<<pm;
     socket->write(Data);
    // for(int i = 0;i<Sockets.size();++i)
    // {
     //   Sockets[i]->write(Data);
     //}
}
