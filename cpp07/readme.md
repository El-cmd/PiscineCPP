# CPP Module 07

Ce module se concentre sur les templates en C++, permettant la programmation générique.

## Exercices

### Exercise 00: Début
Introduction aux templates avec des fonctions simples :
- Création de fonctions template
- Utilisation de types génériques
- Spécialisation de templates

### Exercise 01: Iter
Création d'une fonction template iter :
- Templates avec plusieurs paramètres
- Manipulation de tableaux génériques
- Fonctions callback génériques

### Exercise 02: Array
Implémentation d'une classe template Array :
- Création de classes template
- Gestion de la mémoire avec les templates
- Surcharge d'opérateurs pour types génériques

## Compétences acquises
- Templates de fonctions
- Templates de classes
- Programmation générique
- Spécialisation de templates
- Paramètres de templates
- Contraintes de types
- Manipulation de tableaux génériques

## Comment compiler
Chaque exercice contient son propre Makefile. Pour compiler un exercice :
```bash
cd exXX
make
```

## Notes
- Tous les exercices doivent être compilés avec les flags : -Wall -Wextra -Werror
- Le code doit suivre la norme C++98
- La forme canonique reste obligatoire pour toutes les classes
- Les templates doivent être définis dans les fichiers headers
- Attention à la gestion des cas limites avec les types génériques
- La documentation est cruciale pour les templates
- Les tests doivent couvrir différents types de données