/**
 * \file:   Equipe.h
 * \author: T.E.
 */

#ifndef EQUIPE_H
#define EQUIPE_H

#include <memory>
#include <string>
#include <vector>
#include "Membre.h"

class Equipe
{
public:
  Equipe (const std::string& p_nom);
  Equipe (const Equipe& p_equipe);
  ~Equipe ();
  void ajouterMembre (const Membre& p_membre);
  Equipe& operator= (const Equipe& p_equipe);
  std::string reqEquipeFormate () const;
private:
  std::string m_nom;
  std::vector<std::unique_ptr<Membre>> m_membres;
  //  std::vector<std::shared_ptr<Membre>> m_membres;
};

#endif /* EQUIPE_H */

