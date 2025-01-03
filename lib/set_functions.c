/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   set_functions.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:52:04 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:52:04 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"

sfVector2f set_window_size(sfVector2u windowSize,
    sfTexture *texture, sfSprite *sprite)
{
    sfVector2f scale;

    scale.x = (float) windowSize.x / sfTexture_getSize(texture).x;
    scale.y = (float) windowSize.y / sfTexture_getSize(texture).y;
    sfSprite_setScale(sprite, scale);
    return scale;
}

sfTexture *settexture(char *filepath)
{
    sfTexture *savefile_texture = sfTexture_createFromFile(filepath, NULL);

    if (!savefile_texture) {
        printf("%s: Unable to open file\n", filepath);
        exit(84);
    }
    return savefile_texture;
}

sfSprite *setsprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite) {
        printf("Unable to open sprite\n");
        exit(84);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
