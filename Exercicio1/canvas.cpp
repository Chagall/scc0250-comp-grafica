#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent*) {
    this->pontoMedioCompleto(this->x1,this->y1,this->x2,this->y2);
}

void Canvas::setLinePoints(int x1, int y1, int x2, int y2) {
    this->x1 = this->xCenter + x1;
    this->y1 = this->yCenter + y1;

    this->x2 = this->xCenter + x2;
    this->y2 = this->yCenter + y2;
}

void Canvas::setCenter(int xCenter, int yCenter) {
    this->xCenter = xCenter;
    this->yCenter = yCenter;
}

void Canvas::plotLineLow(int x0, int y0, int x1, int y1) {
    auto painter = std::make_unique<QPainter>(this);
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int incE = 2 * dy;
    int incNE = (2 * (dy - dx));

    int y = y0;
    int x = x0;

    painter->drawPoint(x,y);

    while(x < x1) {
        x = x + 1;

        if(D > 0) {
            y = y + yi;
            D = D + incNE;
        }
        else {
            D = D + incE;
        }
        painter->drawPoint(x,y);
    }
}

void Canvas::plotLineHigh(int x0, int y0, int x1, int y1) {
    auto painter = std::make_unique<QPainter>(this);
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int incE = 2 * dx;
    int incNE = (2 * (dx - dy));

    int x = x0;
    int y = y0;

    painter->drawPoint(x,y);

    while(y < y1) {
        y = y + 1;

        if (D > 0) {
            x = x + xi;
            D = D + incNE;
        }
        else {
            D = D + incE;
        }
        painter->drawPoint(x,y);
    }
}

void Canvas::pontoMedioCompleto(int x0, int y0, int x1, int y1) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            plotLineLow(x1, y1, x0, y0);
        }
        else {
            plotLineLow(x0, y0, x1, y1);
        }
    }
    else {
        if (y0 > y1) {
            plotLineHigh(x1, y1, x0, y0);
        }
        else {
            plotLineHigh(x0, y0, x1, y1);
        }
    }
}
