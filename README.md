# CLIZ_AI

Pour notre projet CLIZ AI, on aura réussi pour ce premier rendu a développer :
- home page avec 3 boutons Chatbot/Inscription/Connexion
- interface graphique de chatbot
- Utilisation d'une API grâce à la librairie curl et la documentation sur ce site (https://curl.se/libcurl/c/)
- Gérer la réception de texte en format json grâce à une librairie cjson -> https://github.com/json-c/json-c
                                                                         -> https://json-c.github.io/json-c/
- Implémenter une zone d'envoie de texte et de réception
- Système de connexion uniquement
- Gérer la plupart des erreurs trouvés et intuitives
- Architecture du code travaillé mais reste à améliorer
- Possibilité de renvoyer plusieurs messages à la suite à l'IA

Améliorations en cours pour le prochain rendu :
- Ajouter un mode d'inscription fonctionnel
- Améliorer l'architecture du programme
- Gérer différemment le système de l'application avec l'accueil et ses trois boutons
- Amélioration de l'interface graphique
- Ajouts de fichiers de configurations
- Changer le modèle d'IA
- Rendre le code plus modulable

Fonctionnement de notre projet actuel -> Page chatbot avec laquelle on peut communiquer en écrivant un texte puis en
appuyant sur entrée ou le bouton send à l'écran, et pour l'instant un système de connexion qui renvoie à la page chatbot,
nous avons un fichier database.txt qui contient un identifiant et mot de passe pour tester !
Nous sommes encore en réflexion par rapport à notre système car nous ne sommes pas satisfait (beaucoup de recode du projet 😄 )

Attention !
Notre modèle d'IA est payante, nous utilisons pour l'instant un modèle Qwen Coder (Qwen2.5-7B-Instruct), qui nous coutent
pas très chère mais à l'avenir nous intègrerons d'autres modèles pour celui la le nombre de tokens (messages que vous envoyer)
est on va dire "illimité pour tester".