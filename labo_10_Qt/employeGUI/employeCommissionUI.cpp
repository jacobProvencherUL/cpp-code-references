#include "employeCommissionUI.h"
#include <qmessagebox.h>


AjoutCommisInterface::AjoutCommisInterface (QWidget *parent) :
QDialog (parent)
{
  ui.setupUi (this);
  ui.dateEdit->setDate (QDate::currentDate ());
  QObject::connect (ui.pushButton, SIGNAL (clicked ()), this, SLOT (valideEnregistrement ()));
}


AjoutCommisInterface::~AjoutCommisInterface () {
 }


QString AjoutCommisInterface::reqNom () const
{
  return ui.lineEdit_nom->text ();
}


QString AjoutCommisInterface::reqPrenom () const
{
  return ui.lineEdit_prenom->text ();
}


QString AjoutCommisInterface::reqSalaire () const
{
  return ui.lineEdit_salaire->text ();
}


QString AjoutCommisInterface::reqCommission () const
{
  return ui.lineEdit_commission->text ();
}


int AjoutCommisInterface::reqQuantite () const
{
  return ui.spinBox_quantite->value ();
}


int AjoutCommisInterface::reqCodeDepartement () const
{
  return ui.spinBox_codeDepartement->value ();
}


util::Date AjoutCommisInterface::reqDateNaissance () const
{
  return m_dateNaissance;
}


void AjoutCommisInterface::valideEnregistrement ()
{
  if (ui.lineEdit_nom->text ().isEmpty ())
    {
      QString message ("Le nom ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (ui.lineEdit_prenom->text ().isEmpty ())
    {
      QString message ("Le prenom ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  QDate dateCourant = QDate::currentDate ();
  if (ui.dateEdit->date () == dateCourant)
    {
      QString message ("Le date ne doit pas etre celle daujourdhui");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else
    {
      m_dateNaissance.asgDate (ui.dateEdit->date ().day (), ui.dateEdit->date ().month (), ui.dateEdit->date ().year ());
      accept ();
    }
}