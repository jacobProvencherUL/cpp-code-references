#ifndef SUPPRIMERCOMMISINTERFACE_H
#define SUPPRIMERCOMMISINTERFACE_H

#include <QDialog>
#include "ui_supprimercommisinterface.h"

class SupprimerCommisInterface : public QDialog
{
    Q_OBJECT

public:
    SupprimerCommisInterface(QWidget *parent = 0);
    ~SupprimerCommisInterface();
    QString reqNom() const;
    QString reqPrenom() const;

private slots:
	void valideSuppression();

private:
    Ui::SupprimerCommisInterfaceClass ui;
};

#endif // SUPPRIMERCOMMISINTERFACE_H