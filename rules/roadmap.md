1. Analyse et Compréhension du Sujet
Lecture du sujet :
Comprendre le problème du dîner des philosophes.
Identifier les comportements à simuler :
Prendre les fourchettes
Manger
Dormir
Réfléchir
Et la détection de la mort (si un philosophe ne mange pas dans le délai time_to_die).
Notions à approfondir :
Programmation avec pthreads : création, gestion et synchronisation des threads.
Utilisation des mutex pour protéger l'accès aux ressources partagées (fourchettes et affichage).
---
2. Conception de l’Architecture du Projet
Structures des données :
Structure pour un philosophe (nommée par exemple t_philo) :
Identifiant du philosophe.
Timestamp du dernier repas.
Nombre de repas consommés.
Pointeurs ou références vers ses deux fourchettes (ou les indices correspondants dans un tableau de mutex).
Structure de la simulation (par exemple t_sim ou t_table) :
Nombre total de philosophes.
Paramètres globaux (time_to_die, time_to_eat, time_to_sleep).
Tableau de mutex, un par fourchette.
Un mutex dédié à l'affichage afin de garantir que les logs ne se chevauchent pas.
Organisation du code en modules :
main.c : Point d’entrée du programme, parsing des arguments, lancement de la simulation.
init.c / init.h : Initialisation des structures (allocation mémoire, initialisation des mutex, etc.).
routine.c / routine.h : Fonctions gérant la vie du philosophe (boucle principale, prise et libération des fourchettes, actions manger/dormir/réfléchir, vérification du temps pour détecter une mort).
utils.c / utils.h : Fonctions utilitaires (par exemple, récupération du timestamp en millisecondes, fonctions d'affichage synchronisé).
---
3. Implémentation de la Partie Obligatoire
3.1. Préparation du Projet
Configuration du Makefile :
Créer le dossier philo/ avec vos fichiers sources.
Prévoir un Makefile qui compile avec cc en utilisant les flags -Wall -Wextra -Werror.
Mettre en place les règles obligatoires : $(NAME), all, clean, fclean, re.
Organisation initiale :
Créer les fichiers de base (main.c, philo.h, etc.) en respectant la norme.
3.2. Initialisation et Création des Ressources
Initialisation de la simulation :
Allouer et initialiser un tableau de threads, un pour chaque philosophe.
Créer et initialiser un mutex pour chaque fourchette.
Mettre en place un mutex spécifique pour protéger l’affichage des logs.
Configuration des paramètres :
Parser les arguments pour récupérer :
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
(Éventuellement) number_of_times_each_philosopher_must_eat
3.3. Écriture de la Boucle de Vie d’un Philosophe
Processus de la routine de chaque thread :
1. Prise des fourchettes :
Utiliser les mutex associés aux fourchettes de gauche et de droite.
Afficher les logs « X a pris une fourchette » dès que chaque fourchette est prise.
Veiller à un ordre de prise qui permette d’éviter les deadlocks (par exemple, en imposant un ordre de verouillage ou en utilisant une stratégie adaptée pour le cas particulier où il n’y a qu’un seul philosophe).
2. Action « Manger » :
Une fois les deux fourchettes prises, afficher le message « X mange ».
Mettre à jour le timestamp du dernier repas.
Dormir pendant time_to_eat millisecondes.
Libération des ressources :
Déverrouiller les mutex des deux fourchettes.
Action « Dormir » :
Afficher le message « X dort ».
Dormir pendant time_to_sleep millisecondes.
5. Action « Réfléchir » :
Afficher le message « X réfléchit ».
Vérification de l’état de vie :
Dans une boucle ou via un thread séparé, vérifier régulièrement si un philosophe n’a pas mangé dans le délai time_to_die. En cas de dépassement, afficher immédiatement (dans les 10 ms) le log de mort et mettre fin à la simulation.
Cas particulier d’un seul philosophe :
Gérer le scénario où un philosophe ne dispose que d’une seule fourchette et finira par mourir faute d’alternative.
---
4. Tests et Débogage
Tests fonctionnels :
Tester avec différentes valeurs pour les paramètres (nombre de philosophes, temps à manger, etc.).
Vérifier que les logs s’affichent correctement et qu’il n’y a pas de chevauchement grâce au mutex dédié à l’affichage.
Contrôle de la synchronisation :
S’assurer que les mutex protègent bien l'accès aux fourchettes.
Vérifier l’absence de data races et de deadlocks.
Gestion des ressources :
Contrôler que tous les mutex sont correctement détruits et que toute la mémoire allouée est bien libérée.
---
5. Finalisation et Préparation à la Défense
Relecture et Conformité :
Relire le sujet pour s'assurer que toutes les exigences sont respectées.
Vérifier la conformité avec la norme de code imposée.
Documentation :
Rédiger un README ou un document de présentation décrivant l’architecture du projet et les choix techniques.
Ajouter des commentaires clairs dans le code pour expliquer la logique de chaque partie.
Préparation à la Défense :
Préparer quelques tests pour démontrer le fonctionnement de la simulation.
Être prêt à expliquer comment la synchronisation est gérée et comment les mutex permettent d’éviter les conflits entre threads.
