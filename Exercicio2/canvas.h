#ifndef CANVAS_H
#define CANVAS_H

#define _USE_MATH_DEFINES
#include <QWidget>
#include <QPainter>
#include <memory>
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std::chrono;

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();
    int option = 0;
    int numOfExecutions = 0;
    int numOfPoints = 0;
    int radius = 0;
    void setCenter(int xCenter, int yCenter);

private:
    Ui::Canvas *ui;
    int xCenter = 0, yCenter = 0;
    void paintEvent(QPaintEvent *event);
    void circlePoints(int x, int y);
    void midPointCircle(int r);
    void polarCoordCircle(int r);
    void polygonAproxCircle(int r);
};

#endif // CANVAS_H
