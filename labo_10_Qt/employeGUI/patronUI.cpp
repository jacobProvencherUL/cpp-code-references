#include "patronUI.h"
#include <qmessagebox.h>

AjoutPatronInterface::AjoutPatronInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(valideEnregistrement()));
}

AjoutPatronInterface::~AjoutPatronInterface()
{

}

QString AjoutPatronInterface::reqNom() const{
	return ui.lineEdit_nom->text();
}
QString AjoutPatronInterface::reqPrenom() const{
	return ui.lineEdit_prenom->text();
}
QString AjoutPatronInterface::reqSalaire() const{
	return ui.lineEdit_salaire->text();
}
int AjoutPatronInterface::reqCodeDepartement() const{
	return ui.spinBox_codeDepartement->value();
}
util::Date AjoutPatronInterface::reqDateNaissance () const{
	return m_dateNaissance;
}

void AjoutPatronInterface::valideEnregistrement(){
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