/**
 * \file TempsTesteur.cpp
 * \brief Test unitaire de la classe Temps.
 * A tester:
 *         Temps();
 *         Temps(const int p_heures, const int p_minutes, const int p_secondes);
 *         int reqHeures() const;
 *         void asgHeures(const int p_heures);
 *         int reqMinutes() const;
 *         void asgMinutes(const int p_minutes);
 *         int reqSecondes() const;
 *         void asgSecondes(const int p_secondes);
 *         void asgTemps(const int p_heures, const int p_minutes, const int p_secondes);
 *         std::string reqTempsFormate() const;
 *         static int reqNbTemps();
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Temps.h"
#include "ContratException.h"

using namespace std;
using namespace labo8;

/**
 * \brief Test du constructeur par défaut
 * 		  Cas valides: Defaut Création de deux dates par défaut, elles doivent être égales
 *		  Cas invalides: aucun d'identifié
 */
TEST (TempsTest, Constructeur_parametreParDefaut_tempsSysteme)
{
  Temps temps1;
  Temps temps2;

  ASSERT_EQ (temps1.reqHeures (), temps2.reqHeures ());
  EXPECT_EQ (temps1.reqMinutes (), temps2.reqMinutes ());
  EXPECT_EQ (temps1.reqSecondes (), temps2.reqSecondes ());
}

/**
 * \brief Test du constructeur avec paramètres
 * 	   Cas valides: constructeurParametreValide Création d'un objet Temps avec des valeurs valides
 * 	                et vérifiacation de tous les attributs.
 *	Cas invalides: constructeurParametreInvalide
 *		   heureInvalide l'heure est supérieure à 24.
 *		   minuteInvalide la minute est supérieure à 60.
 *		   secondeInvalide la seconde est supérieure à 60.
 */
TEST (TempsTest, constructeur_ParametresValides_objetValide)
{
  Temps t1 (10, 15, 45);
  ASSERT_EQ (10, t1.reqHeures ());
  ASSERT_EQ (15, t1.reqMinutes ());
  ASSERT_EQ (45, t1.reqSecondes ());
}

TEST (TempsTest, constructeur_ParametreHeureInvalide_PreconditionException)
{
  ASSERT_THROW (Temps t1 (70, 15, 55), PreconditionException)
          << "L'heure doit être comprise entre 0 et 24";
}

TEST (TempsTest, constructeur_parametreMinuteInvalide_PreconditionException)
{
  ASSERT_THROW (Temps t1 (10, 85, 55), PreconditionException)
          << "La minute doit être comprise entre 0 et 60";
}

TEST (TempsTest, constructeur_parametreSecondeInvalide_PreconditionException)
{
  ASSERT_THROW (Temps t1 (10, 25, 63), PreconditionException)
          << "La seconde doit être comprise entre 0 et 60";
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Temps
 */
class UnTemps : public ::testing::Test
{
public:

  UnTemps () :
  f_temps (13, 25, 35) { }
  Temps f_temps;
};

/**
 * \brief Test de la méthode int reqHeure() const;
 *        Cas valides: reqHeure vérifier le retour de l'heure
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, reqHeures_13)
{
  ASSERT_EQ (f_temps.reqHeures (), 13);
}

/**
 * \brief Test de la méthode int reqMinute() const;
 *        Cas valides: reqHeure vérifier le retour des minutes.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, reqMinutes_25)
{
  ASSERT_EQ (f_temps.reqMinutes (), 25);
}

/**
 * \brief Test de la méthode int reqSeconde() const;
 *        Cas valides: reqHeure vérifier le retour des secondes.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, reqSeconde_35)
{
  ASSERT_EQ (f_temps.reqSecondes (), 35);
}

/**
 * \brief Test de la méthode static int reqNbTemps()
 *        Cas valides: vérifier le retour du nombre d'objet Temps instancié.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, reqNbTemps_2)
{
  Temps t1;
  ASSERT_EQ (f_temps.reqNbTemps (), 2);
}

/**
 * \brief Assigner une nouvelle heure
 * 		  Cas valide : asgHeureValide assigner une heure valide
 * 		  Cas invalide : asgHeureInvalide assigner une heure supérieure à 24
 */
TEST_F (UnTemps, asgHeures_heuresValides_9)
{
  f_temps.asgHeures (9);
  ASSERT_EQ (f_temps.reqHeures (), 9);
}

TEST_F (UnTemps, asgHeures_heureInvalide_PreconditionException)
{
  ASSERT_THROW (f_temps.asgHeures (25), PreconditionException);
}

/**
 * \brief Assigner une nouvelle minute
 * 		  Cas valide : asgMinuteValide assigner une heure valide
 * 		  Cas invalide : asgMinuteInvalide assigner une heure supérieure à 60
 */
TEST_F (UnTemps, asgMinutes_minuteValide_PreconditionException)
{
  f_temps.asgMinutes (12);
  ASSERT_EQ (12, f_temps.reqMinutes ());
}

TEST_F (UnTemps, asgMinutes_minuteInvalide_PreconditionException)
{
  ASSERT_THROW (f_temps.asgMinutes (65), PreconditionException);
}

/**
 * \brief Assigner une nouvelle seconde
 * 		  Cas valide : asgSecondeValide assigner une heure valide.
 * 		  Cas invalide : asgSecondeInvalide assigner une heure supérieure à 24.
 */
TEST_F (UnTemps, asgSecondes_secondesValides_12)
{
  f_temps.asgSecondes (12);
  ASSERT_EQ (f_temps.reqSecondes (), 12);
}

TEST_F (UnTemps, asgSecondes_secondesInvalides_PreconditionException)
{
  ASSERT_THROW (f_temps.asgSecondes (65), PreconditionException);
}

/**
 * \brief Test de la méthode std::string reqTempsFormate()
 *        Cas valides: vérifier le retour des information sur l'objets Temps formaté.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, reqTempsFormate_formatConforme)
{
  ASSERT_EQ (f_temps.reqTempsFormate (), "1:25:35 PM");
}

/**
 * \brief Test de la méthode friend std::ostream& operator<<(std::ostream&, Temps&)
 *        Cas valides: vérifier si l'objet Temps va l'ostream.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, operatorSortie_formatConforme)
{
  ostringstream os;
  os << f_temps;

  ASSERT_EQ (os.str (), "1:25:35 PM");
}

/**
 * \brief Test de la méthode void asgTemps
 *        Cas valides: vérifier que la si méthode modifie correctement les attributs.
 *        Cas invalides: aucun.
 */
TEST_F (UnTemps, asgTemps_assignationConforme)
{
  f_temps.asgTemps (14, 59, 59);

  ASSERT_EQ (f_temps.reqHeures (), 14);
  ASSERT_EQ (f_temps.reqMinutes (), 59);
  ASSERT_EQ (f_temps.reqSecondes (), 59);
}

/**
 * \brief Test la méthode void tic()
 * 		  Cas valide: vérifier que la méthode incrémente correctement d´une seconde
 * 		  Cas invalide: aucun
 */
TEST_F (UnTemps, tic_secondesIncrementees)
{
  f_temps.tic ();
  ASSERT_EQ (f_temps.reqTempsFormate (), "1:25:36 PM");
}
