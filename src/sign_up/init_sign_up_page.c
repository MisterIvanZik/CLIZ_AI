/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_sign_up_page.c                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 12:25:38 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 12:25:38 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

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

sign_up_t *init_sign_up_page(sign_up_t *sign_up, sfVector2u window_size)
{
    sign_up = malloc(sizeof(sign_up_t));
    if (sign_up == NULL)
        return NULL;
    sign_up->backTexture = settexture(LIGHT_SIGN_UP);
    sign_up->backSprite = setsprite(sign_up->backTexture);
    sign_up->backScale = set_window_size(window_size, sign_up->backTexture, sign_up->backSprite);
    sign_up->iconTexture = settexture(MOON_ICON);
    sign_up->iconSprite = setsprite(sign_up->iconTexture);
    sign_up->iconPos = (sfVector2f){1800, 40};
    sfSprite_setPosition(sign_up->iconSprite, sign_up->iconPos);
    sign_up->name = createButton((sfVector2f){750, 410}, (sfVector2f){440, 65}, "Username", sfBlack);
    sign_up->email = createButton((sfVector2f){750, 530}, (sfVector2f){440, 65}, "Email", sfBlack);
    sign_up->password = createButton((sfVector2f){750, 615}, (sfVector2f){440, 65}, "Password", sfBlack);
    sign_up->message_text = createText("", 15, (sfVector2f){755, 375}, sfRed);
    sign_up->user = init_user();
    if (sign_up->user == NULL) {
        free(sign_up);
        return NULL;
    }
    sign_up->is_name_selected = true;
    sign_up->is_email_selected = false;
    sign_up->is_password_selected = false;
    return sign_up;
}
