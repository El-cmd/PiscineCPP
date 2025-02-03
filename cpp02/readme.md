# CPP Module 02

Ce module se concentre sur la programmation orientée objet en C++, particulièrement sur les opérateurs de surcharge et la forme canonique des classes.

## Exercices

### Exercise 00: Mon premier canon
Introduction à la forme canonique orthodoxe de Coplien. Implémentation d'une classe avec les éléments essentiels :
- Constructeur par défaut
- Constructeur de copie
- Opérateur d'assignation
- Destructeur

### Exercise 01: Premiers pas vers une classe utile
Extension des concepts avec l'implémentation d'une classe de nombres à virgule fixe. Introduction aux opérateurs de comparaison et arithmétiques.

### Exercise 02: Maintenant, on parle
Amélioration de la classe de nombres à virgule fixe avec des fonctions membres supplémentaires et des opérateurs de conversion.

## Compétences acquises
- Forme canonique orthodoxe de Coplien
- Surcharge d'opérateurs
- Manipulation des nombres à virgule fixe
- Opérateurs de conversion
- Membres statiques de classe
- Fonctions membres constantes

## Comment compiler
Chaque exercice contient son propre Makefile. Pour compiler un exercice :
```bash
cd exXX
make
```

## Notes
- Tous les exercices doivent être compilés avec les flags : -Wall -Wextra -Werror
- Le code doit suivre la norme C++98
- La forme canonique est obligatoire pour toutes les classes
- Les opérateurs doivent être implémentés de manière cohérente et logique