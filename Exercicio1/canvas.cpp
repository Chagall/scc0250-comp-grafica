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
    this->pontoMedio(this->x1,this->y1,this->x2,this->y2);
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

void Canvas::pontoMedio(int x1, int y1, int x2, int y2) {
    auto painter = std::make_unique<QPainter>(this);
    int dx, dy, incE, incNE, d, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    std::cout << "dx: " << dx << std::endl;
    std::cout << "dy: " << dy << std::endl;
    std::cout << "dy/dx: " << dy/dx << std::endl;

    d = 2 * dy - dx; // dStart
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    x = x1;
    y = y1;

    painter->drawPoint(x,y);

    // Se a reta tem 90º
    if(dx == 0 && dy > 0) {
        std::cout << "90" << std::endl;
        while(y < y2) {
            y = y + 1;
            painter->drawPoint(x,y);
        }
    }
    // Se a reta tem 0º
    else if(dy == 0 && dx > 0) {
        std::cout << "0" << std::endl;
        while(x < x2) {
            x = x + 1;
            painter->drawPoint(x,y);
        }
    }
    // Se a reta tem 45º
    else if((dy/dx) == 1) {
        std::cout << "45" << std::endl;
        while(x < x2) {
            x = x + 1;
            y = y + 1;
            painter->drawPoint(x,y);
        }
    }
    else {
        while(x < x2) {
            if(d <= 0) {
                // Escolha E
                d = d + incE;
                x = x + 1;
            }
            else {
                // Escolha NE
                d = d + incNE;
                x = x + 1;
                y = y + 1;
            }
            // Desenha o pixel aqui com a função do QT de pintar
            painter->drawPoint(x,y);
        }
    }
}
