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

using namespace labo9;
using namespace std;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet EmployeCommission et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       salaire ==0
 *		       commission < 0
 *		       quantite < 0
 */
TEST(EmployeCommis,ConstructeurDefaut)
{
	EmployeCommission unEmployeCommisssion( "Jones", "Sue", util::Date(8, 11, 1975), 2, 200.0, 3.0, 150);
	ASSERT_EQ("Jones",unEmployeCommisssion.reqNomFamille());
	ASSERT_EQ("Sue",unEmployeCommisssion.reqPrenom());
	ASSERT_EQ(util::Date(8, 11, 1975),unEmployeCommisssion.reqDateNaissance());
	ASSERT_EQ(200.0,unEmployeCommisssion.reqSalaire());
	ASSERT_EQ(3.0,unEmployeCommisssion.reqCommission());
	ASSERT_EQ(150,unEmployeCommisssion.reqQuantite());
	ASSERT_EQ(2,unEmployeCommisssion.reqCodeDepartement());

}
//cas invalide
TEST(EmployeCommis,ConstructeurSalaireInvalide)
{
	ASSERT_THROW(EmployeCommission unEmployeCommisssion( "Jones", "Sue", util::Date(8, 11, 1975), 2, 0, 3.0, 150),PreconditionException);
}
TEST(EmployeCommis,ConstructeurCommissionInvalide)
{
	ASSERT_THROW(EmployeCommission unEmployeCommisssion( "Jones", "Sue", util::Date(8, 11, 1975), 2, 200.0, -1, 150),PreconditionException);
}
TEST(EmployeCommis,ConstructeurQuantiteInvalide)
{
	ASSERT_THROW(EmployeCommission unEmployeCommisssion( "Jones", "Sue", util::Date(8, 11, 1975), 2, 200.0, 3.0, -1),PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnEmployeCommission: public ::testing::Test
{
public:
	UnEmployeCommission() :
		unEmployeCommis( "Sue", "Jones", util::Date(8, 11, 1975), 2, 200.0, 3.0, 150)
	{}
	;
	EmployeCommission unEmployeCommis;
};
/**
 * \brief Test de la méthode reqSalaire()
 *     Cas valide: vérifier le retour du salaire de l'employe
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeCommission, reqSalaire)
{
	ASSERT_EQ(200.0,unEmployeCommis.reqSalaire());
}
/**
 * \brief Test de la méthode reqCommission()
 *     Cas valide: vérifier le retour de la commission de l'employe
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeCommission, reqCommission)
{
	ASSERT_EQ(3.0,unEmployeCommis.reqCommission());
}
/**
 * \brief Test de la méthode reqQuantite()
 *     Cas valide: vérifier le retour de la quantité de l'employe
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeCommission, reqQuantite)
{
	ASSERT_EQ(150,unEmployeCommis.reqQuantite());
}
/**
 * \brief Test de la méthode ajusterSalaire()
 *     Cas valide: ajuste le salaire de travail de l'employé
 *     Cas invalide: ajuster le salaire par une valeur invalide
 */
TEST_F(UnEmployeCommission, ajusterSalaireValide)
{
	unEmployeCommis.asgSalaire(250);
}
//cas invalide
TEST_F(UnEmployeCommission, ajusterSalaireInvalide)
{
	ASSERT_THROW(unEmployeCommis.asgSalaire(0),PreconditionException);
}

/**
 * \brief Test de la méthode ajusterCommission()
 *     Cas valide: ajuste la commission de l'employé
 *     Cas invalide: ajuster la commission par une valeur invalide de commission
 */
TEST_F(UnEmployeCommission, ajusterCommissionValide)
{
	unEmployeCommis.asgCommission(4.0);
}
//cas invalide
TEST_F(UnEmployeCommission, ajusterCommissionInvalide)
{
	ASSERT_THROW(unEmployeCommis.asgCommission(-1),PreconditionException);
}

/**
 * \brief Test de la méthode ajusterQuantite()
 *     Cas valide: ajuste la quantité de l'employé
 *     Cas invalide: ajuster la quantité par une valeur invalide
 */
TEST_F(UnEmployeCommission, ajusterQuantiteValide)
{
	unEmployeCommis.asgQuantite(200);
}
//cas invalide
TEST_F(UnEmployeCommission, ajusterQuantiteInvalide)
{
	ASSERT_THROW(unEmployeCommis.asgQuantite(-1),PreconditionException);
}

/**
 * \brief Test de la méthode gain()
 *     Cas valide: vérifier le retour du gain de l'employé
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeCommission,gains)
{
	ASSERT_EQ(650,unEmployeCommis.gains());
}

/**
 * \brief Test de la méthode std::string reqEmployeFormate()
 *        Cas valides: vérifier le retour des information sur l'objets Employe commission formaté
 *        Cas invalides: aucun
 */
TEST_F(UnEmployeCommission,reqEmployeFormate)
{
	std::ostringstream os;
	os << std::endl << " Employé à commission: ";
	os << unEmployeCommis.reqPrenom()<< " " << unEmployeCommis.reqNomFamille();
	ASSERT_EQ(os.str(),unEmployeCommis.reqEmployeFormate());
}
