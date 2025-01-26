/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   struct.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/26 14:29:00 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/26 14:29:00 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "includes.h"
    #include "defines.h"

/* Énumérations */
typedef enum {
    HOME_PAGE,
    SIGN_UP_PAGE,
    LOGIN_PAGE,
    CHATBOT_PAGE,
    TOGGLE_THEME
} Switch_Page;

/* Structures de base */
typedef struct window_s {
    sfRenderWindow *Window;
    sfVideoMode VideoMode;
    sfVector2u windowSize;
    sfEvent event;
    sfVector2i mousePos;
    Switch_Page statePage;
} window_t;

typedef struct button_s {
    sfRectangleShape* rec;
    sfText* text;
    sfVector2f textPos;
} button_t;

/* Structures d'interface */
typedef struct homepage_s {
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfSprite *iconSprite;
    sfTexture *iconTexture;
    sfVector2f iconScale;
    sfVector2f iconPos;
    sfText *sign_text;
    sfText *login_text;
    sfText *image_text;
    bool is_dark_theme;
} homepage_t;

typedef struct login_s {
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfSprite *iconSprite;
    sfTexture *iconTexture;
    sfVector2f iconScale;
    sfVector2f iconPos;
    button_t *email;
    button_t *password;
    sfText *message_text;
    struct user_s *user;
    bool is_email_selected;
    bool is_dark_theme;
} login_t;

/* Structures utilisateur */
typedef struct user_s {
    char *name;
    char *email;
    char *password;
    struct user_s *next;
} user_t;

typedef struct sign_up_s {
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfSprite *iconSprite;
    sfTexture *iconTexture;
    sfVector2f iconScale;
    sfVector2f iconPos;
    button_t *name;
    button_t *email;
    button_t *password;
    sfText *message_text;
    sfText *text;
    user_t *user;
    bool is_name_selected;
    bool is_email_selected;
    bool is_password_selected;
    bool is_dark_theme;
} sign_up_t;

/* Structure principale */
typedef struct cliz_s {
    window_t *window;
    homepage_t *homepage;
    login_t *login;
    button_t *button;
    sign_up_t *sign;
    user_t *user_list;
} cliz_t;

/* Structures du chatbot */
typedef struct api_s {
    char **data;
    size_t *size;
} api_t;

typedef struct input_s {
    sfRectangleShape *background;
    sfText *text;
    char content[1000];
    sfBool isActive;
} input_t;

typedef struct message_s {
    char content[1000];
    sfBool isUser;
    sfRectangleShape *background;
} message_t;

/* Structures de la table de hachage */
typedef struct hash_item_s {
    char *question;
    char *response;
    time_t timestamp;
    struct hash_item_s *next;
} hash_item_t;

typedef struct hash_table_s {
    hash_item_t **items;
    int size;
    int count;
} hash_table_t;

typedef struct chatbot_s {
    sfRenderWindow *window;
    sfFont *font;
    input_t input;
    message_t messages[MAX_MESSAGES];
    int messageCount;
    sfText *displayText;
    sfRectangleShape *sendButton;
    sfText *sendButtonText;
    int scroll;
    hash_table_t *responseCache;
} chatbot_t;

#endif
