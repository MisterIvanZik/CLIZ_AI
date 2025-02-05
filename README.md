# Documentation pour notre Projet CLIZ_AI

## Aperçu du Projet
CLIZ_AI est une application de chatbot intelligente qui combine une interface graphique moderne avec des modèles d'IA avancés. Elle offre une expérience utilisateur complète avec authentification, personnalisation et interaction en temps réel.

## Description du Projet
Le projet CLIZ_AI est une application en C qui propose une interface chatbot sophistiquée avec plusieurs modèles d'IA au choix. L'application intègre un système d'authentification complet, un thème clair/sombre, et une gestion efficace des ressources grâce à un système de cache intelligent.

## Fonctionnalités Principales
### Interface Utilisateur
- Interface graphique fluide et responsive avec CSFML
- Support des thèmes clair/sombre avec basculement en temps réel
- Menu de sélection de modèles d'IA (Qwen, Mistral, Llama)
- Système de scroll pour l'historique des messages

### Chatbot
- Trois modèles d'IA au choix :
  - Qwen 2.5 Coder
  - Mistral v0.3
  - Llama 3.2
- Système de cache pour optimiser les réponses fréquentes
- Limite de taille de messages pour une meilleure expérience

### Système d'Authentification
- Inscription sécurisée des utilisateurs
- Connexion avec email et mot de passe
- Gestion des sessions utilisateur
- Stockage sécurisé des données utilisateur

## Technologies et Architecture
### Technologies Utilisées
- **Langage** : C
- **Interface Graphique** : CSFML (Simple and Fast Multimedia Library pour C)
- **Gestion API** : libcurl
- **Traitement JSON** : json-c
- **Outils** :
  - Github : Gestion de version
  - Trello : Gestion de projet
  - Miro : Design et planification
  - VSCode : Développement

### Architecture du Projet
```
CLIZ_AI/
├── assets/            # Ressources graphiques et polices
├── header/           # Fichiers d'en-tête (.h)
├── lib/             # Bibliothèques et utilitaires
├── src/             # Code source
│   ├── chatbot/    # Logique du chatbot et API
│   ├── homepage/   # Interface d'accueil
│   ├── login/      # Système de connexion
│   ├── sign_up/    # Système d'inscription
│   └── window/     # Gestion des fenêtres
└── tests/          # Tests unitaires
```

## Installation et Configuration
### Prérequis
- GCC
- Make
- CSFML
- libcurl
- json-c

### Installation
1. Cloner le dépôt :
\`\`\`bash
git clone https://github.com/MisterIvanZik/CLIZ_AI.git
cd CLIZ_AI
\`\`\`

2. Installer les dépendances :
\`\`\`bash
sudo apt-get update
sudo apt-get install libcsfml-dev libcurl4-openssl-dev libjson-c-dev
\`\`\`

3. Compiler le projet :
\`\`\`bash
make
\`\`\`

4. Lancer l'application :
\`\`\`bash
./cliz_ai
\`\`\`

## Configuration Avancée
### Variables d'Environnement
- `API_KEY` : Clé d'API pour les modèles d'IA (définie dans defines.h)
- `API_BASE` : URL de base de l'API (définie dans defines.h)

### Personnalisation
- Modification des thèmes dans les assets
- Configuration des modèles dans defines.h
- Ajustement des paramètres de cache dans defines.h

## Performance et Optimisation
### Système de Cache
- Taille du cache : 100 entrées
- Table de hachage optimisée pour les accès rapides

### Gestion de la Mémoire
- Destruction propre des ressources
- Gestion des fuites mémoire avec Valgrind
- Support de l'Address Sanitizer (ASAN)

## Tests et Débogage
### Tests Unitaires
- Framework de test : Criterion
- Coverage avec gcovr
- Tests automatisés pour les fonctions utilitaires

### Outils de Débogage
- Support Valgrind : `make debug_valgrind`
- Support ASAN : `make debug_asan`
- Tests unitaires : `make tests_run`

## Standards de Code
- Style de code normalisé
- Documentation des fonctions
- Gestion des erreurs systématique
- Noms de variables et fonctions explicites

## Auteurs et Contact
- Ivan Zazic
- Clara Lisika

Pour toute question ou retour :
- Email : zazicivan@gmail.com