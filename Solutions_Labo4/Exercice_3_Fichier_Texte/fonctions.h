/*
 * fonctions.h
 * \version 2
 * \brief Déclaration des fonctions
 */

#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <string>
#include <array>

const int NOMBRE_MAX_MOTS {20};

enum
{
  OK, ERREUR
};

int lireListe (const std::string& p_nomFichier, std::array<std::string, NOMBRE_MAX_MOTS>& p_liste);
void afficheListe (const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot);
int compteRedondances (const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot);
void ajouterNombreCaracteres (std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot);
void sauveListe (const std::string& p_nomFichier, const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot);


#endif /* FONCTIONS_H_ */
