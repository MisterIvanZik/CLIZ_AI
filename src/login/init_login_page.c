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

static user_t *init_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return NULL;
    user->name = malloc(NAME_BUFFER + 1);
    user->email = malloc(EMAIL_BUFFER + 1);
    user->password = malloc(PASSWORD_BUFFER + 1);
    if (user->name == NULL || user->email == NULL || user->password == NULL) {
        free(user->name);
        free(user->email);
        free(user->password);
        free(user);
        return NULL;
    }
    user->name[0] = '\0';
    user->email[0] = '\0';
    user->password[0] = '\0';
    user->next = NULL;
    return user;
}

login_t *init_login_page(login_t *login)
{
    login = malloc(sizeof(login_t));

    if (login == NULL)
        return NULL;
    login->login = createText("LOGIN", 40, (sfVector2f){850, 100}, sfBlack);
    login->email = createButton((sfVector2f){700, 300}, sfBlack, "email or username", sfRed);
    login->password = createButton((sfVector2f){700, 500}, sfBlack, "password", sfRed);
    login->message_text = createText("", 30, (sfVector2f){700, 600}, sfBlack);
    login->user = init_user();
    if (login->user == NULL) {
        free(login);
        return NULL;
    }
    login->is_email_selected = true;
    return login;
}
