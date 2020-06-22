#include "widget.h"
#include "ui_widget.h"
#include <QCameraInfo>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    camera = new QCamera(cameras.at(0));
    qDebug() << cameras.at(0);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture = new QCameraImageCapture(camera);
    camera->start();
}

Widget::~Widget()
{
    delete camera;
    delete imageCapture;
    delete ui;
}
void Widget::on_pushButton_Capturer_clicked()
{
    imageCapture->capture("C:/Users/Lucas/Pictures/PhotoCameraQt/capture.jpg");
}
