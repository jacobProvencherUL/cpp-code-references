#include "supprimercommisinterface.h"
#include <qmessagebox.h>

SupprimerCommisInterface::SupprimerCommisInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(valideSuppression()));
}

SupprimerCommisInterface::~SupprimerCommisInterface()
{

}

QString SupprimerCommisInterface::reqNom() const{
	return ui.lineEdit_nom->text();
}

QString SupprimerCommisInterface::reqPrenom() const{
   	return ui.lineEdit_prenom->text();
}

void SupprimerCommisInterface::valideSuppression(){
	if (ui.lineEdit_nom->text().isEmpty() && ui.lineEdit_prenom->text().isEmpty()){
		QString message("Veuillez saisir soit le nom ou le prenom ou encore les deux");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} else {
		accept();
	}
}