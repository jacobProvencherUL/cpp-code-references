/**
 * \file testeurRectangle.cpp
 * \brief Implantation des tests unitaires pour la classe Rectangle
 *        dérivée de Polygone
 * \author THE
 * \version 4.0 mise aux normes
 */

#include<gtest/gtest.h>
#include "Rectangle.h"

/**
 * \brief Test du Constructeur Rectangle(const Point& p1, const Point& p2)
 *        cas valide ConstructeurAvecParametre: Rectangle avec des arguments
 *        cas invalide Aucun d'identifié
 */
TEST (RectangleTest, Constructeur_AvecParametre_objetValide)
{
  Rectangle rectangleTest (Point (1, 2), Point (2, 3));
  ASSERT_EQ (rectangleTest.reqNbPoints (), 4);
  ASSERT_EQ (rectangleTest.reqPoint (1).reqx (), 1);
  ASSERT_EQ (rectangleTest.reqPoint (1).reqy (), 2);
  ASSERT_EQ (rectangleTest.reqPoint (2).reqx (), 2);
  ASSERT_EQ (rectangleTest.reqPoint (2).reqy (), 2);
  ASSERT_EQ (rectangleTest.reqPoint (3).reqx (), 2);
  ASSERT_EQ (rectangleTest.reqPoint (3).reqy (), 3);
  ASSERT_EQ (rectangleTest.reqPoint (4).reqx (), 1);
  ASSERT_EQ (rectangleTest.reqPoint (4).reqy (), 3);
}

/**
 * \brief Test de la méthode virtual void  afficher (std::ostream& os) const
 *        cas valide
 *        AfficherRectangle : Créer le flux d'affichage attendu et vérification s'il est le méme que celui construit par la méthode
 *        cas invalide Aucun d'identifié
 */
TEST (RectangleTest, AfficherRectangle_formatValide)
{
  Rectangle rectangleTest (Point (1, 2), Point (2, 3));
  std::ostringstream os_attendu;
  os_attendu << "Rectangle ";
  rectangleTest.reqPoint (1).afficher (os_attendu);
  os_attendu << " ";
  rectangleTest.reqPoint (2).afficher (os_attendu);
  os_attendu << " ";
  rectangleTest.reqPoint (3).afficher (os_attendu);
  os_attendu << " ";
  rectangleTest.reqPoint (4).afficher (os_attendu);

  std::ostringstream os_test;
  rectangleTest.afficher (os_test);

  ASSERT_EQ (os_attendu.str (), os_test.str ());
}

/**
 * \brief Test de la méthode 	virtual std::string reqNomFormate() const
 *        cas valide reqNomFormate : vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST (RectangleTest, reqNomFormate_formatValide)
{
  Rectangle rectangleTest (Point (1, 2), Point (2, 3));
  std::ostringstream os_attendu;
  os_attendu << "Polygone : " << "Rectangle";
  ASSERT_EQ (rectangleTest.reqNomFormate (), os_attendu.str ());
}
