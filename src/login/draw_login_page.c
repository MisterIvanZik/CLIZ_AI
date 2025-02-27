/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   draw_login_page.c                                         :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/04 14:37:58 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/04 14:37:58 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

void draw_login_page(cliz_t *cliz)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->login->backSprite, NULL);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->login->iconSprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->login->email->rec, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->login->password->rec, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->email->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->password->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->message_text, NULL);
    sfRenderWindow_display(WINDOW);
}
