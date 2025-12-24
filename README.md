# Solitaire – Jeu de cartes en C++ (Console)

## Description

Ce projet est un **jeu de Solitaire (Klondike)** développé en **C++**, entièrement jouable dans le **terminal**.  
Il s’agit d’un **projet extrascolaire personnel**, réalisé pour consolider les compétences en programmation C++ et structuration de projets.

Le programme implémente l’intégralité de la logique du jeu : création et mélange des cartes, gestion du plateau, déplacements selon les règles officielles du Solitaire, affichage en console et détection de la victoire.

Aucune bibliothèque externe n’est utilisée : le projet repose uniquement sur la **bibliothèque standard C++**.

---

## Objectifs pédagogiques

- Maîtriser la **programmation orientée objet** en C++
- Structurer un projet C++ avec fichiers `.h` et `.cpp`
- Manipuler des **structures de données** (`std::vector`, `std::array`)
- Implémenter une **logique de jeu complète**
- Gérer des **entrées utilisateur en console**
- Produire un projet propre et lisible pour un **portfolio étudiant**

---

## Fonctionnalités principales

- Génération complète d’un jeu de **52 cartes**
- Mélange aléatoire de la pioche
- Mise en place automatique du plateau de jeu (7 colonnes)
- Gestion :
  - de la pioche
  - de la défausse
  - des colonnes de jeu
  - des 4 piles de fondation
- Déplacements autorisés :
  - colonne vers colonne
  - pioche vers colonne
  - colonne ou pioche vers fondation
- Respect strict des règles du Solitaire :
  - alternance des couleurs
  - ordre décroissant dans les colonnes
  - ordre croissant par couleur dans les fondations
- Gestion des cartes visibles et cachées
- Détection automatique de la victoire
- Affichage du plateau en **ASCII** avec symboles de cartes (♠ ♥ ♣ ♦) et couleurs en console
- Interface utilisateur textuelle simple et intuitive

---

## Architecture du projet

Le projet est organisé en plusieurs classes et fichiers pour une structure claire et modulable :

### `main.cpp`
- Point d’entrée du programme
- Initialise l’encodage UTF-8 (Windows)
- Crée l’instance du jeu et lance la boucle principale

### `CGame` (`Game.h` / `Game.cpp`)
- Gère la **boucle principale du jeu**
- Affiche le plateau
- Récupère les actions du joueur
- Appelle les méthodes du plateau en fonction des choix

### `CPlateau` (`Plateau.h` / `Plateau.cpp`)
- Représente l’état complet de la partie
- Contient :
  - la pioche
  - la défausse
  - les 7 colonnes de jeu
  - les 4 piles de fondation
- Implémente :
  - l’affichage du plateau
  - les règles de déplacement
  - la gestion de la pioche
  - la vérification de la victoire
- Surcharge de l’opérateur `<<` pour l’affichage en console

### `CCarte` (`Carte.h` / `Carte.cpp`)
- Représente une carte individuelle
- Attributs :
  - valeur
  - couleur
  - visibilité
- Méthodes :
  - accès aux données
  - affichage textuel formaté
  - gestion de la visibilité

### `fonction.h` / `fonction.cpp`
- Fonctions utilitaires globales :
  - création de la pioche
  - mélange aléatoire des cartes
  - remplissage initial du plateau
  - génération de nombres aléatoires

---

## Commandes du jeu

Lors de l’exécution, le joueur peut choisir :

- `P` : Découvrir une carte de la pioche
- `M` : Monter une carte vers une pile de fondation
- `D` : Déplacer une ou plusieurs cartes entre colonnes
- `E` : Déplacer une carte de la pioche vers une colonne
- `Q` : Quitter le jeu

Les entrées se font directement via le clavier et sont guidées par des messages en console.

---

## Conditions de victoire

La partie est gagnée lorsque :  

- Les **4 piles de fondation** contiennent chacune **13 cartes**
- Toutes les cartes sont rangées correctement par couleur et par valeur

Un message de victoire est alors affiché.

---

## Technologies utilisées

- **Langage** : C++
- **Standard** : C++17
- **Paradigme** : Programmation orientée objet
- **Bibliothèque** : Standard C++ uniquement
- **Plateforme** : Windows (UTF-8 pour l’affichage des symboles)

