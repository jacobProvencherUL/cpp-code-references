#include "ajouthoraireinterface.h"
#include <qmessagebox.h>

AjoutHoraireInterface::AjoutHoraireInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton_valideHoraire, SIGNAL(clicked()), this, SLOT(validerEnregistrement()));
}

AjoutHoraireInterface::~AjoutHoraireInterface()
{

}

QString AjoutHoraireInterface::reqNom() const{
	return ui.lineEdit_nom->text();
}

QString AjoutHoraireInterface::reqPrenom() const{
	return ui.lineEdit_prenom->text();
}

util::Date AjoutHoraireInterface::reqDateNaissance() const{
	return m_dateNaissance;
}

QString AjoutHoraireInterface::reqtauxHoraire() const{
	return ui.lineEdit_tauxHoraire->text();
}

int AjoutHoraireInterface::reqNombreHeures() const{
	return ui.spinBox_nombreHeure->value();
}

int AjoutHoraireInterface::reqDepartement() const{
	return ui.spinBox_departement->value();
}

void AjoutHoraireInterface::validerEnregistrement(){
	if (ui.lineEdit_nom->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_prenom->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	QDate qDate = QDate::currentDate();
	if(ui.dateEdit->date() >= qDate){
		QString message("La date de naissance n'est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_tauxHoraire->text().isEmpty()){
		QString message("Le salaire ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} else{
		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
		ui.dateEdit->date().year());
		accept();
	}
}