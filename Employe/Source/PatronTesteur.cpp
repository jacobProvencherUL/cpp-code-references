/**
 * \file PatronTesteur.cpp
 * \brief Test unitaire de la classe Patron
 * \author etudiant
 * \date
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Patron.h"

using namespace labo10;
using namespace std;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Patron et vérification de l'assignation de tous les attributs
 *		  Cas invalides: Salaire hebdo = 0.
 */
TEST(Patron,ConstructeurDefaut)
{
	Patron unPatron( "Jean", "Soucy", util::Date(24,2,1977), 1, 800.00);
	ASSERT_EQ("Jean",unPatron.reqNomFamille());
	ASSERT_EQ("Soucy",unPatron.reqPrenom());
	ASSERT_EQ(util::Date(24, 2, 1977),unPatron.reqDateNaissance());
	ASSERT_EQ(800.0,unPatron.gains());
	ASSERT_EQ(1,unPatron.reqCodeDepartement());

}
//cas invalide
TEST(Patron,ConstructeurSalaireHebdoInvalide)
{
	ASSERT_THROW(Patron unPatron( "Jean", "Soucy", util::Date(24,2,1977), 1, 0);,PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class PatronTest: public ::testing::Test
{
public:
	PatronTest() :
		unPatron( "Jean", "Soucy", util::Date(24,2,1977), 1, 800.00)
	{}
	;
	Patron unPatron;
};
/**
 * \brief Test de la méthode ajusterSalaireHebdo()
 *     Cas valide: ajuste le salaire hebo de travail de l'employé
 *     Cas invalide: ajuster le salaire hebdo par une valeur invalide
 */
TEST_F(PatronTest, ajusterSalaireHebdoValide)
{
	unPatron.asgSalaireHebdo(700.0);
}
//cas invalide
TEST_F(PatronTest, ajusterSalaireHebdoInvalide)
{
	ASSERT_THROW(unPatron.asgSalaireHebdo(0),PreconditionException);
}

/**
 * \brief Test de la méthode gain()
 *     Cas valide: vérifier le retour du gain de l'employé
 *     Cas invalide: aucun
 */
TEST_F(PatronTest,gains)
{
	ASSERT_EQ(800,unPatron.gains());
}

/**
 * \brief Test de la méthode std::string reqEmployeFormate();
 *        Cas valides: vérifier le retour des information sur l'objets Employe Patron formaté
 *        Cas invalides: aucun
 */
TEST_F(PatronTest,reqEmployeFormate)
{
	std::ostringstream os;
	os << std::endl << " Patron : ";
	os << unPatron.reqPrenom()<< " " << unPatron.reqNomFamille();
	ASSERT_EQ(os.str(),unPatron.reqEmployeFormate());
}
