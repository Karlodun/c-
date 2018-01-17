#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(QColor("#000")),
    game(new GameWidget(this))
{
    ui->setupUi(this);
    ui->modeControl->addItem("Classic Life");
    ui->modeControl->addItem("Snake");
    ui->modeControl->addItem("Predator-Victim");
    ui->cellsMode->addItem("Classic/Food");
    ui->cellsMode->addItem("Predator");
    ui->cellsMode->addItem("Victim");

    QPixmap icon(16, 16);
    icon.fill(currentColor);
    ui->colorButton->setIcon( QIcon(icon) );


    connect(ui->StartButton, SIGNAL(clicked()), game,SLOT(startGame()));
    connect(ui->StopButton, SIGNAL(clicked()), game,SLOT(stopGame()));
    connect(ui->ClearButton, SIGNAL(clicked()), game,SLOT(clear()));
    connect(ui->SaveButton, SIGNAL(clicked()), this,SLOT(saveGame()));
    connect(ui->LoadButton, SIGNAL(clicked()), this,SLOT(loadGame()));
    connect(ui->lifetime, SIGNAL(valueChanged(int)), game, SLOT(setLifeInterval(int)));
    connect(ui->iterInterval, SIGNAL(valueChanged(int)), game, SLOT(setInterval(int)));
    connect(ui->cellsMode, SIGNAL(valueChanged(int)), game, SLOT(setCellNumber(int)));

    connect(ui->modeControl, SIGNAL(currentIndexChanged(int)), game, SLOT(setMode(int)));
    connect(ui->cellsMode, SIGNAL(currentIndexChanged(int)), game, SLOT(setCellMode(int)));

    connect(game,SIGNAL(environmentChanged(bool)),ui->cellsMode,SLOT(setDisabled(bool)));
    connect(game,SIGNAL(gameEnds(bool)),ui->cellsMode,SLOT(setEnabled(bool)));
    connect(ui->colorButton, SIGNAL(clicked()), this, SLOT(selectMasterColor()));

//    ui->mainLayout->setStretchFactor(ui->gameLayout, 8);
//    ui->mainLayout->setStretchFactor(ui->setLayout, 2);
    ui->gameLayout->addWidget(game);
//    ui->gameLayout->addWidget(game1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveGame(){
    // disabled due to incompatibility with our cabase and no req. in Milestone2
    /*
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save current game"),
                                                    QDir::homePath(),
                                                    tr("Conway's Game *.life Files (*.life)"));
    if(filename.length() < 1)
        return;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    QString s = QString::number(game->cellNumber())+"\n";
    file.write(s.toUtf8());
    file.write(game->dump().toUtf8());
    QColor color = game->masterColor();
    QString buf = QString::number(color.red())+" "+
                  QString::number(color.green())+" "+
                  QString::number(color.blue())+"\n";
    file.write(buf.toUtf8());
    buf.clear();
    buf = QString::number(ui->iterInterval->value())+"\n";
    file.write(buf.toUtf8());
    file.close();
    */
}

void MainWindow::loadGame(){
    // disabled due to incompatibility with our cabase and no req. in Milestone2
    /*
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open saved game"),
                                                    QDir::homePath(),
                                                    tr("Conway's Game Of Life File (*.life)"));
    if(filename.length() < 1) return;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;
    QTextStream in(&file);
    int sv;
    in >> sv;
    ui->cellsControl->setValue(sv);

    game->setCellNumber(sv); // ### link this
    QString dump="";
    for(int k=0; k != sv; k++) {
        QString t;
        in >> t;
        dump.append(t+"\n");
    }

    game->setDump(dump);

    int r,g,b; // RGB color
    in >> r >> g >> b;
    currentColor = QColor(r,g,b);
    game->setMasterColor(currentColor); // sets color of the dots
    QPixmap icon(16, 16); // icon on the button
    icon.fill(currentColor); // fill with new color
    ui->colorButton->setIcon( QIcon(icon) ); // set icon for button
    in >> r; // r will be interval number
    ui->iterInterval->setValue(r);
    game->setInterval(r);
    */
}

void MainWindow::selectMasterColor()
{
    QColor color = QColorDialog::getColor(currentColor, this, tr("Select color of figures"));
    if(!color.isValid())
        return;
    currentColor = color;
    game->setMasterColor(color);
    QPixmap icon(16, 16);
    icon.fill(color);
    ui->colorButton->setIcon( QIcon(icon) );
}
