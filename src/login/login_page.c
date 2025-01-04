/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   login_page.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/04 14:40:56 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/04 14:40:56 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

login_t *login_page(login_t *login)
{
    login = malloc(sizeof(login_t));
    if (login == NULL)
        return NULL;
    login->login = createText("LOGIN", 40, (sfVector2f){850, 100}, sfBlack);
    login->email = createButton((sfVector2f){700, 300}, sfBlack, "email or username", sfRed);
    login->password = createButton((sfVector2f){700, 500}, sfBlack, "password", sfRed);
    return login;
}
