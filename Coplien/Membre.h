/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Membre.h
 * Author: etudiant
 *
 * Created on 13 janvier 2023, 12:23
 */

#ifndef MEMBRE_H
#define MEMBRE_H
#include <string>

class Membre
{
public:
  Membre (const std::string& p_nom);
  //  Membre (const Membre& orig);
  virtual ~Membre ();
  const std::string& reqNom () const;
private:
  std::string m_nom;
};

#endif /* MEMBRE_H */

