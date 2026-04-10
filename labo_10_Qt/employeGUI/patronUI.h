#ifndef PATRONUI_H
#define PATRONUI_H

#include <QDialog>
#include "ui_patronUI.h"
#include "Date.h"

class AjoutPatronInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutPatronInterface(QWidget *parent = 0);
    ~AjoutPatronInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    QString reqSalaire() const;
    int reqCodeDepartement() const;
    util::Date reqDateNaissance() const;

public slots:
	void valideEnregistrement();

private:
    Ui::AjoutPatronInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // PATRONUI_H