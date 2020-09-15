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
    if(option == 1) {
        this->midPointCircle(100);
    }
    else if(option == 2) {
        this->polarCoordCircle(100);
    }
    else if(option == 3) {
        this->polygonAproxCircle(100);
    }
}

void Canvas::setCenter(int xCenter, int yCenter) {
    this->xCenter = xCenter;
    this->yCenter = yCenter;

    std::cout << "Centro x " << this->xCenter << std::endl;
    std::cout << "Centro y " << this->yCenter << std::endl;
}

void Canvas::circlePoints(int x, int y) {
    auto painter = std::make_unique<QPainter>(this);

    painter->drawPoint(this->xCenter + x, this->yCenter + y);
    painter->drawPoint(this->xCenter + x, this->yCenter - y);
    painter->drawPoint(this->xCenter - x, this->yCenter + y);
    painter->drawPoint(this->xCenter - x, this->yCenter - y);
    painter->drawPoint(this->xCenter + y, this->yCenter + x);
    painter->drawPoint(this->xCenter + y, this->yCenter - x);
    painter->drawPoint(this->xCenter - y, this->yCenter + x);
    painter->drawPoint(this->xCenter - y, this->yCenter - x);
}

void Canvas::midPointCircle(int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;
    int deltaE = 3;
    int deltaSE = -(2 * r) + 5;

    this->circlePoints(x, y);

    while(y > x) {
        // Selecione E
        if(d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        }
        // Seleciona SE
        else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }

        x++;
        this->circlePoints(x, y);
    }
}

void Canvas::polarCoordCircle(int r) {
    auto painter = std::make_unique<QPainter>(this);

    int i = 0;
    int x = 0 ;
    int y = 0;

    /*
     * Como circle points fica encarregado de desenhar os
     * pontos nos outros 7 quadrantes, só precisamos
     * fazer o cálculo no primeiro quadrante, ou seja
     * de 0 a 45º (convertidos em radianos)
    * */

    for (i = 0; i <= 45; i++) {

        x = r * cos(i*(M_PI/180));
        y = r * sin(i*(M_PI/180));
        this->circlePoints(x, y);
    }
}

void Canvas::polygonAproxCircle(int r) {
    auto painter = std::make_unique<QPainter>(this);
    auto points = std::vector<std::shared_ptr<QPoint>>();
    points.clear();

    float stepSize = (2.f*M_PI/(float)this->numOfPoints);

    for (float t = 0.f; t < 2.f*M_PI; t+=stepSize)
    {
        int x = this->xCenter + r*cos(t);
        int y = this->yCenter + r*sin(t);
        points.push_back(std::make_shared<QPoint>(x,y));
    }

    std::cout << "qtd pontos " << points.size() << std::endl;

    for(auto point = points.begin(); point != points.end()-1; ++point)
    {
        //draw a line
        painter->drawLine(**point, **(point+1));
    }

    painter->drawLine(**points.begin(), **points.rbegin());

}
