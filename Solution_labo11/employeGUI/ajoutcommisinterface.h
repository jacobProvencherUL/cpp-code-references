#ifndef AJOUTCOMMISINTERFACE_H
#define AJOUTCOMMISINTERFACE_H

#include <QDialog>
#include "ui_ajoutcommisinterface.h"
#include "Date.h"

class AjoutCommisInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutCommisInterface(QWidget *parent = 0);
    ~AjoutCommisInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqSalaire() const;
    QString reqCommission() const;
    int reqQuantite() const;
    int reqCodeDepartement() const;

private slots:
	void valideEnregistrement();

private:
    Ui::AjoutCommisInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // AJOUTCOMMISINTERFACE_H