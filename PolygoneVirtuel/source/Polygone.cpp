/**
 * \file Polygone.cpp
 * \brief Implantation de la classe Polygone
 * \author theud1
 * \version 3.0 mise aux normes
 */

#include "Polygone.h"

using namespace std;

/**
 * \brief Constructeur de la classe Polygone
 * \param[in] p_nbSommets le nombre de sommets du polygone
 */
Polygone::Polygone (int p_nbSommets)
{
  m_vPoints.resize (p_nbSommets);
}

/**
 * \brief Méthode permettant d'obtenir le point du polygone se trouvant à une position précise
 * \param[in] p_position la position du point que l'on veut récupérer soit indice+1
 * \pre Precondition >=0 && <nombre de points
 * \return le point se trouvant à la position reçue en paramètre
 */
const Point&
Polygone::reqPoint (int p_position) const
{
  return m_vPoints[p_position - 1];
}

/**
 * \brief Assignation d'un point au polygone
 * \param[in] p_position la position où l'on veut mettre le point
 * \param[in] p_point le point que l'on veut assigner
 */
void
Polygone::asgPoint (int p_position, const Point& p_point)
{
  m_vPoints[p_position - 1] = p_point;
}

/**
 * \brief retourne le nom du polygone
 * méthode virtuelle pure pour augmentation dans les classes dérivées
 * \return le nom du polygone
 */
std::string
Polygone::reqNomFormate () const
{
  return "Polygone : ";
}

/**
 * \brief  agrandissement du polygone
 * \param[in] p_centre le point représentant le centre du polygone
 * \param[in] p_facteur un réel qui représente l'agrandissement
 */
void
Polygone::agrandir (const Point& p_centre, double p_facteur)
{
    for (auto& point : m_vPoints)
    {
      point.agrandir (p_centre, p_facteur);
    }
}

/**
 * \brief Déplacement du polygone
 * \param[in] p_dx longueur de déplacement des abcisses des points du polygone
 * \param[in] p_dy longuer de déplacement des ordonnées des points du polygone
 */
void
Polygone::deplacer (double p_dx, double p_dy)
{
  for (auto& point : m_vPoints)
    {
      point.deplacer (p_dx, p_dy);
    }
}

/**
 * \brief Méthode permettant d'obtenir la circonférence du polygone
 * \return la circonférence du polygone
 */
double
Polygone::circonference () const
{
  double circonference = 0;

  for (unsigned int i = 0; i < m_vPoints.size (); i++)
    {
      Point p1 = m_vPoints[i];
      Point p2 = (i + 1 == m_vPoints.size ()) ? m_vPoints[0] : m_vPoints[i + 1];
      circonference += Point::reqDistance (p1, p2);
    }
  return circonference;
}

/**
 * \brief Méthode d'accès au nombre de points du polygone
 * \return le nombre de points du polygone
 */
int
Polygone::reqNbPoints () const
{
  return m_vPoints.size ();
}
