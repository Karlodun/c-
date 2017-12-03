#include "gamewidget.h"
#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include <QColor>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    CAbase base1(30,30);
    worldSize = base1.getworldSize();
    World = new bool[worldSize];
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter map(this);
    paintGrid(map);
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
    emit environmentChanged(true);
    double cellWidth = (double)width()/worldSize;
    double cellHeight = (double)height()/worldSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    World[k*worldSize + j] = !World[k*worldSize + j];
    update();
}


void GameWidget::paintGrid(QPainter &map){
    QRect borders(0, 0, width()-1, height()-1); // borders of the universe
    double cellWidth = (double)width()/worldSize; // width of the widget / number of cells at one row
    for(double k = cellWidth; k <= width(); k += cellWidth)
        map.drawLine(k, 0, k, height());
    double cellHeight = (double)height()/worldSize; // height of the widget / number of cells at one row
    for(double k = cellHeight; k <= height(); k += cellHeight)
        map.drawLine(0, k, width(), k);
    map.drawRect(borders);
}

void GameWidget::paintUniverse(QPainter &map)
{
    double cellWidth = (double)width()/worldSize;
    double cellHeight = (double)height()/worldSize;
    for(int k=1; k <= worldSize; k++) {
        for(int j=1; j <= worldSize; j++) {
            if(World[k*worldSize + j] == true) { // if there is any sense to paint it
                qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
                qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                map.fillRect(r,QColor(120,60,55)); // fill cell with brush of main color
            }
        }
    }
}
