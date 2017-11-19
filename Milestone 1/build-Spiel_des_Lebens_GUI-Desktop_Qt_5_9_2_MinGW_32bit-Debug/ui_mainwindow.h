/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralWidget;
    QWidget *gameWidget;
    QTableView *tableView;
    QFrame *frame;
    QSpinBox *spinWidth;
    QSpinBox *spinHeigh;
    QSlider *sliderSpeed;
    QLCDNumber *lcdAlive;
    QLabel *labelWidth;
    QLabel *labelHeigh;
    QLabel *labelAlive;
    QLCDNumber *lcdAge;
    QLabel *labelAge;
    QLabel *labelSpeed;
    QLCDNumber *lcdSpeed;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *btnStop;
    QPushButton *btnEvolve;
    QPushButton *btnGo;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(660, 401);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gameWidget = new QWidget(centralWidget);
        gameWidget->setObjectName(QStringLiteral("gameWidget"));
        gameWidget->setGeometry(QRect(10, 10, 461, 331));
        tableView = new QTableView(gameWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 451, 331));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(470, 10, 181, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        spinWidth = new QSpinBox(frame);
        spinWidth->setObjectName(QStringLiteral("spinWidth"));
        spinWidth->setGeometry(QRect(20, 200, 41, 22));
        spinHeigh = new QSpinBox(frame);
        spinHeigh->setObjectName(QStringLiteral("spinHeigh"));
        spinHeigh->setGeometry(QRect(90, 200, 43, 22));
        sliderSpeed = new QSlider(frame);
        sliderSpeed->setObjectName(QStringLiteral("sliderSpeed"));
        sliderSpeed->setGeometry(QRect(10, 150, 160, 16));
        sliderSpeed->setOrientation(Qt::Horizontal);
        lcdAlive = new QLCDNumber(frame);
        lcdAlive->setObjectName(QStringLiteral("lcdAlive"));
        lcdAlive->setGeometry(QRect(100, 10, 64, 23));
        labelWidth = new QLabel(frame);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setGeometry(QRect(20, 180, 47, 13));
        labelHeigh = new QLabel(frame);
        labelHeigh->setObjectName(QStringLiteral("labelHeigh"));
        labelHeigh->setGeometry(QRect(90, 180, 47, 13));
        labelAlive = new QLabel(frame);
        labelAlive->setObjectName(QStringLiteral("labelAlive"));
        labelAlive->setGeometry(QRect(10, 10, 51, 16));
        lcdAge = new QLCDNumber(frame);
        lcdAge->setObjectName(QStringLiteral("lcdAge"));
        lcdAge->setGeometry(QRect(100, 40, 64, 23));
        labelAge = new QLabel(frame);
        labelAge->setObjectName(QStringLiteral("labelAge"));
        labelAge->setGeometry(QRect(10, 40, 61, 20));
        labelSpeed = new QLabel(frame);
        labelSpeed->setObjectName(QStringLiteral("labelSpeed"));
        labelSpeed->setGeometry(QRect(10, 120, 81, 16));
        lcdSpeed = new QLCDNumber(frame);
        lcdSpeed->setObjectName(QStringLiteral("lcdSpeed"));
        lcdSpeed->setGeometry(QRect(100, 120, 64, 23));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(91, 80, 71, 22));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 51, 16));
        btnStop = new QPushButton(frame);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(10, 230, 71, 21));
        btnEvolve = new QPushButton(frame);
        btnEvolve->setObjectName(QStringLiteral("btnEvolve"));
        btnEvolve->setGeometry(QRect(10, 260, 71, 21));
        btnGo = new QPushButton(frame);
        btnGo->setObjectName(QStringLiteral("btnGo"));
        btnGo->setGeometry(QRect(10, 290, 71, 21));
        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(90, 230, 80, 31));
        btnLoad = new QPushButton(frame);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setGeometry(QRect(90, 280, 80, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 20));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("MainWindow", "width", Q_NULLPTR));
        labelHeigh->setText(QApplication::translate("MainWindow", "heigh", Q_NULLPTR));
        labelAlive->setText(QApplication::translate("MainWindow", "Cells alive:", Q_NULLPTR));
        labelAge->setText(QApplication::translate("MainWindow", "World Age:", Q_NULLPTR));
        labelSpeed->setText(QApplication::translate("MainWindow", "Evolution Speed", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Color:", Q_NULLPTR));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        btnEvolve->setText(QApplication::translate("MainWindow", "Evolve", Q_NULLPTR));
        btnGo->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        btnSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        btnLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
