/**
 * \file Triangle.cpp
 * \brief Implantation de la classe Triangle
 * \author theud1
 * \version 3.0 mise aux normes
 */
#include <sstream>
#include "Triangle.h"


/**
 * \brief Constructeur de la classe Triangle
 * \param[in] p_point1 un sommet du triangle
 * \param[in] p_point2 un sommet du triangle
 * \param[in] p_point3 un sommet du triangle
 */
Triangle::Triangle (const Point& p_point1, const Point& p_point2,
                    const Point& p_point3) :
Polygone (3)
{
  asgPoint (1, p_point1);
  asgPoint (2, p_point2);
  asgPoint (3, p_point3);
}


/**
 * \brief sortie dans un flux des points du triangle
 * \param[out] p_os l'ostream dans lequel on sort les points du triangle
 */
void Triangle::afficher (std::ostream& p_os) const
{
  p_os << "Triangle " << 3 << " ";
  reqPoint (1).afficher (p_os);
  p_os << " ";
  reqPoint (2).afficher (p_os);
  p_os << " ";
  reqPoint (3).afficher (p_os);
}


/**
 * \brief retourne le nom du polygone
 * 	      méthode virtuelle
 * \return le nom du polygone
 */
std::string Triangle::reqNomFormate () const
{
  std::ostringstream os;
  os << Polygone::reqNomFormate ();
  os << "Triangle";
  return os.str ();
}

