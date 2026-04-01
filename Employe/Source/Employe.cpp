/**
 * \file Employe.cpp
 * \brief Implémentation de la classe de base abstraite Employe.
 *        Note: aucune définition de la méthode virtuelle pure.
 */

// DIRE: C'est le fichier le plus important à comprendre. C'est la classe PARENT.
// Tout ce qu'on met ici est hérité par Patron, EmployeCommission et EmployeHoraire.
// Si on comprend bien cette classe, le reste suit automatiquement.

#include "Employe.h"
#include <iostream>

using namespace std;

namespace labo10
{

/**
 * \brief Constructeur avec paramètre.
 */

// DIRE: Regardez bien la liste d'initialisation — c'est tout ce qui est entre 
// les deux-points et l'accolade ouvrante. C'est exécuté AVANT le corps du constructeur.
// Quand on entre dans les accolades, les 4 attributs sont déjà initialisés.
//
// DIRE: Pour m_dateNaissance, on reconstruit une Date à partir des composantes 
// de p_dateNaissance. On appelle reqJour(), reqMois(), reqAnnee() sur la date 
// reçue en paramètre et on passe ces trois valeurs au constructeur de Date.
// C'est une copie "profonde" — on crée un nouvel objet Date indépendant.
//
// DIRE: Les classes dérivées vont appeler CE constructeur dans leur propre 
// liste d'initialisation avec : Employe(p_nom, p_prenom, p_dateNaissance, p_codeDepartement)
// Elles transmettent les 4 paramètres communs ici, et stockent eux-mêmes 
// leurs attributs propres (salaire, taux horaire, etc.).
Employe::Employe(const std::string& p_nom, const std::string& p_prenom,
        const util::Date& p_dateNaissance, int p_codeDepartement)
    : m_nomFamille(p_nom),
      m_prenom(p_prenom),
      m_dateNaissance(p_dateNaissance.reqJour(),
                      p_dateNaissance.reqMois(),
                      p_dateNaissance.reqAnnee()),
      m_codeDepartement(p_codeDepartement)
{
    // DIRE: Les PRECONDITION vérifient les paramètres d'entrée.
    // Nom vide? Exception. Prénom vide? Exception. Département à 0 ou négatif? Exception.
    // C'est la responsabilité de l'APPELANT de passer des valeurs valides.
    PRECONDITION(!p_nom.empty());
    PRECONDITION(!p_prenom.empty());
    PRECONDITION(p_codeDepartement > 0);

    // DIRE: Les POSTCONDITION vérifient que l'assignation a bien fonctionné.
    // On compare chaque attribut avec le paramètre correspondant.
    // Pour la date, on utilise operator== de la classe Date (celle qu'on a vue 
    // dans Date.cpp qui compare les m_temps).
    POSTCONDITION(m_nomFamille == p_nom);
    POSTCONDITION(m_prenom == p_prenom);
    POSTCONDITION(m_dateNaissance == p_dateNaissance);
    POSTCONDITION(m_codeDepartement == p_codeDepartement);

    // DIRE: INVARIANTS() appelle verifieInvariant() qui est en bas du fichier.
    // Ça vérifie que l'objet est dans un état cohérent à la fin de la construction.
    INVARIANTS();
}

/**
 * \brief Accesseur prénom
 */
// DIRE: Les quatre accesseurs sont simples — ils retournent chacun un attribut.
// Notez le "const" à la fin: on garantit qu'on ne modifie pas l'objet.
// Notez aussi le "const std::string&" comme type de retour: on retourne 
// une RÉFÉRENCE constante, pas une copie. C'est plus efficace pour les strings.
const std::string& Employe::reqPrenom() const
{
    return m_prenom;
}

/**
 * \brief Accesseur nom
 */
const std::string& Employe::reqNomFamille() const
{
    return m_nomFamille;
}

/**
 * \brief Accesseur date de naissance
 */
// DIRE: C'est CET accesseur qu'on utilise dans Utilisation.cpp pour le bonus.
// On va écrire: v_entreprise[x]->reqDateNaissance().reqMois()
// Ça retourne une référence vers l'objet Date, puis on appelle reqMois() dessus.
// C'est un enchaînement d'appels — le premier retourne un objet, le deuxième 
// appelle une méthode sur cet objet.
const util::Date& Employe::reqDateNaissance() const
{
    return m_dateNaissance;
}

/**
 * \brief Accesseur code département
 */
int Employe::reqCodeDepartement() const
{
    return m_codeDepartement;
}

/**
 * \brief Lit la paie de l'employé.
 */
// DIRE: Attention, c'est LE point clé du polymorphisme.
// Cette méthode retourne 0. C'est la version "par défaut" de la classe de base.
// Mais elle est déclarée VIRTUAL dans le .h.
//
// DIRE: Ça veut dire que quand on appelle gains() sur un pointeur Employe*,
// le programme regarde le TYPE RÉEL de l'objet à l'exécution.
// Si c'est un Patron → Patron::gains() est appelée (retourne salaireHebdo).
// Si c'est un EmployeHoraire → EmployeHoraire::gains() (taux × heures).
// Si c'est un EmployeCommission → EmployeCommission::gains() (salaire + commission × quantité).
// Cette version-ci (return 0) n'est jamais appelée en pratique si toutes 
// les dérivées redéfinissent gains().
//
// DIRE: Idéalement, on mettrait "= 0" dans le .h pour la rendre pure virtuelle.
// Comme ça, Employe serait vraiment abstraite et le compilateur FORCERAIT 
// chaque dérivée à implémenter gains(). Mais le code fourni est fait comme ça.
double Employe::gains() const
{
    return 0;
}

/**
 * \brief Affichage du nom et prénom
 */
// DIRE: Celle-ci est aussi virtuelle mais PAS redéfinie de la même façon.
// Les classes dérivées ne la REMPLACENT pas, elles l'APPELLENT.
// Dans Patron::reqEmployeFormate(), on écrit:
//     os << Employe::reqEmployeFormate();
// Ça appelle CETTE version pour avoir "Jean Soucy", puis Patron ajoute 
// ses propres infos autour. C'est la réutilisation du code parent.
std::string Employe::reqEmployeFormate() const
{
    return m_prenom + " " + m_nomFamille;
}

/**
 * \brief Vérifier les invariants
 */
// DIRE: Appelée par INVARIANTS() à la fin du constructeur.
// Trois conditions qui doivent TOUJOURS être vraies pour tout Employe:
// 1) le nom ne doit jamais être vide
// 2) le prénom ne doit jamais être vide  
// 3) le code département doit être > 0
// Si une de ces conditions est fausse → InvariantException avec fichier et ligne.
//
// DIRE: Chaque classe dérivée a en plus son PROPRE verifieInvariant 
// qui vérifie SES attributs (salaire > 0, heures >= 0, etc.).
void Employe::verifieInvariant() const
{
    INVARIANT(!(m_nomFamille.empty()));
    INVARIANT(!(m_prenom.empty()));
    INVARIANT(m_codeDepartement > 0);
}

}
