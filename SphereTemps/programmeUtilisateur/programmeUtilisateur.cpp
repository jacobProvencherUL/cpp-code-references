//============================================================================
// Name        : programmeUtilisateur.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Temps.h"
#include "Sphere.h"

using namespace std;
using namespace labo8;


int main() {
	Sphere sphere(5);
	cout << sphere.reqVolumeFormate() << endl;

	Temps temps(15,45,0);
	cout << temps.reqTempsFormate();
	return 0;
}
