/**
 * \file Base.cpp
 * \brief Implémentation de la classe Base
 * \author T. Eude
 * \version 0.1
 */
#include "Base.h"
#include <iostream>
using namespace std;

/**
 * \brief Constructeur de la classe Base
 * \param[in] p_db
 */
Base::Base (int p_db)
: m_b (p_db)
{
   cout << "Constructeur de la classe de base" << endl;
   cout << "Valeur : " << m_b << endl;
}
/**
 * \brief Destructeur de la classe Base
 */
Base::~Base()
{
   cout << "Destructeur de la classe de base" << endl;
}
