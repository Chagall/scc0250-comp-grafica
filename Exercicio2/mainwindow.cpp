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


void MainWindow::on_DrawCircleQPushButton_clicked()
{
    int centerX = ui->CanvasWidget->size().width()/2;
    int centerY = ui->CanvasWidget->size().height()/2;
    ui->CanvasWidget->setCenter(centerX, centerY);
    ui->CanvasWidget->option = 1;
    ui->CanvasWidget->repaint();
}

void MainWindow::on_DrawCircleCP_QPushButton_clicked()
{
    int centerX = ui->CanvasWidget->size().width()/2;
    int centerY = ui->CanvasWidget->size().height()/2;
    ui->CanvasWidget->setCenter(centerX, centerY);
    ui->CanvasWidget->option = 2;
    ui->CanvasWidget->repaint();
}

void MainWindow::on_DrawCircleAP_QPushButton_clicked()
{
    int centerX = ui->CanvasWidget->size().width()/2;
    int centerY = ui->CanvasWidget->size().height()/2;
    ui->CanvasWidget->setCenter(centerX, centerY);
    ui->CanvasWidget->option = 3;
    ui->CanvasWidget->repaint();

}

