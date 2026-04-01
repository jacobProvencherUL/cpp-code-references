/**
 * \file Carre.cpp
 * \brief Implantation de la classe Carre
 * \author theud1
 * \version 3.0 mise aux normes
 */
#include <sstream>
#include "Carre.h"


/**
 * \brief Constructeur de la classe Carre
 * \param[in] p_point un point correspondant au coin haut gauche
 * \param[in] p_dimension un entier représentant la longueur des côtés du carré
 */
Carre::Carre (const Point& p_point, int p_dimension) :
Polygone (4)
{
  asgPoint (1, p_point);
  asgPoint (2, Point (p_point.reqx () + p_dimension, p_point.reqy ()));
  asgPoint (3,
            Point (p_point.reqx () + p_dimension, p_point.reqy () + p_dimension));
  asgPoint (4, Point (p_point.reqx (), p_point.reqy () + p_dimension));
}


/**
 * \brief sortie dans un flux des points du carré
 * \param[out] p_os l'ostream dans lequel on sort les points du carré
 */
void Carre::afficher (std::ostream& p_os) const
{
  p_os << "Carre ";
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
std::string Carre::reqNomFormate () const
{
  std::ostringstream os;
  os << Polygone::reqNomFormate ();
  os << "Carre";
  return os.str ();
}

