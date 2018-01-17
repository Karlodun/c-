#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include <QColor>
#include <CAbase.h>
#include <iostream>
#include <stdlib.h>
#include "gamewidget.h"
#include "QTime"
#include <QMessageBox>
#include <QTimer>
#include <fstream>
#include <snake.h>
#include <pasture.h>
#include <raptors.h>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;
CAbase base1(10, 10);
Snake snake1;
Pasture pHeard;
Raptors rHeard;

// hardcoded, no time for appopriate integration

void GameWidget::PrepareFieldSnake(){
    // we use initial size, and add borders
    base1.resizeWorld(base1.Nx+2,base1.Ny+2); // also clears world
    // our game is setup in a way, that the border is made of "walls", which are cells with value=2
    // thus we can have random obstacles on the field, if wanted. Game can be extended easely to have this.
    // add borders to outer cells, according to requirement, those borders should NOT be visible on field
    // we could make the field borders thicker, to visualize them.
    for (int i=0; i<=base1.Nx; i++) {  // yes, we set the corner cells twice, who cares?
        base1.setCell(i,0,2); //first row, first to last cell
        base1.setCell(i,base1.Ny,2); //last row, first to last cell
        base1.setCell(0,i,2); //first column, first to last cell
        base1.setCell(0,base1.Nx,2); //last column, first to last cell
    }

    /* random head setter,
     * disabled to comply with requirements that our snake needs head, few body and a tail part
     * those are distinguished just by their values (tail is always 3, even if tail=head)
    base1.setSnakeHead(base1.randomObjId()); // creates one object with value=3, and all objects with value>2 are movable and belong to snake.
    */
    base1.setCell(snake1.grow(base1.getCell(5,5)), 5); // we set a snake into cell 55
    snake1.Status=1;
    // random food cell 1 is food, we could combine both games :-)
    base1.setCell(base1.randomObjId(),1);
}

int GameWidget::moveSnake(){
    // this is only semi object oriented...
    if (1!=snake1.Status) return -1;  //snake is dead, don't move
    int newid;
    switch(snake1.Direction){
    case 8 : newid = snake1.Body[0] - base1.Nx; break;  //up
    case 4 : newid = snake1.Body[0] - 1; break;  //left
    case 5 : newid = snake1.Body[0] + base1.Nx; break; //down
    case 6 : newid = snake1.Body[0] + 1; break; //right
    default : return -1; //dead or not there
    }
    // depending on the object in newid our snake can move, grow or die
    switch(base1.World[newid]){
    case 0 : // move
        base1.setCell(snake1.move(newid), 0); // we move snake and clear tail in one step
        return 0;
    case 1 : // grow
        base1.setCell(snake1.grow(newid), 5);
        base1.setCell(base1.randomObjId(),1); // create random food cell
        return 1;
    default : // die, die, die my darling!
        snake1.Status=2;
        return -1;
    }
}


void GameWidget::evolveJungle(){
    /* we first evolve all raptors, then we evolve pasture
     * this will ensure the required behavior
     */
    int oldID, moveID, moveRes;
    // move raptors
    for (int i=0; i<=rHeard.Population; i++){
        oldID=rHeard.Locations[i];
        moveID=base1.moveSpecialCell(oldID,4);
        moveRes=rHeard.Move(i, moveID, base1.World[moveID]);
        switch(moveRes){
        case 1 : // base knows cell has moved and alive
            base1.World[moveID]=4; // set cell to raptor
            base1.World[oldID]=0; // remove raptor from old place
            break;
        case 0 : // base knows cell died
            base1.World[rHeard.Decay(i)]=0; // remove decayed raptor
        }
    }

    // procede with pasture
    for (int i=0; i<=rHeard.Population; i++){
        oldID=pHeard.Locations[i];
        if (base1.World[oldID]!=3) pHeard.Decay(i);  // the expected animal is not there anymore - update Heard data
        moveID=base1.moveSpecialCell(oldID,3);
        moveRes=pHeard.Move(i, moveID, base1.World[moveID]);
        switch(moveRes){
        case 1 : // base knows cell has moved and alive
            base1.World[moveID]=3; // set cell to pasture
            base1.World[oldID]=0; // remove pasture from old place
            break;
        case 0 : // base knows cell died
            base1.World[rHeard.Decay(i)]=0; // remove decayed pasture
        }
    }
}


GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent),
      timer(new QTimer(this)),
      timerColor(new QTimer(this)),
      generations(-1),
      universeSize(50),
      universeMode(0),
      cellMode(0),
      randomMode(0),
      lifeTime(50)
{
    timer->setInterval(300);
    timerColor->setInterval(50);
    m_masterColor = "#000";
    cout << "connecting timers" << endl;

    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    connect(timerColor, SIGNAL(timeout()), this, SLOT(newGenerationColor()));
    cout << "timers connected" << endl;
}

GameWidget::~GameWidget(){}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUniverse(p);
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
    emit environmentChanged(true);
    double cellWidth = (double)width()/base1.Nx;
    double cellHeight = (double)height()/base1.Ny;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    base1.flipCell(k,j);
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent *e)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;

    base1.flipCell(j,k);
    update();
}

void GameWidget::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt :: Key_2) snake1.move(5);
    if(e->key() == Qt :: Key_4) snake1.move(4);
    if(e->key() == Qt :: Key_6) snake1.move(6);
    if(e->key() == Qt :: Key_8) snake1.move(8);
}


void GameWidget::paintGrid(QPainter &p){
     QRect borders(0, 0, width()-1, height()-1); // borders of the universe
     QColor gridColor = m_masterColor; // color of the grid
     gridColor.setAlpha(10); // must be lighter than main color
     p.setPen(gridColor);
     double cellWidth = (double)width()/universeSize; // width of the widget / number of cells at one row
     for(double k = cellWidth; k <= width(); k += cellWidth)
         p.drawLine(k, 0, k, height());
     double cellHeight = (double)height()/universeSize; // height of the widget / number of cells at one row
     for(double k = cellHeight; k <= height(); k += cellHeight)
         p.drawLine(0, k, width(), k);
     p.drawRect(borders);
 }

void GameWidget::paintUniverse(QPainter &p){
 double cellWidth = (double)width()/universeSize;
 double cellHeight = (double)height()/universeSize;
 for(int k=1; k <= universeSize; k++) {
     for(int j=1; j <= universeSize; j++) {
         qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
         qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
         QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
         cout << "cellval: " << base1.getCell(j, k)<< endl;
        switch(base1.getCell(j, k)){
        case 0 : // empty cell
            //p.fillRect(r, Qt::gray);
            break;
        case 1 : // living cell, food for snake
            p.fillRect(r,Qt::green);
            break;
        case 2 : // wall
            p.fillRect(r,Qt::darkRed);
            break;
        case 3 : //pasture
            p.fillRect(r,Qt::yellow); //victimcells are Yellow
            break;
        case 4 : // raptor
            p.fillRect(r,Qt::blue); //predatorcells are Blue
            break;
        case 5 : // snake
            p.fillRect(r,Qt::cyan);
            break;
        }
     }
 }
}

int GameWidget::cellNumber()  // Number of the cells in one row
{
    return universeSize;
}

QColor GameWidget::masterColor()
{
    return m_masterColor;
}

QColor GameWidget::SetColor(const int &color)
{
    QColor cellColor[12]= {Qt::red, Qt::darkRed, Qt::green, Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan, Qt::darkCyan, Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow};
    return cellColor[color];
}

void GameWidget::setMasterColor(const QColor &color)
{
    m_masterColor = color;
    update();
}

void GameWidget::startGame(const int &number)  // Start Game
{
    generations = number;
    timer->start();
}

void GameWidget::stopGame()  //Stop Game
{
    timer->stop();
    timerColor->stop();
}

void GameWidget::clear() // Clear game field
{
    base1.clearWorld();
    gameEnds(true);
    base1.resizeWorld(universeSize,universeSize);
    randomMode = 0;
    update();
}

void GameWidget::setCellNumber(const int &s) // Set number of the cells in one row
{
    universeSize = s;
    base1.resizeWorld(s,s);
    update();
}

void GameWidget::setMode(const int &m) //Set evolution mode, but all modes can run together
{
    universeMode = m;
    if (m==1) PrepareFieldSnake();
    if (m==2) clear(); // clears Map, so User can place Raptors and Pastures
    update();
}

void GameWidget::setCellMode(const int &m) //Set cell mode
{
    cellMode = m;
    if (m==1) Raptors();
    else if (m==2) Pasture();
    update();
}

int GameWidget::lifeInterval() //cell's lifetime - number of step when cell is on the universe
{
    return lifeTime;
}

void GameWidget::setLifeInterval(const int &l) // set lifetime for cell
{
    lifeTime = l;
}

QString GameWidget::dump() // Dump of current universe
{
    char temp;
    QString master = "";
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
            if(base1.getCell(j,k) == 1) {
                temp = '*';
            } else {
                temp = 'o';
            }
            master.append(temp);
        }
        master.append("\n");
    }
    return master;
}

void GameWidget::setDump(const QString &data) // Set current universe from it's dump
{
    int current = 0;
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
           if(data[current] == '*') base1.setCell(j,k,1);
            current++;
        }
        current++;
    }
    update();
}


int GameWidget::interval() // Interval between generations
{
    return timer->interval();
}

void GameWidget::setInterval(int msec) // Set interval between generations
{
    timer->setInterval(msec);
}

void GameWidget::newGeneration()  // Start the evolution of universe and update the game field
{
    cout << "new generations" << endl;

    if(generations < 0) generations++;
    cout << "evolving world" << endl;

    base1.evolveWorld();

    update();
    cout << "updated" << endl;

    generations--;
    if(generations == 0) {
        stopGame();
        gameEnds(true);
        QMessageBox::information(this,
                                 tr("Game finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
}

void GameWidget::newGenerationColor() // Start the evolution of universe and update the game field for "Cyclic cellular automata" mode
{
    if(generations < 0)
        generations++;

    update();

    generations--;
    if(generations == 0) {
        stopGame();
        gameEnds(true);
        QMessageBox::information(this,
                                 tr("Game finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
}
