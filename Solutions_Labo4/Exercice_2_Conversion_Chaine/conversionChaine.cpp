/**
 * \file conversionChaine.cpp
 * \brief labo 3
 *
 */

#include <string>
#include <sstream>//pour pouvoir utiliser le istringstream
#include <iostream>

using namespace std;


int main ()
{
  string chaine {
                 "2979403 2 16.99 Câble DVI-D Dual-Link Mâle à Mâle de six Pieds Noir "};

  istringstream is_chaine {chaine};

  int reference;
  is_chaine >> reference;

  int quantite;
  is_chaine >> quantite;

  float prix;
  is_chaine >> prix;

  char buffer[256];
  is_chaine.ignore ();
  is_chaine.getline (buffer, 256);
  string designation = buffer;

  cout << "Référence: " << reference << "\n";
  cout << "Quantité: " << quantite << "\n";
  cout << "Prix: " << prix << "\n";
  cout << "Désignation: " << designation << "\n";

  return 0;
}



