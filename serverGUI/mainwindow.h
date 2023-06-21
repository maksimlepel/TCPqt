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
    void setLable(QPixmap pm);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
     Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
