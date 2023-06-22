#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::setPixmap(QPixmap pm)
{
    ui->label->setPixmap( pm );
}
void MainWindow::setText(QString str)
{
    ui->label_2->setText(str);
}
MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_clicked()
{
    QDataStream in( dataFromServer );
    QPixmap pm1;
    in >> pm1;

    //QPixmap *pm = new QPixmap( ":/bobr1.jpg" );
    QPainter painter;
    painter.begin(&pm1);
    painter.setPen(Qt::yellow);
    painter.setFont(QFont("Tahoma", 20));
    painter.drawText(pm1.rect(), Qt::AlignCenter, QString("kurva_bober"));
    painter.end();


    ui->label->setPixmap( pm1 );
}
void MainWindow::on_pushButton_2_clicked()
{
    QDataStream in( dataFromServer );
    QString str;
    in >> str;
    ui->label_2->setText(str);
}*/
