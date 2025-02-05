/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   handle_login_events.c                                     :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/05 13:51:17 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/05 13:51:17 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

static void toggle_login_theme(login_t *login)
{
    if (login->is_dark_theme) {
        login->backTexture = settexture(LIGHT_LOGIN);
        login->iconTexture = settexture(MOON_ICON);
        sfText_setColor(login->email->text, sfBlack);
        sfText_setColor(login->password->text, sfBlack);
        sfText_setPosition(login->email->text, (sfVector2f){815, 228});
        sfText_setPosition(login->password->text,(sfVector2f){815, 310});
    } else {
        login->backTexture = settexture(DARK_LOGIN);
        login->iconTexture = settexture(SUN_ICON);
        sfText_setColor(login->email->text, sfWhite);
        sfText_setColor(login->password->text, sfWhite);
        sfText_setPosition(login->email->text, (sfVector2f){830, 228});
        sfText_setPosition(login->password->text, (sfVector2f){830, 310});
    }
    sfSprite_setTexture(login->backSprite, login->backTexture, sfTrue);
    sfSprite_setTexture(login->iconSprite, login->iconTexture, sfTrue);
    login->is_dark_theme = !login->is_dark_theme;
}

static void handle_login_input_events(cliz_t *cliz, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        handle_login_input(cliz->login, event);
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab) {
        cliz->login->is_email_selected = !cliz->login->is_email_selected;
    }
}

static void handle_login_mouse_events(cliz_t *cliz, sfEvent event)
{
    sfFloatRect select_email = sfRectangleShape_getGlobalBounds(cliz->login->email->rec);
    sfFloatRect select_password = sfRectangleShape_getGlobalBounds(cliz->login->password->rec);
    sfFloatRect iconBounds = sfSprite_getGlobalBounds(cliz->login->iconSprite);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&select_email, MOUSE_POS.x, MOUSE_POS.y)) {
            cliz->login->is_email_selected = true;
        } else if (sfFloatRect_contains(&select_password, MOUSE_POS.x, MOUSE_POS.y)) {
            cliz->login->is_email_selected = false;
        } else if (sfFloatRect_contains(&iconBounds, MOUSE_POS.x, MOUSE_POS.y)) {
            toggle_login_theme(cliz->login);
        } else if (MOUSE_POS.x >= 810 && MOUSE_POS.x <= 1105 &&
            MOUSE_POS.y >= 360 && MOUSE_POS.y <= 395) {
                check_login_user(cliz);
        }
    }
}

void handle_login_events(cliz_t *cliz, sfEvent event)
{
    handle_login_input_events(cliz, event);
    handle_login_mouse_events(cliz, event);
}
