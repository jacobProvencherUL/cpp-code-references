#ifndef EMPLOYECOMMISSION_H
#define EMPLOYECOMMISSION_H

#include <QDialog>
#include "Date.h"
#include "ui_employeCommissionUI.h"

class AjoutCommisInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutCommisInterface(QWidget *parent = 0);
    ~AjoutCommisInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    QString reqSalaire() const;
    QString reqCommission() const;
    int reqQuantite() const;
    int reqCodeDepartement() const;
    util::Date reqDateNaissance() const;

public slots:
	void valideEnregistrement();

private:
    Ui::AjoutCommisInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // EMPLOYECOMMISSION_H