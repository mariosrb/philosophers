# Résumé de la Norme 42

La **Norme 42** est un ensemble de règles et de conventions de codage adoptées dans l'école 42. Son objectif est de garantir la qualité, la lisibilité et la maintenabilité du code. Ce résumé présente les points essentiels de cette norme :

## 1. Formatage et Indentation

- **Indentation** : Utilisez **une tabulation** par niveau d'indentation.
- **Longueur des lignes** : Limitez chaque ligne à environ 80 colonnes (sauf exceptions justifiées).
- **Espacement** : Veillez à ajouter des espaces là où nécessaire (après des virgules, autour d'opérateurs, etc.) et à éviter les espaces inutiles en fin de ligne.

## 2. Nommage

- **Variables et Fonctions** : Choisissez des noms explicites et représentatifs. Les conventions recommandent souvent l'usage du *snake_case* (lettres minuscules séparées par des underscores).
- **Constantes** : Elles sont généralement écrites en majuscules avec des underscores pour séparer les mots.
- **Fichiers** : Le nom du fichier doit indiquer clairement son contenu.

## 3. Structure du Code

- **En-tête de fichier** : Chaque fichier source doit comporter un en-tête en commentaire mentionnant le nom du fichier, l’auteur, les dates de création et de modification, ainsi qu’une brève description.
- **Blocs de code** : Tous les blocs (fonctions, boucles, conditions) doivent être entourés d’accolades, même pour une seule instruction.
- **Fonctions** : Elles doivent être concises et réaliser une tâche spécifique. En cas de complexité excessive, une fonction doit être décomposée en sous-fonctions.

## 4. Commentaires

- **Utilisation** : Les commentaires doivent éclairer les parties complexes du code ou justifier des choix techniques.
- **Format** : Respectez un style uniforme pour la rédaction des commentaires, qu’ils soient en ligne ou en bloc.

## 5. Bonnes Pratiques

- **Lisibilité** : Le code doit être écrit de manière claire et facile à comprendre par d’autres développeurs.
- **Modularité** : Privilégiez la décomposition du code en modules et fonctions pour limiter la complexité.
- **Gestion des erreurs** : Implémentez une vérification systématique des retours de fonctions et une gestion rigoureuse des erreurs.
- **Compilation** : Le code doit se compiler sans avertissements, en utilisant, par exemple, les flags \( -Wall \), \( -Wextra \) et \( -Werror \).

## 6. Limitations et Spécificités

- **Bibliothèques** : L’utilisation de certaines bibliothèques peut être restreinte afin de favoriser la réécriture ou la compréhension des fonctions de base.
- **Variables Globales** : Leur usage est fortement déconseillé pour limiter les effets de bord et améliorer la maintenabilité.

---