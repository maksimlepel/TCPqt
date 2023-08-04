#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

void MainWindow::SendToServer()
{
    try{myPixmap.load(ui->lineEdit_2->text());}
    catch(...){myPixmap.load("C:/Users/NoSuchFileException/Desktop/beavers/bobr4");}
    int size = ui->spinBox->value();
    QString color=ui->comboBox->currentText();
    QString str=ui->lineEdit->text();
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
    ui->label_2->setPixmap( myPixmap );
}

void MainWindow::on_pushButton_3_clicked()
{

this->SendToServer();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
     myPixmap.load(ui->lineEdit_2->text());
     ui->label->setPixmap( myPixmap );
}

void MainWindow::on_pushButton_2_clicked()
{
    myPixmap.save(ui->lineEdit_3->text(),"JPG");
}
