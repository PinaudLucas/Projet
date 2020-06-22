#ifndef GESTIONNAIRECASIER_H
#define GESTIONNAIRECASIER_H

#include <QWidget>
#include "lecteurdecarte.h"
#include "accesbdd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GestionnaireCasier; }
QT_END_NAMESPACE

class GestionnaireCasier : public QWidget
{
    Q_OBJECT

public:
    GestionnaireCasier(QWidget *parent = nullptr);
    ~GestionnaireCasier();

private slots:
    void onLecteurdeCarteNouveaucode(QString code);

private:
    Ui::GestionnaireCasier *ui;
    LecteurDeCarte *leLecteur;
    Accesbdd laBdd;
};
#endif // GESTIONNAIRECASIER_H
