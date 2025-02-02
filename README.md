# Documentation pour notre Projet CLIZ_AI

## Aperçu du Projet
Ce projet est une application complète conçue pour offrir une interface utilisateur conviviale pour gérer et interagir avec diverses fonctionnalités. Il comprend des composants pour chatbot, page d'accueil, connexion, inscription et gestion de la fenêtre.

## Description du Projet
Le projet CLIZ_AI est une application web complète qui offre une interface utilisateur intuitive pour gérer et interagir avec diverses fonctionnalités. Il est conçu pour faciliter l'interaction avec un chatbot, une page d'accueil, une gestion de connexion, une inscription et la gestion de la fenêtre de l'application.

## Fonctionnalités Principales
- **Chatbot** : Interface de chatbot pour l'interaction utilisateur.
- **Page d'accueil** : Interface principale de l'application.
- **Connexion** : Gestion de la fonctionnalité de connexion.
- **Inscription** : Gestion du processus d'inscription des utilisateurs.
- **Gestion de la fenêtre** : Gestion de la fenêtre de l'application et ses événements.

## Technologies Utilisées
- **Langages de programmation** : C.
- **Bibliothèques** : Csfml, Curl, Json.
- **Outils** : Github, Trello, Miro, VSCode.

## Installation et Configuration
Pour installer et configurer le projet, vous devez :
1. Cloner le dépôt sur votre machine :
`git clone https://github.com/MisterIvanZik/CLIZ_AI.git`

`cd CLIZ_AI`
2. Installer les dépendances en exécutant :
`sudo apt-get update`

`sudo apt-get install libcsfml-dev libcurl4-openssl-dev libjson-c-dev`
3. Configurer la base de données en modifiant le fichier `database.txt`.
4. Lancer l'application en exécutant :
`make`

`./cliz_ai`

## Utilisation
Pour utiliser l'application, vous pouvez :
- Interagir avec le chatbot en utilisant la page d'accueil.
- Se connecter ou s'inscrire à l'aide des fonctionnalités de connexion et d'inscription.
- Gérer la fenêtre de l'application en utilisant les événements spécifiques.

## Structure du Projet
Le projet est organisé en plusieurs dossiers et fichiers :
- **assets** : Contient des images, des polices et autres ressources utilisées dans l'application.
- **header** : Inclut des fichiers de tête pour le projet.
- **lib** : Contient des fichiers de bibliothèque pour des fonctions et des utilitaires.
- **Makefile** : Définit le processus de construction pour le projet.
- **README.md** : Ce fichier, fournissant une documentation pour le projet.
- **src** : Contient des fichiers de code source pour les différents composants de l'application.

### Détails Techniques de l'IA
- **URL de l'API** : `https://glhf.chat/api/openai/v1`
- **Modèle Utilisé** : Qwen2.5-7B-Instruct
- **Clé d'API** : La clé d'API est stockée dans le fichier `defines.h` et est utilisée pour authentifier les requêtes à l'API.

## Auteurs
- Ivan Zazic
- Clara Lisika

## Contact
Pour toute demande ou feedback, veuillez contacter le mainteneur du projet à zazicivan@gmail.com.
