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
    long executionTime = 0;

    if(option == 1) {
        for(int i = 0; i < this->numOfExecutions; i++) {
            auto start = high_resolution_clock::now();

            this->midPointCircle(this->radius);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(stop - start);

            std::cout << "It[" << i+1 << "]: " << duration.count() << "ms" << std::endl;

            executionTime += duration.count();
        }

        executionTime = executionTime / this->numOfExecutions;

        std::cout << "Tempo medio: " << double(executionTime)/1000 << " segundos" << std::endl;
    }
    else if(option == 2) {
        for(int i = 0; i < this->numOfExecutions; i++) {
            auto start = high_resolution_clock::now();

            this->polarCoordCircle(this->radius);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            std::cout << "It[" << i+1 << "]: " << duration.count() << " microsegundos" << std::endl;

            executionTime += duration.count();
        }

        executionTime = executionTime / this->numOfExecutions;

        std::cout << "Tempo medio: " << double(executionTime)/1000000 << " segundos" << std::endl;
    }
    else if(option == 3) {
        for(int i = 0; i < this->numOfExecutions; i++) {
            auto start = high_resolution_clock::now();

            this->polygonAproxCircle(this->radius);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            std::cout << "It[" << i+1 << "]: " << duration.count() << " microsegundos" << std::endl;

            executionTime += duration.count();
        }

        executionTime = executionTime / this->numOfExecutions;

        std::cout << "Tempo medio: " << double(executionTime)/1000000 << " segundos" << std::endl;
    }

    executionTime = 0;
    this->option = 0;
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

void Canvas::midPointCircle(int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -(2 * radius) + 5;

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

void Canvas::polarCoordCircle(int radius) {
    auto painter = std::make_unique<QPainter>(this);

    int x = 0, y = 0;

    /*
     * Como circle points fica encarregado de desenhar os
     * pontos nos outros 7 quadrantes, só precisamos
     * fazer o cálculo no primeiro quadrante, ou seja
     * de 0 a 45º (convertidos em radianos)
    * */

    /*
     * Precisamos decidir também qual será o tamanho
     * do passo do loop até chegar aos 45º
     * Escolhemos 0.5
     * */

    for (double i = 0; i <= 45; i+= 0.5) {
        // Conversão de radiano para graus
        double degree = i * (M_PI/double(180));
        x = radius * cos(degree);
        y = radius * sin(degree);
        this->circlePoints(x, y);
    }
}

void Canvas::polygonAproxCircle(int radius) {
    auto painter = std::make_unique<QPainter>(this);
    int x = 0, y = 0;

    // Vetor de pontos usados para desenhar as retas
    auto points = std::vector<std::shared_ptr<QPoint>>();

    // Iniciamos limpando o vetor de pontos
    points.clear();

    double twoPi = 2 * M_PI; // 2 PI

    /*
     * O tamanho do passo que vamos dar no loop
     * é o comprimento da circunferência
     * dividido pela qtd. de pontos
    */
    double stepSize = twoPi/double(this->numOfPoints);

    for (double t = 0.f; t < twoPi; t += stepSize) {
        // Adicionamos xCenter e yCenter para
        // desenhar no centro do Canvas
        x = this->xCenter + radius * cos(t);
        y = this->yCenter + radius * sin(t);
        points.push_back(std::make_shared<QPoint>(x,y));
    }
    for(auto point = points.begin(); point != points.end()-1; ++point) {
        painter->drawLine(**point, **(point+1));
    }

    painter->drawLine(**points.begin(), **points.rbegin());
}
