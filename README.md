## Fichiers Principaux

### `src/main.c`

Le fichier `src/main.c` contient le point d'entrée du programme. Il initialise la structure principale `cliz_t` et appelle la fonction `homepage` pour démarrer l'application.

### `Makefile`

Le `Makefile` contient les instructions pour compiler le projet. Il définit les fichiers sources, les bibliothèques nécessaires et les options de compilation.

### Répertoire `includes`

Ce répertoire contient les fichiers d'en-tête du projet, définissant les structures de données et les prototypes de fonctions.

- `includes/chatbot.h` : Définit les structures et les fonctions pour le chatbot.
- `includes/include.h` : Inclut les bibliothèques standard et SFML.
- `includes/macros.h` : Définit des macros utilisées dans tout le projet.
- `includes/prototype.h` : Contient les prototypes de fonctions.
- `includes/struct.h` : Définit les structures de données utilisées dans le projet.

### Répertoire `lib`

Ce répertoire contient des fonctions utilitaires pour la création, la destruction et la gestion des éléments graphiques.

- `lib/create_functions.c` : Contient des fonctions pour créer des boutons et des textes.
- `lib/destroy_functions.c` : Contient des fonctions pour détruire des boutons.
- `lib/set_functions.c` : Contient des fonctions pour définir les textures, les sprites et les polices.
- `lib/utils_functions.c` : Contient des fonctions utilitaires pour manipuler des chaînes de caractères.

### Répertoire `src`

Ce répertoire contient les fichiers sources principaux du projet, organisés par fonctionnalité.

#### Répertoire `chatbot`

- `src/chatbot/api/api.c` : Contient les fonctions pour interagir avec l'API d'intelligence artificielle.
- `src/chatbot/destroy/destroy.c` : Contient des fonctions pour détruire les éléments du chatbot.
- `src/chatbot/events/events.c` : Gère les événements du chatbot.
- `interface/` : Contient les fichiers pour l'interface du chatbot.
  - `src/chatbot/interface/draw.c` : Dessine l'interface du chatbot.
  - `src/chatbot/interface/init.c` : Initialise l'interface du chatbot.
  - `src/chatbot/interface/input.c` : Gère les entrées de texte du chatbot.
  - `src/chatbot/interface/interface.c` : Crée l'interface du chatbot.
  - `src/chatbot/interface/messages.c` : Gère les messages du chatbot.
- `src/chatbot/utils.c` : Contient des fonctions utilitaires pour le chatbot.

#### Répertoire `homepage`

- `src/homepage/destroy_homepage.c` : Détruit les éléments de la page d'accueil.
- `src/homepage/draw_homepage.c` : Dessine la page d'accueil.
- `src/homepage/events_homepage.c` : Gère les événements de la page d'accueil.
- `src/homepage/handle_events.c` : Gère les événements de la fenêtre principale.
- `src/homepage/homepage.c` : Contient la fonction principale pour la page d'accueil.
- `src/homepage/init_homepage.c` : Initialise la page d'accueil.

#### Répertoire `login`

- `src/login/destroy_login_page.c` : Détruit les éléments de la page de connexion.
- `src/login/draw_login_page.c` : Dessine la page de connexion.
- `src/login/handle_login_events.c` : Gère les événements de la page de connexion.
- `src/login/handle_login_input.c` : Gère les entrées de texte de la page de connexion.
- `src/login/init_login_page.c` : Initialise la page de connexion.
- `src/login/load_users_from_file.c` : Charge les utilisateurs à partir d'un fichier.
- `src/login/login.c` : Contient la fonction pour vérifier les informations de connexion.

#### Répertoire `sign_up`

- `src/sign_up/check_sign_up_user.c` : Vérifie les informations d'inscription.
- `src/sign_up/destroy_sign_up_page.c` : Détruit les éléments de la page d'inscription.
- `src/sign_up/destroy_user_list.c` : Détruit la liste des utilisateurs.
- `src/sign_up/draw_sign_up_page.c` : Dessine la page d'inscription.
- `src/sign_up/handle_sign_events.c` : Gère les événements de la page d'inscription.
- `src/sign_up/handle_sign_input.c` : Gère les entrées de texte de la page d'inscription.
- `src/sign_up/init_sign_up_page.c` : Initialise la page d'inscription.
- `src/sign_up/sign_up.c` : Contient la fonction pour ajouter un nouvel utilisateur.

#### Répertoire `window`

- `src/window/destroy_window.c` : Détruit la fenêtre principale.
- `src/window/init_window.c` : Initialise la fenêtre principale.

## Fonctionnalités Principales

### Connexion Utilisateur

La fonctionnalité de connexion permet aux utilisateurs de se connecter en utilisant leur adresse e-mail et leur mot de passe. Les informations de connexion sont vérifiées par rapport à une liste d'utilisateurs chargée à partir d'un fichier.

### Inscription Utilisateur

La fonctionnalité d'inscription permet aux nouveaux utilisateurs de s'inscrire en fournissant un nom d'utilisateur, une adresse e-mail et un mot de passe. Les informations sont vérifiées et ajoutées à la liste des utilisateurs.

### Chatbot

Le chatbot permet aux utilisateurs d'interagir avec une intelligence artificielle en envoyant des messages et en recevant des réponses. L'interface graphique du chatbot est gérée par SFML, et les interactions avec l'IA sont gérées par CURL.

## Conclusion

CLIZ_AI est un projet complet qui combine une interface graphique avec des fonctionnalités de connexion, d'inscription et d'interaction avec un chatbot. La structure de notre projet est bien organisée, avec des fichiers séparés pour chaque fonctionnalité, ce qui facilite la maintenance et l'extension du code 😄
