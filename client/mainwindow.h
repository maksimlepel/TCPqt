#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QPixmap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

private:
    QPixmap* myPixmap;
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray Data;
    void SendString(QString str);
    void SendImage();
public slots:
    void slotReadyRead();
};

#endif // MAINWINDOW_H
