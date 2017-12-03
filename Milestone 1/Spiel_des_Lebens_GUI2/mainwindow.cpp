#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cabase.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameWidget game1();

    connect(ui->StartButton, SIGNAL(clicked()), game1,SLOT(startGame()));
    connect(ui->StopButton, SIGNAL(clicked()), game1,SLOT(stopGame()));
    connect(ui->ClearButton, SIGNAL(clicked()), game1,SLOT(clear()));
    connect(ui->SaveButton, SIGNAL(clicked()), this,SLOT(saveGame()));
    connect(ui->LoadButton, SIGNAL(clicked()), this,SLOT(loadGame()));

    ui->gameLayout->addWidget(game1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
