/**
 * \file Employe.cpp
 * \brief Implémentation de la classe de base abstraite Employe.
 *        Note: aucune définition de la méthode virtuelle pure.
 * \author etudiant
 * \version 0.1
 * \date
 */

#include "Employe.h"
#include <iostream>
#include "ContratException.h"

using namespace std;
namespace labo9
{


  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Employe à partir de valeurs passées en paramètres.
   * \param[in] p_nom est un string qui représente le nom de l'employé.
   * \param[in] p_prenom est un string qui représente le prénom de l'employé.
   * \param[in] p_dateNaissance est une date qui représente la date de naissance de l'employé.
   * \param[in] p_codeDepartement est un entier qui représente le code départemental de l'employé
   * \pre p_nom non vide
   * \pre p_prenom non vide
   * \pre p_codeDepartement supérieur à 0
   * \post m_nomFamille prend la valeur de p_nom
   * \post m_prenom prend la valeur de p_prenom
   * \post m_codeDepartement prend la valeur de p_codeDepartement
   * \post m_dateNaissance prend la valeur de p_dateNaissance
   */
  Employe::Employe (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement) :
  m_nomFamille (p_nom), m_prenom (p_prenom), m_dateNaissance (p_dateNaissance.reqJour (), p_dateNaissance.reqMois (),
                                                              p_dateNaissance.reqAnnee ()), m_codeDepartement (
                                                                                                               p_codeDepartement)
  {
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (!p_prenom.empty ());
    PRECONDITION (p_codeDepartement > 0);

    POSTCONDITION (m_nomFamille == p_nom);
    POSTCONDITION (m_prenom == p_prenom);
    POSTCONDITION (m_dateNaissance == p_dateNaissance);
    POSTCONDITION (m_codeDepartement == p_codeDepartement);
    INVARIANTS ();
  }


  /**
   * \brief Accesseur prénom de l'employé
   * \return le prénom
   */
  const std::string& Employe::reqPrenom () const
  {
    return m_prenom;
  }


  /**
   * \brief Accesseur nom de l'employé
   * \return le nom de famille
   */
  const std::string& Employe::reqNomFamille () const
  {
    return m_nomFamille;
  }


  /**
   * \brief Accesseur date de naissance de l'employé
   * \return la date de naissance
   */
  const util::Date& Employe::reqDateNaissance () const
  {
    return m_dateNaissance;
  }


  /**
   * \brief Accesseur code département de l'enployé
   * \return le code du departement
   */
  int Employe::reqCodeDepartement () const
  {
    return m_codeDepartement;
  }


  /**
   * \brief Lit la paie de l'employé.
   *         methode virtuelle
   * \return les gains de l'employé
   */
  double Employe::gains () const
  {
    return 0;
  }


  /**
   * \brief Affichage du nom et prénom de l'employé.
   * \return Le nom et prénom de l'employé.
   */
  std::string Employe::reqEmployeFormate () const
  {
    return m_prenom + " " + m_nomFamille;
  }


  /**
   * \brief Vérifier les invariants de la classe
   */
  void Employe::verifieInvariant () const
  {
    INVARIANT (!(m_nomFamille.empty ()));
    INVARIANT (!(m_prenom.empty ()));
    INVARIANT (m_codeDepartement > 0);
  }

}
