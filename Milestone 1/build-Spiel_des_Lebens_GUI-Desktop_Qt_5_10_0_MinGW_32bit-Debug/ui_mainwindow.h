/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QPushButton *btnStop;
    QPushButton *btnEvolve;
    QPushButton *btnGo;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QPushButton *btnClear;
    QPushButton *pushButton;
    QSpinBox *spinCellsTic;
    QSpinBox *spinSnakeTic;
    QLabel *labelCellsTic;
    QLabel *labelSnakeTic;
    QLabel *labelControls;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(655, 474);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gameWidget = new QWidget(centralWidget);
        gameWidget->setObjectName(QStringLiteral("gameWidget"));
        gameWidget->setGeometry(QRect(10, 10, 400, 400));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameWidget->sizePolicy().hasHeightForWidth());
        gameWidget->setSizePolicy(sizePolicy);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(420, 40, 231, 371));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        spinWidth = new QSpinBox(frame);
        spinWidth->setObjectName(QStringLiteral("spinWidth"));
        spinWidth->setGeometry(QRect(10, 200, 41, 22));
        spinWidth->setMinimum(10);
        spinWidth->setMaximum(50);
        spinHeigh = new QSpinBox(frame);
        spinHeigh->setObjectName(QStringLiteral("spinHeigh"));
        spinHeigh->setGeometry(QRect(60, 200, 43, 22));
        spinHeigh->setMinimum(10);
        spinHeigh->setMaximum(50);
        sliderSpeed = new QSlider(frame);
        sliderSpeed->setObjectName(QStringLiteral("sliderSpeed"));
        sliderSpeed->setGeometry(QRect(10, 100, 160, 16));
        sliderSpeed->setMaximum(120);
        sliderSpeed->setOrientation(Qt::Horizontal);
        lcdAlive = new QLCDNumber(frame);
        lcdAlive->setObjectName(QStringLiteral("lcdAlive"));
        lcdAlive->setGeometry(QRect(100, 10, 64, 23));
        labelWidth = new QLabel(frame);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setGeometry(QRect(10, 180, 47, 13));
        labelHeigh = new QLabel(frame);
        labelHeigh->setObjectName(QStringLiteral("labelHeigh"));
        labelHeigh->setGeometry(QRect(60, 180, 47, 13));
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
        labelSpeed->setGeometry(QRect(10, 70, 81, 16));
        lcdSpeed = new QLCDNumber(frame);
        lcdSpeed->setObjectName(QStringLiteral("lcdSpeed"));
        lcdSpeed->setGeometry(QRect(100, 70, 64, 23));
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
        btnSave->setGeometry(QRect(99, 230, 71, 21));
        btnLoad = new QPushButton(frame);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setGeometry(QRect(99, 260, 71, 21));
        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(100, 290, 71, 21));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 180, 61, 41));
        spinCellsTic = new QSpinBox(frame);
        spinCellsTic->setObjectName(QStringLiteral("spinCellsTic"));
        spinCellsTic->setGeometry(QRect(120, 120, 43, 22));
        spinSnakeTic = new QSpinBox(frame);
        spinSnakeTic->setObjectName(QStringLiteral("spinSnakeTic"));
        spinSnakeTic->setGeometry(QRect(120, 150, 43, 22));
        labelCellsTic = new QLabel(frame);
        labelCellsTic->setObjectName(QStringLiteral("labelCellsTic"));
        labelCellsTic->setGeometry(QRect(10, 120, 81, 16));
        labelSnakeTic = new QLabel(frame);
        labelSnakeTic->setObjectName(QStringLiteral("labelSnakeTic"));
        labelSnakeTic->setGeometry(QRect(10, 150, 101, 16));
        labelControls = new QLabel(centralWidget);
        labelControls->setObjectName(QStringLiteral("labelControls"));
        labelControls->setGeometry(QRect(420, 10, 81, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        labelWidth->setText(QApplication::translate("MainWindow", "width", nullptr));
        labelHeigh->setText(QApplication::translate("MainWindow", "heigh", nullptr));
        labelAlive->setText(QApplication::translate("MainWindow", "Cells alive:", nullptr));
        labelAge->setText(QApplication::translate("MainWindow", "World Age:", nullptr));
        labelSpeed->setText(QApplication::translate("MainWindow", "Steps/Second", nullptr));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        btnEvolve->setText(QApplication::translate("MainWindow", "Evolve", nullptr));
        btnGo->setText(QApplication::translate("MainWindow", "Go", nullptr));
        btnSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        btnLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Resize", nullptr));
        labelCellsTic->setText(QApplication::translate("MainWindow", "Steps/Age - Cells", nullptr));
        labelSnakeTic->setText(QApplication::translate("MainWindow", "Steps/Move - Snake", nullptr));
        labelControls->setText(QApplication::translate("MainWindow", "Controls", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
