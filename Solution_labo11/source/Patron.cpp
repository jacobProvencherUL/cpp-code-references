/**
 * \file Patron.cpp
 * \brief Implémentation de la classe Patron.
 * \author etudiant
 * \version 0.1
 * \date
 */

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
Patron::Patron(const std::string& p_nom, const std::string& p_prenom,
		const util::Date& p_dateNaissance, int p_codeDepartement,
		double p_salaireHebdo) :
		Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement), m_salaireHebdo(
				p_salaireHebdo) // appelle constructeur de classe de base.
{
	PRECONDITION(p_salaireHebdo > 0);

	POSTCONDITION(m_salaireHebdo == p_salaireHebdo);
	INVARIANTS();
}
/**
 * \brief Ajuste le salaire du Patron
 * \param[in] p_salaireHebdo salaire hébdomadaire de l'employe
 * \pre p_salaireHebdo > 0
 * \post m_salaireHebdo prend la valeur de p_salaireHebdo
 */
void Patron::asgSalaireHebdo(double p_salaireHebdo)
{
	PRECONDITION(p_salaireHebdo > 0)
	m_salaireHebdo = p_salaireHebdo; //m_salaireHebdo = p_salaireHebdo > 0 ? p_salaireHebdo: 0;
	POSTCONDITION(m_salaireHebdo == p_salaireHebdo);
	INVARIANTS();
}
/**
 * \brief Lit la paie du Patron.
 *         methode virtuelle
 * \return les gains de l'employé
 */
double Patron::gains() const
{
	return m_salaireHebdo;
}
/**
 * \brief Affiche les informations du Patron sous forme d'une chaîne de caractère formatee
 * \return les informations sur un employé
 */
std::string Patron::reqEmployeFormate() const
{
	ostringstream os;
	os << std::endl << "Patron : " << std::endl;
	os << Employe::reqEmployeFormate() << std::endl;
	os << "Date de naissance : " << Employe::reqDateNaissance() << std::endl;
	os << "Code de departement : " << Employe::reqCodeDepartement() << std::endl;
	os << "Salaire : " << m_salaireHebdo << std::endl;
	return os.str();
}

/**
 * \brief Vérifie les invariants de la classe
 */
void Patron::verifieInvariant() const
{
	INVARIANT(m_salaireHebdo > 0);
}

}  // namespace labo10
