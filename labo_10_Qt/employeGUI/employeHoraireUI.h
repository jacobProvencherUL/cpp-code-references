#ifndef EMPLOYEHORRAIREUI_H
#define EMPLOYEHORRAIREUI_H

#include <QDialog>
#include "ui_employeHorraireUI.h"
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
    QString reqTauxHoraire() const;
    int reqCodeDepartement() const;
    int reqNombreHeures() const;

public slots:
	void valideEnregistrement();

private:
    Ui::AjoutHoraireInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // EMPLOYEHORRAIREUI_H