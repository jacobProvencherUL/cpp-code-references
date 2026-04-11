/**
 * \file Employe.h
 * \brief Classe de base abstraite Employe
 * \author etudiant
 * \version 0.1
 * \date
 */
#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include "Date.h"
#include "ContratException.h"

namespace labo10
{
/**
 * \class Employe
 * \brief Classe de base
 */
class Employe
{
public:

	Employe(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement);
	virtual ~Employe(){};

	//Accesseurs
	int reqCodeDepartement() const;
	const std::string& reqPrenom() const;
	const std::string& reqNomFamille() const;
	const util::Date& reqDateNaissance() const;

   virtual double gains() const;
   virtual std::string reqEmployeFormate() const; // virtuelle.

private:
     std::string m_nomFamille;
   	 std::string m_prenom;
   	 util::Date m_dateNaissance;
   	 int m_codeDepartement;
   	 void verifieInvariant() const;

};

}
#endif /* EMPLOYE_H_ */
