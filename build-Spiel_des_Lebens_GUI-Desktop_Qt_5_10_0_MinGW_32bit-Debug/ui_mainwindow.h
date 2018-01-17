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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *setLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *StopButton;
    QPushButton *StartButton;
    QPushButton *ClearButton;
    QLabel *label_3;
    QSpinBox *lifetime;
    QLabel *SizeLabel;
    QComboBox *modeControl;
    QLabel *label;
    QComboBox *cellsMode;
    QLabel *label_2;
    QSpinBox *iterInterval;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *colorButton;
    QPushButton *LoadButton;
    QPushButton *SaveButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *gameLayout;

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
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(360, 0, 291, 381));
        setLayout = new QVBoxLayout(verticalLayoutWidget);
        setLayout->setSpacing(6);
        setLayout->setContentsMargins(11, 11, 11, 11);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        setLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        StopButton = new QPushButton(verticalLayoutWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout_2->addWidget(StopButton);

        StartButton = new QPushButton(verticalLayoutWidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        horizontalLayout_2->addWidget(StartButton);

        ClearButton = new QPushButton(verticalLayoutWidget);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));

        horizontalLayout_2->addWidget(ClearButton);


        setLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        setLayout->addWidget(label_3);

        lifetime = new QSpinBox(verticalLayoutWidget);
        lifetime->setObjectName(QStringLiteral("lifetime"));
        lifetime->setMinimum(10);
        lifetime->setMaximum(100000);
        lifetime->setSingleStep(10);

        setLayout->addWidget(lifetime);

        SizeLabel = new QLabel(verticalLayoutWidget);
        SizeLabel->setObjectName(QStringLiteral("SizeLabel"));

        setLayout->addWidget(SizeLabel);

        modeControl = new QComboBox(verticalLayoutWidget);
        modeControl->setObjectName(QStringLiteral("modeControl"));

        setLayout->addWidget(modeControl);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        setLayout->addWidget(label);

        cellsMode = new QComboBox(verticalLayoutWidget);
        cellsMode->setObjectName(QStringLiteral("cellsMode"));

        setLayout->addWidget(cellsMode);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        setLayout->addWidget(label_2);

        iterInterval = new QSpinBox(verticalLayoutWidget);
        iterInterval->setObjectName(QStringLiteral("iterInterval"));
        iterInterval->setMinimum(50);
        iterInterval->setMaximum(100000);
        iterInterval->setSingleStep(10);
        iterInterval->setValue(100);

        setLayout->addWidget(iterInterval);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        colorButton = new QPushButton(verticalLayoutWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        horizontalLayout_4->addWidget(colorButton);

        LoadButton = new QPushButton(verticalLayoutWidget);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));

        horizontalLayout_4->addWidget(LoadButton);

        SaveButton = new QPushButton(verticalLayoutWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        horizontalLayout_4->addWidget(SaveButton);


        setLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer_2);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, 0, 361, 381));
        gameLayout = new QVBoxLayout(verticalLayoutWidget_2);
        gameLayout->setSpacing(6);
        gameLayout->setContentsMargins(11, 11, 11, 11);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));
        gameLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        StopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        ClearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Set Lifetime of moving cells:", nullptr));
        SizeLabel->setText(QApplication::translate("MainWindow", "Universe Mode :", nullptr));
        label->setText(QApplication::translate("MainWindow", "Cells Mode:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Generation Intervall (in msec):", nullptr));
        iterInterval->setSuffix(QApplication::translate("MainWindow", "ms", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "color for Cells", nullptr));
        LoadButton->setText(QApplication::translate("MainWindow", "Load", nullptr));
        SaveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
