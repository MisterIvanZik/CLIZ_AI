/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   handle_events.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 22:06:12 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 22:06:12 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void close_window(cliz_t *cliz)
{
    if (EVENT.type == sfEvtClosed || (
        EVENT.type == sfEvtKeyPressed &&
        EVENT.key.code == sfKeyEscape))
        sfRenderWindow_close(WINDOW);
}

int handle_events(cliz_t *cliz)
{
    while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
        close_window(cliz);
        switch (cliz->window->statePage) {
            case HOME_PAGE:
                handle_homepage_events(cliz, EVENT);
                break;
            case LOGIN_PAGE:
                handle_login_events(cliz, EVENT);
                break;
            case SIGN_UP_PAGE:
                handle_sign_events(cliz, EVENT);
                break;
            default:
                break;
        }
    }
    return 0;
}
