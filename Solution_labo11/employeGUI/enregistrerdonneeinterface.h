#ifndef ENREGISTRERDONNEEINTERFACE_H
#define ENREGISTRERDONNEEINTERFACE_H

#include <QDialog>
#include "ui_enregistrerdonneeinterface.h"

class EnregistrerDonneeInterface : public QDialog
{
    Q_OBJECT

public:
    EnregistrerDonneeInterface(QWidget *parent = 0);
    ~EnregistrerDonneeInterface();
    QString reqNom();

public slots:
	void valideEnregistrement();

private:
    Ui::EnregistrerDonneeInterfaceClass ui;
};

#endif // ENREGISTRERDONNEEINTERFACE_H