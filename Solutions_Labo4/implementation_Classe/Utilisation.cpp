/**
 * \file Utilisation.cpp
 * \brief Programme pilote pour tester la classe Sphere.
 * \version 0.1
 */

#include "Sphere.h"
#include <iostream>

using namespace std;


int main ()
{
  Sphere maSphere (4);
  cout << maSphere.reqVolumeFormate () << endl;
  return 0;
}
