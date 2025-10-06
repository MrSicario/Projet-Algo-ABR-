# 🌳 Arbre Binaire de Recherche (ABR) Avancé - Implémentation en C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C Standard](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

Une implémentation complète et optimisée d'un **Arbre Binaire de Recherche (ABR)** en langage C avec équilibrage automatique, gestion des doublons et fonctionnalités avancées.

## 📋 Table des Matières

- [🎯 Features](#-features)
- [🏗️ Architecture du Projet](#️-architecture-du-projet)
- [🚀 Installation et Compilation](#-installation-et-compilation)
- [📚 API Référence](#-api-référence)
- [🔍 Algorithmes Implémentés](#-algorithmes-implémentés)
- [📊 Complexités](#-complexités)
- [💻 Exemples d'Utilisation](#-exemples-dutilisation)
- [👥 Contributeurs](#-contributeurs)
- [📄 License](#-license)

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
