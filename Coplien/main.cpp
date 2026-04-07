/**
 * \file   main.cpp
 * \author: T.E.
 */

#include <iostream>
#include "Equipe.h"
#include "Membre.h"

#include"EquipeB.h"

using namespace std;


/**
 * \brief programme utilisant une classe "forme canonique de Coplien"
 *
 */
int main ()
{
  Equipe equipe1 ("gagnants");
  Membre jo ("jo");
  Membre blo ("blo");
  equipe1.ajouterMembre (jo);
  equipe1.ajouterMembre (blo);

  cout << equipe1.reqEquipeFormate ();
  {
    Equipe equipe2 (equipe1);

    cout << "equipe1 :" << endl << equipe1.reqEquipeFormate ();
    cout << "equipe2 :" << endl << equipe2.reqEquipeFormate ();
  }
  Equipe equipe3 ("perdants");
  cout << "equipe3 :" << endl << equipe3.reqEquipeFormate ();

  equipe3 = equipe1;
  cout << "equipe3 :" << endl << equipe3.reqEquipeFormate ();

  EquipeB equipe4 ("non copiable");
  EquipeB equipe5 ("pour tester la copie");
  //  equipe5 = equipe4;
  return 0;
}
