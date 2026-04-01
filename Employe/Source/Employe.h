/**
 * \file Employe.h
 * \brief Classe de base abstraite Employe
 * \author etudiant
 * \version 0.1
 * \date
 */

// DIRE: Garde d'inclusion, même principe que Date.h.
#ifndef EMPLOYE_H_
#define EMPLOYE_H_

// DIRE: On inclut Date.h parce qu'on a un attribut de type util::Date (la date de naissance).
// On inclut ContratException.h pour les macros PRECONDITION, POSTCONDITION, INVARIANTS.
// Notez que Date.h inclut déjà ContratException.h et <string>, mais on les réinclut 
// explicitement — c'est une bonne pratique, comme ça notre fichier ne dépend pas 
// de ce que Date.h inclut en interne.
#include "Date.h"
#include "ContratException.h"

// DIRE: On est dans le namespace labo10. C'est le namespace du système de paie.
// La classe Date est dans "util", les classes métier sont dans "labo10".
// Les deux sont séparés parce qu'ils n'ont pas la même responsabilité.
namespace labo10
{
/**
 * \class Employe
 * \brief Classe de base
 */

// DIRE: Voici la classe de base de tout le système. Patron, EmployeCommission et 
// EmployeHoraire vont toutes hériter de cette classe.
// Elle contient tout ce qui est COMMUN à tous les types d'employés.
// Les choses spécifiques (salaire hebdo, taux horaire, commission) seront
// dans les classes dérivées.
class Employe
{
public:

	// DIRE: Le constructeur prend quatre paramètres — ce sont les infos communes à TOUS les employés.
	// Peu importe si c'est un patron ou un employé horaire, il a un nom, un prénom, 
	// une date de naissance et un département.
	// Les strings sont passés par const référence pour éviter une copie inutile.
	// La Date aussi est passée par const référence, même logique.
	// Le int est passé par valeur parce que copier un int coûte rien.
	Employe(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement);

	// DIRE: Le destructeur est VIRTUEL. C'est obligatoire dès qu'on a des méthodes virtuelles.
	// Pourquoi? Parce qu'on va utiliser des pointeurs Employe* qui pointent vers des Patron,
	// des EmployeCommission, etc. Si on fait delete sur ce pointeur, il faut que le VRAI 
	// destructeur soit appelé, pas juste celui de Employe.
	// Sans virtual ici, on aurait des fuites mémoire potentielles.
	// Le corps est vide {} parce qu'on n'a pas de mémoire dynamique à libérer.
	virtual ~Employe(){};

	//Accesseurs

	// DIRE: Quatre accesseurs, un par attribut. Convention du cours: "req" pour requête.
	// Ils sont tous const — ils ne modifient pas l'objet.
	// reqDateNaissance() c'est celui qu'on va utiliser dans Utilisation.cpp pour le bonus:
	// on fera v_entreprise[x]->reqDateNaissance().reqMois() pour avoir le mois de naissance.
	int reqCodeDepartement() const;
	const std::string& reqPrenom() const;
	const std::string& reqNomFamille() const;
	const util::Date& reqDateNaissance() const;

	// DIRE: Voici le coeur du polymorphisme. gains() est VIRTUAL.
	// Ça veut dire que quand on appelle gains() sur un pointeur Employe*,
	// c'est la version de la VRAIE classe de l'objet qui est appelée.
	// Si le pointeur pointe vers un Patron → Patron::gains().
	// Si c'est un EmployeHoraire → EmployeHoraire::gains().
	// Le compilateur utilise la vtable pour trouver la bonne version à l'exécution.
	//
	// DIRE: Ici elle n'est PAS pure virtuelle (pas de = 0).
	// Ça veut dire qu'on PEUT instancier un Employe directement.
	// Idéalement on mettrait "= 0" pour forcer chaque dérivée à l'implémenter
	// et empêcher de créer un Employe de base. Mais le code fourni est comme ça.
   virtual double gains() const;

	// DIRE: Même chose pour reqEmployeFormate — elle est virtuelle.
	// La version de base retourne juste "prenom nom".
	// Les classes dérivées ajoutent leurs infos spécifiques autour,
	// en appelant Employe::reqEmployeFormate() à l'intérieur.
   virtual std::string reqEmployeFormate() const; // virtuelle.

private:

	// DIRE: Les quatre attributs privés. C'est l'encapsulation.
	// Personne de l'extérieur peut écrire monEmploye.m_prenom = "".
	// Tout passe par le constructeur (qui a des PRECONDITION) et les accesseurs.
	//
	// DIRE: m_dateNaissance est un OBJET Date, pas un pointeur.
	// Ça veut dire que quand on construit un Employe, le constructeur de copie de Date
	// est appelé automatiquement via la liste d'initialisation du constructeur.
	// La Date vit et meurt avec l'Employe — c'est la COMPOSITION.
     std::string m_nomFamille;
   	 std::string m_prenom;
   	 util::Date m_dateNaissance;
   	 int m_codeDepartement;

	// DIRE: verifieInvariant est privée parce que c'est un mécanisme interne.
	// Elle est appelée par la macro INVARIANTS() à la fin du constructeur et des mutateurs.
	// Elle vérifie que le nom et le prénom sont non vides, que le code département > 0.
	// Si un invariant est violé, ça lance une InvariantException.
   	 void verifieInvariant() const;

};

}
#endif /* EMPLOYE_H_ */
