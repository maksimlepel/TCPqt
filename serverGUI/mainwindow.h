#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include<QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QByteArray dataFromServer;
    void setPixmap(QPixmap pm);
    void setText(QString str);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

private:
     Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
