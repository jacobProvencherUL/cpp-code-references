#include "chargerdonneeinterface.h"
#include <qmessagebox.h>
#include <QFileDialog>

ChargerDonneeInterface::ChargerDonneeInterface(QWidget *parent) :
		QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_saveDonnee, SIGNAL(clicked()), this,
			SLOT(valideEnregistrement()));
}

ChargerDonneeInterface::~ChargerDonneeInterface()
{

}

QString ChargerDonneeInterface::reqNom()
{
//	QString nomFichier = QFileDialog::getOpenFileName(this,
//			"Charger le fichier", QString(), "Texte(*txt)");
//		return nomFichier;
	return ui.lineEdit_nom->text();
}

void ChargerDonneeInterface::valideEnregistrement()
{

	if (ui.lineEdit_nom->text().isEmpty())
	{
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	else
	{
		accept();
	}
}
