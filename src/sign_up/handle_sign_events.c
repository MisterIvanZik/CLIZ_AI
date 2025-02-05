/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   handle_sign_events.c                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 13:37:46 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 13:37:46 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

static void toggle_sign_theme(sign_up_t *sign)
{
    if (sign->is_dark_theme) {
        sign->backTexture = settexture(LIGHT_SIGN_UP);
        sign->iconTexture = settexture(MOON_ICON);
        sfText_setPosition(sign->email->text, (sfVector2f){1265, 195});
        sfText_setPosition(sign->password->text, (sfVector2f){1265, 280});
        sfText_setPosition(sign->name->text, (sfVector2f){1265, 415});
    } else {
        sign->backTexture = settexture(DARK_SIGN_UP);
        sign->iconTexture = settexture(SUN_ICON);
        sfText_setPosition(sign->email->text, (sfVector2f){1265, 195});
        sfText_setPosition(sign->password->text, (sfVector2f){1265, 280});
        sfText_setPosition(sign->name->text, (sfVector2f){1265, 415});
    }
    sfSprite_setTexture(sign->backSprite, sign->backTexture, sfTrue);
    sfSprite_setTexture(sign->iconSprite, sign->iconTexture, sfTrue);
    sign->is_dark_theme = !sign->is_dark_theme;
}

static void switch_to_next_field(sign_up_t *sign)
{
    if (sign->is_name_selected) {
        sign->is_name_selected = false;
        sign->is_email_selected = true;
    } else if (sign->is_email_selected) {
        sign->is_email_selected = false;
        sign->is_password_selected = true;
    } else if (sign->is_password_selected) {
        sign->is_password_selected = false;
        sign->is_name_selected = true;
    }
}

static void handle_sign_input_events(cliz_t *cliz, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        handle_sign_input(cliz->sign, event);
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab) {
        switch_to_next_field(cliz->sign);
    }
}

static void handle_sign_mouse_events(cliz_t *cliz, sfEvent event)
{
    sfFloatRect select_name = sfText_getGlobalBounds(cliz->sign->name->text);
    sfFloatRect select_email = sfText_getGlobalBounds(cliz->sign->email->text);
    sfFloatRect select_password = sfText_getGlobalBounds(cliz->sign->password->text);
    sfFloatRect iconBounds = sfSprite_getGlobalBounds(cliz->login->iconSprite);

    if (event.type == sfEvtMouseButtonPressed) {
        my_printf("Clic à la position : x = %d, y = %d\n", (int)MOUSE_POS.x, (int)MOUSE_POS.y);
        if (sfFloatRect_contains(&select_name, MOUSE_POS.x, MOUSE_POS.y)) {
            cliz->sign->is_name_selected = true;
            cliz->sign->is_email_selected = false;
            cliz->sign->is_password_selected = false;
        } else if (sfFloatRect_contains(&select_email, MOUSE_POS.x, MOUSE_POS.y)) {
            cliz->sign->is_name_selected = false;
            cliz->sign->is_email_selected = true;
            cliz->sign->is_password_selected = false;
        } else if (sfFloatRect_contains(&select_password, MOUSE_POS.x, MOUSE_POS.y)) {
            cliz->sign->is_name_selected = false;
            cliz->sign->is_email_selected = false;
            cliz->sign->is_password_selected = true;
        } else if (sfFloatRect_contains(&iconBounds, MOUSE_POS.x, MOUSE_POS.y)) {
            toggle_sign_theme(cliz->sign);
        }  else if (MOUSE_POS.x >= 1215 && MOUSE_POS.x <= 1660 &&
            MOUSE_POS.y >= 510 && MOUSE_POS.y <= 555) {
                check_sign_up_user(cliz);
        }
    }
}
void handle_sign_events(cliz_t *cliz, sfEvent event)
{
    handle_sign_input_events(cliz, event);
    handle_sign_mouse_events(cliz, event);
}
