/**
 * \file EmployeHoraire.cpp
 * \brief Implémentation de la classe EmployeHoraire
 */

// DIRE: Troisième et dernière classe dérivée. Même structure que Patron et EmployeCommission.
// La différence c'est la logique de gains(): ici on a le temps supplémentaire.
// C'est la méthode gains() la plus complexe des trois — bonne occasion de faire 
// un calcul en direct avec les étudiants.

#include <iostream>
#include <sstream>
#include "EmployeHoraire.h"

namespace labo10
{
/**
 * \brief Constructeur avec paramètre
 */

// DIRE: Exactement le même patron que EmployeCommission.
// Première partie de la liste d'initialisation: Employe(...) → les 4 paramètres communs.
// Deuxième partie: m_tauxHoraire et m_heures → les 2 attributs propres.
// C'est le parent qui stocke nom/prénom/date/département.
// C'est EmployeHoraire qui stocke le taux et les heures.
//
// DIRE: Comparez les trois constructeurs dérivés — ils commencent tous par 
// Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement).
// C'est toujours la même chose. Seule la deuxième partie change.
EmployeHoraire::EmployeHoraire(const std::string& p_nom,
		const std::string& p_prenom, const util::Date& p_dateNaissance,
		int p_codeDepartement, double p_tauxHoraire, double p_heures) :
		Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement), m_tauxHoraire(
				p_tauxHoraire), m_heures(p_heures) // appelle du constructeur de la classe de base.
{
	// DIRE: Le taux horaire doit être positif — un taux de 0$ par heure ça n'a pas de sens.
	// Les heures doivent être entre 0 et 168. Pourquoi 168? Parce que 24 × 7 = 168.
	// C'est le nombre maximum d'heures dans une semaine. Même si c'est théorique,
	// on met une borne pour empêcher les valeurs absurdes.
	PRECONDITION(p_tauxHoraire > 0);
	PRECONDITION(p_heures > 0 && p_heures < 168);

	POSTCONDITION(m_tauxHoraire == p_tauxHoraire);
	POSTCONDITION(m_heures == p_heures);

	INVARIANTS();
}

/**
 * \brief Accesseur taux horaire
 */

// DIRE: Deux accesseurs, un par attribut propre. Rien de spécial.
double EmployeHoraire::reqTauxHoraire() const
{
	return m_tauxHoraire;
}

/**
 * \brief Accesseur heures
 */

double EmployeHoraire::reqHeure() const
{
	return m_heures;
}

/**
 * \brief Ajuste le taux horaire
 */

// DIRE: Même patron que les mutateurs de EmployeCommission.
// PRECONDITION → assignation → POSTCONDITION → INVARIANTS.
// Le nom "asgPaie" est un peu trompeur — ça modifie le taux horaire, pas la paie totale.
// C'est le code fourni, on le garde tel quel.
void EmployeHoraire::asgPaie(double p_tauxHoraire)
{
	PRECONDITION(p_tauxHoraire > 0);
	m_tauxHoraire = p_tauxHoraire;
	POSTCONDITION(m_tauxHoraire == p_tauxHoraire);
	INVARIANTS();
}

/**
 * \brief Ajuste les heures
 */

// DIRE: La borne 168 c'est 24h × 7 jours. C'est le maximum absolu dans une semaine.
// En pratique personne travaille 168 heures, mais c'est une borne de sécurité.
void EmployeHoraire::asgHeures(double p_heuresTravaillees)
{
	PRECONDITION(p_heuresTravaillees > 0 && p_heuresTravaillees < 168);
	m_heures = p_heuresTravaillees;
	POSTCONDITION(m_heures == p_heuresTravaillees);
	INVARIANTS();
}

/**
 * \brief retourne la paie
 */

// DIRE: C'est LA méthode la plus intéressante de tout le labo.
// C'est la seule des trois gains() qui a une condition if/else.
//
// DIRE: Faisons le calcul ensemble. Cas 1: 40 heures, taux 13.75$.
// On est dans le if parce que 40 <= 40.
// Résultat: 13.75 × 40 = 550$.
//
// DIRE: Cas 2: 50 heures, même taux.
// On est dans le else parce que 50 > 40.
// Les 40 premières heures: 40 × 13.75 = 550$.
// Les 10 heures supplémentaires: 10 × 13.75 × 1.5 = 206.25$.
// Total: 550 + 206.25 = 756.25$.
//
// DIRE: Le 1.5 c'est "temps et demi" — les heures au-delà de 40 sont payées 
// à 150% du taux normal. C'est la norme du travail au Québec.
//
// DIRE: Comparez les trois gains():
//   Patron: return m_salaireHebdo                    → trivial
//   EmployeCommission: return m_salaire + m_commission * m_quantite  → une formule
//   EmployeHoraire: if/else avec temps supplémentaire → une condition
// Trois logiques différentes, un seul appel gains() dans la boucle de Utilisation.cpp.
double EmployeHoraire::gains() const
{
	double gainsEmploye;

	if (m_heures <= 40) // pas de temps supplémentaire.
		gainsEmploye = m_tauxHoraire * m_heures;
	else
		gainsEmploye = 40 * m_tauxHoraire
				+ (m_heures - 40) * m_tauxHoraire * 1.5;

	return gainsEmploye;
}

/**
 * \brief Affichage formaté
 */

// DIRE: Identique aux deux autres: titre propre + appel au parent.
// Les trois classes font exactement la même chose ici, juste le titre change:
//   Patron: "Patron :"
//   EmployeCommission: "Employé à commission:"
//   EmployeHoraire: "Employé horaire :"
// Puis Employe::reqEmployeFormate() pour le nom/prénom commun à tous.
std::string EmployeHoraire::reqEmployeFormate() const
{
	std::ostringstream os;

	os << std::endl << " Employé horaire : ";
	os << Employe::reqEmployeFormate();

	return os.str();
}

/**
 * \brief Vérifie les invariants
 */

// DIRE: Vérifie les deux attributs propres: taux > 0 et heures dans les bornes.
// Les attributs du parent (nom, prénom, département) sont vérifiés 
// par Employe::verifieInvariant(), pas ici.
void EmployeHoraire::verifieInvariant() const
{
	INVARIANT(m_tauxHoraire > 0);
	INVARIANT(m_heures > 0 && m_heures < 168);
}

} // namespace labo10