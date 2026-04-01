/**
 * \file EmployeHoraireTesteur.cpp
 * \brief Test unitaire de la classe EmployeHoraire
 * \author etudiant
 * \date
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "EmployeHoraire.h"

using namespace labo10;
using namespace std;

/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet EmployeHoraire et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       TauxHoraire = 0
 *		       Heure = 0
 */
TEST(EmployeHoraire,ConstructeurDefaut)
{
	EmployeHoraire unEmployeHoraire( "Price", "Karen", util::Date(29, 12, 1980), 1, 13.75, 40);
	ASSERT_EQ("Price",unEmployeHoraire.reqNomFamille());
	ASSERT_EQ("Karen",unEmployeHoraire.reqPrenom());
	ASSERT_EQ(util::Date(29, 12, 1980),unEmployeHoraire.reqDateNaissance());
	ASSERT_EQ(13.75,unEmployeHoraire.reqTauxHoraire());
	ASSERT_EQ(40,unEmployeHoraire.reqHeure());

}
// cas invalide
TEST(EmployeHoraire,ConstructeurTauxHoraireInvalide)
{
	ASSERT_THROW(EmployeHoraire unEmployeHoraire( "Price", "Karen", util::Date(29, 12, 1980), 1, 0, 40),PreconditionException);
}
TEST(EmployeHoraire,ConstructeurHeureInvalide)
{
	ASSERT_THROW(EmployeHoraire unEmployeHoraire( "Price", "Karen", util::Date(29, 12, 1980), 1, 13.75, 0),PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnEmployeHoraire: public ::testing::Test
{
public:
	UnEmployeHoraire() :
		unEmployeHoraire( "Karen", "Price", util::Date(29, 12, 1980), 1, 13.75, 40)
	{}
	;
	EmployeHoraire unEmployeHoraire;
};
/**
 * \test Test de la méthode reqTauxHoraire()
 *
 *     Cas valide: vérifier le retour du taux horaire de l'employé
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeHoraire, reqTauxHoraire)
{
	ASSERT_EQ(13.75,unEmployeHoraire.reqTauxHoraire());
}
/**
 * \test Test de la méthode reqHeure()
 *
 *     Cas valide: vérifier le retour des heures de travail de l'employé
 *     Cas invalide: aucun
 */
TEST_F(UnEmployeHoraire, reqHeure)
{
	ASSERT_EQ(40,unEmployeHoraire.reqHeure());
}
/**
 * \test Test de la méthode ajusterPaie()
 *
 *     Cas valide: ajuste la paie de l'employé
 *     Cas invalide: ajuster la paie avec une valeur invalide.
 */
TEST_F(UnEmployeHoraire, ajusterPaieValide)
{
	unEmployeHoraire.asgPaie(15);
}
//cas invalide
TEST_F(UnEmployeHoraire, ajusterPaieInvalide)
{
	ASSERT_THROW(unEmployeHoraire.asgPaie(0),PreconditionException);
}
/**
 * \test Test de la méthode ajusterHeure()
 *
 *     Cas valide: ajuste les heures de travail de l'employé
 *     Cas invalide: ajuster les heures par une valeur invalide.
 */
TEST_F(UnEmployeHoraire, ajusterHeureValide)
{
	unEmployeHoraire.asgHeures(35);
}
//cas invalide
TEST_F(UnEmployeHoraire, ajusterHeureInvalide)
{
	ASSERT_THROW(unEmployeHoraire.asgHeures(0),PreconditionException);
}
/**
 * \test Test de la méthode gain()
 *
 *     Cas valide: vérifier le retour du gain de l'employé
 *     Cas invalide: aucun.
 */
TEST_F(UnEmployeHoraire,gains)
{
	ASSERT_EQ(550,unEmployeHoraire.gains());
}

/**
 * \test Test de la méthode std::string reqEmployeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Employe horaire formaté
 *        Cas invalides: aucun
 */
TEST_F(UnEmployeHoraire,reqEmployeFormate)
{
	std::ostringstream os;
	os << std::endl << " Employé horaire : ";
	os << unEmployeHoraire.reqPrenom()<< " " << unEmployeHoraire.reqNomFamille();
	ASSERT_EQ(os.str(),unEmployeHoraire.reqEmployeFormate());
}
