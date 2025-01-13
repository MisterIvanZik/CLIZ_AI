/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy_login_page.c                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/06 00:45:03 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/06 00:45:03 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void destroy_user(user_t *user)
{
    if (user == NULL)
        return;
    free(user->name);
    free(user->email);
    free(user->password);
    free(user);
}

void destroy_login_page(login_t *login)
{
    destroyButton(login->email);
    destroyButton(login->password);
    sfText_destroy(login->message_text);
    sfSprite_destroy(login->iconSprite);
    sfTexture_destroy(login->iconTexture);
    sfSprite_destroy(login->backSprite);
    sfTexture_destroy(login->backTexture);
    destroy_user(login->user);
    free(login);
}
