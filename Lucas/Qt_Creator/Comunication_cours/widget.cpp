#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBoxPort->addItem("Choissisez un port");
    foreach( QSerialPortInfo info, QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPort->addItem(info.portName());
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSerie_clicked()
{
    port= new QSerialPort(ui->comboBoxPort->currentText());
    qDebug() << ui->comboBoxPort->currentText();
    if(!port->open(QIODevice::ReadWrite)){
        qDebug() << "pb ouverture port serie ;" << port->errorString();
        delete port;
    }else{
        connect(port, &QSerialPort::readyRead,this,&Widget::onQSerialPort_ReadyRead);
    }
    // Vitesse de communication
    port->setBaudRate(QSerialPort::Baud9600);
    // Nombre de bits de données
    port->setDataBits(QSerialPort::Data8);
    //parité
    port->setParity(QSerialPort::EvenParity);
    // Valeur possible de bit de stop
    port->setStopBits(QSerialPort::OneStop);
    //controle de flux
    port->setFlowControl(QSerialPort::NoFlowControl);
}

void Widget::on_comboBoxPort_currentIndexChanged(int index)
{
    if (index == 0){
        qDebug() << " CHOISIE UN BON PORT !!!!!";
        ui->pushButtonSerie->setEnabled(false);
        
    }else{
        ui->pushButtonSerie->setEnabled(true);
    }
}
void Widget::onQSerialPort_ReadyRead()
{
    QString commande;
    if(port->bytesAvailable() > 0){
        commande = port->readAll();
        ui->textBrowser->append(commande);
    }
}
