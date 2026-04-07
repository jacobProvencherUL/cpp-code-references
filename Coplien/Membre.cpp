/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Membre.cpp
 * Author: etudiant
 *
 * Created on 13 janvier 2023, 12:23
 */

#include "Membre.h"


Membre::Membre (const std::string& p_nom) : m_nom (p_nom) { }


//Membre::Membre (const Membre& orig) { }


Membre::~Membre () { }


const std::string& Membre::reqNom () const
{
  return m_nom;
}

