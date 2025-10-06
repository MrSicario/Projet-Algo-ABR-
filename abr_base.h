#ifndef ABR_BASE_H
#define ABR_BASE_H

// ==================== STRUCTURES DE DONNÉES ====================
typedef struct Noeud {
    int valeur;
    struct Noeud* gauche;
    struct Noeud* droite;
    int hauteur;
    int compteur;
} Noeud;

typedef struct {
    Noeud* racine;
    int taille;
    int hauteur_max;
    int rotations;
} ABR;

// ==================== DÉCLARATIONS DES FONCTIONS ====================

Noeud* creerNoeud(int valeur);
void initialiserABR(ABR* arbre);

int hauteurNoeud(Noeud* n);
void mettreAJourHauteur(Noeud* n);
int facteurEquilibre(Noeud* n);

Noeud* rotationDroite(Noeud* y, ABR* arbre);
Noeud* rotationGauche(Noeud* x, ABR* arbre);


Noeud* insererEquilibre(Noeud* racine, int valeur, ABR* arbre);
void inserer(ABR* arbre, int valeur);

#endif
