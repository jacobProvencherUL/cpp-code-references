#include "employegui.h"
#include "EmployeException.h"
#include "EmployeCommission.h"
#include "EmployeHoraire.h"
#include "Patron.h"
#include "ajoutcommisinterface.h"
#include "ajouthoraireinterface.h"
#include "ajoutpatroninterface.h"
#include "enregistrerdonneeinterface.h"
#include "chargerdonneeinterface.h"
#include "supprimercommisinterface.h"
#include <QMessageBox>
#include <qfile.h>
#include <qtextstream.h>
#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace labo10;

EmployeGUI::EmployeGUI(QWidget *parent) :
		QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnWidth(0, 180);
	ui.tableWidget->setColumnWidth(1, 209);
	ui.tableWidget->setColumnWidth(2, 170);
//	nomDeMonApplication = "Gestion Employe GIF-1003";
	QObject::connect(ui.actionCommis, SIGNAL(triggered()), this,
			SLOT(dialogAjoutCommis()));
	QObject::connect(ui.actionHoraire, SIGNAL(triggered()), this,
			SLOT(dialogAjoutHoraire()));
	QObject::connect(ui.actionPatron, SIGNAL(triggered()), this,
			SLOT(dialogAjoutPatron()));
	QObject::connect(ui.actionCommis_sup, SIGNAL(triggered()), this,
			SLOT(dialogSupprimerCommis()));
	QObject::connect(ui.actionHoraire_sup, SIGNAL(triggered()), this,
			SLOT(dialogSupprimerHoraire()));
	QObject::connect(ui.actionPatron_sup, SIGNAL(triggered()), this,
			SLOT(dialogSupprimerPatron()));
	QObject::connect(ui.actionSauvegarder_dans, SIGNAL(triggered()), this,
			SLOT(dialogEnregistrerInfor()));
	QObject::connect(ui.actionCharger_a_partir_de, SIGNAL(triggered()), this,
			SLOT(dialogChargerFichier()));

}

EmployeGUI::~EmployeGUI()
{
	sauvegarderEmploye("QtDonneeEmploye.txt");
	for(size_t i = 0; i < m_vEmploye.size(); i++)
		delete m_vEmploye[i];
}

void EmployeGUI::dialogAjoutCommis()
{
	AjoutCommisInterface saisieCommis(this);
	if (saisieCommis.exec())
	{
		ajouterCommis(saisieCommis.reqNom().toStdString(),
				saisieCommis.reqPrenom().toStdString(),
				saisieCommis.reqDateNaissance(),
				saisieCommis.reqSalaire().toDouble(),
				saisieCommis.reqCommission().toDouble(),
				saisieCommis.reqQuantite(), saisieCommis.reqCodeDepartement());
	}
}

void EmployeGUI::ajouterCommis(const std::string& p_nom, const std::string& p_prenom,
		const util::Date& p_dateNaissance, int p_codeDepartement, double p_salaire, double p_commission,
		int p_quantite)
{
	try
	{
		EmployeCommission employeCommis(p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_salaire,
				p_commission, p_quantite);
		if (verifiePresentEmploye(employeCommis))
			throw EmployeDejaPresentException(
					"Impossible d’ajouter cet employe, il est deja present dans la liste");
		m_vEmploye.push_back(new EmployeCommission(employeCommis));
		int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(p_dateNaissance.reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(QString::fromStdString(p_nom)));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(QString::fromStdString(p_prenom)));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
	} catch (EmployeDejaPresentException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void EmployeGUI::dialogAjoutHoraire()
{
	AjoutHoraireInterface saisieHoraire(this);
		if (saisieHoraire.exec()){
			ajouterHoraire(saisieHoraire.reqNom().toStdString(), saisieHoraire.reqPrenom().toStdString(),
					saisieHoraire.reqDateNaissance(), saisieHoraire.reqtauxHoraire().toDouble(),
					(double)saisieHoraire.reqNombreHeures(), saisieHoraire.reqDepartement());
		}
}

void EmployeGUI::ajouterHoraire(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement,
	   	   	   double p_tauxHoraire, double p_heures){
	try{
		EmployeHoraire employeHoraire(p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_tauxHoraire,
				p_heures);
		if (verifiePresentEmploye(employeHoraire))
			throw EmployeDejaPresentException("Impossible d’ajouter cet employe, il est deja present dans la liste");
		m_vEmploye.push_back(new EmployeHoraire(employeHoraire));
		int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(p_dateNaissance.reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(QString::fromStdString(p_nom)));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(QString::fromStdString(p_prenom)));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
	} catch (EmployeDejaPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void EmployeGUI::dialogAjoutPatron()
{
	AjoutPatronInterface saisiePatron(this);
	if (saisiePatron.exec()){
		ajouterPatron(saisiePatron.reqNom().toStdString(), saisiePatron.reqPrenom().toStdString(),
				saisiePatron.reqDateNaissance(), saisiePatron.reqSalaireHebdo().toDouble(),
				saisiePatron.reqDepartement());
	}
}

void EmployeGUI::ajouterPatron(const std::string& p_nom, const std::string& p_prenom,
		const util::Date& p_dateNaissance, int p_codeDepartement, double p_salaireHebdo){
	try{
		Patron employePatron(p_nom, p_prenom, p_dateNaissance, p_codeDepartement, p_salaireHebdo);
		if (verifiePresentEmploye(employePatron))
			throw EmployeDejaPresentException("Impossible d’ajouter cet employe, il est deja present dans la liste");
		m_vEmploye.push_back(new Patron(employePatron));
		int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(p_dateNaissance.reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(QString::fromStdString(p_nom)));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(QString::fromStdString(p_prenom)));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
	} catch (EmployeDejaPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

/*
 * Attention les menus supprimer commis,horaire,patron on le même code. On est parti du principe que lorsqu'on supprime un employé
 * on ne cherche pas à savoir s'il est commis ou patron ou horaire. Aussi telle que la fonction est codée, elle supprimera tous les
 * employé dont la saisie correspond. Par exemple si vous avez deux employés du même nom et que vous avez entrés ce nom dans la
 * fenêtre de suppression alors ces deux employés seront supprimés.
 */
void EmployeGUI::dialogSupprimerCommis()
{
	SupprimerCommisInterface supprimerCommis(this);
	if (supprimerCommis.exec()){
		if (supprimerCommis.reqNom().isEmpty())
			supprimerEmploye("", supprimerCommis.reqPrenom().toStdString());
		else if (supprimerCommis.reqPrenom().isEmpty())
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), "");
		else
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), supprimerCommis.reqPrenom().toStdString());
		//afficherListeEmploye();
	}
}

void EmployeGUI::supprimerEmploye(const std::string& p_nom, const std::string& p_prenom){
	try{
		if (!verifiePresenceEmploye(p_nom, p_prenom)){
			throw EmployeNonPresentException("Impossible de supprimer un employe qui n'existe pas dans la "
				"liste");
		}
		std::vector<Employe*>::iterator it;
		if (!p_nom.empty() && p_prenom.empty()) {
			for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
				if ((*it)->reqNomFamille() == p_nom){
					delete (*it);
					it = m_vEmploye.erase(it);
				}
			}
		} else if (!p_prenom.empty() && p_nom.empty()){
			for(it = m_vEmploye.begin(); it < m_vEmploye.end(); it++){
				if ((*it)->reqPrenom() == p_prenom){
					delete (*it);
					it = m_vEmploye.erase(it);
				}
			}
		} else {
			for(it = m_vEmploye.begin(); it < m_vEmploye.end(); it++){
				if ((*it)->reqNomFamille() == p_nom && (*it)->reqPrenom() == p_prenom){
					delete (*it);
					it = m_vEmploye.erase(it);
				}
			}
		}
		afficherListeEmploye();
	} catch (EmployeNonPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void EmployeGUI::dialogSupprimerHoraire()
{
	SupprimerCommisInterface supprimerCommis(this);
	if (supprimerCommis.exec()){
		if (supprimerCommis.reqNom().isEmpty())
			supprimerEmploye("", supprimerCommis.reqPrenom().toStdString());
		else if (supprimerCommis.reqPrenom().isEmpty())
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), "");
		else
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), supprimerCommis.reqPrenom().toStdString());
		//afficherListeEmploye();
	}
}

void EmployeGUI::dialogSupprimerPatron()
{
	SupprimerCommisInterface supprimerCommis(this);
	if (supprimerCommis.exec()){
		if (supprimerCommis.reqNom().isEmpty())
			supprimerEmploye("", supprimerCommis.reqPrenom().toStdString());
		else if (supprimerCommis.reqPrenom().isEmpty())
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), "");
		else
			supprimerEmploye(supprimerCommis.reqNom().toStdString(), supprimerCommis.reqPrenom().toStdString());
		//afficherListeEmploye();
	}
}

void EmployeGUI::dialogEnregistrerInfor()
{
	EnregistrerDonneeInterface sauvegarderDonnee(this);
	if (sauvegarderDonnee.exec()){
		sauvegarderEmploye(sauvegarderDonnee.reqNom().toStdString());
	}
}

void EmployeGUI::dialogChargerFichier()
{
	ChargerDonneeInterface chargerDonnee(this);
	if (chargerDonnee.exec()){
		chargerEmploye(chargerDonnee.reqNom().toStdString());
	}
}

void EmployeGUI::selectionLigneTable(){
	int ligne = ui.tableWidget->currentRow();
	QTableWidgetItem *tNom = ui.tableWidget->item(ligne, 0);
	QTableWidgetItem *tPrenom = ui.tableWidget->item(ligne, 1);
	std::vector<Employe*>::iterator it;
	for (it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
		if ((*it)->reqNomFamille() == (*tNom).text().toStdString() && (*it)->reqPrenom() == (*tPrenom).text().toStdString())
			ui.textBrowser->setText((*it)->reqEmployeFormate().c_str());
	}
}

bool EmployeGUI::verifiePresentEmploye(labo10::Employe& p_employe){
	bool employePresent = false;
	vector<Employe *>::const_iterator it;
	for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
		if ((*it)->reqNomFamille() == p_employe.reqNomFamille()
				&& (*it)->reqPrenom() == p_employe.reqPrenom() && (*it)->reqDateNaissance() == p_employe.reqDateNaissance())
			employePresent = true;
	}
	return employePresent;
}

bool EmployeGUI::verifiePresenceEmploye(const std::string& p_nom, const std::string& p_prenom){
	bool employePresent = false;
	vector<Employe *>::const_iterator it;
	if (!p_nom.empty() && p_prenom.empty()) {
		for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
			if ((*it)->reqNomFamille() == p_nom)
				employePresent = true;
		}
	} else if (!p_prenom.empty() && p_nom.empty()){
		for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
			if ((*it)->reqPrenom() == p_prenom)
				employePresent = true;
		}
	} else {
		for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
			if ((*it)->reqNomFamille() == p_nom && (*it)->reqPrenom() == p_prenom)
				employePresent = true;
		}
	}
	return employePresent;
}

void EmployeGUI::sauvegarderEmploye(const string& p_nomDuFichier){
	try{
		// Création d'un objet QFile
		QFile file(p_nomDuFichier.c_str());
		// On ouvre notre fichier en lecture seule et on vérifie l'ouverture
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
			throw std::string("Impossible d'ouvrir le fichier");
		// Création d'un objet QTextStream à partir de notre objet QFile
		QTextStream flux(&file);
		// On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
		flux.setCodec("ISO 8859-1");
		// Écriture des différentes lignes dans le fichier
		for(size_t i = 0; i < m_vEmploye.size(); i++){
			flux << m_vEmploye[i]->reqEmployeFormate().c_str();
		}
	}catch (std::string& e){
		QString message = (e.c_str());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void EmployeGUI::chargerEmploye(const std::string& p_nomDuFichier){
	try{
		int nombreDeLigne = ui.tableWidget->rowCount();
		for (int i = nombreDeLigne; i>0; i--)
			ui.tableWidget->removeRow(i);
		nombreDeLigne = ui.tableWidget->rowCount();
		QFile file(p_nomDuFichier.c_str());
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			throw std::string("Impossible d'ouvrir le fichier");
		QTextStream contenuFichier(&file);
		bool etapeAjoutNouvelEmploye = false;
		string attributNouvelEmploye[9];
		string typeEmploye;
		//Employe * nouvelEmploye;
		int nombreValeurLu = 0;
		while (!contenuFichier.atEnd()){
			istringstream is_ligne(contenuFichier.readLine().toStdString());
			char buffer[256];
			is_ligne.getline(buffer,255);
			string ligne = buffer;
			if (etapeAjoutNouvelEmploye == false){
				if (!ligne.empty()){
					if (ligne.find("commission") != std::string::npos){
						typeEmploye = "commission";
					} else if (ligne.find("horaire") != std::string::npos){
						typeEmploye = "horaire";
					}else{
						typeEmploye = "patron";
					}
					etapeAjoutNouvelEmploye = true;
				}
			} else{
				if (ligne.empty()){
					etapeAjoutNouvelEmploye = false;
					nombreValeurLu = 0;
					if (typeEmploye == "commission")
						m_vEmploye.push_back(new EmployeCommission(attributNouvelEmploye[0], attributNouvelEmploye[1],
								util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
										atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
										atof(attributNouvelEmploye[6].c_str()), atof(attributNouvelEmploye[7].c_str()),
										atoi(attributNouvelEmploye[8].c_str())));
					else if (typeEmploye == "horaire")
						m_vEmploye.push_back(new EmployeHoraire(attributNouvelEmploye[0], attributNouvelEmploye[1],
								util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
										atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
										atof(attributNouvelEmploye[6].c_str()), atof(attributNouvelEmploye[7].c_str())));
					else
						m_vEmploye.push_back(new Patron(attributNouvelEmploye[0], attributNouvelEmploye[1],
								util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
										atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
										atof(attributNouvelEmploye[6].c_str())));
				}
				else{
					if (typeEmploye == "commission") {
						switch(nombreValeurLu){
							case 0:{
								istringstream is_ligneLu(ligne);
								is_ligneLu >> attributNouvelEmploye[1];
								is_ligneLu >> attributNouvelEmploye[0];
								nombreValeurLu++;
							}; break;
							case 1:{
								attributNouvelEmploye[2] = ligne.substr(20,2);
								attributNouvelEmploye[3] = ligne.substr(23,2);
								attributNouvelEmploye[4] = ligne.substr(26,4);
								nombreValeurLu++;
							}; break;
							case 2:{
								attributNouvelEmploye[5] = ligne.substr(22);
								nombreValeurLu++;
							}; break;
							case 3:{
								attributNouvelEmploye[6] = ligne.substr(10);
								nombreValeurLu++;
							}; break;
							case 4:{
								attributNouvelEmploye[7] = ligne.substr(13);
								nombreValeurLu++;
							}; break;
							case 5:{
								attributNouvelEmploye[8] = ligne.substr(18);
								nombreValeurLu++;
							}; break;
							default:{
							}; break;
						}
					} else if (typeEmploye == "horaire"){
						switch(nombreValeurLu){
							case 0:{
								istringstream is_ligneLu(ligne);
								is_ligneLu >> attributNouvelEmploye[1];
								is_ligneLu >> attributNouvelEmploye[0];
								nombreValeurLu++;
							}; break;
							case 1:{
								attributNouvelEmploye[2] = ligne.substr(20,2);
								attributNouvelEmploye[3] = ligne.substr(23,2);
								attributNouvelEmploye[4] = ligne.substr(26,4);
								nombreValeurLu++;
							}; break;
							case 2:{
								attributNouvelEmploye[5] = ligne.substr(22);
								nombreValeurLu++;
							}; break;
							case 3:{
								attributNouvelEmploye[6] = ligne.substr(19);
								nombreValeurLu++;
							}; break;
							case 4:{
								attributNouvelEmploye[7] = ligne.substr(29);
								nombreValeurLu++;
							}; break;
							default:{
							}; break;
						}
					} else{
						switch(nombreValeurLu){
							case 0:{
								istringstream is_ligneLu(ligne);
								is_ligneLu >> attributNouvelEmploye[1];
								is_ligneLu >> attributNouvelEmploye[0];
								nombreValeurLu++;
							}; break;
							case 1:{
								attributNouvelEmploye[2] = ligne.substr(20,2);
								attributNouvelEmploye[3] = ligne.substr(23,2);
								attributNouvelEmploye[4] = ligne.substr(26,4);
								nombreValeurLu++;
							}; break;
							case 2:{
								attributNouvelEmploye[5] = ligne.substr(22);
								nombreValeurLu++;
							}; break;
							case 3:{
								attributNouvelEmploye[6] = ligne.substr(10);
								nombreValeurLu++;
							}; break;
							default:{
							}; break;
						}
					}
				}
			}
		}
		file.close();
		if (typeEmploye == "commission")
			m_vEmploye.push_back(new EmployeCommission(attributNouvelEmploye[0], attributNouvelEmploye[1],
					util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
							atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
							atof(attributNouvelEmploye[6].c_str()), atof(attributNouvelEmploye[7].c_str()),
							atoi(attributNouvelEmploye[8].c_str())));
		else if (typeEmploye == "horaire")
			m_vEmploye.push_back(new EmployeHoraire(attributNouvelEmploye[0], attributNouvelEmploye[1],
					util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
							atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
							atof(attributNouvelEmploye[6].c_str()), atof(attributNouvelEmploye[7].c_str())));
		else
			m_vEmploye.push_back(new Patron(attributNouvelEmploye[0], attributNouvelEmploye[1],
					util::Date(atol(attributNouvelEmploye[2].c_str()), atol(attributNouvelEmploye[3].c_str()),
							atol(attributNouvelEmploye[4].c_str())), atoi(attributNouvelEmploye[5].c_str()),
							atof(attributNouvelEmploye[6].c_str())));
		afficherListeEmploye();
	} catch (std::string& e){
		QString message = (e.c_str());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void EmployeGUI::afficherListeEmploye(){
	int nombreDeLigne = ui.tableWidget->rowCount();
	for (int i = nombreDeLigne; i>=0; --i)
		ui.tableWidget->removeRow(i);
	nombreDeLigne = 0;
	std::vector<Employe*>::iterator it;
	for(it = m_vEmploye.begin(); it != m_vEmploye.end(); it++){
		QString date = QString::fromStdString((*it)->reqDateNaissance().reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem((*it)->reqNomFamille().c_str()));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem((*it)->reqPrenom().c_str()));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
		nombreDeLigne++;
	}
}