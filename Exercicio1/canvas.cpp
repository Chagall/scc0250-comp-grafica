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
    this->plotLineTotal(this->x1,this->y1,this->x2,this->y2);
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

    if(dx != 0) {
        std::cout << "abs(dy/dx): " << abs((float)dy/(float)dx) << std::endl;
    }

    x = x1;
    y = y1;

    painter->drawPoint(x,y);

    // Se a reta tem 90º
    if(dx == 0 && dy > 0) {
        std::cout << "90 graus" << std::endl;
        while(y < y2) {
            y = y + 1;
            painter->drawPoint(x,y);
        }
    }
    // Se a reta tem 0º
    else if(dy == 0 && dx > 0) {
        std::cout << "0 graus" << std::endl;
        while(x < x2) {
            x = x + 1;
            painter->drawPoint(x,y);
        }
    }
    // Se a reta tem 45º
    else if(dx != 0 && ((float)dy/(float)dx) == 1) {
        std::cout << "45 graus" << std::endl;
        while(x < x2) {
            x = x + 1;
            y = y + 1;
            painter->drawPoint(x,y);
        }
    }
    else {
        // Se o valor absoluto de dy/dx < 1
        if(abs((float)dy/(float)dx) < 1) {
            d = 2 * dy - dx; // dStart
            incE = 2 * dy;
            incNE = 2 * (dy - dx);

            std::cout << "Inclinacao menor que 1" << std::endl;
            while(x < x2) {
                x = x + 1;
                if(d <= 0) {
                    // Escolha E
                    d = d + incE;
                }
                else {
                    // Escolha NE
                    d = d + incNE;
                    y = y + 1;
                }
                // Desenha o pixel aqui com a função do QT de pintar
                painter->drawPoint(x,y);
            }
        }
        else {
            d = 2 * dx - dy; // dStart
            incE = 2 * dx;
            incNE = 2 * (dx - dy);

            std::cout << "Inclinação maior que 1" << std::endl;
            while(y < y2) {
                y = y + 1;
                if(d <= 0) {
                    // Escolha E
                    d = d + incE;
                }
                else {
                    d = d + incNE;
                    x = x + 1;
                }
                // Desenha o pixel aqui com a função do QT de pintar
                painter->drawPoint(x,y);
            }
        }


    }
}

void Canvas::pontoMedioCompleto(int x,int y,int x2, int y2) {
    auto painter = std::make_unique<QPainter>(this);
    int w = x2 - x ;
    int h = y2 - y ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (w<0){
        dx1 = -1;
    }
    else if (w>0) {
        dx1 = 1 ;
    }

    if (h<0) {
        dy1 = -1 ;
    }
    else if (h>0) {
        dy1 = 1 ;
    }

    if (w<0) {
        dx2 = -1 ;
    }
    else if (w>0) {
        dx2 = 1 ;
    }

    int longest = abs(w) ;
    int shortest = abs(h) ;
    int numerator = longest >> 1 ;

    for (int i=0;i<=longest;i++) {
        painter->drawPoint(x,y);
        numerator += shortest ;
        if (!(numerator<longest)) {
            numerator -= longest ;
            x += dx1 ;
            y += dy1 ;
        } else {
            x += dx2 ;
            y += dy2 ;
        }
    }
}

void Canvas::plotLine(int x0, int y0, int x1, int y1) {
    int dx, sx, dy, sy, err, e2;
    auto painter = std::make_unique<QPainter>(this);
    dx =  abs(x1-x0);
    sx = x0<x1 ? 1 : -1;
    dy = -abs(y1-y0);
    sy = y0<y1 ? 1 : -1;
    err = dx+dy;  /* error value e_xy */

    while (true){
        /* loop */
        painter->drawPoint(x0,y0);

        if (x0==x1 && y0==y1){
            break;
        }

        e2 = 2*err;
        if (e2 >= dy) {
            /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        }
    }
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

void Canvas::plotLineTotal(int x0, int y0, int x1, int y1) {
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
