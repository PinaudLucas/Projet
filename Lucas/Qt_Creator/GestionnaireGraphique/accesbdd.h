#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDateTime>
#include <QtSql>

#define ADDRESSE "192.168.0.22"
#define NOM "root"
#define MDP "toto"
#define NOMBASE "gestionlecteur de carte"

class Accesbdd
{

public:
    Accesbdd();
    ~Accesbdd();
    bool RecupererInfoEleve(QString &nom, QString &prenom, QString &classe, QString &statut, QString _code);

private:
    QSqlDatabase bddMdl;

};
#endif // ACCESBDD_H
