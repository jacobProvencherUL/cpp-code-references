/**
 * \file utilisationPolygones.cpp
 *  \brief Interface utilisateur de la hierarchie de classe sur les polygones
 *  \author theud1
 *  \version 0.1
 */
#include <iostream>
#include <vector>
#include "Polygone.h"
#include "Carre.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;


void faireTraitementGenerique (vector<Polygone*>& p_vPoly)
{
  // --- Utilisation polymorphique sans connaitre le type de VPolygone
  cout << "Traitement generique sans connaitre le type de polygone" << endl;

  // --- Traitement non constant sur les polygones
  for (unsigned int i = 0; i < p_vPoly.size (); i++)
    {
      p_vPoly[i]->afficher (cout);
      cout << endl;
      cout << "Circonference : " << p_vPoly[i]->circonference () << endl;
      cout << "Deplacer de [2, 2]" << endl;
      p_vPoly[i]->deplacer (2, 2);
      p_vPoly[i]->afficher (cout);
      cout << endl;
      cout << "Agrandissement : 2x " << endl;
      p_vPoly[i]->agrandir (Point (0, 0), 2);
      p_vPoly[i]->afficher (cout);
      cout << endl;
      cout << "Circonference : " << p_vPoly[i]->circonference () << endl;

      cout << "Pressez retour" << endl;
      cin.get ();
    }

  /*
   // En utilisant un iterator

   vector<Polygone*>::iterator iterI = p_vPoly.begin();
   while (iterI != p_vPoly.end())
   {
   (*iterI)->afficher(cout);
   cout << endl;
   cout << "Circonference : " << (*iterI)->circonference() << endl;
   cout << "Deplacer de [2, 2]" << endl;
   (*iterI)->deplacer(2, 2);
   (*iterI)->afficher(cout);
   cout << endl;
   cout << "Agrandissement : 2x " << endl;
   (*iterI)->agrandir(Point(0,0), 2);
   (*iterI)->afficher(cout);
   cout << endl;
   cout << "Circonference : " << (*iterI)->circonference() << endl;
   iterI++;

   cout << "Pressez retour" << endl;
   cin.get();
   }
   */
}


int main ()
{
  // --- Création des Polygones...
  vector<Polygone*> vPoly;

  cout << "Creation de polygones" << endl;

  cout << "On cree un triangle" << endl;
  Triangle t1 (Point (10, 10), Point (30, 20), Point (10, 30));

  cout << "On cree un carre" << endl;
  Carre c1 (Point (50, 50), 10);

  cout << "On cree un rectangle" << endl;
  Rectangle r1 (Point (30, 30), Point (60, 60));

  vPoly.push_back (&t1);
  vPoly.push_back (&r1);
  vPoly.push_back (&c1);

  cout << "Pret a faire du traitement generique" << endl;
  cout << "Pressez retour" << endl;
  cin.get ();

  faireTraitementGenerique (vPoly);
  cout << "fin du programme";

  return 0;
}

