/**
 * \file Rectangle.h
 * \brief Déclaration de la classe rectangle qui hérite de la classe Polygone
 * \author theud1
 * \version 2.0 mise aux nornes
 */
#ifndef Rectangle_H_DEJA_INCLU
#define Rectangle_H_DEJA_INCLU

#include "Polygone.h"
#include <iostream>
#include "Point.h"

/**
 * \class Rectangle
 * \brief Cette classe permet de gérer des rectangles. Elle hérite de Polygone
 */
class Rectangle : public Polygone
{
public:
    Rectangle(const Point& p_point1, const Point& p_point2);
    void afficher(std::ostream& p_os) const override;
    std::string reqNomFormate() const override;
};

#endif // --- #ifndef Rectangle_H_DEJA_INCLU
