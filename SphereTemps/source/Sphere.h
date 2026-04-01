/**
 * \file Sphere.h
 * \brief déclarations de la classe Sphere.
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <string>

namespace labo8
{

/**
 * \class Sphere
 * \brief Classe modélisant l'interface d'une sphère.
 */
class Sphere
{
public:
	Sphere(double p_rayon = 0);
	double reqRayon() const;
	void asgRayon(double p_rayon);
	double volumeSphere() const;
	std::string reqVolumeFormate() const;

private:
	double m_rayon;
	void verifieInvariant() const;
};

} /* namespace labo8 */

#endif /* SPHERE_H_ */
