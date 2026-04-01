/**
 * \file Point.h
 * \brief Déclaration de la classe Point
 * \author theud1
 * \version 3.0 mise aux normes
 */

#ifndef POINT_H_DEJA_INCLU
#define POINT_H_DEJA_INCLU

#include <iostream>

/**
 * \class Point
 * \brief Cette classe permet de gérer des points en coordonnées cartésiennes
 */
class Point
{
public:
  Point (double p_x = 0, double p_y = 0);
  void deplacer (double p_dx, double p_dy);
  void agrandir (const Point& p_centre, double p_facteur);
  void afficher (std::ostream& p_os) const;
  double reqx () const;
  double reqy () const;
  bool operator==(const Point& p_point) const;

  static double reqDistance (const Point& p_point1, const Point& p_point2);

private:
  double m_x;
  double m_y;
};

#endif // --- #ifndef POINT_H_DEJA_INCLU
