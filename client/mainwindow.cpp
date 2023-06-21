#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPixmap = new QPixmap( ":/bobr.jpg" );
    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1",2323);
}

void MainWindow::SendString(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out<<str;
    socket->write(Data);
    ui->lineEdit->clear();
}

void MainWindow::SendImage()
{
    ui->label_2->setPixmap( *myPixmap );
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out<<*myPixmap;

    socket->write(Data);
    qDebug()<<Data;
     qDebug()<<"Image send OK";
}

void MainWindow::slotReadyRead()
{
    socket->waitForReadyRead();
    QByteArray dataFromServer;
dataFromServer.clear();
 dataFromServer=socket->readAll();
 QDataStream in( dataFromServer );
 QPixmap pm1;
 in >> pm1;
 ui->label->setPixmap( pm1 );
}

void MainWindow::on_pushButton_2_clicked()
{
    SendString(ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
    SendString(ui->lineEdit->text());

}

void MainWindow::on_pushButton_3_clicked()//send picture
{

this->SendImage();
}
