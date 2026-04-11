#include "ajoutpatroninterface.h"
#include <qmessagebox.h>

AjoutPatronInterface::AjoutPatronInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton_validePatron, SIGNAL(clicked()), this, SLOT(validerEnregistrement()));
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

util::Date AjoutPatronInterface::reqDateNaissance() const{
	return m_dateNaissance;
}

QString AjoutPatronInterface::reqSalaireHebdo() const{
	return ui.lineEdit_salaireHebdo->text();
}

int AjoutPatronInterface::reqDepartement() const{
	return ui.spinBox_departement->value();
}

void AjoutPatronInterface::validerEnregistrement(){
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
   	if(ui.lineEdit_salaireHebdo->text().isEmpty()){
   		QString message("Le salaire ne doit pas etre vide");
   		QMessageBox::information(this, "ERREUR", message);
   		return;
   	} else{
   		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
   		ui.dateEdit->date().year());
   		accept();
   	}
}
