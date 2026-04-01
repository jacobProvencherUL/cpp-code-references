/**
 * \file EmployeCommission.h
 * \brief Classe EmployeCommission, dérivée de la classe Employe.
 * \author etudiant
 * \version 0.1
 * \date
 */

#ifndef EMPLOYECOMMISSION_H_
#define EMPLOYECOMMISSION_H_

// DIRE: On inclut seulement Employe.h. C'est suffisant parce que Employe.h 
// inclut déjà Date.h, ContratException.h et <string>.
// On n'a pas besoin de réinclure tout ça.
#include "Employe.h"

namespace labo10
{
/**
 * \class EmployeCommission
 * \brief Classe dérivée de la classe Employe
 */

// DIRE: Regardez bien la syntaxe de l'héritage ici.
// "class EmployeCommission: public Employe"
// Le "public" veut dire que tout ce qui est public dans Employe 
// reste public dans EmployeCommission.
// Donc on peut appeler reqPrenom(), reqNomFamille(), reqDateNaissance()
// directement sur un objet EmployeCommission, même si ces méthodes 
// sont définies dans Employe.
// C'est la relation "est un" : un EmployeCommission EST UN Employe.
class EmployeCommission: public Employe {
public:

	// DIRE: Le constructeur prend 7 paramètres. Les 4 premiers (nom, prénom, 
	// dateNaissance, codeDepartement) sont ceux de Employe — ils seront 
	// transmis au parent dans la liste d'initialisation du .cpp.
	// Les 3 derniers (salaire, commission, quantite) sont propres à cette classe.
	//
	// DIRE: Notez les valeurs par défaut: codeDepartement = 1, salaire = 0.0, etc.
	// Ça veut dire qu'on peut créer un EmployeCommission en passant seulement 
	// nom, prénom et date, et les autres prennent les valeurs par défaut.
	// Les valeurs par défaut se mettent dans le .h SEULEMENT, jamais dans le .cpp.
	EmployeCommission(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
				double p_salaire = 0.0,
				double p_commission = 0.0, int p_quantite = 0);

	// DIRE: Trois accesseurs, un par attribut propre à cette classe.
	// Les accesseurs du parent (reqPrenom, reqNomFamille, etc.) sont déjà 
	// hérités, pas besoin de les redéclarer.
   // ajout des accesseurs
    double reqSalaire() const;
   	double reqCommission() const;
   	int reqQuantite() const;

	// DIRE: Trois mutateurs — "asg" pour assigner. Ils permettent de modifier 
	// les attributs après la construction.
	// Dans le .cpp, chacun aura une PRECONDITION pour valider la valeur,
	// une POSTCONDITION pour confirmer l'assignation, et INVARIANTS() à la fin.
   	void asgSalaire( double p_salaire );
   	void asgCommission( double p_commission);
   	void asgQuantite( int p_quantite);

	// DIRE: Voici les deux méthodes qu'on REDÉFINIT depuis la classe parent.
	// Le mot "override" à la fin, c'est un ajout de C++11. C'est pas obligatoire 
	// mais c'est une TRÈS bonne pratique.
	// Ce que override fait: il dit au compilateur "je suis en train de redéfinir 
	// une méthode virtuelle du parent". Si on fait une faute de frappe dans le nom 
	// ou si la signature ne correspond pas exactement, le compilateur nous avertit 
	// avec une erreur au lieu de créer silencieusement une NOUVELLE méthode.
	// Sans override, si on écrivait "double gain() const" par erreur (sans le s),
	// ça compilerait sans erreur mais ça ne redéfinirait pas gains() du parent.
	// Le polymorphisme ne marcherait pas et on chercherait le bug pendant des heures.
	//
	// DIRE: gains() ici va retourner: m_salaire + m_commission * m_quantite.
	// Exemple: 200 + 3.0 × 150 = 650$.
    double gains() const override;

	// DIRE: reqEmployeFormate() va afficher "Employé à commission:" 
	// puis appeler Employe::reqEmployeFormate() pour le nom/prénom/date/département,
	// puis ajouter salaire, commission et quantité.
    std::string reqEmployeFormate() const override;

private:

	// DIRE: Trois attributs propres à l'employé à commission.
	// Le salaire de base est payé chaque semaine peu importe les ventes.
	// La commission est le montant touché PAR article vendu.
	// La quantité est le nombre d'articles vendus cette semaine.
	// Ces trois attributs N'EXISTENT PAS dans Employe ni dans Patron 
	// ni dans EmployeHoraire. Chaque classe dérivée a ses propres attributs.
   double m_salaire;      // salaire hebdomadaire de base.
   double m_commission;   // montant par article vendu.
   int m_quantite;        // total d'articles vendus pour la semaine.

	// DIRE: Chaque classe a son propre verifieInvariant.
	// Celui de Employe vérifie nom non vide, département > 0.
	// Celui-ci vérifie en plus que salaire > 0, commission >= 0, quantité >= 0.
	// INVARIANTS() dans le constructeur appelle le verifieInvariant de CETTE classe.
   void verifieInvariant() const;

};

}  // namespace labo10

#endif /* EMPLOYECOMMISSION_H_ */
