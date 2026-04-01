/**
 * \file Derive.cpp
 * \brief Implémentation de la classe Derive
 * \author T. Eude
 * \version 0.1
 */
#include "Derive.h"
#include <iostream>
using namespace std;
/**
 * \brief Constructeur de la classe Derive
 * \param[in] p_db
 * \param[in] p_dd
 */
Derive::Derive (int p_db, int p_dd)
: Base(p_db), m_d (p_dd)
{
   cout << "Constructeur de la classe derivee" << endl;
   cout << "Valeur : " << m_d << endl;
}
/**
 * \brief Destructeur de la classe Derive
 */
Derive::~Derive()
{
   cout << "Destructeur de la classe derivee" << endl;
}
