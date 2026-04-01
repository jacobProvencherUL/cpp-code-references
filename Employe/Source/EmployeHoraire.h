/**
 * \file EmployeHoraire.h
 * \brief Déclaration de la classe EmployeHoraire héritant de la classe Employe
 * \author etudiant
 * \version 0.1
 * \date
 */

#ifndef EMPLOYEHORAIRE_H_
#define EMPLOYEHORAIRE_H_

#include "Employe.h"

namespace labo10
{

/**
 * \class EmployeHoraire
 * \brief Classe dérivée de la classe Employe
 */

// DIRE: Troisième classe dérivée. Même patron que Patron et EmployeCommission:
// héritage public de Employe, donc c'est un Employe avec des attributs en plus.
// Un EmployeHoraire est payé à l'heure, contrairement au Patron (salaire fixe)
// et à l'EmployeCommission (salaire + commission par vente).
class EmployeHoraire : public Employe
{
public:

	// DIRE: Le constructeur prend 6 paramètres. Les 4 premiers (nom, prénom,
	// dateNaissance, codeDepartement) vont au parent Employe.
	// Les 2 derniers sont propres à cette classe: le taux horaire et les heures.
	// Valeurs par défaut: codeDepartement = 1, tauxHoraire = 0.0, heures = 0.0.
	//
	// DIRE: Comparez avec EmployeCommission qui avait 3 attributs propres.
	// Ici on en a 2. Chaque type d'employé a ses propres données.
	// Mais le constructeur commence toujours par les mêmes 4 paramètres du parent.
    EmployeHoraire(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
                   double p_tauxHoraire = 0.0, double p_heures = 0.0);

	// DIRE: Deux accesseurs pour les deux attributs propres.
	// Les accesseurs du parent (reqPrenom, reqNomFamille, reqDateNaissance,
	// reqCodeDepartement) sont hérités automatiquement, pas besoin de les redéclarer.
    double reqTauxHoraire() const;
    double reqHeure() const;

	// DIRE: Deux mutateurs. Remarquez les noms: asgPaie pour le taux horaire,
	// asgHeures pour les heures. Le nom "asgPaie" est un peu trompeur — 
	// ça modifie le taux horaire, pas la paie totale. C'est le code fourni tel quel.
	// Dans le .cpp, asgHeures va valider que les heures sont entre 0 et 168
	// (168 = 24h × 7 jours, le maximum théorique dans une semaine).
    void asgPaie(double p_tauxHoraire);
    void asgHeures(double p_heuresTravaillees);

	// DIRE: Les deux redéfinitions avec override, comme dans EmployeCommission.
	//
	// DIRE: gains() ici a une logique plus complexe que les deux autres classes.
	// Si heures <= 40: gains = tauxHoraire × heures (taux normal).
	// Si heures > 40: gains = 40 × taux + (heures - 40) × taux × 1.5 (temps supp).
	// Le 1.5 c'est "temps et demi" — les heures supplémentaires sont payées 
	// à 150% du taux normal. C'est la norme du travail au Québec.
	//
	// DIRE: Exemple concret: taux = 13.75$, heures = 40 → 13.75 × 40 = 550$.
	// Avec 50 heures: 40 × 13.75 + 10 × 13.75 × 1.5 = 550 + 206.25 = 756.25$.
    double gains() const override;
    std::string reqEmployeFormate() const override;

private:

	// DIRE: Seulement deux attributs propres. C'est la classe dérivée la plus simple
	// après Patron (qui n'en a qu'un).
	// m_tauxHoraire c'est combien l'employé gagne par heure.
	// m_heures c'est combien d'heures il a travaillé cette semaine.
    double m_tauxHoraire; // taux horaire.
    double m_heures; // m_heures travaillées pour la semaine.

	// DIRE: Son propre verifieInvariant. Vérifie que tauxHoraire > 0,
	// heures >= 0 et heures < 168. Chaque classe vérifie SES attributs.
    void verifieInvariant() const;
};


} // namespace labo10

#endif /* EMPLOYEHORAIRE_H_ */