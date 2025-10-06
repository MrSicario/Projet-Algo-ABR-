#include "abr_base.h"
#include <stdlib.h>

// ==================== CRÉATION ET INITIALISATION ====================
Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) return NULL;
    nouveau->valeur = valeur;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    nouveau->hauteur = 1;
    nouveau->compteur = 1;
    return nouveau;
}
void initialiserABR(ABR* arbre) {
    arbre->racine = NULL;
    arbre->taille = 0;
    arbre->hauteur_max = 0;
    arbre->rotations = 0;
}

// ==================== GESTION DES HAUTEURS ================
int hauteurNoeud(Noeud* n) {
    return n == NULL ? 0 : n->hauteur;
}

void mettreAJourHauteur(Noeud* n) {
    if (n == NULL) return;
    int h_gauche = hauteurNoeud(n->gauche);
    int h_droite = hauteurNoeud(n->droite);
    n->hauteur = (h_gauche > h_droite ? h_gauche : h_droite) + 1;
}

int facteurEquilibre(Noeud* n) {
    if (n == NULL) return 0;
    return hauteurNoeud(n->gauche) - hauteurNoeud(n->droite);
}

// ==================== ROTATIONS POUR ÉQUILIBRAGE ==============
Noeud* rotationDroite(Noeud* y, ABR* arbre) {
    Noeud* x = y->gauche;
    Noeud* T2 = x->droite;
    x->droite = y;
    y->gauche = T2;
    mettreAJourHauteur(y);
    mettreAJourHauteur(x);

    if (arbre != NULL) arbre->rotations++;
    return x;
}
Noeud* rotationGauche(Noeud* x, ABR* arbre) {
    Noeud* y = x->droite;
    Noeud* T2 = y->gauche;

    y->gauche = x;
    x->droite = T2;

    mettreAJourHauteur(x);
    mettreAJourHauteur(y);

    if (arbre != NULL) arbre->rotations++;
    return y;
}

// ==================== INSERTION AVEC ÉQUILIBRAGE ====================
Noeud* insererEquilibre(Noeud* racine, int valeur, ABR* arbre) {
    if (racine == NULL) {
        Noeud* nouveau = creerNoeud(valeur);
        if (arbre != NULL && nouveau != NULL) arbre->taille++;
        return nouveau;
    }

    if (valeur < racine->valeur) {
        racine->gauche = insererEquilibre(racine->gauche, valeur, arbre);
    } else if (valeur > racine->valeur) {
        racine->droite = insererEquilibre(racine->droite, valeur, arbre);
    } else {
        racine->compteur++;
        return racine;
    }

    mettreAJourHauteur(racine);
    int equilibre = facteurEquilibre(racine);

    if (equilibre > 1 && valeur < racine->gauche->valeur) {
        return rotationDroite(racine, arbre);
    }
    if (equilibre < -1 && valeur > racine->droite->valeur) {
        return rotationGauche(racine, arbre);
    }
    if (equilibre > 1 && valeur > racine->gauche->valeur) {
        racine->gauche = rotationGauche(racine->gauche, arbre);
        return rotationDroite(racine, arbre);
    }
    if (equilibre < -1 && valeur < racine->droite->valeur) {
        racine->droite = rotationDroite(racine->droite, arbre);
        return rotationGauche(racine, arbre);
}
    return racine;
}
void inserer(ABR* arbre, int valeur) {
    arbre->racine = insererEquilibre(arbre->racine, valeur, arbre);
    int h = hauteurNoeud(arbre->racine);
    if (h > arbre->hauteur_max) {
        arbre->hauteur_max = h;
    }
}
