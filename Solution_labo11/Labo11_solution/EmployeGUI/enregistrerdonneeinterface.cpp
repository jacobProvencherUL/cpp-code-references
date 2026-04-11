#include "enregistrerdonneeinterface.h"
#include <qmessagebox.h>

EnregistrerDonneeInterface::EnregistrerDonneeInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_saveDonnee, SIGNAL(clicked()), this, SLOT(valideEnregistrement()));
}

EnregistrerDonneeInterface::~EnregistrerDonneeInterface()
{

}

QString EnregistrerDonneeInterface::reqNom(){
	return ui.lineEdit_nom->text();
}

void EnregistrerDonneeInterface::valideEnregistrement(){
   	if (ui.lineEdit_nom->text().isEmpty()){
   		QString message("Le nom ne doit pas etre vide");
   		QMessageBox::information(this, "ERREUR", message);
   		return;
   	} else{
   		accept();
   	}
}
