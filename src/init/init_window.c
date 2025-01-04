/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_window.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:23:11 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:23:11 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

window_t *init_window(window_t *window)
{
    window = malloc(sizeof(window_t));
    if (window == NULL)
        return NULL;
    window->VideoMode = sfVideoMode_getDesktopMode();
    window->Window = sfRenderWindow_create(window->VideoMode, WINDOW_NAME,
    sfClose | sfResize, NULL);
    window->windowSize = sfRenderWindow_getSize(window->Window);
    window->backTexture = settexture(HOMEPAGE);
    window->backSprite = setsprite(window->backTexture);
    window->backScale = set_window_size(window->windowSize,
    window->backTexture, window->backSprite);
    window->mousePos = sfMouse_getPositionRenderWindow(window->Window);
    window->statePage = HOME_PAGE;
    return window;
}
