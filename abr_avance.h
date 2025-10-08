#ifndef ABR_AVANCE_H
#define ABR_AVANCE_H

#include "abr_operations.h"
#include <stdio.h>

// Fonctionnalités avancées
int hauteurArbre(Noeud* racine);
int compterNoeuds(Noeud* racine);
int estABRValide(Noeud* racine, int min, int max);
Noeud* kiemeElement(Noeud* racine, int k, int* compteur);
void elementsPlage(Noeud* racine, int min, int max);

// Statistiques et analyse
void afficherStatistiques(ABR* arbre);

// Sauvegarde et chargement
void sauvegarderInfixe(Noeud* racine, FILE* fichier);
int sauvegarderABR(ABR* arbre, const char* nom_fichier);
ABR* chargerABR(const char* nom_fichier);

// Gestion mémoire
void libererArbre(Noeud* racine);
void libererABR(ABR* arbre);

// Fonction principale
int main();

#endif
