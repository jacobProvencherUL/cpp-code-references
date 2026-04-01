/**
 * \file SphereTesteur.cpp
 * \brief Testeur de la classe Sphere
 *  A tester:
 *         Sphere();
 *         Sphere(double p_rayon);
 *         void asgRayon(double p_nouveauRayon);
 *         double reqRayon() const;
 *         double volumeSphere() const;
 *         std::string reqVolumeFormate() const;
 */

#include <gtest/gtest.h>
#include <cmath>

#include "Sphere.h"
#include "ContratException.h"

using namespace labo8;

/**
 * \brief Test du constructeur par défaut Sphere()
 *     Cas valide: par défaut le diametre doit etre nul.
 *     Cas invalide: aucun.
 */
TEST (SphereTest, Constructeur_ParDefaut_diametreNul)
{
  Sphere uneSphere;
  ASSERT_EQ (uneSphere.reqRayon (), 0);
}

/**
 * \brief Test du constructeur avec paramètre Sphere(double p_rayon)
 *     Cas valide:  rayon >= 0.
 *     Cas invalide: rayon < 0.
 */
TEST (SphereTest, Constructeur_RayonValide_rayon25)
{
  Sphere uneSphere (25);
  ASSERT_EQ (uneSphere.reqRayon (), 25);
}

TEST (SphereTest, Constructeur_RayonInvalide_PreconditionException)
{
  ASSERT_THROW (Sphere uneSphere (-25), PreconditionException) << "Une sphère ne doit pas accepter de rayon négatif";
}

/**
 * \brief Test fixture pour les méthodes de la classe Sphere.
 */
class SphereValide : public ::testing::Test
{
public:

  SphereValide () :
  f_sphere (2.5) { }

  Sphere f_sphere;
};

/**
 * \brief Test de la méthode void asgRayon(double p_nouveauRayon).
 *     Cas valide: nouveau rayon>=0.
 *     Cas invalide: nouveau rayon <0.
 */
TEST_F (SphereValide, asgRayon_rayonValide_objetValide)
{
  f_sphere.asgRayon (30);
  ASSERT_EQ (f_sphere.reqRayon (), 30);
}

TEST_F (SphereValide, asgRayon_rayonInvalide_PreconditionException)
{
  ASSERT_THROW (f_sphere.asgRayon (-25), PreconditionException) << "Une sphère ne doit pas accepter de rayon négatif";
}

/**
 * \brief Test de la méthode double reqRayon().
 *     Cas valide: vérifier le retour du rayon.
 *     Cas invalide: aucun.
 */
TEST_F (SphereValide, reqRayon_2_5)
{
  ASSERT_EQ (f_sphere.reqRayon (), 2.5);
}

/**
 * \brief Test de la méthode volumeSphere().
 *     Cas valide: calcul du volume de la sphère.
 *     Cas invalide: aucun.
 */
TEST_F (SphereValide, volumeSphere_résultatConforme)
{
  ASSERT_EQ (f_sphere.volumeSphere (), (4.0 / 3.0) * (3.14159 * pow (2.5, 3)));
}

/**
 * \brief Test de la méthode d'affichage reqVolumeFormate().
 *     Cas valide: vérifier la chaine retournée : le volume.
 *     Cas invalide: aucun.
 */
TEST_F (SphereValide, reqVolumeFormate_formatConforme)
{
  std::ostringstream os;
  os << "Le volume de la sphere de rayon " << f_sphere.reqRayon ()
          << " est : " << f_sphere.volumeSphere () << std::endl;

  ASSERT_EQ (os.str (), f_sphere.reqVolumeFormate ());
}
