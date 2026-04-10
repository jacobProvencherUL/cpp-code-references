/**
 * \file Utilisation.cpp
 * \brief Programme principal pour la création des objets des classes enfants dela classe parent Employe.
 * \author etudiant
 */
#include <memory>
#include <vector>

#include <iostream>
#include <string>
#include <cstdlib>
#include "Employe.h"
#include "Patron.h"
#include "EmployeCommission.h"
#include "EmployeHoraire.h"
#include "time.h"

using namespace std;
using namespace labo9;
//using namespace util;

int determineMois ();  // Détermine le mois courant


int main ()
{
  Patron unPatron ("Soucy", "Jean", util::Date (15, 2, 1977), 1, 800.00);
  EmployeCommission unEmployeCommisssion ( "Sue", "Jones", util::Date (8, 11, 1975), 1, 200.0, 3.0, 150);
  EmployeHoraire unEmployeHoraire ( "Price", "Karen", util::Date (17, 03, 1973), 1, 13.75, 40);
  Employe * v_entreprise[ 3 ] = { &unPatron, &unEmployeCommisssion, &unEmployeHoraire };

  int mois = determineMois ();
  for ( int x = 0; x < 3; x++ )
    {
      cout << v_entreprise[x]->reqEmployeFormate ();
      cout << "du departement " << v_entreprise[x]->reqCodeDepartement () << endl;
      cout << "dont l’anniversaire est: " << v_entreprise[x]->reqDateNaissance ().reqDateFormatee () << " a gagné " ;
      if ( v_entreprise[x]->reqDateNaissance ().reqMois () == mois)
        cout << v_entreprise[x]->gains () + 100 << " BON ANNIVERSAIRE!!! " << endl;
      else
        cout << v_entreprise[x]->gains () << endl;
    }
  return 0;
}


/**
 * \brief Détermination du mois courant
 * \return le mois courant
 */
int determineMois ()
{
  time_t tempsCourant;
  char chaineMois[ 3 ];

  time ( &tempsCourant );
  strftime ( chaineMois, 3, "%m",      // strftime %m Le numéro du mois (entre 01 et 12)
            localtime ( &tempsCourant ) );    // date et heure courante
  return atoi ( chaineMois );      // atoi conversion d'un string en entier
}



