#include "abr_operations.h"
#include <stdio.h>
#include <stdlib.h>

// **** RECHERCHE ****
Noeud* rechercherRecursif(Noeud* racine, int valeur) {
    if (racine == NULL || racine->valeur == valeur) {
        return racine;
    }

    if (valeur < racine->valeur) {
        return rechercherRecursif(racine->gauche, valeur);
    } else {
        return rechercherRecursif(racine->droite, valeur);
    }
}

int rechercher(ABR* arbre, int valeur) {
    Noeud* resultat = rechercherRecursif(arbre->racine, valeur);
    return resultat != NULL;
}

Noeud* trouverMinimum(Noeud* racine) {
    Noeud* courant = racine;
    while (courant && courant->gauche != NULL) {
        courant = courant->gauche;
    }
    return courant;
}

Noeud* trouverMaximum(Noeud* racine) {
    Noeud* courant = racine;
    while (courant && courant->droite != NULL) {
        courant = courant->droite;
    }
    return courant;
}

// **** SUPPRESSION ****
Noeud* supprimerRecursif(Noeud* racine, int valeur, ABR* arbre) {
    if (racine == NULL) return racine;

    if (valeur < racine->valeur) {
        racine->gauche = supprimerRecursif(racine->gauche, valeur, arbre);
    } else if (valeur > racine->valeur) {
        racine->droite = supprimerRecursif(racine->droite, valeur, arbre);
    } else {
        if (racine->compteur > 1) {
            racine->compteur--;
            return racine;
        }

        if (racine->gauche == NULL) {
            Noeud* temp = racine->droite;
            free(racine);
            if (arbre != NULL) arbre->taille--;
            return temp;
        } else if (racine->droite == NULL) {
            Noeud* temp = racine->gauche;
            free(racine);
            if (arbre != NULL) arbre->taille--;
            return temp;
        }

        Noeud* temp = trouverMinimum(racine->droite);
        racine->valeur = temp->valeur;
        racine->compteur = temp->compteur;
        temp->compteur = 1;

        racine->droite = supprimerRecursif(racine->droite, temp->valeur, arbre);
    }

    if (racine == NULL) return racine;

    mettreAJourHauteur(racine);
    int equilibre = facteurEquilibre(racine);

    if (equilibre > 1 && facteurEquilibre(racine->gauche) >= 0) {
        return rotationDroite(racine, arbre);
    }
    if (equilibre > 1 && facteurEquilibre(racine->gauche) < 0) {
        racine->gauche = rotationGauche(racine->gauche, arbre);
        return rotationDroite(racine, arbre);
    }
    if (equilibre < -1 && facteurEquilibre(racine->droite) <= 0) {
        return rotationGauche(racine, arbre);
    }
    if (equilibre < -1 && facteurEquilibre(racine->droite) > 0) {
        racine->droite = rotationDroite(racine->droite, arbre);
        return rotationGauche(racine, arbre);
    }

    return racine;
}

void supprimer(ABR* arbre, int valeur) {
    arbre->racine = supprimerRecursif(arbre->racine, valeur, arbre);
}

// ******* PARCOURS ********
void parcoursInfixeRecursif(Noeud* racine) {
    if (racine != NULL) {
        parcoursInfixeRecursif(racine->gauche);
        printf("%d(%d) ", racine->valeur, racine->compteur);
        parcoursInfixeRecursif(racine->droite);
    }
}

void parcoursPrefixeRecursif(Noeud* racine) {
    if (racine != NULL) {
        printf("%d(%d) ", racine->valeur, racine->compteur);
        parcoursPrefixeRecursif(racine->gauche);
        parcoursPrefixeRecursif(racine->droite);
    }
}

void parcoursPostfixeRecursif(Noeud* racine) {
    if (racine != NULL) {
        parcoursPostfixeRecursif(racine->gauche);
        parcoursPostfixeRecursif(racine->droite);
        printf("%d(%d) ", racine->valeur, racine->compteur);
    }
}

void parcoursNiveaux(Noeud* racine) {
    if (racine == NULL) return;

    Noeud** file = (Noeud**)malloc(1000 * sizeof(Noeud*));
    int debut = 0, fin = 0;

    file[fin++] = racine;

    printf("Parcours par niveaux: ");
    while (debut < fin) {
        Noeud* courant = file[debut++];
        printf("%d(%d) ", courant->valeur, courant->compteur);

        if (courant->gauche != NULL) file[fin++] = courant->gauche;
        if (courant->droite != NULL) file[fin++] = courant->droite;
    }
    printf("\n");

    free(file);
}

void afficherParcoursInfixe(ABR* arbre) {
    printf("Parcours infixe (trié): ");
    parcoursInfixeRecursif(arbre->racine);
    printf("\n");
}

void afficherParcoursPrefixe(ABR* arbre) {
    printf("Parcours préfixe: ");
    parcoursPrefixeRecursif(arbre->racine);
    printf("\n");
}

void afficherParcoursPostfixe(ABR* arbre) {
    printf("Parcours postfixe: ");
    parcoursPostfixeRecursif(arbre->racine);
    printf("\n");
}
