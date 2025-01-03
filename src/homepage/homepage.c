/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   homepage.c                                                :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:50:06 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:50:06 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void homepage(cliz_t *cliz)
{
    cliz->window = init_window(cliz->window);
    while (sfRenderWindow_isOpen(WINDOW)) {
        handle_events(cliz);
        draw_homepage(cliz);
    }
    sfSprite_destroy(cliz->window->backSprite);
    sfRenderWindow_destroy(WINDOW);
}
