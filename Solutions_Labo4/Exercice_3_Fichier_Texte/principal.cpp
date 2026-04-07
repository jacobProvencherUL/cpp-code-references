/*
 * principal.cpp
 * \version 2 avec array
 * \brief Programme principal permettant de lire un fichier contenant des mots.
 */

#include <iostream>
#include <array>
#include "fonctions.h"

using namespace std;


int main ()
{

  cout << "Donnez le nom du fichier a lire" << endl;
  char buffer[256] ;
  //  cin.getline (buffer, 256);
  string nomFichier = "listeMots.txt"; //buffer;

  //lire le fichier
  array<string , NOMBRE_MAX_MOTS> mots;
  int nombreMots = lireListe (nomFichier, mots);
  cout << "Liste de mots : " << endl;

  afficheListe (mots, nombreMots);

  //pour compter le nombre de mots lus
  cout << "Nombre de redondances: " << compteRedondances (mots, nombreMots) << endl;

  //ajouter à chaque mots, le nombre de caractères les composant
  ajouterNombreCaracteres (mots, nombreMots);

  afficheListe (mots, nombreMots); //pour afficher avant la sauvegarde

  //sauvegarde de l'ajout
  cout << endl <<
          "Donnez le nom du fichier de sauvegarde " << endl;

  cin.getline (buffer, 256);
  string nomFichierSauvegarde = buffer;
  sauveListe (nomFichierSauvegarde, mots, nombreMots);

  return 0;
}
