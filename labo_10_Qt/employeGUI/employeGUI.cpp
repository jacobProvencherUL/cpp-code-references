/*
 * File:   employeGUI.cpp
 * Author: etudiant
 *
 */


#include <iostream>
#include "Patron.h"
#include "Employe.h"
#include "EmployeHoraire.h"
#include "EmployeCommission.h"

#include "employeGUI.h"
#include "employeHoraireUI.h"
#include "patronUI.h"


#include "employeCommissionUI.h"
#include "Date.h"
#include <QMessageBox>
#include <QTableWidget>

using namespace labo9;
using namespace std;


employeGUI::employeGUI (QWidget *parent)
: QMainWindow (parent)
{
  ui.setupUi (this);
  ui.tableWidget->setColumnWidth (0, 200);
  ui.tableWidget->setColumnWidth (1, 209);
  ui.tableWidget->setColumnWidth (2, 200);
  QObject::connect (ui.actionCommission, SIGNAL (triggered ()), this, SLOT (dialogAjoutCommis ()));
  QObject::connect (ui.actionHoraire, SIGNAL (triggered ()), this, SLOT (dialogAjoutHoraire ()));
  QObject::connect (ui.actionPatron, SIGNAL (triggered ()), this, SLOT (dialogAjoutPatron ()));
}


employeGUI::~employeGUI () {
 }


void employeGUI::dialogAjoutCommis ()
{
  AjoutCommisInterface saisieCommis (this);
  if (saisieCommis.exec ())
    {
      ajoutCommis (saisieCommis.reqNom ().toStdString (), saisieCommis.reqPrenom ().toStdString (),
                   saisieCommis.reqDateNaissance (), saisieCommis.reqCodeDepartement (),
                   saisieCommis.reqSalaire ().toDouble (), saisieCommis.reqCommission ().toDouble (),
                   saisieCommis.reqQuantite ());
      int nombreDeLigne = ui.tableWidget->rowCount ();
      QString date = QString::fromStdString (saisieCommis.reqDateNaissance ().reqDateFormatee ());
      ui.tableWidget->setRowCount (nombreDeLigne + 1);
      ui.tableWidget->setItem (nombreDeLigne, 0, new QTableWidgetItem (saisieCommis.reqNom ()));
      ui.tableWidget->setItem (nombreDeLigne, 1, new QTableWidgetItem (saisieCommis.reqPrenom ()));
      ui.tableWidget->setItem (nombreDeLigne, 2, new QTableWidgetItem (date));
    }
}


void employeGUI::dialogAjoutHoraire ()
{
  AjoutHoraireInterface saisieHoraire (this);
  if (saisieHoraire.exec ())
    {
      ajoutHoraire (saisieHoraire.reqNom ().toStdString (), saisieHoraire.reqPrenom ().toStdString (),
                    saisieHoraire.reqDateNaissance (), saisieHoraire.reqCodeDepartement (),
                    saisieHoraire.reqTauxHoraire ().toDouble (), (double) saisieHoraire.reqNombreHeures ());
      int nombreDeLigne = ui.tableWidget->rowCount ();
      QString date = QString::fromStdString (saisieHoraire.reqDateNaissance ().reqDateFormatee ());
      ui.tableWidget->setRowCount (nombreDeLigne + 1);
      ui.tableWidget->setItem (nombreDeLigne, 0, new QTableWidgetItem (saisieHoraire.reqNom ()));
      ui.tableWidget->setItem (nombreDeLigne, 1, new QTableWidgetItem (saisieHoraire.reqPrenom ()));
      ui.tableWidget->setItem (nombreDeLigne, 2, new QTableWidgetItem (date));
    }
}


void employeGUI::dialogAjoutPatron ()
{
  AjoutPatronInterface saisiePatron;
  if (saisiePatron.exec ())
    {
      ajoutPatron (saisiePatron.reqNom ().toStdString (), saisiePatron.reqPrenom ().toStdString (),
                   saisiePatron.reqDateNaissance (), saisiePatron.reqCodeDepartement (),
                   saisiePatron.reqSalaire ().toDouble ());
      int nombreDeLigne = ui.tableWidget->rowCount ();
      QString date = QString::fromStdString (saisiePatron.reqDateNaissance ().reqDateFormatee ());
      ui.tableWidget->setRowCount (nombreDeLigne + 1);
      ui.tableWidget->setItem (nombreDeLigne, 0, new QTableWidgetItem (saisiePatron.reqNom ()));
      ui.tableWidget->setItem (nombreDeLigne, 1, new QTableWidgetItem (saisiePatron.reqPrenom ()));
      ui.tableWidget->setItem (nombreDeLigne, 2, new QTableWidgetItem (date));
    }
}


void employeGUI::ajoutCommis (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                              int p_codeDepartement, double p_salaire, double p_commission, int p_quantite)
{
  EmployeCommission employeCommission (p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_salaire,  p_commission, p_quantite);
  m_vEmployes.push_back (make_unique <EmployeCommission> (employeCommission));
}


void employeGUI::ajoutHoraire (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                               int p_codeDepartement, double p_tauxHoraire, double p_heures)
{
  //  EmployeHoraire unEmployeHoraire ( "Price", "Karen", util::Date (17, 03, 1973), 1, 13.75, 40);
  //  m_vEmployes.push_back (make_unique <EmployeHoraire> (unEmployeHoraire));

  EmployeHoraire employeHoraire (p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_tauxHoraire, p_heures);
  m_vEmployes.push_back (make_unique <EmployeHoraire> (employeHoraire));
}


void employeGUI::ajoutPatron (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                              int p_codeDepartement, double p_salaireHebdo)
{
  Patron patron (p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_salaireHebdo);
  m_vEmployes.push_back (make_unique <Patron> (patron));
}