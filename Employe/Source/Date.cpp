/**
 * \file Date.cpp
 * \brief Implantation de la classe Date
 *        révision : normes 12-2013
 *        balises Doxygen
 *        révision des commentaires de spécification d'en-tête des méthodes
 * \author Yves Roy Version initiale, THE
 * \date 28 octobre 2016
 * \version 2.4
 */

// DIRE: Ce fichier c'est l'IMPLÉMENTATION de la classe Date.
// Le .h déclarait les méthodes, ici on écrit ce qu'elles font vraiment.
// Date est une classe utilitaire — pas d'héritage, pas de polymorphisme ici.
// On va l'utiliser dans Employe pour stocker la date de naissance.

#include "Date.h"
#include <sstream>
#include <ctime>
#include <iostream>

// DIRE: Trois constantes statiques. "static" ici veut dire qu'elles sont visibles 
// seulement dans CE fichier .cpp, pas ailleurs.
// MAX_SECONDE correspond au 31 décembre 2037 — la limite haute de time_t 32 bits.
// JOUR_EN_SECONDES = 60 × 60 × 24 = 86400. C'est le nombre de secondes dans une journée.
// MIN_SECONDE = 5 heures en secondes, c'est l'ajustement pour le fuseau horaire de Greenwich.
static const long MAX_SECONDE = 2145848400;
static const long JOUR_EN_SECONDES = 60 * 60 * 24;
static const long MIN_SECONDE = 5 * 60 * 60; // 5 heure par rapport à Greenwich

using namespace std;
namespace util
{
/**
 * \brief constructeur par défaut \n
 * La date prise par défaut est la date du système
 */

// DIRE: Si on écrit juste "Date d;" sans paramètres, on tombe ici.
// time(NULL) retourne le nombre de secondes depuis le 1er janvier 1970 jusqu'à maintenant.
// Ensuite localtime() décompose ce nombre en jour/mois/année.
// Et on passe ces valeurs à asgDate() qui les restocke proprement avec toutes les validations.
// Ça a l'air redondant mais c'est pour s'assurer que les POSTCONDITION et INVARIANTS passent.
Date::Date()
{
	m_temps = time(NULL);

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);

	asgDate(infoTempsP->tm_mday, infoTempsP->tm_mon + 1,
			infoTempsP->tm_year + 1900);

	INVARIANTS();
}
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Date à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si la date est considérée comme valide.
 * 		  Autrement, une erreur d'assertion est générée.
 * \param[in] p_jour est un entier long qui représente le jour de la date
 * \param[in] p_mois est un entier long qui représente le mois de la date
 * \param[in] p_annee est un entier long qui représente l'année de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre à une date valide
 * \post l'objet construit a été initialisé à partir des entiers passés en paramètres
 */

// DIRE: C'est CE constructeur qu'on utilise dans le labo.
// Exemple: Date d(15, 3, 1975) pour le 15 mars 1975.
// La PRECONDITION vérifie d'abord que c'est une date valide.
// Si on passe le 31 février, ça lance une PreconditionException immédiatement.
// Après asgDate, les trois POSTCONDITION vérifient que les valeurs ont bien été stockées.
// C'est le patron classique: PRECONDITION → travail → POSTCONDITION → INVARIANTS.
Date::Date(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION (Date::validerDate(p_jour, p_mois, p_annee));

	asgDate(p_jour, p_mois, p_annee);

	POSTCONDITION (reqJour() == p_jour);
	POSTCONDITION (reqMois() == p_mois);
	POSTCONDITION (reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Assigne une date à l'objet courant
 * \param[in] p_jour est un entier long qui représente le jour de la date
 * \param[in] p_mois est un entier long qui représente le mois de la date
 * \param[in] p_annee est un entier long qui représente l'année de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre à une date valide
 * \post l'objet a été assigné à partir des entiers passés en paramètres
 */

// DIRE: C'est ici que la conversion jour/mois/année → secondes se fait.
// On remplit une structure tm (du C standard) avec les valeurs qu'on veut,
// puis mktime() convertit ça en time_t (nombre de secondes).
// Notez les ajustements: tm_year compte depuis 1900 (donc 2025 → 125),
// tm_mon va de 0 à 11 (donc mars → 2, pas 3). C'est une bizarrerie du C.
// tm_isdst = -1 dit au système de déterminer automatiquement l'heure d'été.
void Date::asgDate(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION(Date::validerDate(p_jour, p_mois, p_annee));

	struct tm infoTemps;

	infoTemps.tm_year = (p_annee - 1900);
	infoTemps.tm_mon = (p_mois - 1);
	infoTemps.tm_mday = p_jour;
	infoTemps.tm_hour = 0;
	infoTemps.tm_min = 0;
	infoTemps.tm_sec = 0;
	infoTemps.tm_isdst = -1;

	m_temps = mktime(&infoTemps);

	POSTCONDITION(reqJour() == p_jour);
	POSTCONDITION(reqMois() == p_mois);
	POSTCONDITION(reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Ajoute ou retire un certain nombre de jours à la date courante
 * \param p_nbJour est une entier long qui représente le nombre de jours à ajouter ou à soustraire s'il est négatif
 * \return un booléen qui indique si l'opération a réussi ou non
 */

// DIRE: On ajoute (ou retire si négatif) des jours à la date.
// C'est juste une addition de secondes: nbJours × 86400.
// Mais on vérifie d'abord que le résultat ne sort pas des bornes 1970-2037.
// Si ça déborde, on ne fait rien et on retourne false. Sinon true.
// C'est une approche différente du design par contrat — ici on retourne 
// un code d'erreur au lieu de lancer une exception.
bool Date::ajouteNbJour(long p_nbJour)
{
	bool bRet = true;

	long tModif = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	if (tModif < MIN_SECONDE || tModif > MAX_SECONDE)
	{
		bRet = false;
	}
	else
	{
		m_temps = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	}

	INVARIANTS();
	return bRet;
}
/**
 * \brief retourne le jour de la date
 * \return un entier long qui représente le jour de la date
 */

// DIRE: Les trois accesseurs suivants font tous la même chose:
// 1) localtime() convertit m_temps (secondes) en structure jour/mois/année
// 2) On extrait le champ voulu
// 3) On ajuste si nécessaire
// L'ASSERTION vérifie que localtime n'a pas échoué (retourne NULL si erreur système).
long Date::reqJour() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mday;
}
/**
 * \brief retourne le mois de la date
 * \return un entier long qui représente le mois de la date
 */

// DIRE: CELUI-CI est crucial pour le labo. C'est avec reqMois() qu'on va 
// comparer le mois de naissance au mois courant pour le bonus de 100$.
// Dans Utilisation.cpp: v_entreprise[x]->reqDateNaissance().reqMois()
// Le +1 c'est parce que tm_mon va de 0 (janvier) à 11 (décembre).
// Nous on veut 1 (janvier) à 12 (décembre).
long Date::reqMois() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mon + 1;
}
/**
 * \brief retourne l'année de la date
 * \return un entier long qui représente l'année de la date
 */

// DIRE: Le +1900 c'est parce que tm_year compte les années depuis 1900.
// Donc pour 2025, tm_year vaut 125. On ajoute 1900 pour avoir 2025.
long Date::reqAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_year + 1900;
}
/**
 * \brief retourne le ième jour de l'année correspondant au jour de la date
 * \return un entier long qui représente le ième jour de l'année
 */

// DIRE: tm_yday va de 0 à 365. Le 1er janvier = 0, donc on ajoute 1.
// Exemple: le 1er février = jour 32 de l'année.
long Date::reqJourAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_yday + 1;
}
/**
 * \brief Déterminer si une année est bissextile ou non
 * \param[in] p_annee un entier long qui représente l'année à vérifier
 * \return estBissextile un booléen qui a la valeur true si l'année est bissextile et false sinon
 */

// DIRE: Méthode statique — pas besoin d'objet, on appelle Date::estBissextile(2024).
// La règle: divisible par 4 → oui, SAUF si divisible par 100 → non, 
// SAUF si divisible par 400 → oui.
// 2024 → oui. 1900 → non. 2000 → oui.
// Cette méthode est utilisée par validerDate pour savoir si février a 28 ou 29 jours.
bool Date::estBissextile(long p_annee)
{
	bool estBissextile = false;

	if (((p_annee % 4 == 0) && (p_annee % 100 != 0)) || ((p_annee % 4 == 0) && (p_annee
			% 100 == 0) && (p_annee % 400 == 0)))
	{
		estBissextile = true;
	}

	return estBissextile;
}
/**
 * \brief retourne le nom du jour de la semaine en français
 * \return une chaîne de caractères qui représente le nom du jour de la semaine en français
 */

// DIRE: Méthode PRIVÉE. Utilisée seulement par reqDateFormatee().
// Le tableau static est créé une seule fois en mémoire, pas à chaque appel.
// tm_wday va de 0 (dimanche) à 6 (samedi), donc l'index tombe directement 
// sur le bon jour dans le tableau.
string Date::reqNomJourSemaine() const
{
	static string JourSemaine[] =
	{ "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);//AssertionException si l'heure système n'a pas correctement été récupérée
	return JourSemaine[infoTempsP->tm_wday];

}
/**
 * \brief retourne le nom du mois en français
 * \return une chaîne de caractères qui représente le nom du mois en français
 */

// DIRE: Aussi PRIVÉE. Même principe avec un tableau de noms de mois.
// tm_mon va de 0 à 11, donc l'index tombe directement sur le bon mois.
// Pas de +1 ici parce qu'on utilise tm_mon comme index dans un tableau qui commence à 0.
// Comparez avec reqMois() qui ajoute +1 parce qu'elle retourne un numéro humain (1-12).
string Date::reqNomMois() const
{
	static string NomMois[] =
	{ "janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout",
			"septembre", "octobre", "novembre", "decembre" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);//AssertionException si l'heure système n'a pas correctement été récupérée
	return NomMois[infoTempsP->tm_mon];
}
/**
 * \brief retourne une date formatée dans une chaîne de caracères (string)
 * \return la date formatée dans une chaîne de caractères
 */

// DIRE: C'est la méthode PUBLIQUE qui assemble tout pour l'affichage.
// Elle appelle les deux méthodes privées reqNomJourSemaine() et reqNomMois().
// Résultat: "Mardi le 08 mars 2024".
// Le if (reqJour() < 10) ajoute un zéro devant les jours à un chiffre: "08" au lieu de "8".
// ostringstream c'est un flux en mémoire — on écrit dedans comme dans cout, 
// puis os.str() retourne la chaîne complète.
 string Date::reqDateFormatee() const
{
	ostringstream os;

	os << reqNomJourSemaine() << " le ";
	if (reqJour() < 10)
	{
		os << "0";
	}
	os << reqJour() << " ";
	os << reqNomMois() << " ";
	os << reqAnnee();

	return os.str();
}

/**
 * \brief Vérifie la validité d'une date
 * \param[in] p_jour un entier long représentant le jour de la date
 * \param[in] p_mois un entier long représentant  le mois de la date
 * \param[in] p_annee un entier long représentant l'année de la date
 * \return un booléen indiquant si la date est valide ou non
 */

// DIRE: Méthode statique utilisée dans toutes les PRECONDITION.
// Le tableau JourParMois donne le nombre de jours dans chaque mois.
// Si c'est février ET année bissextile, on ajoute 1 jour (29 au lieu de 28).
// Les bornes 1970-2037 correspondent aux limites de time_t 32 bits.
// Quatre vérifications: mois entre 1 et 12, année dans les bornes, 
// ajustement bissextile, puis jour entre 1 et le max du mois.
bool Date::validerDate(long p_jour, long p_mois, long p_annee)
{
	long JourParMois[] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const long DEBUT_TEMPS = 1970;
	static const long FIN_TEMPS = 2037;

	bool valide = false;

	if (p_mois > 0 && p_mois <= 12 && p_annee >= DEBUT_TEMPS && p_annee <= FIN_TEMPS)
	{
		if (p_mois == 2 && Date::estBissextile(p_annee))
		{
			JourParMois[p_mois - 1]++;
		}
		if (p_jour > 0 && p_jour <= JourParMois[p_mois - 1])
		{
			valide = true;
		}
	}
	return valide;
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_date à comparer à la date courante
 * \return un booléen indiquant si les deux dates sont égales ou non
 */

// DIRE: Les trois opérateurs suivants montrent l'avantage de stocker un seul nombre.
// Comparer deux dates = comparer deux entiers. C'est trivial.
// Si on avait stocké jour/mois/année séparément, il faudrait comparer les trois.
bool Date::operator==(const Date& p_date) const
{
	return m_temps == p_date.m_temps;
}

/**
 * \brief surcharge de l'opérateur <
 * \param[in] p_date à comparer à la date courante
 * \return un booléen indiquant si la date courante est plus petite que la date passée en paramètre
 */

// DIRE: Plus le nombre de secondes est petit, plus la date est ancienne.
// Donc m_temps < p_date.m_temps veut dire "ma date est avant la sienne".
bool Date::operator<(const Date& p_date) const
{
	return m_temps < p_date.m_temps;
}

/**
 * \brief retourne le nombre de jours entre deux dates
 * \param[in] p_date à soustraire à la date courante
 * \return un entier qui représente le nombre de jours entre la date courante
 * 	et celle passée en paramètre
 */

// DIRE: difftime retourne la différence en secondes (un double).
// On divise par 86400 pour avoir des jours.
// Le static_cast<int> tronque la partie décimale — on veut un nombre entier de jours.
int Date::operator-(const Date& p_date) const
{
	double nbSec = difftime(m_temps, p_date.m_temps);
	return static_cast<int> (nbSec / JOUR_EN_SECONDES);
}

/**
 * \relates Date
 * \brief surcharge de la fonction << d'écriture dans un flux de sortie
 * \param[in] p_os un flux de sortie  dans laquelle on va écrire
 * \param[in] p_date sortie dans le flux
 * \return le flux dans lequel on a écrit la date, ceci pour les appels en cascade
 */

// DIRE: C'est la fonction friend déclarée dans le .h.
// C'est PAS une méthode de Date — c'est une fonction libre. Pas de "Date::" devant.
// Elle produit le format "25/12/2025" avec des zéros devant si jour ou mois < 10.
// Le retour de p_os permet l'enchaînement: cout << d1 << " au " << d2.
 ostream& operator<<( ostream& p_os, const Date& p_date)
{
	long jour = p_date.reqJour();
	long mois = p_date.reqMois();

	if (jour < 10)
	{
		p_os << "0";
	}
	p_os << jour << "/";
	if (mois < 10)
	{
		p_os << "0";
	}
	p_os << mois << "/";
	p_os << p_date.reqAnnee();

	return p_os;
}

/**
 * \brief Teste l'invariant de la classe Date. L'invariant de cette classe s'assure que la date est valide
 */

// DIRE: Appelée par la macro INVARIANTS() à la fin de chaque méthode qui modifie l'objet.
// Trois vérifications: le temps est dans les bornes min et max,
// et la date reconstruite (jour/mois/année) est toujours valide.
// Si un de ces trois INVARIANT échoue → InvariantException.
// C'est le filet de sécurité qui garantit qu'on n'a jamais un objet Date corrompu.
void Date::verifieInvariant() const
{
	INVARIANT(m_temps >= MIN_SECONDE);
	INVARIANT(m_temps <= MAX_SECONDE);
	INVARIANT(Date::validerDate(reqJour(), reqMois(), reqAnnee()));
}
}// namespace util