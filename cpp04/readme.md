# CPP Module 04

Ce module se concentre sur le polymorphisme, les classes abstraites et les interfaces en C++.

## Exercices

### Exercise 00: Polymorphisme
Introduction au polymorphisme avec des classes d'animaux :
- Utilisation des classes de base
- Fonctions virtuelles
- Comportements spécifiques aux classes dérivées

### Exercise 01: Je ne veux pas brûler le monde
Approfondissement du polymorphisme avec :
- Gestion de la mémoire dans les hiérarchies de classes
- Interactions entre différentes classes
- Utilisation appropriée des destructeurs virtuels

### Exercise 02: Classe abstraite
Introduction aux classes abstraites :
- Méthodes virtuelles pures
- Classes abstraites vs interfaces
- Implémentation de comportements abstraits

### Exercise 03: Interface & recap
Utilisation avancée des interfaces et récapitulation des concepts :
- Création et utilisation d'interfaces
- Gestion d'inventaire de materia
- Application pratique du polymorphisme

## Compétences acquises
- Polymorphisme
- Classes abstraites
- Interfaces
- Fonctions virtuelles et virtuelles pures
- Destructeurs virtuels
- Héritage multiple avec interfaces
- Gestion dynamique des objets

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
- Attention particulière à la gestion de la mémoire avec le polymorphisme
- Les destructeurs virtuels sont essentiels dans les classes de base
- L'utilisation correcte des interfaces est cruciale pour la conception orientée objet