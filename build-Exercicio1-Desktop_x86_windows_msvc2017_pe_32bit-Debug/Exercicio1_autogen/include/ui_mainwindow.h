/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Canvas *DrawCanvas;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSpinBox *x1SpinBox;
    QSpinBox *y1SpinBox;
    QSpinBox *x2SpinBox;
    QSpinBox *y2SpinBox;
    QPushButton *drawPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 495);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        DrawCanvas = new Canvas(centralwidget);
        DrawCanvas->setObjectName(QString::fromUtf8("DrawCanvas"));

        horizontalLayout->addWidget(DrawCanvas);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        x1SpinBox = new QSpinBox(frame);
        x1SpinBox->setObjectName(QString::fromUtf8("x1SpinBox"));
        x1SpinBox->setMaximum(9999);

        verticalLayout->addWidget(x1SpinBox);

        y1SpinBox = new QSpinBox(frame);
        y1SpinBox->setObjectName(QString::fromUtf8("y1SpinBox"));
        y1SpinBox->setMaximum(9999);

        verticalLayout->addWidget(y1SpinBox);

        x2SpinBox = new QSpinBox(frame);
        x2SpinBox->setObjectName(QString::fromUtf8("x2SpinBox"));
        x2SpinBox->setMaximum(9999);

        verticalLayout->addWidget(x2SpinBox);

        y2SpinBox = new QSpinBox(frame);
        y2SpinBox->setObjectName(QString::fromUtf8("y2SpinBox"));
        y2SpinBox->setMaximum(9999);

        verticalLayout->addWidget(y2SpinBox);

        drawPushButton = new QPushButton(frame);
        drawPushButton->setObjectName(QString::fromUtf8("drawPushButton"));

        verticalLayout->addWidget(drawPushButton);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 740, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        x1SpinBox->setToolTip(QCoreApplication::translate("MainWindow", "x1", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        x1SpinBox->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        x1SpinBox->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        x1SpinBox->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        y1SpinBox->setToolTip(QCoreApplication::translate("MainWindow", "y1", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        x2SpinBox->setToolTip(QCoreApplication::translate("MainWindow", "x2", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        y2SpinBox->setToolTip(QCoreApplication::translate("MainWindow", "y2", nullptr));
#endif // QT_CONFIG(tooltip)
        drawPushButton->setText(QCoreApplication::translate("MainWindow", "Desenhar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
