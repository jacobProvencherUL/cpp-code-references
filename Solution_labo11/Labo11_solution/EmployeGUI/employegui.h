#ifndef EMPLOYEGUI_H
#define EMPLOYEGUI_H

#include <QtGui/QMainWindow>
#include "ui_employegui.h"
#include "Employe.h"
#include "Date.h"
#include <vector>
#include <string.h>

class EmployeGUI : public QMainWindow
{
    Q_OBJECT

public:
    EmployeGUI(QWidget *parent = 0);
    ~EmployeGUI();
    void ajouterCommis(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
			double p_salaire = 0.0, double p_commission = 0.0, int p_quantite = 0);
    void ajouterHoraire(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
	   	   	   double p_tauxHoraire= 0.0, double p_heures= 0.0);
    void ajouterPatron(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
			 double p_salaireHebdo = 0.0);
    void supprimerEmploye(const std::string& p_nom, const std::string& p_prenom);

public slots:
	void dialogAjoutCommis();
	void dialogAjoutHoraire();
	void dialogAjoutPatron();
	void dialogSupprimerCommis();
	void dialogSupprimerHoraire();
	void dialogSupprimerPatron();
	void dialogEnregistrerInfor();
	void dialogChargerFichier();
	void selectionLigneTable();

private:
    Ui::EmployeGUIClass ui;
    std::vector<labo10::Employe*> m_vEmploye;
    bool verifiePresentEmploye(labo10::Employe& p_employe);
    bool verifiePresenceEmploye(const std::string& p_nom, const std::string& p_prenom);
    void sauvegarderEmploye(const std::string& p_nomDuFichier);
    void chargerEmploye(const std::string& p_nomDuFichier);
    void afficherListeEmploye();
};

#endif // EMPLOYEGUI_H
