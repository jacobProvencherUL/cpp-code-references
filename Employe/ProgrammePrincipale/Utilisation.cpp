/**
 * \file Utilisation.cpp
 * \brief Programme principal pour la création des objets des classes enfants dela classe parent Employe.
 * \author etudiant
 * \version 0.1
 */

// DIRE: C'est LE fichier le plus important à montrer en dernier.
// C'est ici que tout se connecte. On a vu les classes séparément,
// maintenant on voit comment elles travaillent ENSEMBLE grâce au polymorphisme.

#include <iostream>
#include <string>
#include <cstdlib>
#include "Employe.h"
#include "Patron.h"
#include "EmployeCommission.h"
#include "EmployeHoraire.h"
#include "time.h"

using namespace std;
using namespace labo10;
//using namespace util;

int determineMois();  // Détermine le mois courant

int main()
{
	// DIRE: On crée trois objets de trois types DIFFÉRENTS.
	// Chacun appelle son propre constructeur qui appelle le constructeur de Employe en premier.
	// Notez util::Date(15,2,1977) — c'est un objet Date temporaire créé sur place.
	// Pas besoin de le stocker dans une variable, on le passe directement au constructeur.
        Patron unPatron("Soucy", "Jean", util::Date(15,2,1977), 1, 800.00);

	// DIRE: Celui-ci a 7 paramètres: nom, prénom, date, département, salaire, commission, quantité.
	// Les 4 premiers vont au parent Employe, les 3 derniers restent dans EmployeCommission.
	   	EmployeCommission unEmployeCommisssion( "Sue", "Jones", util::Date(8,11,1975), 1, 200.0, 3.0, 150);

	// DIRE: Celui-ci a 6 paramètres: les 4 du parent + taux horaire + heures.
	   	EmployeHoraire unEmployeHoraire( "Price", "Karen", util::Date(17,03,1973), 1, 13.75, 40);

	// DIRE: VOICI la ligne la plus importante de tout le programme.
	// On crée un tableau de 3 pointeurs de type Employe*.
	// MAIS les objets réels sont un Patron, un EmployeCommission et un EmployeHoraire.
	// L'esperluette & prend l'adresse de chaque objet.
	//
	// DIRE: Pourquoi ça marche? Parce que Patron EST UN Employe (héritage public).
	// Un pointeur vers une classe dérivée peut toujours être converti 
	// en pointeur vers la classe de base. C'est l'UPCASTING.
	//
	// DIRE: À partir de maintenant, on ne sait plus quel type réel se cache 
	// derrière chaque case du tableau. Et c'est PAS GRAVE.
	// Grâce au virtual, le bon gains() et le bon reqEmployeFormate() 
	// seront appelés automatiquement. C'est ça le polymorphisme.
	   	Employe * v_entreprise[ 3 ] = { &unPatron, &unEmployeCommisssion, &unEmployeHoraire };

	// DIRE: determineMois() retourne le mois courant du système (1 à 12).
	// On va le comparer avec le mois de naissance de chaque employé.
	   	int mois = determineMois();

	// DIRE: UNE SEULE boucle pour traiter les trois types d'employés.
	// On n'a pas besoin de savoir si c'est un Patron ou un EmployeHoraire.
	// Le code est identique pour tout le monde. C'est la force du polymorphisme:
	// on écrit le code UNE FOIS, et il marche pour tous les types présents ET futurs.
	// Si demain on ajoute un EmployeStagiaire, cette boucle marchera sans modification.
	   	for ( int x = 0; x < 3; x++ )
	   	{
		// DIRE: reqEmployeFormate() est virtuelle.
		// Quand x=0, le pointeur pointe vers un Patron → Patron::reqEmployeFormate() est appelée.
		// Quand x=1, EmployeCommission::reqEmployeFormate().
		// Quand x=2, EmployeHoraire::reqEmployeFormate().
		// Le compilateur ne choisit pas — c'est la vtable à l'EXÉCUTION qui décide.
	   		cout<< v_entreprise[x]->reqEmployeFormate();

		// DIRE: reqCodeDepartement() est définie dans Employe et n'est PAS virtuelle.
		// Pas besoin — tous les employés ont un département, et c'est toujours 
		// le même code qui retourne m_codeDepartement. Pas de comportement spécialisé.
	   		cout<< "du departement " << v_entreprise[x]->reqCodeDepartement() <<endl;

		// DIRE: Voici l'enchaînement d'appels pour la date de naissance.
		// v_entreprise[x] → pointeur Employe*
		// ->reqDateNaissance() → retourne une référence vers l'objet Date
		// .reqDateFormatee() → retourne "Lundi le 15 février 1977"
		// C'est deux appels en chaîne: le premier retourne un objet,
		// le deuxième appelle une méthode sur cet objet.
	   		cout<< "dont l'anniversaire est: "<< v_entreprise[x]->reqDateNaissance().reqDateFormatee() <<" a gagné " ;

		// DIRE: VOICI le bonus d'anniversaire demandé dans l'exercice.
		// On compare le mois courant avec le mois de naissance.
		// reqDateNaissance() retourne l'objet Date.
		// .reqMois() extrait le mois (1 à 12).
		// Si ça correspond au mois courant → c'est son mois d'anniversaire.
		//
		// DIRE: Exemple concret. Si on est en février (mois = 2),
		// Jean Soucy est né le 15/02/1977 → reqMois() retourne 2 → MATCH → bonus 100$.
		// Jones Sue est née le 08/11/1975 → reqMois() retourne 11 → pas de match.
		// Karen Price est née le 17/03/1973 → reqMois() retourne 3 → pas de match.
	   		if ( v_entreprise[x]->reqDateNaissance().reqMois() == mois)

			// DIRE: gains() est virtuelle — c'est la bonne version qui est appelée.
			// Pour le Patron: 800 + 100 = 900$.
			// Le + 100 c'est la prime d'anniversaire ajoutée au résultat de gains().
			// On ne modifie PAS l'objet — on ajoute 100 seulement pour l'affichage.
	   				cout<< v_entreprise[x]->gains() + 100 << " BON ANNIVERSAIRE!!! " << endl;
	   		else
			// DIRE: Pas d'anniversaire ce mois-ci → gains normaux.
			// Patron: 800$. EmployeCommission: 650$. EmployeHoraire: 550$.
	   			cout<< v_entreprise[x]->gains() <<endl;
	   	}

	   return 0;
}

/**
 * \brief Détermination du mois courant
 * \return le mois courant
 */

// DIRE: Fonction utilitaire qui récupère le mois courant du système.
// time() donne les secondes depuis 1970 (comme dans la classe Date).
// localtime() convertit en structure avec jour/mois/année.
// strftime() avec "%m" extrait juste le mois sous forme de chaîne "01" à "12".
// atoi() convertit cette chaîne en entier: "03" → 3.
// C'est le même mois qu'on compare ensuite avec reqMois() de la date de naissance.
int determineMois()
{
	time_t tempsCourant;
	char chaineMois[ 3 ];

	time( &tempsCourant );
	strftime( chaineMois, 3, "%m",      // strftime %m Le numéro du mois (entre 01 et 12)
		localtime( &tempsCourant ) );    // date et heure courante
	return atoi( chaineMois );      // atoi conversion d'un string en entier
}