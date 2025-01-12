/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   draw_homepage.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:45:14 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:45:14 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"

void draw_homepage(cliz_t *cliz)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->homepage->backSprite, NULL);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->homepage->iconSprite, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->homepage->sign_text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->homepage->login_text, NULL);
}
