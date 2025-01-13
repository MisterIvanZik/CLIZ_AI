/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   draw_sign_up_page.c                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 12:30:03 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 12:30:03 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void draw_sign_up_page(cliz_t *cliz)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->sign->backSprite, NULL);
    sfRenderWindow_drawSprite(WINDOW,
    cliz->sign->iconSprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->sign->name->rec, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->sign->email->rec, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->sign->password->rec, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->sign->name->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->sign->email->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->sign->password->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->sign->message_text, NULL);
    sfRenderWindow_display(WINDOW);
}
