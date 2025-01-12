/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   struct.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:12:42 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:12:42 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef STRUCT_H
    #define STRUCT_H
    #include "include.h"

typedef enum {
    HOME_PAGE,
    SIGN_UP_PAGE,
    LOGIN_PAGE,
    CHATBOT_PAGE,
    TOGGLE_THEME
} Switch_Page;

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

typedef struct homepage_s {
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfText *sign_text;
    sfText *login_text;
    sfText *image_text;
    sfSprite *iconSprite;
    sfTexture *iconTexture;
    sfVector2f iconScale;
    sfVector2f iconPos;
    bool is_dark_theme;
} homepage_t;

typedef struct user_s {
    char *name;
    char *email;
    char *password;
    struct user_s *next;
} user_t;

typedef struct sign_up_s {
    sfText *sign_up;
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

typedef struct login_s {
    sfText *login;
    button_t *email;
    button_t *password;
    sfText *message_text;
    user_t *user;
    bool is_email_selected;
    bool is_dark_theme;
} login_t;

typedef struct cliz_s {
    window_t *window;
    homepage_t *homepage;
    login_t *login;
    button_t *button;
    sign_up_t *sign;
    user_t *user_list;
} cliz_t;

#endif
