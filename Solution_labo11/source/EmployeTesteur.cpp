/**
 * \file EmployeTesteur.cpp
 * \brief Test unitaire de la classe de base Employe
 * \author etudiant
 * \date
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Employe.h"

using namespace std;
using namespace labo10;

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet employe et verification de l’assignation de tous les attributs
 * 		cas invalides:
 * 			Nom vide
 * 			Prenom vide
 * 			CodeDepartement < 0
*/
TEST(Employe, Constructeur){
	Employe unEmploye("Price", "Karen", util::Date(15,06,1975), 1);
	ASSERT_EQ("Price", unEmploye.reqNomFamille());
	ASSERT_EQ("Karen", unEmploye.reqPrenom());
	ASSERT_EQ(util::Date(15,06,1975), unEmploye.reqDateNaissance());
	ASSERT_EQ(1, unEmploye.reqCodeDepartement());
}
//Cas invalide
TEST(Employe, ConstructeurInvalideNom){
	ASSERT_THROW(Employe unEmploye("", "Karen", util::Date(15,06,1975), 1), PreconditionException);
}
TEST(Employe, ConstructeurInvalidePrenom){
	ASSERT_THROW(Employe unEmploye("Price", "", util::Date(15,06,1975), 1), ContratException);
}
TEST(Employe, ConstructeurInvalideCodeDepartement){
	ASSERT_THROW(Employe unEmploye("Price", "Karen", util::Date(15,06,1975), -1), ContratException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class unEmploye: public ::testing::Test{
public:
	unEmploye():
		employe("Soucy", "Jean", util::Date(24,2,1977), 1)
	{}
	Employe employe;
};

/**
 * \test Test de la méthode reqNomFamille()
 * 		Cas valide: vérifier le retour du nom de famille
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, reqNomFamille){
	ASSERT_EQ("Soucy", employe.reqNomFamille());
}

/**
 * \test Test de la méthode reqPrenom()
 * 		Cas valide: vérifier le retour du prénom de l'employé
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, reqPrenom){
	ASSERT_EQ("Jean", employe.reqPrenom());
}

/**
 * \test Test de la méthode reqDateNaissance()
 * 		Cas valide: vérifier le retour de la date de naissance de l'employé
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, reqDateNaissance){
	ASSERT_EQ(util::Date(24,2,1977), employe.reqDateNaissance());
}

/**
 * \test Test de la méthode reqCodeDepartement()
 * 		Cas valide: vérifier le retour du code département de l'employé
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, reqCodeDepartement){
	ASSERT_EQ(1, employe.reqCodeDepartement());
}

/**
 * \test Test de la méthode gains()
 * 		Cas valide: vérifier le retour du gain de l'employé
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, gains){
	ASSERT_EQ(0.0, employe.gains());
}

/**
 * \test Test de la méthode std::string reqEmployeFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet Employe formaté
 * 		Cas invalide: aucun
 */
TEST_F(unEmploye, reqEmployeFormatee){
	ASSERT_EQ("Jean Soucy",employe.reqEmployeFormate());
}
