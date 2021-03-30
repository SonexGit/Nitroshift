#ifndef _COMBAT_H_
#define _COMBAT_H_

#include "header.h"

/* Fonctions */
int estUnBoss(entite * e);
void iaEnnemi(entite * e);
void actionEnnemi(entite * e);
void deroulementCombat(int level);

#endif // _COMBAT_H_