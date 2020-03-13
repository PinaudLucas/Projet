#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget();

private slots:
    void on_pushButton_Capturer_clicked();

private:
    Ui::Widget *ui;

    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

#endif // WIDGET_H
