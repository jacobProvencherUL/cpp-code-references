/**
 * \file Derive.h
 * \brief Interface de la classe Derive
 * \author T. Eude
 * \version 0.1
 */
#ifndef DERIVE_H_DEJA_INCLU
#define DERIVE_H_DEJA_INCLU

#include "Base.h"

class Derive : public Base
{
public:
   Derive  (int p_db, int p_dd);
   ~Derive ();

private:
   int m_d;
};

#endif // #ifndef DERIVE_H_DEJA_INCLU
