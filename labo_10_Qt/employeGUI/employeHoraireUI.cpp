#include "employeHoraireUI.h"
#include <qmessagebox.h>

AjoutHoraireInterface::AjoutHoraireInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(valideEnregistrement()));
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
QString AjoutHoraireInterface::reqTauxHoraire() const{
	return ui.lineEdit_tauxHoraire->text();
}
int AjoutHoraireInterface::reqNombreHeures() const{
	return ui.spinBox_nbHeures->value();
}
int AjoutHoraireInterface::reqCodeDepartement() const{
	return ui.spinBox_codeDepartement->value();
}
util::Date AjoutHoraireInterface::reqDateNaissance () const{
	return m_dateNaissance;
}

void AjoutHoraireInterface::valideEnregistrement(){
	if (ui.lineEdit_nom->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEdit_prenom->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	QDate dateCourant = QDate::currentDate();
	if (ui.dateEdit->date() == dateCourant){
		QString message("Le date ne doit pas etre celle daujourdhui");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}else {
		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(), ui.dateEdit->date().year());
		accept();
	}
}