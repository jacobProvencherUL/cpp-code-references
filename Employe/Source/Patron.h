/**
 * \file Patron.h
 * \brief Classe Patron, dérivée de la classe Employe.
 * \author etudiant
 * \version 0.1
 * \date
 */

#ifndef PATRON_H_
#define PATRON_H_

#include "Employe.h"

namespace labo10
{

/**
 * \class Patron
 * \brief Classe dérivée de la classe Employe
 */

// DIRE: C'est la classe dérivée la plus simple des trois.
// Un Patron a juste un salaire fixe par semaine. Pas de commission, pas d'heures.
// C'est un bon point de départ pour comprendre l'héritage avant de regarder 
// les deux autres qui sont plus complexes.
class Patron : public Employe
{
public:

	// DIRE: Le constructeur prend 5 paramètres. Les 4 premiers vont au parent Employe.
	// Le 5ème, p_salaireHebdo, c'est le seul attribut propre au Patron.
	//
	// DIRE: Comparez les trois constructeurs dérivés côte à côte:
	//   Patron:             4 params parent + 1 propre  (salaireHebdo)
	//   EmployeCommission:  4 params parent + 3 propres (salaire, commission, quantité)
	//   EmployeHoraire:     4 params parent + 2 propres (tauxHoraire, heures)
	// Les 4 premiers sont TOUJOURS les mêmes. C'est ça la force de l'héritage:
	// le tronc commun est factorisé dans Employe.
    Patron(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
           double p_salaireHebdo = 0.0);

	// DIRE: Un seul mutateur. Le Patron n'a qu'un attribut propre, donc un seul "asg".
	// Notez qu'il n'y a PAS d'accesseur reqSalaireHebdo() déclaré ici.
	// C'est un oubli dans le code fourni — en principe il devrait y en avoir un.
	// On peut quand même obtenir le salaire via gains() qui retourne la même valeur.
    void asgSalaireHebdo(double p_salaireHebdo);

	// DIRE: Les deux redéfinitions avec override.
	// gains() pour le Patron c'est le plus simple possible: return m_salaireHebdo.
	// Pas de calcul, pas de condition. Le patron gagne son salaire fixe, point.
	//
	// DIRE: reqEmployeFormate() va afficher "Patron:" puis appeler 
	// Employe::reqEmployeFormate() pour le nom/prénom/date/département.
	// C'est la réutilisation du code parent — on n'a pas besoin de réécrire 
	// l'affichage du nom et du prénom dans chaque classe dérivée.
    double gains() const override;
    std::string reqEmployeFormate() const override;

private:

	// DIRE: Un seul attribut privé. C'est pour ça que Patron est la classe 
	// la plus simple à comprendre et à tester.
	// Comparez: EmployeCommission a 3 attributs, EmployeHoraire en a 2, Patron en a 1.
    double m_salaireHebdo;

	// DIRE: Son verifieInvariant vérifie juste que m_salaireHebdo > 0.
	// C'est le plus court des trois.
    void verifieInvariant() const;

};

} // namespace labo10

#endif /* PATRON_H_ */