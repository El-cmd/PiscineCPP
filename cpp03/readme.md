# CPP Module 03

Ce module se concentre sur l'héritage en C++, un concept fondamental de la programmation orientée objet.

## Exercices

### Exercise 00: Aaaaand... OPEN!
Introduction à l'héritage avec la création d'une classe de base ClapTrap. Cet exercice permet de comprendre :
- Les bases de l'héritage
- L'initialisation des classes de base
- La gestion des attributs protégés

### Exercise 01: Serena, my love!
Extension de l'exercice précédent avec la création d'une classe dérivée ScavTrap. Points clés :
- Héritage public
- Redéfinition de méthodes
- Constructeurs et destructeurs dans l'héritage

### Exercise 02: Repetitive work
Introduction d'une nouvelle classe dérivée FragTrap, démontrant :
- L'héritage multiple
- La réutilisation de code
- Les spécificités de chaque classe dérivée

## Compétences acquises
- Héritage simple et multiple
- Membres et méthodes protégés
- Constructeurs et destructeurs virtuels
- Redéfinition de méthodes
- Initialisation des classes de base
- Ordre d'appel des constructeurs et destructeurs

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
- L'utilisation appropriée des modificateurs d'accès (public, protected, private) est cruciale
- Attention particulière à la gestion de la mémoire dans les hiérarchies de classes