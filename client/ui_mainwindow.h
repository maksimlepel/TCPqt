/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *connect_bt;
    QLabel *inputImage_lb;
    QLabel *receivedImage_lb;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *save_bt;
    QLineEdit *savePath_le;
    QLabel *label_8;
    QPushButton *send_bt;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *textColor_cb;
    QSpinBox *textSize_sb;
    QLabel *label_5;
    QLineEdit *text_le;
    QLineEdit *sourcePath_le;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(876, 590);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        connect_bt = new QPushButton(centralWidget);
        connect_bt->setObjectName(QStringLiteral("connect_bt"));
        connect_bt->setGeometry(QRect(9, 9, 75, 23));
        inputImage_lb = new QLabel(centralWidget);
        inputImage_lb->setObjectName(QStringLiteral("inputImage_lb"));
        inputImage_lb->setGeometry(QRect(20, 50, 341, 311));
        receivedImage_lb = new QLabel(centralWidget);
        receivedImage_lb->setObjectName(QStringLiteral("receivedImage_lb"));
        receivedImage_lb->setGeometry(QRect(420, 30, 451, 411));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 0, 131, 41));
        QFont font;
        font.setPointSize(15);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 0, 151, 41));
        label_4->setFont(font);
        save_bt = new QPushButton(centralWidget);
        save_bt->setObjectName(QStringLiteral("save_bt"));
        save_bt->setGeometry(QRect(580, 500, 75, 23));
        savePath_le = new QLineEdit(centralWidget);
        savePath_le->setObjectName(QStringLiteral("savePath_le"));
        savePath_le->setGeometry(QRect(490, 480, 291, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 480, 41, 21));
        QFont font1;
        font1.setPointSize(12);
        label_8->setFont(font1);
        send_bt = new QPushButton(centralWidget);
        send_bt->setObjectName(QStringLiteral("send_bt"));
        send_bt->setGeometry(QRect(130, 390, 141, 81));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 370, 110, 106));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textColor_cb = new QComboBox(layoutWidget);
        textColor_cb->setObjectName(QStringLiteral("textColor_cb"));

        gridLayout->addWidget(textColor_cb, 3, 0, 1, 1);

        textSize_sb = new QSpinBox(layoutWidget);
        textSize_sb->setObjectName(QStringLiteral("textSize_sb"));
        textSize_sb->setMinimum(10);
        textSize_sb->setMaximum(100);
        textSize_sb->setSingleStep(5);
        textSize_sb->setValue(40);

        gridLayout->addWidget(textSize_sb, 4, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        text_le = new QLineEdit(layoutWidget);
        text_le->setObjectName(QStringLiteral("text_le"));

        gridLayout->addWidget(text_le, 1, 0, 1, 1);

        sourcePath_le = new QLineEdit(centralWidget);
        sourcePath_le->setObjectName(QStringLiteral("sourcePath_le"));
        sourcePath_le->setGeometry(QRect(20, 480, 371, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 450, 98, 19));
        label_6->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        connect_bt->raise();
        inputImage_lb->raise();
        receivedImage_lb->raise();
        label_3->raise();
        label_4->raise();
        save_bt->raise();
        savePath_le->raise();
        label_8->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        send_bt->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 876, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        connect_bt->setText(QApplication::translate("MainWindow", "Connect", 0));
        inputImage_lb->setText(QString());
        receivedImage_lb->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Input Image", 0));
        label_4->setText(QApplication::translate("MainWindow", "Received image", 0));
        save_bt->setText(QApplication::translate("MainWindow", "SAVE", 0));
        savePath_le->setText(QApplication::translate("MainWindow", "C:/Users/NoSuchFileException/Desktop/beavers/bobr.jpg", 0));
        label_8->setText(QApplication::translate("MainWindow", "Path", 0));
        send_bt->setText(QApplication::translate("MainWindow", "SendPictureAndText", 0));
        textColor_cb->clear();
        textColor_cb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "color0", 0)
         << QApplication::translate("MainWindow", "color1", 0)
         << QApplication::translate("MainWindow", "black", 0)
         << QApplication::translate("MainWindow", "white", 0)
         << QApplication::translate("MainWindow", "darkGray", 0)
         << QApplication::translate("MainWindow", "gray", 0)
         << QApplication::translate("MainWindow", "lightGray", 0)
         << QApplication::translate("MainWindow", "red", 0)
         << QApplication::translate("MainWindow", "green", 0)
         << QApplication::translate("MainWindow", "blue", 0)
         << QApplication::translate("MainWindow", "cyan", 0)
         << QApplication::translate("MainWindow", "magenta", 0)
         << QApplication::translate("MainWindow", "darkYellow", 0)
         << QApplication::translate("MainWindow", "transparent", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "Input Text", 0));
        text_le->setText(QApplication::translate("MainWindow", "Default text", 0));
        sourcePath_le->setText(QApplication::translate("MainWindow", "C:\\Users\\NoSuchFileException\\Desktop\\beavers\\bobr4", 0));
        label_6->setText(QApplication::translate("MainWindow", "Image Source", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
