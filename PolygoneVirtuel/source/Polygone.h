/**
 * \file Polygone.h
 * \brief Déclaration de la classe Polygone, classe abstraite
 * \author theud1
 * \version 3.0 mise aux normes
 */
#ifndef POLYGONE_H_DEJA_INCLU
#define POLYGONE_H_DEJA_INCLU

#include <iostream>
#include <vector>
#include "Point.h"

/**
 * \class Polygone
 * \brief Classe abstraite qui permet de gérer des polygones
 */
class Polygone
{
public:
  Polygone (int p_nbSommets);

  virtual
  ~Polygone () { };

  const Point& reqPoint (int p_position) const;
  void asgPoint (int p_position, const Point& p_point);

  virtual std::string reqNomFormate () const = 0;
  virtual void afficher (std::ostream& p_os) const = 0;

  void deplacer (double p_dx, double p_dy);
  void agrandir (const Point& p_centre, double p_facteur);
  double circonference () const;
  int reqNbPoints () const;


private:
  std::vector<Point> m_vPoints;
};

#endif // --- #ifndef POLYGONE_H_DEJA_INCLU
