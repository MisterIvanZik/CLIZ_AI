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

#include "prototypes.h"

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
        my_printf("%s: Unable to open file\n", filepath);
        exit(84);
    }
    return savefile_texture;
}

sfSprite *setsprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite) {
        my_printf("Unable to open sprite\n");
        exit(84);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfFont *setfont(char *filepath)
{
    sfFont *savefile_font = sfFont_createFromFile(filepath);

    if (savefile_font == NULL) {
        my_printf("%s: Unable to open font\n", filepath);
        exit(84);
    }
    return savefile_font;
}
