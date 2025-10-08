#ifndef ABR_OPERATIONS_H
#define ABR_OPERATIONS_H

#include "abr_base.h"
#include <stdio.h>


// Recherche
Noeud* rechercherRecursif(Noeud* racine, int valeur);
int rechercher(ABR* arbre, int valeur);
Noeud* trouverMinimum(Noeud* racine);
Noeud* trouverMaximum(Noeud* racine);
// Suppression
Noeud* supprimerRecursif(Noeud* racine, int valeur, ABR* arbre);
void supprimer(ABR* arbre, int valeur);
// Parcours
void parcoursInfixeRecursif(Noeud* racine);
void parcoursPrefixeRecursif(Noeud* racine);
void parcoursPostfixeRecursif(Noeud* racine);
void parcoursNiveaux(Noeud* racine);
void afficherParcoursInfixe(ABR* arbre);
void afficherParcoursPrefixe(ABR* arbre);
void afficherParcoursPostfixe(ABR* arbre);

#endif
