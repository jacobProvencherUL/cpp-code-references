/**
 * \file Carre.h
 * \brief Déclaration de la classe Carre qui hérite de la classe Polygone
 * \author theud1
 * \version 3.0 mise aux normes
 */
#ifndef Carre_H_DEJA_INCLU
#define Carre_H_DEJA_INCLU

#include "Polygone.h"
#include <iostream>
#include "Point.h"

/**
 * \class Carre
 * \brief Cette classe permet de gérer des carrés. Elle hérite de Polygone
 */
class Carre : public Polygone
{
public:
    Carre(const Point& p_point, int p_dim);
    void afficher(std::ostream& p_os) const override;
    std::string reqNomFormate() const override;
};

#endif // --- #ifndef Carre_H_DEJA_INCLU
