# 🌳 Arbre Binaire de Recherche (ABR) Avancé - Implémentation en C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C Standard](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

Une implémentation complète et optimisée d'un **Arbre Binaire de Recherche (ABR)** en langage C avec équilibrage automatique, gestion des doublons et fonctionnalités avancées.

## 👥 Contributeurs
Ce projet a été réalisé par 3 développeurs :

[Mahaisoa ( MrSicario)] L1C-249 - Structures de base et insertion

[Djamaldine] - Opérations et parcours

[Mihaja] - Fonctionnalités avancées et intégration


## 📋 Table des Matières

- [🎯 Features](#-features)
- [🏗️ Architecture du Projet](#️-architecture-du-projet)
- [🚀 Installation et Compilation](#-installation-et-compilation)
- [🔍 Algorithmes Implémentés](#-algorithmes-implémentés)
- [📊 Complexités](#-complexités)
- [💻 Exemples d'Utilisation](#-exemples-dutilisation)

## 🎯 Features

### ✅ **Fonctionnalités de Base**
- **Insertion** avec équilibrage automatique
- **Recherche** rapide en O(log n)
- **Suppression** intelligente (3 cas gérés)
- **Gestion des doublons** avec compteur

### 🔥 **Fonctionnalités Avancées**
- **Équilibrage automatique** par rotations
- **Parcours multiples** (infixe, préfixe, postfixe, niveaux)
- **Recherche par plage** d'éléments
- **K-ème élément** le plus petit
- **Sauvegarde/chargement** depuis fichier
- **Statistiques complètes** de l'arbre
- **Validation** de la propriété ABR

### 🛡️ **Qualités du Code**
- **Gestion mémoire** rigoureuse (pas de fuites)
- **Découpage modulaire** en 3 parties
- **Documentation** complète
- **Tests intensifs** inclus
- **Code optimisé** pour la performance

## 🏗️ Architecture du Projet

📦 ABR_Avance/

├── 📄 abr_base.h/.c # Partie 1 - Structures et insertion

├── 📄 abr_operations.h/.c # Partie 2 - Recherche, suppression, parcours

├── 📄 abr_avance.h/.c # Partie 3 - Fonctionnalités avancées et main

├── 📄 Makefile # Système de compilation

└── 📄 README.md # Documentation



### **Répartition des Tâches par Membre**

| Membre | Partie | Responsabilités |
|--------|--------|-----------------|
| **Membre 1** | `abr_base` | Structures, insertion, équilibrage |
| **Membre 2** | `abr_operations` | Recherche, suppression, parcours |
| **Membre 3** | `abr_avance` | Fonctions avancées, main, statistiques |

## 🚀 Installation et Compilation

### **Prérequis**
- Compilateur C (gcc recommandé)
- Système Linux/Unix ou Windows avec WSL

### **Compilation**
```
# Cloner le dépôt
git clone https://github.com/votre-username/ABR_Avance.git
cd ABR_Avance

# Compilation simple
make

# Ou compilation manuelle
gcc -Wall -Wextra -std=c99 -O2 -c abr_base.c
gcc -Wall -Wextra -std=c99 -O2 -c abr_operations.c
gcc -Wall -Wextra -std=c99 -O2 -c abr_avance.c
gcc -Wall -Wextra -std=c99 -O2 -o abr_avance abr_base.o abr_operations.o abr_avance.o

# Exécution
ex : ./abr_avance

# Nettoyage
make clean
```

## 🔍 Algorithmes Implémentés
1. Insertion avec Équilibrage
```
Algorithme insererEquilibre(racine, valeur):
    Si racine est NULL → créer nouveau nœud
    Sinon si valeur < racine.valeur → aller à gauche
    Sinon si valeur > racine.valeur → aller à droite
    Sinon → incrémenter compteur
    
    Mettre à jour la hauteur
    Calculer facteur d'équilibre
    
    Cas déséquilibre gauche-gauche → rotation droite
    Cas déséquilibre droite-droite → rotation gauche  
    Cas déséquilibre gauche-droite → double rotation
    Cas déséquilibre droite-gauche → double rotation
```
2. Suppression Intelligente
```
Algorithme supprimer(racine, valeur):
    Trouver le nœud à supprimer
    Cas 1: Feuille → suppression simple
    Cas 2: Un enfant → remplacement
    Cas 3: Deux enfants → remplacer par successeur inordre
    Rééquilibrer l'arbre après suppression
```
3. Recherche par Plage
```
Algorithme elementsPlage(racine, min, max):
    Si min < racine.valeur → explorer gauche
    Si min ≤ racine.valeur ≤ max → afficher
    Si max > racine.valeur → explorer droite
```

## 📊 Complexités
*Avec équilibrage automatique

|Opération | 	Meilleur Cas |	Cas Moyen	| Pire Cas |
|----------|---------------|------------|----------|
|Insertion |	    O(1)	   |   O(log n)	|  O(log n)*|
|Recherche |	    O(1)	   |   O(log n)	|  O(log n)*|
|Suppression |  	O(1)	   |   O(log n)	|  O(log n)*|
|Parcours	   | O(n)	       |    O(n)	  |    O(n)   |
|Hauteur	   |   O(log n)	 |    O(log n)	|  O(log n)*|

## 💻 Exemples d'Utilisation
- Exemple 1 : Création et Manipulation
```
#include "abr_avance.h"

int main() {
    ABR* arbre = (ABR*)malloc(sizeof(ABR));
    initialiserABR(arbre);
    
    // Insertion multiple
    int donnees[] = {50, 30, 70, 20, 40, 60, 80, 30, 50};
    for (int i = 0; i < 9; i++) {
        inserer(arbre, donnees[i]);
    }
    
    afficherParcoursInfixe(arbre);
    // Output: 20(1) 30(2) 40(1) 50(2) 60(1) 70(1) 80(1)
    
    afficherStatistiques(arbre);
    libererABR(arbre);
    return 0;
}
```
- Exemple 2 : Recherches Avancées
```
// Recherche du 5ème plus petit élément
int compteur = 0;
Noeud* kieme = kiemeElement(arbre->racine, 5, &compteur);
if (kieme) {
    printf("5ème élément: %d\n", kieme->valeur);
}

// Recherche entre 25 et 60
printf("Éléments 25-60: ");
elementsPlage(arbre->racine, 25, 60);
printf("\n");
```
- Exemple 3 : Sauvegarde
```
// Sauvegarde de l'arbre
if (sauvegarderABR(arbre, "mon_arbre.txt")) {
    printf("Sauvegarde réussie!\n");
}

// Chargement
ABR* arbre_charge = chargerABR("mon_arbre.txt");
```
