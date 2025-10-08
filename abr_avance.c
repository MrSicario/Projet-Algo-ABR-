#include "abr_avance.h"
#include <stdio.h>
#include <stdlib.h>

// ========== FONCTIONNALITÉS AVANCÉES ==========
int hauteurArbre(Noeud* racine) {
    if (racine == NULL) return 0;
    int h_gauche = hauteurArbre(racine->gauche);
    int h_droite = hauteurArbre(racine->droite);
    return (h_gauche > h_droite ? h_gauche : h_droite) + 1;
}

int compterNoeuds(Noeud* racine) {
    if (racine == NULL) return 0;
    return 1 + compterNoeuds(racine->gauche) + compterNoeuds(racine->droite);
}

int estABRValide(Noeud* racine, int min, int max) {
    if (racine == NULL) return 1;

    if (racine->valeur <= min || racine->valeur >= max) {
        return 0;
    }

    return estABRValide(racine->gauche, min, racine->valeur) &&
    estABRValide(racine->droite, racine->valeur, max);
}

Noeud* kiemeElement(Noeud* racine, int k, int* compteur) {
    if (racine == NULL) return NULL;

    Noeud* gauche = kiemeElement(racine->gauche, k, compteur);
    if (gauche != NULL) return gauche;

    (*compteur)++;
    if (*compteur == k) return racine;

    return kiemeElement(racine->droite, k, compteur);
}

void elementsPlage(Noeud* racine, int min, int max) {
    if (racine == NULL) return;

    if (min < racine->valeur) {
        elementsPlage(racine->gauche, min, max);
    }

    if (min <= racine->valeur && racine->valeur <= max) {
        printf("%d(%d) ", racine->valeur, racine->compteur);
    }

    if (max > racine->valeur) {
        elementsPlage(racine->droite, min, max);
    }
}

// ========= STATISTIQUES ET ANALYSE =======
void afficherStatistiques(ABR* arbre) {
    printf("\n========== STATISTIQUES DE L'ABR ==========\n");
    printf("Taille totale: %d nœuds\n", arbre->taille);
    printf("Hauteur maximale: %d\n", hauteurArbre(arbre->racine));
    printf("Nombre de rotations: %d\n", arbre->rotations);
    printf("Facteur d'équilibre racine: %d\n", facteurEquilibre(arbre->racine));

    Noeud* min = trouverMinimum(arbre->racine);
    Noeud* max = trouverMaximum(arbre->racine);
    if (min && max) {
        printf("Minimum: %d, Maximum: %d\n", min->valeur, max->valeur);
    }

    printf("ABR valide: %s\n", estABRValide(arbre->racine, -1000000, 1000000) ? "OUI" : "NON");
    printf("============================================\n\n");
}

// ======= SAUVEGARDE ET CHARGEMENT ========
void sauvegarderInfixe(Noeud* racine, FILE* fichier) {
    if (racine == NULL) return;

    sauvegarderInfixe(racine->gauche, fichier);
    for (int i = 0; i < racine->compteur; i++) {
        fprintf(fichier, "%d ", racine->valeur);
    }
    sauvegarderInfixe(racine->droite, fichier);
}

int sauvegarderABR(ABR* arbre, const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) return 0;

    sauvegarderInfixe(arbre->racine, fichier);
    fclose(fichier);
    return 1;
}

ABR* chargerABR(const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) return NULL;

    ABR* arbre = (ABR*)malloc(sizeof(ABR));
    initialiserABR(arbre);

    int valeur;
    while (fscanf(fichier, "%d", &valeur) == 1) {
        inserer(arbre, valeur);
    }

    fclose(fichier);
    return arbre;
}

// ========= GESTION MÉMOIRE ===========
void libererArbre(Noeud* racine) {
    if (racine != NULL) {
        libererArbre(racine->gauche);
        libererArbre(racine->droite);
        free(racine);
    }
}
void libererABR(ABR* arbre) {
    libererArbre(arbre->racine);
    free(arbre);
}

// ========== FONCTION PRINCIPALE ======
int main() {
    printf("===== ARBRE BINAIRE DE RECHERCHE AVANCÉ =====\n\n");

    ABR* arbre = (ABR*)malloc(sizeof(ABR));
    initialiserABR(arbre);

    printf("=== PHASE 1: INSERTIONS ===\n");
    int donnees[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 30, 50, 70};
    int nb_donnees = sizeof(donnees) / sizeof(donnees[0]);

    for (int i = 0; i < nb_donnees; i++) {
        inserer(arbre, donnees[i]);
    }

    printf("\n=== PARCOURS DE L'ARBRE ===\n");
    afficherParcoursInfixe(arbre);
    afficherParcoursPrefixe(arbre);
    parcoursNiveaux(arbre->racine);

    afficherStatistiques(arbre);

    printf("\n=== PHASE 2: RECHERCHES ===\n");
    printf("Recherche de 30: %s\n", rechercher(arbre, 30) ? "TROUVÉ" : "NON TROUVÉ");
    printf("Recherche de 55: %s\n", rechercher(arbre, 55) ? "TROUVÉ" : "NON TROUVÉ");

    printf("\n=== PHASE 3: FONCTIONNALITÉS AVANCÉES ===\n");
    int k = 5;
    int compteur = 0;
    Noeud* kieme = kiemeElement(arbre->racine, k, &compteur);
    if (kieme) {
        printf("%d-ème plus petit élément: %d\n", k, kieme->valeur);
    }
    printf("Éléments entre 25 et 60: ");
    elementsPlage(arbre->racine, 25, 60);
    printf("\n");

    printf("\n=== PHASE 4: SUPPRESSIONS ===\n");
    supprimer(arbre, 20);
    supprimer(arbre, 30);
    supprimer(arbre, 50);
    afficherParcoursInfixe(arbre);
    afficherStatistiques(arbre);

    printf("\n=== PHASE 5: SAUVEGARDE ===\n");
    if (sauvegarderABR(arbre, "arbre_sauvegarde.txt")) {
        printf("Sauvegarde réussie\n");
    }

    libererABR(arbre);
    printf("\n===== PROGRAMME TERMINÉ =====\n");
    return 0;
}
