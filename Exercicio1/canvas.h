#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <memory>
#include <iostream>
#include <cmath>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();
    void setLinePoints(int x1, int y1, int x2, int y2);
    void setCenter(int xCenter, int yCenter);
    bool shouldDraw = false;

private:
    Ui::Canvas *ui;
    int x1 = 1, y1 = 1;
    int x2 = 2, y2 = 2;
    int xCenter = 0, yCenter = 0;

    void paintEvent(QPaintEvent *event);
    void pontoMedio(int x1, int y1, int x2, int y2);
    void pontoMedioCompleto(int x,int y,int x2, int y2);
    void plotLine(int x0, int y0, int x1, int y1);

    void plotLineLow(int x0, int y0, int x1, int y1);
    void plotLineHigh(int x0, int y0, int x1, int y1);
    void plotLineTotal(int x0, int y0, int x1, int y1);
};

#endif // CANVAS_H
