/**
 * \file testeurCarre.cpp
 * \brief Implantation des tests unitaires pour la classe Carre
 *        dérivée de Polygone
 *  \author THE
 * \version 4.0 mise aux normes
 */

#include<gtest/gtest.h>
#include "Carre.h"

/**
 * \brief Test du Constructeur Carre(const Point& p_point, int p_dim);
 *        cas valide ConstructeurAvecParametre: Carre avec des arguments
 *        cas invalide Aucun d'identifié
 */
TEST (CarreTest, Constructeur_AvecParametre_objetValide)
{
  Carre carreTest (Point (1, 2), 4);
  ASSERT_EQ (carreTest.reqNbPoints (), 4);
  ASSERT_EQ (carreTest.reqPoint (1).reqx (), 1);
  ASSERT_EQ (carreTest.reqPoint (1).reqy (), 2);
  ASSERT_EQ (carreTest.reqPoint (2).reqx (), 5);
  ASSERT_EQ (carreTest.reqPoint (2).reqy (), 2);
  ASSERT_EQ (carreTest.reqPoint (3).reqx (), 5);
  ASSERT_EQ (carreTest.reqPoint (3).reqy (), 6);
  ASSERT_EQ (carreTest.reqPoint (4).reqx (), 1);
  ASSERT_EQ (carreTest.reqPoint (4).reqy (), 6);
}

/**
 * \brief Test de la méthode virtual void  afficher (std::ostream& p_os) const
 *        cas valide AfficherCarre : Créer le flux d'affichage attendu et vérification
 *        s'il est le même que celui construit par la méthode
 *        cas invalide Aucun d'identifié
 */
TEST (CarreTest, AfficherCarre_formatValide)
{
  Carre carreTest (Point (3, 2), 1);
  std::ostringstream os_attendu, os_test;
  os_attendu << "Carre ";
  carreTest.reqPoint (1).afficher (os_attendu);
  os_attendu << " ";
  carreTest.reqPoint (2).afficher (os_attendu);
  os_attendu << " ";
  carreTest.reqPoint (3).afficher (os_attendu);
  os_attendu << " ";
  carreTest.reqPoint (4).afficher (os_attendu);

  carreTest.afficher (os_test);

  ASSERT_EQ (os_test.str (), os_attendu.str ());
}

/**
 * \brief Test de la méthode 	virtual std::string reqNomFormate() const
 *        cas valide reqNomFormate : vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST (CarreTest, reqNomFormate_formatValide)
{
  Carre carreTest (Point (3, 2), 1);
  std::ostringstream os_attendu;
  os_attendu << "Polygone : " << "Carre";
  ASSERT_EQ (carreTest.reqNomFormate (), os_attendu.str ());
}
