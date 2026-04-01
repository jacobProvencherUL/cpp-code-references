/**
 * \file Sphere.cpp
 * \brief Implémentation de l'interface de la classe Sphere
 */

#include "Sphere.h"
#include <cmath>
#include <sstream>
#include "ContratException.h"

namespace labo8
{

/**
 * \brief Constructeur avec parametre.
 *        Initialisation du rayon de l'objet Sphere selon la valeur reçu en paramètre.
 *        Dans le cas où aucune valeur n'est reçue en paramètre, la valeur 0.0 est attribuée.
 * \param[in] p_rayon, le rayon de la sphère.
 * \pre p_rayon de la sphère doit être >=0.
 * \post Vérification de l'attribut m_rayon s'il contient le rayon courant.
 */
Sphere::Sphere(double p_rayon) :
		m_rayon(p_rayon)
{
	PRECONDITION(p_rayon >= 0);
	POSTCONDITION(m_rayon == p_rayon);
	INVARIANTS();
}

/**
 * \brief fonction accesseur récupérant le rayon d'une sphère.
 * \return m_rayon, le rayon de la sphere.
 */
double Sphere::reqRayon() const
{
	return m_rayon;
}

/**
 * \brief Modification du rayon de la sphère avec le nouveau rayon reçu en paramètre.
 * \param[in] p_rayon, le nouveau rayon de la sphère.
 * \pre p_rayon de la sphère doit être >=0.
 * \post Vérification de l'attribut m_rayon s'il contient le nouveau rayon courant.
 */
void Sphere::asgRayon(double p_rayon)
{
	PRECONDITION(p_rayon >= 0);
	m_rayon = p_rayon;
	POSTCONDITION(m_rayon == p_rayon);
	INVARIANTS();
}

/**
 * \brief Méthode qui fait le calcul du volume de la sphère.
 * \return le volume de la sphère.
 */
double Sphere::volumeSphere() const
{
	double volume;
	volume = (4.0 / 3.0) * (3.14159 * pow(m_rayon, 3));
	return volume;
}

/**
 * \brief méthode retournant les informations formatées sur le volume de la sphère.
 * \return un objet string contenant les informations formatées.
 */
std::string Sphere::reqVolumeFormate() const
{
	std::ostringstream os;
	os << "Le volume de la sphere de rayon " << reqRayon() << " est : "
			<< volumeSphere() << std::endl;
	return os.str();
}

/**
 * \brief vérifie que le rayon de la sphère est toujours positif ou nul.
 */
void Sphere::verifieInvariant() const
{
	INVARIANT(m_rayon >= 0);
}

} /* namespace labo8 */

