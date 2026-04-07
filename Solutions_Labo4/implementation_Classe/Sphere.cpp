/**
 * \file Sphere.cpp
 * \brief Implémentation de l'interface de la classe Sphere
 * \version 0.1
 */
#include "Sphere.h"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;


  /**
   * \brief Constructeur avec parametre.
   *        Initialisation du rayon de l'objet Sphere selon la valeur reçu en paramètre.
   * \param[in] p_rayon, le rayon de la sphère.
   */
  Sphere::Sphere (double p_rayon) : m_rayon (p_rayon) { }


  /**
   * \brief fonction accesseur récupérant le rayon d'une sphère.
   * \return m_rayon, le rayon de la sphere.
   */
  double Sphere::reqRayon () const
  {
    return m_rayon;
  }


  /**
   * \brief Modification du rayon de la sphère avec le nouveau rayon reçu en paramètre.
   * \param[in] p_nouveauRayon, le rayon de la sphère.
   */
  void Sphere::asgRayon (double p_nouveauRayon)
  {
    m_rayon = p_nouveauRayon;
  }


  /**
   * \brief Méthode qui fait le calcule du volume de la sphère.
   * \return le volume de la sphère.
   */
  double Sphere::volumeSphere () const
  {
    double volume;
    volume = (4.0 / 3.0) * (3.14159 * pow (m_rayon, 3));
    return volume;
  }


  /**
   * \brief méthode retournant les informations formatees sur le volume de la sphère.
   * \return un objet string contenant les information formatees.
   */
  string Sphere::reqVolumeFormate () const
  {
    ostringstream os;
    os << "Le volume de la sphere de rayon " << reqRayon () << " est : "
            << volumeSphere () << endl;
    return os.str ();
  }
