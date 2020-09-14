#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_drawPushButton_clicked()
{
    int x1 = ui->x1SpinBox->value();
    int y1 = ui->y1SpinBox->value();
    int x2 = ui->x2SpinBox->value();
    int y2 = ui->y2SpinBox->value();

    int centerX = ui->DrawCanvas->size().width()/2;
    int centerY = ui->DrawCanvas->size().height()/2;

    ui->DrawCanvas->setCenter(centerX, centerY);
    ui->DrawCanvas->setLinePoints(x1, y1, x2, y2);
    ui->DrawCanvas->repaint();
}
