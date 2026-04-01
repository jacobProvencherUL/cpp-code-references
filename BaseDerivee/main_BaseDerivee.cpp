/**
 * \file main_BaseDerivee.cpp
 * \brief Programme pilote démontrant l'ordre d'appel des constructeurs et destructeurs dans une structure d'héritage
 * \author T. Eude
 * \version 0.1
 */
#include "Derive.h"

#include <iostream>
using namespace std;

void demoConstructeurDestructeur();

int main()
{
	cout << "Debut simulation" << endl;
	demoConstructeurDestructeur();
	cout << "Fin simulation" << endl;
	return 0;
}

void demoConstructeurDestructeur()
{
	Derive v(1234, 4321);
	cout << "On va quitter la fonction : retour à l'appelant" << endl;
}
