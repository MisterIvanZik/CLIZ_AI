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
    #define EMAIL_BUFFER 100
    #define PASSWORD_BUFFER 12

typedef enum {
    HOME_PAGE,
    SIGN_UP_PAGE,
    LOGIN_PAGE,
    CHATBOT_PAGE
} Switch_Page;

typedef struct window_s {
    sfRenderWindow *Window;
    sfVideoMode VideoMode;
    sfVector2u windowSize;
    sfEvent event;
    sfVector2i mousePos;
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfVector2f backPos;
    Switch_Page statePage;
} window_t;

typedef struct button_s {
    sfRectangleShape* rec;
    sfText* text;
    sfVector2f textPos;
} button_t;

typedef struct user_s {
    char *email;
    char *password;
    struct user_s *next;
} user_t;

typedef struct login_s {
    sfText *login;
    button_t *email;
    button_t *password;
    sfSprite *buttonSprite;
    sfTexture *buttonTexture;
    sfVector2f buttonScale;
    sfVector2f buttonPos;
    sfText *message_text;
    char email_input[50];
    char password_input[50];
    bool is_email_selected;
} login_t;

typedef struct cliz_s {
    window_t *window;
    login_t *login;
    button_t *button;
    user_t *user;
} cliz_t;

#endif
