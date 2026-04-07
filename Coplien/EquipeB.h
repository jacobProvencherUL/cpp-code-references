/**
 * \file:   EquipeB.h
 * \author: T.E.
 * \brief Il est possible d'empêcher la copie d'un objet simplement en rendant
 * inaccessibles les méthodes qui font la copie, exemple :
 */

#ifndef EQUIPEB_H
#define EQUIPEB_H

#include <memory>
#include <string>
#include <vector>
#include "Membre.h"

class EquipeB
{
public:
  EquipeB (const std::string& p_nom);
  EquipeB (const EquipeB& p_equipe) = delete; //(c++11) ou les déclarer privé
  EquipeB& operator= (const EquipeB& p_equipe) = delete;

  //  void ajouterMembre (const Membre& p_membre);
  //  std::string reqEquipeFormate () const;
private:
  std::string m_nom;
  std::vector<std::unique_ptr<Membre>> m_membres;
  //  std::vector<std::shared_ptr<Membre>> m_membres;
  //  EquipeB (const EquipeB& p_equipe);
  //  EquipeB& operator= (const EquipeB& p_equipe);
};

#endif /* EQUIPEB_H */

