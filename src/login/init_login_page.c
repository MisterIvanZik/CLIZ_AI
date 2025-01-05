/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_login_page.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
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

login_t *init_login_page(login_t *login)
{
    login = malloc(sizeof(login_t));

    if (login == NULL)
        return NULL;
    login->login = createText("LOGIN", 40, (sfVector2f){850, 100}, sfBlack);
    login->email = createButton((sfVector2f){700, 300}, sfBlack, "email or username", sfRed);
    login->password = createButton((sfVector2f){700, 500}, sfBlack, "password", sfRed);
    login->message_text = createText("", 30, (sfVector2f){700, 600}, sfBlack);
    login->email_input[0] = '\0';
    login->password_input[0] = '\0';
    login->is_email_selected = true;
    return login;
}
