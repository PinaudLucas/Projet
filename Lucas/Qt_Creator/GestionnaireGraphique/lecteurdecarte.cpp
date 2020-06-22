#include "lecteurdecarte.h"

LecteurDeCarte::LecteurDeCarte(QString _nomPort)
{  
    port = new QSerialPort(_nomPort);
    if(!port->open(QIODevice::ReadWrite)){
        qDebug() << "pb ouverture port serie ;" << port->errorString();
        delete port;
    }
    else
    {
        connect(port, &QSerialPort::readyRead, this, &LecteurDeCarte::onQSerialPort_ReadyRead);
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

void LecteurDeCarte::onQSerialPort_ReadyRead()
{
    if(port->bytesAvailable() == 8){
        commande = port->readAll();
        commande = commande.mid(0,6);
        qDebug() << "codeCarte :" << commande;
        emit nouveaucode(commande);
    }
    else
    {
        commande = port->readAll();
        qDebug() << "Veuillez scannez votre carte de self s'il vous plaît!";

    }
}

QString LecteurDeCarte::getCommande() const
{
    return commande;
}
