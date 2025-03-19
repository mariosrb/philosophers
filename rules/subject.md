Objectif général
Le but du projet est de simuler le problème classique du dîner des philosophes en C. Il s'agit de mettre en pratique la programmation concurrente à l'aide de threads (pour la partie obligatoire) et de processus (pour la partie bonus), tout en utilisant les mécanismes de synchronisation appropriés (mutexes et sémaphores).
---
Les grandes parties du projet
Partie obligatoire (philo) :
Architecture :
Chaque philosophe est représenté par un thread.
Autant de philosophes qu'il y a de fourchettes.
Chaque philosophe dispose d’une fourchette à sa gauche et à sa droite (sauf le cas particulier où il n’y a qu’un seul philosophe).
Contraintes et comportements :
Les philosophes réalisent les actions suivantes en boucle : prendre les fourchettes, manger, dormir, et réfléchir.
Pour manger, un philosophe doit récupérer à la fois la fourchette à sa gauche et celle à sa droite. Pour éviter les interblocages (deadlocks), la gestion de la récupération des fourchettes doit être soigneusement orchestrée.
Chaque action (prendre une fourchette, manger, dormir, réfléchir et éventuellement mourir) doit être loggée dans la console avec un timestamp en millisecondes et le numéro du philosophe, suivant un format bien précis.
La simulation s’arrête lorsqu’un philosophe meurt (c’est-à-dire, s’il ne mange pas avant le délai time_to_die) ou, si l’argument optionnel est précisé, lorsque tous les philosophes ont mangé au moins le nombre de fois indiqué.
Exigences techniques :
Le programme doit être compilé avec les flags -Wall -Wextra -Werror via cc.
Aucune variable globale n’est autorisée.
La libération de toute mémoire allouée, ainsi que la destruction correcte des mutex, est impérative.
Le code devra être organisé en fichiers comportant un Makefile avec des règles précises ($(NAME), all, clean, fclean, re).
2. Partie bonus (philo_bonus) :
Architecture :
Chaque philosophe est représenté par un processus séparé.
Plutôt que d’attribuer une fourchette à chaque philosophe, toutes les fourchettes sont placées au centre de la table, leur disponibilité étant gérée par un sémaphore.
Particularités :
Les mêmes comportements et contraintes que la partie obligatoire s’appliquent (manger, dormir, réfléchir, mourir, gestion des timings, logs précis, etc.).
La synchronisation se fait à l'aide de sémaphores (par exemple en utilisant sem_open, sem_wait, sem_post, etc.) au lieu des mutex classiques.
Critère d’évaluation :
La partie bonus ne sera évaluée que si la partie obligatoire est totalement fonctionnelle et conforme aux exigences.
---
Points clés et contraintes supplémentaires
Affichage des logs :
Chaque changement d'état d'un philosophe doit être affiché avec le format suivant :
timestamp_in_ms
 
X
 
a
 
pris
 
une
 
fourchette
timestamp_in_ms X a pris une fourchette
timestamp_in_ms
 
X
 
mange
timestamp_in_ms X mange
timestamp_in_ms
 
X
 
dort
timestamp_in_ms X dort
timestamp_in_ms
 
X
 
r
e
ˊ
fl
e
ˊ
chit
timestamp_in_ms X r 
e
ˊ
 fl 
e
ˊ
 chit
timestamp_in_ms
 
X
 
est
 
mort
timestamp_in_ms X est mort
Il est important que ces messages soient affichés de manière à éviter tout chevauchement (race condition sur l'affichage).
Gestion des erreurs et libération de ressources :
Tout segment de mémoire allouée doit être libéré, et toute ressource système (mutex, sémaphores, etc.) doit être correctement détruite pour éviter les fuites ou les comportements indéfinis.
Précision temporelle :
Le timestamp doit être en millisecondes, et si un philosophe meurt, le message de mort doit être affiché dans les 10 ms suivant l’événement réel.
Synchronisation :
Pour éviter les problèmes de concurrence (data races), l’accès aux fourchettes (ou au sémaphore dans le bonus) devra se faire de manière sécurisée.