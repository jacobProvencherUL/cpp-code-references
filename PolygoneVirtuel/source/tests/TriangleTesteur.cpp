/**
 * \file testeurTriangle.cpp
 * \brief Implantation des tests unitaires pour la classe Triangle dérivée de Polygone
 * \author THE
 * \version 4.0 mise aux normes
 */
#include<gtest/gtest.h>
#include "Triangle.h"

/**
 * \brief Test du Constructeur Triangle(const Point& p_point1, const Point& p_point2, const Point& p_point3);
 *
 * cas valide : <br>
 * ConstructeurAvecParametres: Triangle avec des arguments
 * <br>
 * cas invalide : <br>
 * Aucun d'identifié
 */
TEST (TriangleTest, Constructeur_AvecParametres_objetValide)
{
  Triangle triangleTest (Point (1, 2), Point (2, 2), Point (2, 1));
  ASSERT_EQ (triangleTest.reqNbPoints (), 3);
  ASSERT_EQ (triangleTest.reqPoint (1).reqx (), 1);
  ASSERT_EQ (triangleTest.reqPoint (1).reqy (), 2);
  ASSERT_EQ (triangleTest.reqPoint (2).reqx (), 2);
  ASSERT_EQ (triangleTest.reqPoint (2).reqy (), 2);
  ASSERT_EQ (triangleTest.reqPoint (3).reqx (), 2);
  ASSERT_EQ (triangleTest.reqPoint (3).reqy (), 1);
}

/**
 * \brief Test de la méthode virtual void  afficher (std::ostream& p_os) const
 *
 * cas valide : <br>
 * AfficherTriangle : Créer le flux d'affichage attendu et vérification s'il
 * est le même que celui construit par la méthode
 * <br>
 * cas invalide : <br>
 * Aucun d'identifié
 */
TEST (TriangleTest, Afficher_triangle_formatValide)
{
  Triangle triangleTest (Point (1, 2), Point (2, 2), Point (2, 1));
  std::ostringstream os_attendu;
  os_attendu << "Triangle " << 3 << " ";
  triangleTest.reqPoint (1).afficher (os_attendu);
  os_attendu << " ";
  triangleTest.reqPoint (2).afficher (os_attendu);
  os_attendu << " ";
  triangleTest.reqPoint (3).afficher (os_attendu);

  std::ostringstream os_test;
  triangleTest.afficher (os_test);

  ASSERT_EQ (os_test.str (), os_attendu.str ());
}

/**
 * \brief Test de la méthode 	virtual std::string reqNomFormate() const
 *
 * cas valide : <br>
 * reqNomFormate : vérification du retour
 * <br>
 * cas invalide : <br>
 * Aucun d'identifié
 */
TEST (TriangleTest, reqNomFormate_triangle_formatValide)
{
  Triangle triangleTest (Point (1, 2), Point (2, 2), Point (2, 1));
  std::ostringstream os_attendu;
  os_attendu << "Polygone : " << "Triangle";
  ASSERT_EQ (triangleTest.reqNomFormate (), os_attendu.str ());
  //	std::cout << t.reqNomFormate() << std::endl;
}
