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

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

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
    } else if (event.key.code == sfKeyEnter) {
        check_sign_up_user(cliz);
    }
}

static void handle_sign_mouse_events(sign_up_t *sign, sfEvent event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect select_name = sfText_getGlobalBounds(sign->name->text);
    sfFloatRect select_email = sfText_getGlobalBounds(sign->email->text);
    sfFloatRect select_password = sfText_getGlobalBounds(sign->password->text);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&select_name, mouse_pos.x, mouse_pos.y)) {
            sign->is_name_selected = true;
            sign->is_email_selected = false;
            sign->is_password_selected = false;
        }
        else if (sfFloatRect_contains(&select_email, mouse_pos.x, mouse_pos.y)) {
            sign->is_name_selected = false;
            sign->is_email_selected = true;
            sign->is_password_selected = false;
        }
        else if (sfFloatRect_contains(&select_password, mouse_pos.x, mouse_pos.y)) {
            sign->is_name_selected = false;
            sign->is_email_selected = false;
            sign->is_password_selected = true;
        }
    }
}

void handle_sign_events(cliz_t *cliz, sfEvent event)
{
    handle_sign_input_events(cliz, event);
    handle_sign_mouse_events(cliz->sign, event, WINDOW);
}
