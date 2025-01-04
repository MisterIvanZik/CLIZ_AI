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

typedef struct login_s {
    sfText *login;
    button_t *email;
    button_t *password;
} login_t;

typedef struct cliz_s {
    window_t *window;
    login_t *login;
    button_t *button;
} cliz_t;

#endif
