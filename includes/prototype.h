/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   prototype.h                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:09:30 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:09:30 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_
    #include "include.h"
    #include "struct.h"

window_t *init_window(window_t *window);
int handle_events(cliz_t *cliz);
void draw_homepage(cliz_t *cliz);
void homepage(cliz_t *cliz);
sfVector2f set_window_size(sfVector2u windowSize,
    sfTexture *texture, sfSprite *sprite);
sfTexture *settexture(char *filepath);
sfSprite *setsprite(sfTexture *texture);

#endif
