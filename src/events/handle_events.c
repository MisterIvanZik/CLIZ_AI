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

static void close_window(cliz_t *cliz)
{
    if (cliz->window->event.type == sfEvtClosed || (
        cliz->window->event.type == sfEvtKeyPressed &&
        cliz->window->event.key.code == sfKeyEscape))
        sfRenderWindow_close(WINDOW);
}

int handle_events(cliz_t *cliz)
{
    sfVector2i mousePos;

    while (sfRenderWindow_pollEvent(WINDOW, &cliz->window->event)) {
        close_window(cliz);
        if (cliz->window->event.type == sfEvtMouseButtonPressed) {
            mousePos = sfMouse_getPositionRenderWindow(WINDOW);
            if (mousePos.x >= 365 && mousePos.x <= 650 &&
                mousePos.y >= 800 && mousePos.y <= 880) {
                sfRenderWindow_close(WINDOW);
            }
        }
    }
    return 0;
}
