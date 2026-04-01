/**
 * \file testeurPolygone.cpp
 * \brief Implantation des tests unitaires de la classe Polygone
 *        Polygone étant une classe abstraite, on crée une classe concrète
 *        dérivée de cette classe afin de pouvoir effectuer les tests
 * \author administrateur
 * \version 3.0 mise aux normes
 */

#include<gtest/gtest.h>
#include "Polygone.h"
#include "Point.h"
using namespace std;

/**
 * \class PolygoneDeTest
 * \brief classe de test permettant de tester la classe abstraite Polygone
 */
class PolygoneDeTest : public Polygone
{
public:

  PolygoneDeTest (int nbSommets) :
  Polygone (nbSommets) { }; //instancie un objet Polygone

  //méthodes déclarées virtuelles pure dans la classe de base Polygone
  //elles doivent être implémentées dans toute classe dérivée

  void
  afficher (std::ostream& os) const override {
    //définie pour que ceal compile
    //rien à tester ici car la méthode n'est pas définie dans Polygone
  };

  std::string
  reqNomFormate () const override
  {
    return Polygone::reqNomFormate ();
  }
  ;
};

/**
 * \brief Test du Constructeur Polygone(int nbSommets)
 *        cas valide:
 *         ConstructeurAvecParametre :	Polygone à 4 sommets, i.e la taille du vecteur doit être 4,
 *         les Points sont construits par défaut donc à coordonées 0
 *        cas invalide Aucun d'identifié
 */
TEST (PolygoneTest, Constructeur_Avec4sommets_objetValide)
{
  PolygoneDeTest polygoneTest (4);
  ASSERT_EQ (polygoneTest.reqNbPoints (), 4);
  ASSERT_EQ (polygoneTest.reqPoint (1).reqx (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (2).reqx (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (3).reqx (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (4).reqx (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (1).reqy (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (2).reqy (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (3).reqy (), 0);
  ASSERT_EQ (polygoneTest.reqPoint (4).reqy (), 0);
}

/**
 * \brief Test de l'assignation des points
 * cas valides:
 * assignation d'un point
 * assignation de 4 points
 * cas invalide Aucun d'identifié
 */
TEST (PolygoneTest, asgPoint_1point_objetValide)
{
  PolygoneDeTest polygoneTest (4);
  Point unPoint (1, 1);
  polygoneTest.asgPoint (1, unPoint);
  ASSERT_EQ (polygoneTest.reqPoint (1), unPoint);
}

TEST (PolygoneTest, asgPoint_4points_objetValide)
{
  PolygoneDeTest polygoneTest (4);
  Point point1 (1, 1);
  Point point2 (1, 2);
  Point point3 (2, 1);
  Point point4 (2, 2);
  polygoneTest.asgPoint (1, point1);
  polygoneTest.asgPoint (2, point2);
  polygoneTest.asgPoint (3, point3);
  polygoneTest.asgPoint (4, point4);
  ASSERT_EQ (4, polygoneTest.reqNbPoints ());
  ASSERT_EQ (polygoneTest.reqPoint (1), point1);
  ASSERT_EQ (polygoneTest.reqPoint (2), point2);
  ASSERT_EQ (polygoneTest.reqPoint (3), point3);
  ASSERT_EQ (polygoneTest.reqPoint (4), point4);
}

/**
 * \class UnPolygone
 * \brief Fixture  UnPolygone pour la création d'un objet Polygone pour les tests
 */
class UnPolygone : public ::testing::Test
{
public:

  UnPolygone () :
  t_polygone (4)
  {
    t_polygone.asgPoint (1, Point (1, 1));
    t_polygone.asgPoint (2, Point (1, 2));
    t_polygone.asgPoint (3, Point (2, 1));
    t_polygone.asgPoint (4, Point (2, 2));
  }
  ;

  PolygoneDeTest t_polygone;
};
//[1,1] [1,2]
//[2,1] [2,2]

/**
 * \brief Test de la méthode Point reqPoint(int pos) const
 * cas valide reqPoint : 
 * Polygone à 4 sommets, vérification du retour 
 * du premier
 * arbitraire, du troisième
 * du dernier
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, ReqPoint_premierPoint_coordonneesValides)
{
  ASSERT_EQ (t_polygone.reqPoint (1).reqx (), 1);
  ASSERT_EQ (t_polygone.reqPoint (1).reqy (), 1);
}

TEST_F (UnPolygone, ReqPoint_troisiemePoint_coordonneesValides)
{
  ASSERT_EQ (t_polygone.reqPoint (3).reqx (), 2);
  ASSERT_EQ (t_polygone.reqPoint (3).reqy (), 1);
}

TEST_F (UnPolygone, ReqPoint_dernierPointcoordonneesValides)
{
  ASSERT_EQ (t_polygone.reqPoint (t_polygone.reqNbPoints ()).reqx (), 2);
  ASSERT_EQ (t_polygone.reqPoint (t_polygone.reqNbPoints ()).reqy (), 2);
}

/**
 * \brief Test de la méthode void deplacer(double dx, double dy)
 *        cas valide:
 *         DeplacerPolygone : Polygone à 4 sommets, les sommets sont tous à 0
 *         Déplacement et vérification de l'incrémentation des reqx et reqy des 4 sommets
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, DeplacerPolygone_1_1virgule5_coordonneesIncrementees)
{

  t_polygone.deplacer (1.0, 1.5);
  EXPECT_EQ (t_polygone.reqPoint (1).reqx (), 2.0);
  EXPECT_EQ (t_polygone.reqPoint (1).reqy (), 2.5);
  EXPECT_EQ (t_polygone.reqPoint (2).reqx (), 2.0);
  EXPECT_EQ (t_polygone.reqPoint (2).reqy (), 3.5);
  EXPECT_EQ (t_polygone.reqPoint (3).reqx (), 3.0);
  EXPECT_EQ (t_polygone.reqPoint (3).reqy (), 2.5);
  EXPECT_EQ (t_polygone.reqPoint (4).reqx (), 3.0);
  EXPECT_EQ (t_polygone.reqPoint (4).reqy (), 3.5);
}

/**
 * \brief Test de la méthode void agrandir(const Point& centre, double facteur)
 *        cas valide:
 *	 	 	 AgrandirPolygone : Polygone à 4 sommets, agrandissement et vérification de mise à jour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, AgrandirPolygone_coordonneesChangees)
{
  t_polygone.agrandir (Point (2, 2), 2);
  EXPECT_EQ (t_polygone.reqPoint (1).reqx (), 0.0);
  EXPECT_EQ (t_polygone.reqPoint (1).reqy (), 0.0);
  EXPECT_EQ (t_polygone.reqPoint (2).reqx (), 0.0);
  EXPECT_EQ (t_polygone.reqPoint (2).reqy (), 2.0);
  EXPECT_EQ (t_polygone.reqPoint (3).reqx (), 2.0);
  EXPECT_EQ (t_polygone.reqPoint (3).reqy (), 0.0);
  EXPECT_EQ (t_polygone.reqPoint (4).reqx (), 2.0);
  EXPECT_EQ (t_polygone.reqPoint (4).reqy (), 2.0);
}

/**
 * \brief Test de la méthode double circonference() const
 *        cas valide:
 *	 	 	 CirconferencePolygone : Polygone à 4 sommets, vérification de la circonférence
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, CirconferencePolygone_circonferenceValide)
{
  ASSERT_FLOAT_EQ (t_polygone.circonference (), 4.8284273);
}

/**
 * \brief Test de la méthode 	virtual std::string reqNomFormate() const=0;
 *        cas valide CirconferencePolygone : Polygone à 4 sommets, vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, reqNomFormate_formatValide)
{
  ASSERT_EQ (t_polygone.reqNomFormate (), "Polygone : ");
}

/**
 * \brief Test de la méthode int reqNbPoints() const
 *        cas valide GetNbPoints : Polygone par défaut à 4 sommets, vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, ReqNbPoints_nombreValide)
{
  ASSERT_EQ (t_polygone.reqNbPoints (), 4);
}

/**
 * \brief Test de la méthode void asgPoint(int pos, const Point& p)
 *        cas valide asgPoint : Polygone par défaut à 4 sommets, vérification de l'assignation
 * du premier
 * arbitraire, du troisième
 * du dernier
 *        cas invalide Aucun d'identifié
 */
TEST_F (UnPolygone, AsgPoint_premierPointmoins1moins2_coordonneesChangees)
{
  t_polygone.asgPoint (1, Point (-1, -2));
    ASSERT_EQ (t_polygone.reqPoint (1).reqx (), -1);
    ASSERT_EQ (t_polygone.reqPoint (1).reqy (), -2);
}
TEST_F (UnPolygone, AsgPoint_troisiemePointmoins1moins2_coordonneesChangees)
{
  t_polygone.asgPoint (3, Point (-1, -2));
    ASSERT_EQ (t_polygone.reqPoint (3).reqx (), -1);
    ASSERT_EQ (t_polygone.reqPoint (3).reqy (), -2);
}
TEST_F (UnPolygone, AsgPoint_dernierPointmoins1moins2_coordonneesChangees)
{
  t_polygone.asgPoint (t_polygone.reqNbPoints (), Point (-1, -2));
    ASSERT_EQ (t_polygone.reqPoint (t_polygone.reqNbPoints ()).reqx (), -1);
    ASSERT_EQ (t_polygone.reqPoint (t_polygone.reqNbPoints ()).reqy (), -2);
}

