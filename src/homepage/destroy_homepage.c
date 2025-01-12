/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy_homepage.c                                        :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/06 00:46:40 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/06 00:46:40 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void destroy_homepage(homepage_t *homepage)
{
    sfText_destroy(homepage->login_text);
    sfText_destroy(homepage->sign_text);
    sfSprite_destroy(homepage->iconSprite);
    sfTexture_destroy(homepage->iconTexture);
    sfSprite_destroy(homepage->backSprite);
    sfTexture_destroy(homepage->backTexture);
    free(homepage);
}
