/**
 * \file:   Equipe.cpp
 * \author: T.E.
 */

#include<memory>
#include <sstream>
#include<iostream>
#include "Equipe.h"
#include "Membre.h"

using namespace std;


/**
 * \brief constructeur
 */
Equipe::Equipe (const std::string& p_nom) : m_nom (p_nom) { }


/**
 * \brief constructeur copie, c'est une forme canonique de coplien, il faut faire une copie en profondeur
 * @param p_equipe l'équipe dont on veut construire une copie
 */
Equipe::Equipe (const Equipe& p_equipe) : m_nom (p_equipe.m_nom)
{
  for (auto & element : p_equipe.m_membres)
    {
      //m_membres.push_back (unique_ptr<Membre>  (new Membre (*element))); //c++11

      //m_membres.push_back ( make_unique <Membre> (*element)); //c++14

      ajouterMembre (*element);
    }
}


/**
 *\brief c'est une forme canonique de coplien, il faut faire une copie en profondeur
 * @param p_proprietaire
 * @return l'objet courant pour les appels en cascade
 */

Equipe& Equipe::operator = (const Equipe& p_equipe)
{

  if (!(this == & p_equipe  ))
    {
      m_nom = p_equipe.m_nom;
      m_membres.clear ();

      for (auto & element : p_equipe.m_membres)
        {
          //m_membres.push_back (unique_ptr<Membre>  (new Membre (*element))); //c++11
          //m_membres.push_back ( make_unique <Membre> (*element)); //c++14
          ajouterMembre (*element);
        }
    }
  return *this;
}


/**
 * \brief destructeur qui ne fait rien
 * la libération de la mémoire allouée dynamiquement a été faite à la
 * destruction des unique_ptr
 */
Equipe::~Equipe ()
{
  cout << "le destructeur a été appelé, il ne fait rien, la libération de la mémoire allouée dynamiquement a été faite à la destruction des unique_ptr" << endl;
}


/**
 * \brief pour ajouter un membre à l'équipe
 * une copie du membre est construite sur le monceau,
 * make_unique fait une demande d'allocation dynamique de mémoire et construit
 * un unique_ptr pour mémoriser l'adresse
 * c'est le unique_ptr qui gère la libération de la mémoire (allouée
 * dynamiquement) à sa destruction
 * @param p_membre le membre à ajouter,
 *
 */
void Equipe::ajouterMembre (const Membre& p_membre)
{
  m_membres.push_back ( make_unique <Membre> (p_membre)); //c++14
  //  m_membres.push_back (unique_ptr<Membre>  (new Membre (p_membre))); //c++11
}


/**
 * \brief convertit les données de l'équipe dans une chaîne de caractères formatée
 * @return un objet string contenant les données formatées
 */
std::string Equipe::reqEquipeFormate () const
{
  ostringstream os;
  os << "composition de l'équipe " << m_nom << endl;
  for (const auto & element : m_membres)
    {
      os << element->reqNom () << endl;
    }
  return os.str ();
}


