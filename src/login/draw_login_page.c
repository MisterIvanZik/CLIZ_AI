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

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void draw_login_page(cliz_t *cliz)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->login->email->rec, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, cliz->login->password->rec, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->login, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->email->text, NULL);
    sfRenderWindow_drawText(WINDOW, cliz->login->password->text, NULL);
    sfRenderWindow_display(WINDOW);
}
