/**
 * \file Rectangle.cpp
 * \brief Implantation de la classe Rectangle
 * \author theud1
 * \version 2.0 mise aux normes
 */
#include <sstream>
#include "Rectangle.h"


/**
 * \brief Constructeur de la classe Rectangle
 * \param[in] p_point1 un point
 * \param[in] p_point2 un point non consécutif à p2
 */
Rectangle::Rectangle (const Point& p_point1, const Point& p_point2) :
Polygone (4)
{
  asgPoint (1, p_point1);
  asgPoint (2, Point (p_point2.reqx (), p_point1.reqy ()));
  asgPoint (3, p_point2);
  asgPoint (4, Point (p_point1.reqx (), p_point2.reqy ()));
}


/**
 * \brief sortie dans un flux des points du rectangle
 * \param[out] p_os l'ostream dans lequel on sort les points du rectangle
 */
void Rectangle::afficher (std::ostream& p_os) const
{
  p_os << "Rectangle ";
  reqPoint (1).afficher (p_os);
  p_os << " ";
  reqPoint (2).afficher (p_os);
  p_os << " ";
  reqPoint (3).afficher (p_os);
  p_os << " ";
  reqPoint (4).afficher (p_os);
}


/**
 * \brief retourne le nom du polygone
 *        méthode virtuelle
 * \return le nom du polygone
 */
std::string Rectangle::reqNomFormate () const
{
  std::ostringstream os;
  os << Polygone::reqNomFormate ();
  os << "Rectangle";
  return os.str ();
}

