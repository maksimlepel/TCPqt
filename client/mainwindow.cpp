#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->send_bt->setEnabled(false);
    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SendToServer()
{
    int size = ui->textSize_sb->value();
    QString color=ui->textColor_cb->currentText();
    QString str=ui->text_le->text();
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out<<myPixmap<<str<<color<<size;
    socket->write(Data);
}

void MainWindow::slotReadyRead()
{
    socket->waitForReadyRead();
    QByteArray data;
    data=socket->readAll();
    QDataStream in( data );
    in >> myPixmap;
    ui->receivedImage_lb->setPixmap( myPixmap );
}

void MainWindow::on_save_bt_clicked()
{
    if(!myPixmap.save(ui->savePath_le->text(),"JPG"))
    {
        QMessageBox msgBox;
        msgBox.setText("incorrect path");
        msgBox.exec();
    }
}

void MainWindow::on_connect_bt_clicked()
{
     socket->connectToHost("127.0.0.1",2323);
}

void MainWindow::on_send_bt_clicked()
{
    this->SendToServer();
    ui->send_bt->setEnabled(false);
}

void MainWindow::on_sourcePath_le_editingFinished()
{
    myPixmap.load(ui->sourcePath_le->text());
    if(myPixmap.isNull())
    {
        ui->inputImage_lb->clear();
        ui->send_bt->setEnabled(false);
        return;
    }
    ui->inputImage_lb->setPixmap( myPixmap );
    ui->send_bt->setEnabled(true);
}
