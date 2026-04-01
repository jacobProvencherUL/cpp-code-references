/**
 * \file Triangle.h
 * \brief Déclaration de la classe Triangle qui hérite de la classe Polygone
 * \author theud1
 * \version 3.0 mise aux normes
 */
#ifndef Triangle_H_DEJA_INCLU
#define Triangle_H_DEJA_INCLU

#include "Polygone.h"
#include <iostream>
#include "Point.h"

/**
 * \class Triangle
 * \brief Cette classe permet de gérer des triangles. Elle hérite de Polygone
 */
class Triangle : public Polygone
{
public:
  Triangle (const Point& p_point1, const Point& p_point2,
            const Point& p_point3);
   void afficher (std::ostream& p_os) const override;
   std::string reqNomFormate () const override;
};

#endif // --- #ifndef Triangle_H_DEJA_INCLU
