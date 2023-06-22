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
void MainWindow::setConnectionStatus(QString str)
{
    ui->label_3->setText(str);
}
MainWindow::~MainWindow()
{
    delete ui;
}
