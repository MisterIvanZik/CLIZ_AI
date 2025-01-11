/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy_sign_up_page.c                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 12:33:23 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 12:33:23 by lisika               ########## ########   ######## ###########         */
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

void destroy_sign_up_page(sign_up_t *sign)
{
    if (sign == NULL)
        return;
    destroyButton(sign->name);
    destroyButton(sign->email);
    destroyButton(sign->password);
    sfText_destroy(sign->sign_up);
    sfText_destroy(sign->message_text);
    destroy_user(sign->user);
    free(sign);
}
