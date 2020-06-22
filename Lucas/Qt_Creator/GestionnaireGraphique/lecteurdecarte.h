#ifndef LECTEURDECARTE_H
#define LECTEURDECARTE_H

#include <QObject>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>

#define PORT "COM4"

class LecteurDeCarte : public QObject
{
    Q_OBJECT

public:
    LecteurDeCarte(QString _nomPort = PORT);
    QString getCommande() const;

private slots:
    void onQSerialPort_ReadyRead();

signals:
    void nouveaucode(QString code);

private:
    QSerialPort *port;
    QString commande;

};

#endif // LECTEURDECARTE_H
