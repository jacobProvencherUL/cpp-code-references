/**
 * \file Sphere.h
 * \brief Prototype des fonctions de la classe Sphere.
 * \author etudiant
 * \version 0.1
 */
#ifndef SPHERE_H_
#define SPHERE_H_

#include <string>

  /**
   * \class Sphere
   * \brief Classe modélisant l'interface d'une sphère.
   */
  class Sphere
  {
  public:
    Sphere (double p_rayon = 0); 
    double reqRayon () const;
    void asgRayon (double p_nouveauRayon);
    double volumeSphere () const; 
    std::string reqVolumeFormate () const; 

  private:
    double m_rayon;
  };


#endif /* SPHERE_H_ */
