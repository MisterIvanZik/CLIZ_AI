/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   prototypes.h                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/26 03:51:13 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/26 03:51:13 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_
    #include "struct.h"

/* Utilitaires */
char *my_strncpy(char *dest, char *src, int n);
int my_strlen(char *str);
char *my_strdup(char *str1);
int my_strcmp(char *str1, char *str2);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_unsigned_nbr(unsigned int nb);
int my_intflags(char *format, va_list ap);
int my_charflags(char *format, va_list ap);
int my_strflags(char *format, va_list ap);
int my_unsigned_int(char *format, va_list ap);
int my_percent_flag(char *format, va_list ap);
int my_printf(char *format, ...);

/* Fonctions de configuration graphique */
sfVector2f set_window_size(sfVector2u windowSize, sfTexture *texture, sfSprite *sprite);
sfTexture *settexture(char *filepath);
sfSprite *setsprite(sfTexture *texture);
sfFont *setfont(char *filepath);

/* Création et destruction d'éléments UI */
button_t *createButton(sfVector2f buttonPos, sfVector2f buttonSize, const char *buttonName, sfColor buttonNameColor);
sfText* createText(const char* string, unsigned int textSize, sfVector2f textPos, sfColor textColor);
void destroyButton(button_t *button);

/* Gestion de la fenêtre principale */
window_t *init_window(window_t *window);
void destroy_window(window_t *window);
void close_window(cliz_t *cliz);

/* Page d'accueil */
homepage_t *init_homepage(homepage_t *homepage, sfVector2u window_size);
void homepage(cliz_t *cliz);
int handle_events(cliz_t *cliz);
void handle_homepage_events(cliz_t *cliz, sfEvent event);
void draw_homepage(cliz_t *cliz);
void destroy_homepage(homepage_t *homepage);

/* Page de connexion */
login_t *init_login_page(login_t *login, sfVector2u window_size);
void check_login_user(cliz_t *cliz);
void handle_login_input(login_t *login, sfEvent event);
void handle_login_events(cliz_t *cliz, sfEvent event);
void draw_login_page(cliz_t *cliz);
void destroy_login_page(login_t *login);

/* Page d'inscription */
sign_up_t *init_sign_up_page(sign_up_t *sign_up, sfVector2u window_size);
void load_users_from_file(cliz_t *cliz, const char *filename);
int sign_up(FILE *file, cliz_t *cliz);
void check_sign_up_user(cliz_t *cliz);
void handle_sign_input(sign_up_t *sign, sfEvent event);
void handle_sign_events(cliz_t *cliz, sfEvent event);
void draw_sign_up_page(cliz_t *cliz);
void destroy_sign_up_page(sign_up_t *sign);
void destroy_user_list(user_t *head);

/* Interface du chatbot */
void initAiInterface(void);
chatbot_t *create_chat_interface(void);
void draw_chatbot(chatbot_t *interface);
input_t create_input_box(sfFont *font);
void handle_text_input(chatbot_t *interface, sfEvent event);

/* Menu de sélection de modèle */
sfText *create_model_text(sfFont *font, int index, const char *modelName);
sfRectangleShape *create_model_background(int index, sfBool isSelected);
void init_model_menu(chatbot_t *interface);
void handle_model_selection(chatbot_t *interface, sfVector2i mousePos);
void handle_main_controls(chatbot_t *interface, sfVector2i mousePos);

/* Gestion des événements du chatbot */
void handle_mouse_click(chatbot_t *interface, sfVector2i mousePos);
void handle_key_press(chatbot_t *interface, sfKeyCode key);
void handle_scroll(chatbot_t *interface, sfEvent event);
void handle_mouse_events(chatbot_t *interface, sfEvent event);
void handle_chatbot_events(chatbot_t *interface);
void destroy_interface(chatbot_t *interface);

/* Gestion des messages */
void send_message(chatbot_t *ai);
void add_message(chatbot_t *ai, char *content, sfBool isUser);
float calculate_message_height(sfText *messageText, char *content);
void draw_single_message(chatbot_t *ai, sfText *messageText, char *content,
                        float x, float y, sfBool isUser, int index);
void draw_messages(chatbot_t *ai);

/* API et traitement des réponses */
size_t callback(void *receivedData, size_t sizeOfOneElement, size_t numberOfElements, void *userData);
char *prepareJsonPayload(chatbot_t *interface, CURL *curl, char *userInput);
char *extractAiResponse(char *data);
char *getAiResponse(chatbot_t *interface, char *userInput);

/* Table de hachage pour le cache */
unsigned int hash_function(const char *key);
hash_table_t *hash_create(void);
int insert_elem(hash_table_t *table, const char *question, const char *response);
char *search_elem(hash_table_t *table, const char *question);
void hash_destroy(hash_table_t *table);

#endif
