/**
 * \file:   equipeTesteur
 * \author: etudiant
 *
 * \date Created on 13 janvier 2023, 14:18
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Equipe.h"
#include "Membre.h"
using namespace std;


TEST (Equipe, ajouter)
{
  Equipe uneEquipe;
  Membre jo ("jo");
  Membre blo ("blo");
  uneEquipe.ajouterMembre (jo);
  uneEquipe.ajouterMembre (blo);
  ASSERT_FALSE (uneEquipe.reqEquipeFormate ().empty ());
  cout << uneEquipe.reqEquipeFormate ();
}


TEST (Equipe, ccEquipe)
{
  Equipe equipe1;
  Membre jo ("jo");
  Membre blo ("blo");
  equipe1.ajouterMembre (jo);
  equipe1.ajouterMembre (blo);
  Equipe equipe2 (equipe1);
  ASSERT_EQ (equipe1.reqEquipeFormate (), equipe2.reqEquipeFormate ());
  cout << "equipe1 :" << endl << equipe1.reqEquipeFormate ();
  cout << "equipe2 :" << endl << equipe2.reqEquipeFormate ();
}