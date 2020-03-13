#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_pushButtonSerie_clicked();

    void on_comboBoxPort_currentIndexChanged(int index);

    void onQSerialPort_ReadyRead();

private:
    Ui::Widget *ui;
    QSerialPort *port;
};

#endif // WIDGET_H
