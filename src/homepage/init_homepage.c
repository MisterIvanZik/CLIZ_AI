/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_homepage.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
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

homepage_t *init_homepage(homepage_t *homepage, sfVector2u window_size)
{
    homepage = malloc(sizeof(homepage_t));
    if (homepage == NULL)
        return NULL;
    homepage->backTexture = settexture(LIGHT_HOMEPAGE);
    homepage->backSprite = setsprite(homepage->backTexture);
    homepage->backScale = set_window_size(window_size, homepage->backTexture, homepage->backSprite);
    homepage->iconTexture = settexture(MOON_ICON);
    homepage->iconSprite = setsprite(homepage->iconTexture);
    homepage->iconPos = (sfVector2f){1800, 40};
    sfSprite_setPosition(homepage->iconSprite, homepage->iconPos);
    homepage->sign_text = createText("SIGN_UP", 30, (sfVector2f){900, 750}, sfBlack);
    homepage->login_text = createText("LOGIN", 30, (sfVector2f){1265, 750}, sfBlack);
    homepage->is_dark_theme = false;
    return homepage;
}
