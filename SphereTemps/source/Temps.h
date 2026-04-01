/**
 * \file Temps.h
 * \brief Prototype des fonctions de la classe Temps.
 */

#ifndef TEMPS_H_
#define TEMPS_H_

#include <string>

namespace labo8
{

/**
 * \class Temps
 * \brief Classe modélisant l'interface d'un objet temps.
 */
class Temps
{
public:
	friend std::ostream& operator<<(std::ostream &, const Temps &);

	Temps();
	Temps(int p_heures, int p_minutes, int p_secondes);
	~Temps();
	int reqHeures() const;
	void asgHeures(int p_heures);
	int reqMinutes() const;
	void asgMinutes(int p_minutes);
	int reqSecondes() const;
	void asgSecondes(int p_secondes);
	void asgTemps(int p_heures, int p_minutes, int p_secondes);
	std::string reqTempsFormate() const;
	void tic();
	static int reqNbTemps();

private:
	int m_heures;
	int m_minutes;
	int m_secondes;
	static int m_nbTemps;
	void verifieInvariant() const;
};

} /* namespace labo8 */

#endif /* TEMPS_H_ */
