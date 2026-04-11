#ifndef CHARGERDONNEEINTERFACE_H
#define CHARGERDONNEEINTERFACE_H

#include <QDialog>
#include "ui_chargerdonneeinterface.h"

class ChargerDonneeInterface : public QDialog
{
    Q_OBJECT

public:
    ChargerDonneeInterface(QWidget *parent = 0);
    ~ChargerDonneeInterface();
    QString reqNom();

public slots:
	void valideEnregistrement();

private:
    Ui::ChargerDonneeInterfaceClass ui;
};

#endif // CHARGERDONNEEINTERFACE_H