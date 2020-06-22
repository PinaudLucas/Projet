#include "gestionnairecasier.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireCasier w;
    w.show();
    return a.exec();
}
