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

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void handle_login_input_events(cliz_t *cliz, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        handle_login_input(cliz->login, event);
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab) {
        cliz->login->is_email_selected = !cliz->login->is_email_selected;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        check_login_user(cliz);
    }
}

static void handle_login_mouse_events(login_t *login, sfEvent event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect select_email = sfRectangleShape_getGlobalBounds(login->email->rec);
    sfFloatRect select_password = sfRectangleShape_getGlobalBounds(login->password->rec);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&select_email, mouse_pos.x, mouse_pos.y)) {
            login->is_email_selected = true;
        } else if (sfFloatRect_contains(&select_password, mouse_pos.x, mouse_pos.y)) {
            login->is_email_selected = false;
        }
    }
}

void handle_login_events(cliz_t *cliz, sfEvent event)
{
    handle_login_input_events(cliz, event);
    handle_login_mouse_events(cliz->login, event, WINDOW);
}
