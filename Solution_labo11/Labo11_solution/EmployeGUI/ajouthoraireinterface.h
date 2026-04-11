#ifndef AJOUTHORAIREINTERFACE_H
#define AJOUTHORAIREINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajouthoraireinterface.h"
#include "Date.h"

class AjoutHoraireInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutHoraireInterface(QWidget *parent = 0);
    ~AjoutHoraireInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqtauxHoraire() const;
    int reqNombreHeures() const;
    int reqDepartement() const;

private slots:
  	void validerEnregistrement();

private:
    Ui::AjoutHoraireInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // AJOUTHORAIREINTERFACE_H
