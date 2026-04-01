/**
 * \file Patron.cpp
 * \brief Implémentation de la classe Patron.
 * \author etudiant
 * \version 0.1
 * \date
 */

// 👉 Idée globale à expliquer :
// Cette classe représente un type particulier d’employé : le patron.
// Comme Patron dérive de Employe, on réutilise les informations communes
// (nom, prénom, date de naissance, code de département),
// puis on ajoute ici ce qui est spécifique au patron : son salaire hebdomadaire.

#include <iostream>
#include <sstream>
#include "Patron.h"

using namespace std;
namespace labo10
{

/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet Patron à partir de valeurs passées en paramètres.
 * \param[in] p_nom nom de l'employe
 * \param[in] p_prenom prenom de l'employe
 * \param[in] p_dateNaissance date de naissance de l'employe
 * \param[in] p_salaireHebdo salaire hébdomadaire de l'employe
 * \param[in] p_codeDepartement code du departement auquel appartient l'employe
 * \pre p_salaireHebdo > 0
 * \post m_salaireHebdo prend la valeur de p_salaireHebdo
 */

// 👉 À dire ici :
// On commence par appeler le constructeur de la classe de base Employe.
// Donc la partie commune à tous les employés est construite d’abord.
// Ensuite, on initialise ce qui est propre au patron, ici son salaire hebdomadaire.
// C’est exactement le principe de l’héritage :
// la classe dérivée réutilise la classe de base et ajoute son propre comportement.

Patron::Patron(const std::string& p_nom, const std::string& p_prenom,
		const util::Date& p_dateNaissance, int p_codeDepartement,
		double p_salaireHebdo) :
		Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement), m_salaireHebdo(
				p_salaireHebdo) // appelle constructeur de classe de base.
{
	// 👉 Ici on vérifie que le salaire est valide.
	// On ne veut pas construire un patron avec un salaire hebdomadaire nul ou négatif.
	PRECONDITION(p_salaireHebdo > 0);

	// 👉 Après la construction, on vérifie que l’attribut a bien reçu la bonne valeur.
	POSTCONDITION(m_salaireHebdo == p_salaireHebdo);

	// 👉 Vérification globale de la cohérence de l’objet.
	INVARIANTS();
}

/**
 * \brief Ajuste le salaire du Patron
 * \param[in] p_salaireHebdo salaire hébdomadaire de l'employe
 * \pre p_salaireHebdo > 0
 * \post m_salaireHebdo prend la valeur de p_salaireHebdo
 */

// 👉 À dire ici :
// Cette méthode permet de modifier le salaire du patron après la création de l’objet.
// Comme toujours, on protège l’objet avec une précondition :
// le nouveau salaire doit rester strictement positif.

void Patron::asgSalaireHebdo(double p_salaireHebdo)
{
	PRECONDITION(p_salaireHebdo > 0)
	m_salaireHebdo = p_salaireHebdo; //m_salaireHebdo = p_salaireHebdo > 0 ? p_salaireHebdo: 0;

	// 👉 On vérifie après modification que la valeur a bien été affectée.
	POSTCONDITION(m_salaireHebdo == p_salaireHebdo);

	// 👉 On revalide les invariants de la classe.
	INVARIANTS();
}

/**
 * \brief Lit la paie du Patron.
 *         methode virtuelle
 * \return les gains de l'employé
 */

// 👉 C’est ici le point important pour le polymorphisme.
// Tous les employés ont une méthode gains(), mais chaque type d’employé
// ne calcule pas sa paie de la même façon.
// Pour un patron, la paie est simplement son salaire hebdomadaire.
// Donc ici, on redéfinit la logique de gains pour ce type précis d’employé.

double Patron::gains() const
{
	return m_salaireHebdo;
}

/**
 * \brief Affiche les informations du Patron sous forme d'une chaîne de caractère formatee
 * \return les informations sur un employé
 */

// 👉 Ici, on personnalise l’affichage.
// On ajoute juste le mot "Patron", puis on réutilise l’affichage commun de la classe Employe.
// C’est une bonne pratique : on ne duplique pas le code du parent,
// on le réutilise et on complète seulement ce qui change.

std::string Patron::reqEmployeFormate() const
{
	ostringstream os;
	os << std::endl << " Patron : ";
	os << Employe::reqEmployeFormate();
	return os.str();
}

/**
 * \brief Vérifie les invariants de la classe
 */

// 👉 Ici on vérifie que l’objet Patron reste toujours valide.
// Le salaire hebdomadaire doit toujours être strictement positif.

void Patron::verifieInvariant() const
{
	INVARIANT(m_salaireHebdo > 0);
}

}  // namespace labo10