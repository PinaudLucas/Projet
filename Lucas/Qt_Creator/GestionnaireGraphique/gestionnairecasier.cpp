#include "gestionnairecasier.h"
#include "ui_gestionnairecasier.h"

GestionnaireCasier::GestionnaireCasier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionnaireCasier)
{
    ui->setupUi(this);
    leLecteur = new LecteurDeCarte(PORT);

    connect(leLecteur, &LecteurDeCarte::nouveaucode, this, &GestionnaireCasier::onLecteurdeCarteNouveaucode);
}

GestionnaireCasier::~GestionnaireCasier()
{
    delete ui;
    delete leLecteur;
}

void GestionnaireCasier::onLecteurdeCarteNouveaucode(QString code)
{
    QString nom;
    QString prenom;
    QString classe;
    QString statut;

    laBdd.RecupererInfoEleve(nom, prenom, classe, statut, code);
}
