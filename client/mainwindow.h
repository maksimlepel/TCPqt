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

    void on_save_bt_clicked();

    void on_connect_bt_clicked();

    void on_send_bt_clicked();

    void on_sourcePath_le_editingFinished();

private:
    QPixmap myPixmap;
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray Data;
    void SendToServer();
public slots:
    void slotReadyRead();
};

#endif // MAINWINDOW_H
