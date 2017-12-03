#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "cabase.h"
#include <QPainter>
#include <QRectF>
#include <QWidget>
#include <QColor>


class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr); 
    int worldSize;
    bool *World = NULL;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);

private:
    CAbase base1(int x, int y);

signals:
    //when one of the cell has been changed,emit this signal to lock the universeSize
    void environmentChanged(bool ok);

private slots:
    void paintGrid(QPainter &map);
    void paintUniverse(QPainter &map);

public slots:
};



#endif // GAMEWIDGET_H
