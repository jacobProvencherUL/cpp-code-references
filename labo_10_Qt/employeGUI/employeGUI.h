/*
 * File:   employeGUI.h
 * Author: etudiant
 *
 */

#ifndef _EMPLOYEGUI_H
#define _EMPLOYEGUI_H

#include <vector>
#include <memory>
#include "Employe.h"
#include "ui_employeGUI.h"
#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>

class employeGUI : public QMainWindow
{
  Q_OBJECT
public:
  employeGUI (QWidget *parent = 0);
  ~employeGUI ();
  void ajoutCommis (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                    int p_codeDepartement = 1, double p_salaire = 0.0, double p_commission = 0.0, int p_quantite = 0);
  void ajoutHoraire (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                     int p_codeDepartement = 1, double p_tauxHoraire = 0.0, double p_heures = 0.0);
  void ajoutPatron (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                    int p_codeDepartement = 1, double p_salaireHebdo = 0.0);
public slots:
  void dialogAjoutCommis ();
  void dialogAjoutHoraire ();
  void dialogAjoutPatron ();

private:
  Ui::EmployeGUIClass ui;
  std::vector<std::unique_ptr<labo9::Employe>> m_vEmployes;
};

#endif /* _EMPLOYEGUI_H */
