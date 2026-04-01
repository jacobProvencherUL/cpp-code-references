/**
 * \file Temps.cpp
 * \brief Implémentation de l'interface de la classe Temps
 */

#include "Temps.h"
#include <time.h>
#include <sstream>
#include "ContratException.h"

namespace labo8
{

int Temps::m_nbTemps = 0;

/**
 * \brief Constructeur par defaut qui represente l'heure actuelle,la valeur par défaut est celle du système ajustée selon l'heure de Greenwich.
 * \return Un objet temps
 * \post m_nbTemps > 0
 */
Temps::Temps()
{
	m_secondes = time(NULL); // nombre de secondes depuis 1970
	m_minutes = (m_secondes % 3600) / 60; // nombre de minutes dans la dernière heure
	m_heures = (m_secondes / 3600) % 24; // nombre d'heures aujourd'hui, IMPORTANT: l’heure ici est en GMT
	/*
	 * Pour mettre l’heure en GMT-4 ou GMT-5, il faut tenir compte
	 * *** pour GMT-4 de l’intervalle [1..3] parce que si en GMT il est 3 et que vous faites uniquement -4 pour
	 *     avoir l’heure GMT-4 vous vous retrouverez avec une heure négative;
	 *     pareille pour GMT-5, c’est l’intervalle [1..4]
	 * */
	/* Mettre m_heure en GMT-4*/
	switch (m_heures)
	{
	case 1:
		m_heures = 21;
		break;
	case 2:
		m_heures = 22;
		break;
	case 3:
		m_heures = 23;
		break;
	default:
		m_heures = m_heures - 4;
		break;
	}
	/* Mettre m_heure en GMT-5
	 switch (m_heure)
	 {
	 case 1:
	 m_heures = 20;
	 break;
	 case 2:
	 m_heures = 21;
	 break;
	 case 3:
	 m_heures = 22;
	 break;
	 case 4:
	 m_heures = 23;
	 break;
	 default:
	 m_heures = m_heures - 5;
	 break;
	 }*/
	m_secondes = m_secondes % 60; // nombre de secondes dans la dernière minute

	m_nbTemps++;

	POSTCONDITION(m_nbTemps != 0);
	INVARIANTS();
}

/**
 * \brief Constructeur avec parametres,
 * 			les valeurs passées non valides sont mises à zéro.
 * \param[in] p_heures >=0 et <24.
 * \param[in] p_minutes >=0 et <60.
 * \param[in] p_secondes >=0 et <60.
 * \pre p_heures est dans un format valide.
 * \pre p_minutes est dans un format valide.
 * \pre p_secondes est dans un format valide.
 * \post m_heure prend la valeur de p_heure.
 * \post m_minute prend la valeur de p_minute.
 * \post m_seconde prend la valeur de p_seconde.
 * \post m_nbTemps > 0
 * \return Un objet temps
 */
Temps::Temps(int p_heures, int p_minutes, int p_secondes) :
		m_heures(p_heures), m_minutes(p_minutes), m_secondes(p_secondes)
{
	PRECONDITION(p_heures >= 0 && p_heures < 24);
	PRECONDITION(p_minutes >= 0 && p_minutes < 60);
	PRECONDITION(p_secondes >= 0 && p_secondes < 60);

	m_nbTemps++;

	POSTCONDITION(m_heures == p_heures);
	POSTCONDITION(m_minutes == p_minutes);
	POSTCONDITION(m_secondes == p_secondes);
	POSTCONDITION(m_nbTemps != 0);
	INVARIANTS();
}

/**
 * \brief Destructeur nécessaire pour mettre à jour l'attribut m_nbTemps de la classe Temps.
 */
Temps::~Temps()
{
	m_nbTemps--;
}

/**
 * \brief Méthode accesseur récupérant l'heure.
 * \return l'heure
 */
int Temps::reqHeures() const
{
	return m_heures;
}

/**
 * \brief Assignation de l'attribut de l'heure avec la valeur passée en paramètre.
 *        Si la valeur passée est invalide, p_heure est mis à 0.
 * \param[in] p_heures >= 0 et < 24.
 * \pre p_heures doit être compris entre 0 et 24.
 * \post m_heure prend la valeur du paramètre reçu en entrée.
 */
void Temps::asgHeures(int p_heures)
{
	PRECONDITION(p_heures >= 0 && p_heures < 24);
	m_heures = p_heures;
	POSTCONDITION(m_heures == p_heures);
	INVARIANTS();
}

/**
 * \brief Méthode accesseur récupérant les minutes.
 * \return les minutes
 */
int Temps::reqMinutes() const
{
	return m_minutes;
}

/**
 * \brief Assignation de l'attribut des minutes avec la valeur passée en paramètre.
 *        Si la valeur passée est invalide, p_minute est mis à 0.
 * \param[in] p_minutes qui représnete les minutes.
 * \pre p_minute doit être compris entre 0 et 60.
 * \post m_minute prend la valeur du paramètre reçu en entrée.
 */
void Temps::asgMinutes(int p_minutes)
{
	PRECONDITION(p_minutes >= 0 && p_minutes < 60);
	m_minutes = p_minutes;
	POSTCONDITION(m_minutes == p_minutes);
	INVARIANTS();
}

/**
 * \brief Méthode accesseur récupérant les secondes.
 * \return les secondes
 */
int Temps::reqSecondes() const
{
	return m_secondes;
}

/**
 * \brief Assignation de l'attribut des secondes avec la valeur passée en paramètre.
 *        Si la valeur passée est invalide, p_seconde est mis à 0.
 * \param[in] p_secondes qui représente les secondes.
 * \pre p_secondes doit être compris entre 0 et 60.
 * \post m_seconde prend la valeur du paramètre reçu en entrée.
 */
void Temps::asgSecondes(int p_secondes)
{
	PRECONDITION(p_secondes >= 0 && p_secondes < 60);
	m_secondes = p_secondes;
	POSTCONDITION(m_secondes == p_secondes);
	INVARIANTS();
}

/**
 * \brief Méthode permettant la modification des attributs heure, minute, seconde ensemble.
 *        Si la valeur passée est invalide, p_seconde est mis à 0.
 * \param[in] p_heures qui représente les heures.
 * \param[in] p_minutes qui représente les minutes.
 * \param[in] p_secondes qui représente les secondes.
 */
void Temps::asgTemps(int p_heures, int p_minutes, int p_secondes)
{
	asgHeures(p_heures);
	asgMinutes(p_minutes);
	asgSecondes(p_secondes);
}

/**
 * \brief Méthode retournant une chaîne contenant l'ensemble des attributs formatés.
 * \return un objet string.
 */
std::string Temps::reqTempsFormate() const
{
	std::ostringstream os;
	os << ((m_heures == 0 || m_heures == 12) ? 12 : m_heures % 12) << ":"
			<< ((m_minutes < 10) ? "0" : "") << m_minutes << ":"
			<< ((m_secondes < 10) ? "0" : "") << m_secondes
			<< ((m_heures < 12) ? " AM" : " PM");
	return os.str();
}

/**
 * \brief Surcharge de l'opérateur << pour permettre d'envoyer dans un flux de sortie ostream un objet Temps.
 * \param[in] p_os un flux de sortie.
 * \param[in] p_temps l'objet à sortir.
 * \return un flux de sortie pour permettre les appels en cascade.
 */
std::ostream& operator<<(std::ostream & p_os, const Temps & p_temps)
{
	p_os << p_temps.reqTempsFormate();
	return p_os;
}

/**
 * \brief Méthode ajoutant une seconde à l'heure.
 */
void Temps::tic()
{
	asgSecondes(m_secondes + 1);
	if (m_secondes == 0)
	{
		asgMinutes(m_minutes + 1);
		if (m_minutes == 0)
			asgHeures(m_heures + 1);
	}
}

/**
 * \brief Méthode retournant le nombre d'objets temps crée.
 * \return nombre d'objets temps.
 */
int Temps::reqNbTemps()
{
	return m_nbTemps;
}

/**
 * \brief Vérifier les invariants de classe Temps.
 */
void Temps::verifieInvariant() const
{
	INVARIANT(m_heures >= 0 && m_heures < 24);
	INVARIANT(m_minutes >= 0 && m_minutes < 60);
	INVARIANT(m_secondes >= 0 && m_secondes < 60);
}

} /* namespace labo8 */
