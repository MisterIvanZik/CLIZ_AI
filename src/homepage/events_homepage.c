/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   events_homepage.c                                         :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/04 14:33:28 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/04 14:33:28 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static int get_clicked_button(sfVector2i mouse_pos, Switch_Page *cliked_button)
{
    if (mouse_pos.x >= 380 && mouse_pos.x <= 625 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *cliked_button = CHATBOT_PAGE;
        return 1;
    }

    if (mouse_pos.x >= 820 && mouse_pos.x <= 1080 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *cliked_button = SIGN_UP_PAGE;
        return 1;
    }

    if (mouse_pos.x >= 1285 && mouse_pos.x <= 1535 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *cliked_button = LOGIN_PAGE;
        return 1;
    }
    return 0;
}

void events_homepage(cliz_t *cliz)
{
    sfVector2i mouse_pos = MOUSE_POS;
    Switch_Page clicked_button;

    if (!get_clicked_button(mouse_pos, &clicked_button))
        return;
    switch (clicked_button) {
        case CHATBOT_PAGE:
            cliz->window->statePage = CHATBOT_PAGE;
            break;
        case SIGN_UP_PAGE:
            cliz->window->statePage = SIGN_UP_PAGE;
            break;
        case LOGIN_PAGE:
            cliz->window->statePage = LOGIN_PAGE;
            break;
        default:
            break;
    }
}