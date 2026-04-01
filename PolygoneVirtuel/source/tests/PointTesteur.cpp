/**
 * \file testeurPoint.cpp
 *	Implantation des tests unitaires pour la classe Point
 *  \author Administrateur
 * \version 4.0 mise aux normes
 */

#include<gtest/gtest.h>
#include "Point.h"

/**
 * \brief Test du Constructeur Point(double reqx=0, double reqy=0)
 *        cas valide
 *         ConstructeurParDefaut :	Point par défaut reqx=0, reqy=0
 *         ConstructeurAvecParametre: Point avec des arguments
 *        cas invalide Aucun d'identifié
 */

TEST (PointTest, constructeur_ParametreParDefaut_coordonneeszerozero)
{
  Point pointTest;
  ASSERT_EQ (pointTest.reqx (), 0);
  ASSERT_EQ (pointTest.reqy (), 0);
}

TEST (PointTest, constructeur_AvecParametre_objetValide)
{
  Point pointTest (2.5, 3.4);
  ASSERT_EQ (pointTest.reqx (), 2.5);
  ASSERT_EQ (pointTest.reqy (), 3.4);
}

/**
 * \class UnPoint
 * \brief fixture pour créer un point pour les tests
 */

class UnPoint : public ::testing::Test
{
public:

  UnPoint () :
  f_point (2.5, 3.4) { }
  ;

  Point f_point;
};

/**
 * \brief Test de la méthode void deplacer(double p_dx, double p_dy)
 *        cas valide DeplacerPoint : Point déplacé, vérification du changement des coordonnées
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, deplacerPoint_1_2virgule1_coordonneesChangees)
{
  f_point.deplacer (1, 2.1);
  ASSERT_EQ (f_point.reqx (), 3.5);
  ASSERT_EQ (f_point.reqy (), 5.5);
}

/**
 * \brief Test de la méthode void agrandir(const Point& p_centre, double p_facteur)
 *        cas valide AgrandirPoint : Point agrandi, vérification du changement des coordonnées
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, agrandir_Point_facteur2_coordonneesChangees)
{
  f_point.agrandir (Point (1, 1), 2);
  ASSERT_EQ (f_point.reqx (), 4);
  ASSERT_EQ (f_point.reqy (), 5.8);
}

/**
 * \brief Test de la méthode void afficher (std::ostream& p_os) const
 *        cas valide AfficherPoint : Créer le flux d'affichage attendu et vérification
 *        s'il est le même que celui construit par la méthode
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, afficher_Point_formatValide)
{
  std::ostringstream os1, os2;
  os1 << "[" << 2.5 << "," << 3.4 << "]";
  f_point.afficher (os2);

  ASSERT_EQ (os2.str (), os1.str ());
}

/**
 * \brief Test de la méthode double reqx() const
 *        cas valide ReqX : Vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, reqX_coordonneeValide2virgule5)
{
  ASSERT_EQ (f_point.reqx (), 2.5);
}

/**
 * \brief Test de la méthode double reqy() const
 *        cas valide ReqY : Vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, reqY_coordonneeValide3virgule4)
{
  ASSERT_EQ (f_point.reqy (), 3.4);
}

/**
 * \brief Test de la méthode static double reqDistance (const Point& p_point1, const Point& p_point2);
 *        cas valide ReqDistance : Vérification de la distance retournée
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPoint, reqDistance_distanceValide2virgule0518284)
{
  Point p (1, 2);
  ASSERT_FLOAT_EQ (Point::reqDistance (f_point, p), 2.0518284);
}
