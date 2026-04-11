#ifndef AJOUTPATRONINTERFACE_H
#define AJOUTPATRONINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutpatroninterface.h"
#include "Date.h"

class AjoutPatronInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutPatronInterface(QWidget *parent = 0);
    ~AjoutPatronInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqSalaireHebdo() const;
    int reqDepartement() const;

private slots:
    void validerEnregistrement();

private:
    Ui::AjoutPatronInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // AJOUTPATRONINTERFACE_H
