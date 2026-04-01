/**
 * \file EmployeCommission.cpp
 * \brief Implémentation de la classe EmployeCommission.
 */

// DIRE: Première classe dérivée qu'on regarde en détail dans le .cpp.
// Prenez le temps de comparer avec Employe.cpp — on va voir que le constructeur 
// commence par appeler le constructeur du parent, puis ajoute ses propres attributs.
// C'est le patron qu'on retrouve dans TOUTES les classes dérivées.

#include <iostream>
#include <sstream>
#include "EmployeCommission.h"

using namespace std;
namespace labo10
{
/**
 * \brief Constructeur avec paramètre
 */

// DIRE: Regardez bien la liste d'initialisation. Elle a deux parties.
// PREMIÈRE PARTIE: Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement)
// C'est l'appel au constructeur du PARENT. On lui passe les 4 paramètres communs.
// C'est Employe qui va stocker le nom, le prénom, la date et le département.
// EmployeCommission ne touche pas à ces attributs — c'est pas son rôle.
//
// DEUXIÈME PARTIE: m_salaire(p_salaire), m_commission(p_commission), m_quantite(p_quantite)
// C'est l'initialisation des 3 attributs PROPRES à EmployeCommission.
//
// DIRE: L'ordre est important: le parent est TOUJOURS initialisé en premier,
// ensuite les attributs propres. C'est le C++ qui impose ça.
EmployeCommission::EmployeCommission(const std::string& p_nom,
		const std::string& p_prenom, const util::Date& p_dateNaissance,
		int p_codeDepartement, double p_salaire, double p_commission,
		int p_quantite) :
		Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement), m_salaire(
				p_salaire), m_commission(p_commission), m_quantite(p_quantite)
{
	// DIRE: Les préconditions vérifient les 3 paramètres propres.
	// Le salaire doit être strictement positif — un employé avec un salaire de 0 ça n'a pas de sens.
	// La commission peut être zéro (pas de commission cette semaine) mais pas négative.
	// La quantité pareil: zéro ventes c'est possible, mais -5 ventes c'est impossible.
	// Les paramètres du parent (nom, prénom, etc.) sont validés par le constructeur de Employe.
	// On ne les revérifie pas ici — c'est la responsabilité du parent.
	PRECONDITION(p_salaire > 0);
	PRECONDITION(p_commission >= 0);
	PRECONDITION(p_quantite >= 0);

	POSTCONDITION(m_commission == p_commission);
	POSTCONDITION(m_quantite == p_quantite);
	POSTCONDITION(m_salaire == p_salaire);

	INVARIANTS();
}

/**
 * \brief Accesseur sur le salaire
 */

// DIRE: Trois accesseurs simples, un par attribut propre.
// Pas besoin de déclarer reqPrenom() ou reqNomFamille() ici — 
// elles sont héritées de Employe et accessibles directement.
double EmployeCommission::reqSalaire() const
{
	return m_salaire;
}

/**
 * \brief Accesseur sur la commission
 */

// DIRE: La commission c'est le montant par article vendu.
// Exemple: 3.00$ par article.
double EmployeCommission::reqCommission() const
{
	return m_commission;
}

/**
 * \brief Accesseur sur la quantité
 */

// DIRE: La quantité c'est combien d'articles vendus cette semaine.
// Exemple: 150 articles.
int EmployeCommission::reqQuantite() const
{
	return m_quantite;
}

/**
 * \brief Ajuste le salaire
 */

// DIRE: Les trois mutateurs suivants ont tous la même structure:
// PRECONDITION → assignation → POSTCONDITION → INVARIANTS.
// C'est le patron systématique du design par contrat pour les mutateurs.
// Comparez avec le code original fourni qui faisait:
//    m_salaire = p_salaire > 0 ? p_salaire : 0;
// Ça masquait l'erreur silencieusement. Ici on la détecte et on l'expose.
void EmployeCommission::asgSalaire(double p_salaire)
{
	PRECONDITION(p_salaire > 0);
	m_salaire = p_salaire;
	POSTCONDITION(m_salaire == p_salaire);
	INVARIANTS();
}

/**
 * \brief Ajuste la commission
 */

void EmployeCommission::asgCommission(double p_commission)
{
	PRECONDITION(p_commission >= 0);
	m_commission = p_commission;
	POSTCONDITION(m_commission == p_commission);
	INVARIANTS();
}

/**
 * \brief Ajustement de la quantité
 */

void EmployeCommission::asgQuantite(int p_quantite)
{
	PRECONDITION(p_quantite >= 0);
	m_quantite = p_quantite;
	POSTCONDITION(m_quantite == p_quantite);
	INVARIANTS();
}

/**
 * \brief retourne la paie
 */

// DIRE: C'est ICI que le polymorphisme prend tout son sens.
// Dans Utilisation.cpp, on appelle v_entreprise[x]->gains() sur un pointeur Employe*.
// Si l'objet réel est un EmployeCommission, c'est CETTE version qui est appelée.
//
// DIRE: La formule: salaire de base + commission × quantité.
// Faites le calcul avec les étudiants: 200 + 3.0 × 150 = 200 + 450 = 650$.
// Comparez avec Patron::gains() qui retourne juste le salaire fixe,
// et EmployeHoraire::gains() qui a la logique du temps supplémentaire.
// Trois formules différentes, mais un seul appel gains() dans la boucle.
// C'est ça le polymorphisme.
double EmployeCommission::gains() const
{
	return m_salaire + m_commission * m_quantite;
}

/**
 * \brief Affichage formaté
 */

// DIRE: Regardez bien l'appel Employe::reqEmployeFormate().
// C'est l'appel EXPLICITE à la version du parent, avec le préfixe Employe::.
// Si on écrivait juste reqEmployeFormate() sans le préfixe, 
// on s'appellerait soi-même → récursion infinie → crash du programme.
//
// DIRE: C'est le patron de réutilisation: la dérivée ajoute son titre 
// "Employé à commission:" puis délègue au parent pour le nom/prénom.
// Les trois classes dérivées font la même chose avec des titres différents.
std::string EmployeCommission::reqEmployeFormate() const
{
	ostringstream os;
	os << std::endl << " Employé à commission: ";
	os << Employe::reqEmployeFormate();
	return os.str();
}

/**
 * \brief Vérifie les invariants
 */

// DIRE: Chaque classe vérifie SES propres attributs.
// Employe::verifieInvariant() vérifie nom, prénom, département.
// Celui-ci vérifie salaire, commission, quantité.
// Quand INVARIANTS() est appelé dans le constructeur de EmployeCommission,
// c'est CE verifieInvariant qui est exécuté.
void EmployeCommission::verifieInvariant() const
{
	INVARIANT(m_salaire > 0);
	INVARIANT(m_commission >= 0);
	INVARIANT(m_quantite >= 0);
}

} // namespace labo10
