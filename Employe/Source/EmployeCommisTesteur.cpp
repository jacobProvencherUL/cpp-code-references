/**
 * \file EmployeCommisTesteur.cpp
 * \brief Test unitaire de la classe EmployeCommission
 * \author etudiant
 * \date
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "EmployeCommission.h"

using namespace labo10;
using namespace std;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet EmployeCommission et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       salaire ==0
 *		       commission < 0
 *		       quantite < 0
 */
TEST (EmployeCommisTest, Constructeur_parametresDefaut_objetValide)
{
  EmployeCommission unEmployeCommisssion ("Jones", "Sue", util::Date (8, 11, 1975), 2, 200.0, 3.0, 150);
  ASSERT_EQ (unEmployeCommisssion.reqNomFamille (), "Jones");
  ASSERT_EQ (unEmployeCommisssion.reqPrenom (), "Sue");
  ASSERT_EQ (unEmployeCommisssion.reqDateNaissance (), util::Date (8, 11, 1975));
  ASSERT_EQ (unEmployeCommisssion.reqSalaire (), 200.0);
  ASSERT_EQ (unEmployeCommisssion.reqCommission (), 3.0);
  ASSERT_EQ (unEmployeCommisssion.reqQuantite (), 150);
  ASSERT_EQ (unEmployeCommisssion.reqCodeDepartement (), 2);

}
//cas invalide

TEST (EmployeCommisTest, Constructeur_SalaireInvalide_PreconditionException)
{
  ASSERT_THROW (EmployeCommission unEmployeCommisssion ("Jones", "Sue", util::Date (8, 11, 1975), 2, 0, 3.0, 150), PreconditionException);
}

TEST (EmployeCommisTest, Constructeur_CommissionInvalide_PreconditionException)
{
  ASSERT_THROW (EmployeCommission unEmployeCommisssion ("Jones", "Sue", util::Date (8, 11, 1975), 2, 200.0, -1, 150), PreconditionException);
}

TEST (EmployeCommisTest, Constructeur_QuantiteInvalide_PreconditionException)
{
  ASSERT_THROW (EmployeCommission unEmployeCommisssion ("Jones", "Sue", util::Date (8, 11, 1975), 2, 200.0, 3.0, -1), PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnEmployeCommission : public ::testing::Test
{
public:

  UnEmployeCommission () :
  f_employeCommis ("Sue", "Jones", util::Date (8, 11, 1975), 2, 200.0, 3.0, 150) { }
  ;
  EmployeCommission f_employeCommis;
};

/**
 * \brief Test de la méthode reqSalaire()
 *     Cas valide: vérifier le retour du salaire de l'employe
 *     Cas invalide: aucun
 */
TEST_F (UnEmployeCommission, reqSalaire_200)
{
  ASSERT_EQ (f_employeCommis.reqSalaire (), 200.0);
}

/**
 * \brief Test de la méthode reqCommission()
 *     Cas valide: vérifier le retour de la commission de l'employe
 *     Cas invalide: aucun
 */
TEST_F (UnEmployeCommission, reqCommission_3)
{
  ASSERT_EQ (f_employeCommis.reqCommission (), 3.0);
}

/**
 * \brief Test de la méthode reqQuantite()
 *     Cas valide: vérifier le retour de la quantité de l'employe
 *     Cas invalide: aucun
 */
TEST_F (UnEmployeCommission, reqQuantite_150)
{
  ASSERT_EQ (f_employeCommis.reqQuantite (), 150);
}

/**
 * \brief Test de la méthode ajusterSalaire()
 *     Cas valide: ajuste le salaire de travail de l'employé
 *     Cas invalide: ajuster le salaire par une valeur invalide
 */
TEST_F (UnEmployeCommission, asgSalaire_salaireValide_salaireModifie)
{
  f_employeCommis.asgSalaire (250);
  ASSERT_EQ (f_employeCommis.reqSalaire (), 250);
}
//cas invalide

TEST_F (UnEmployeCommission, asgSalaire_salaireInvalide_PreconditionException)
{
  ASSERT_THROW (f_employeCommis.asgSalaire (0), PreconditionException);
}

/**
 * \brief Test de la méthode ajusterCommission()
 *     Cas valide: ajuste la commission de l'employé
 *     Cas invalide: ajuster la commission par une valeur invalide de commission
 */
TEST_F (UnEmployeCommission, asgCommission_CommissionValide_commissionModifiee)
{
  f_employeCommis.asgCommission (4.0);
  ASSERT_EQ (f_employeCommis.reqCommission (), 4.0);
}
//cas invalide

TEST_F (UnEmployeCommission, asgCommission_CommissionInvalide_PreconditionException)
{
  ASSERT_THROW (f_employeCommis.asgCommission (-1), PreconditionException);
}

/**
 * \brief Test de la méthode ajusterQuantite()
 *     Cas valide: ajuste la quantité de l'employé
 *     Cas invalide: ajuster la quantité par une valeur invalide
 */
TEST_F (UnEmployeCommission, asgQuantite_QuantiteValide_200)
{
  f_employeCommis.asgQuantite (200);
  ASSERT_EQ (f_employeCommis.reqQuantite(),200);
  
}
//cas invalide

TEST_F (UnEmployeCommission, asgQuantite_QuantiteInvalide_PreconditionException)
{
  ASSERT_THROW (f_employeCommis.asgQuantite (-1), PreconditionException);
}

/**
 * \brief Test de la méthode gain()
 *     Cas valide: vérifier le retour du gain de l'employé
 *     Cas invalide: aucun
 */
TEST_F (UnEmployeCommission, gains_650)
{
  ASSERT_EQ ( f_employeCommis.gains (),650);
}

/**
 * \brief Test de la méthode std::string reqEmployeFormate()
 *        Cas valides: vérifier le retour des information sur l'objets Employe commission formaté
 *        Cas invalides: aucun
 */
TEST_F (UnEmployeCommission, reqEmployeFormate_formatConforme)
{
  std::ostringstream os;
  os << std::endl << " Employé à commission: ";
  os << f_employeCommis.reqPrenom () << " " << f_employeCommis.reqNomFamille ();
  ASSERT_EQ (os.str (), f_employeCommis.reqEmployeFormate ());
}
