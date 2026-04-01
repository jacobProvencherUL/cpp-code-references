/**
 * \file Point.cpp
 * \brief Implantation de la classe Point
 * \author theud1
 * \version 3.0 mise aux normes
 */
#include "Point.h"
#include <cmath>

/**
 * \brief Constructeur de la classe Point
 * \param[in] p_x l'abcisse du point
 * \param[in] p_y la coordonnée du point
 */
Point::Point (double p_x, double p_y)
: m_x (p_x), m_y (p_y) { }

/**
 * \brief Méthode d'accès au point
 *  \return le nombre de points du polygone
 */
double
Point::reqx () const
{
  return m_x;
}

/**
 * \brief Méthode d'accès au point
 *  \return le nombre de points du polygone
 */
double
Point::reqy () const
{
  return m_y;
}

/**
 * \brief compare deux points pour vérifier s'ils sont égaux
 * @param p_point le point comparé à l'objet courant
 * @return true s'ils ont les mêmes coordonnées false sinon
 */
bool Point::operator== (const Point& p_point) const
{
  return (m_x == p_point.m_x && m_y == p_point.m_y);
}

/**
 * \brief Méthode permettant d'agrandir un point
 * \param[in] p_centre le point duquel on éloigne le point courant
 * \param[in] p_facteur un réel représentant l'agrandissement
 */
void
Point::agrandir (const Point& p_centre, double p_facteur)
{
  m_x = m_x * p_facteur + p_centre.reqx () * (1 - p_facteur);
  m_y = m_y * p_facteur + p_centre.reqx () * (1 - p_facteur);
}

/**
 * \brief Pour déplacer un point
 * \param[in] p_dx la longueur de déplacement de l'abcisse
 * \param[in] p_dy la longueur de déplacement de la coordonée
 */
void
Point::deplacer (double p_dx, double p_dy)
{
  m_x += p_dx;
  m_y += p_dy;
}

/**
 * \brief Affichage des coordonnées du point
 * \param[in] p_os une ostream dans laquelle on affiche les coordonnées
 */
void
Point::afficher (std::ostream& p_os) const
{
  p_os << "[" << m_x << "," << m_y << "]";
}

/**
 * \brief Méthode permettant d'obtenir la distance entre deux points
 * 		méthode statique
 * \param[in] p_point1 le premier point
 * \param[in] p_point2 le deuxième point
 * \return racine2 la distance entre les deux points
 */
double
Point::reqDistance (const Point& p_point1, const Point& p_point2)
{
  double x2 = pow (p_point2.reqx () - p_point1.reqx (), 2);
  double y2 = pow (p_point2.reqy () - p_point1.reqy (), 2);
  double racine2 = sqrt (x2 + y2);
  return racine2;
}
