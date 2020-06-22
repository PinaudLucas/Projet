#include "accesbdd.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QFileInfo>

QString getLastExecutedQuery(const QSqlQuery& query)
{
    QString str = query.lastQuery();
    QMapIterator<QString, QVariant> it(query.boundValues());
    while (it.hasNext())
    {
        it.next();
        str.replace(it.key(),it.value().toString());
    }
    return str;
}

Accesbdd::Accesbdd()
{
    bddMdl = QSqlDatabase::addDatabase(("QMYSQL"));
    bddMdl.setHostName(ADDRESSE);
    bddMdl.setUserName(NOM);
    bddMdl.setPassword(MDP);
    bddMdl.setDatabaseName(NOMBASE);

    if(bddMdl.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " << bddMdl.hostName();
    }
    else
    {
        qDebug() << "La connexion a échouée, désolé" << bddMdl.lastError();
    }
}

Accesbdd::~Accesbdd()
{
    bddMdl.close();
}

bool Accesbdd::RecupererInfoEleve(QString &nom, QString &prenom, QString &classe, QString &statut, QString _code)
{
    bool retour = false;
    if(bddMdl.isOpen())
    {
        QSqlQuery requete(bddMdl.database());

        requete.prepare("SELECT nom, prenom, classe, statusMDL FROM utilisateurs WHERE codeCarte = :id; ");
        requete.bindValue(":id", _code);
        if(!requete.exec())
        {
            qDebug() << "Problème dans la requette RecupererInfoEleve" ;
            qDebug() << getLastExecutedQuery(requete);
            qDebug() << bddMdl.lastError();
        }
        while(requete.next()){
            nom = requete.value("nom").toString();
            prenom = requete.value("prenom").toString();
            classe = requete.value("classe").toString();
            statut = requete.value("statusMDL").toString();
            if(statut == "adherent")
            {
                qDebug() << "nom :" << nom;
                qDebug() << "prenom :" << prenom;
                qDebug() << "classe :" << classe;
                retour = true;
            }
            else
            {
                qDebug() << "Veuillez vous inscrire à la MDl";
            }
        }
    }
    else
    {
        qDebug() << "La base de données n'est pas ouverte ";
    }
    return retour;
}

