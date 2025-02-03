# CPP Module 06

Ce module se concentre sur les conversions de types en C++, les types statiques et dynamiques.

## Exercices

### Exercise 00: Conversion de types scalaires
Introduction aux conversions de types en C++ :
- Conversion entre types scalaires (int, float, double, char)
- Gestion des cas limites et spéciaux
- Affichage approprié selon le type

### Exercise 01: Sérialisation
Manipulation des pointeurs et de la sérialisation :
- Conversion de pointeurs en types scalaires
- Sérialisation de données
- Manipulation bits à bits

### Exercise 02: Identification de types réels
Travail avec RTTI (Run-Time Type Information) :
- Identification dynamique de types
- Utilisation de dynamic_cast
- Gestion des types polymorphiques

## Compétences acquises
- Conversions de types explicites et implicites
- Manipulation de pointeurs
- Sérialisation de données
- RTTI (Run-Time Type Information)
- Dynamic casting
- Gestion des cas limites
- Manipulation bits à bits

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
- Attention particulière aux conversions de types dangereuses
- Les cas limites doivent être gérés proprement
- La documentation du code est importante pour les conversions complexes