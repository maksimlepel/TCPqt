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
    QByteArray data;
    data=socket->readAll();
    QDataStream in( data );
    QString color;
    int size;
    in >> myPixmap>>myString>>color>>size;
    _w->setPixmap(myPixmap);
    _w->setText(myString);
    qDebug()<<myString;


    QPainter painter;
    painter.begin(&myPixmap);
    if(color=="green"){painter.setPen(Qt::green);}
    else if(color=="yellow"){painter.setPen(Qt::yellow);}
    else if(color=="white"){painter.setPen(Qt::white);}
    else if(color=="black"){painter.setPen(Qt::black);}
    else if(color=="blue"){painter.setPen(Qt::blue);}
    else if(color=="red"){painter.setPen(Qt::red);}


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
    // for(int i = 0;i<Sockets.size();++i)
    // {
     //   Sockets[i]->write(Data);
     //}
}
