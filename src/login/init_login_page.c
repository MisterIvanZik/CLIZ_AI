/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_login_page.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/04 14:40:56 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/04 14:40:56 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

static user_t *init_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return NULL;
    user->name = malloc(NAME_BUFFER + 1);
    user->email = malloc(EMAIL_BUFFER + 1);
    user->password = malloc(PASSWORD_BUFFER + 1);
    if (user->name == NULL || user->email == NULL || user->password == NULL) {
        free(user->name);
        free(user->email);
        free(user->password);
        free(user);
        return NULL;
    }
    user->name[0] = '\0';
    user->email[0] = '\0';
    user->password[0] = '\0';
    user->next = NULL;
    return user;
}

login_t *init_login_page(login_t *login, sfVector2u window_size)
{
    login = malloc(sizeof(login_t));

    if (login == NULL)
        return NULL;
    login->backTexture = settexture(LIGHT_LOGIN);
    login->backSprite = setsprite(login->backTexture);
    login->backScale = set_window_size(window_size, login->backTexture, login->backSprite);
    login->iconTexture = settexture(MOON_ICON);
    login->iconSprite = setsprite(login->iconTexture);
    login->iconPos = (sfVector2f){1800, 40};
    sfSprite_setPosition(login->iconSprite, login->iconPos);
    login->email = createButton((sfVector2f){815, 228}, (sfVector2f){420, 75}, "Email", sfBlack);
    login->password = createButton((sfVector2f){815, 310}, (sfVector2f){420, 75}, "Password", sfBlack);
    login->message_text = createText("", 15, (sfVector2f){820, 150}, sfRed);
    login->user = init_user();
    if (login->user == NULL) {
        free(login);
        return NULL;
    }
    login->is_email_selected = true;
    login->is_dark_theme = false;
    return login;
}
