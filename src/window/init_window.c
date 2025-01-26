/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_window.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/12 22:48:43 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/12 22:48:43 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

window_t *init_window(window_t *window)
{
    window = malloc(sizeof(window_t));
    if (window == NULL)
        return NULL;
    window->VideoMode = sfVideoMode_getDesktopMode();
    window->Window = sfRenderWindow_create(window->VideoMode, WINDOW_NAME,
    sfClose | sfResize, NULL);
    window->windowSize = sfRenderWindow_getSize(window->Window);
    window->mousePos = sfMouse_getPositionRenderWindow(window->Window);
    window->statePage = HOME_PAGE;
    return window;
}
