/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_sign_up_page.c                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 12:25:38 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 12:25:38 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

user_t *init_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return NULL;
    user->name = malloc(51);
    user->email = malloc(101);
    user->password = malloc(51);
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

sign_up_t *init_sign_up_page(sign_up_t *sign_up)
{
    sign_up = malloc(sizeof(sign_up_t));
    if (sign_up == NULL)
        return NULL;
    sign_up->sign_up = createText("SIGN_UP", 40, (sfVector2f){850, 50}, sfBlue);
    sign_up->name = createButton((sfVector2f){700, 100}, sfBlack, "name", sfBlack);
    sign_up->email = createButton((sfVector2f){700, 300}, sfBlack, "email", sfBlack);
    sign_up->password = createButton((sfVector2f){700, 500}, sfBlack, "password", sfBlack);
    sign_up->message_text = createText("", 30, (sfVector2f){700, 600}, sfRed);
    sign_up->user = init_user();
    if (sign_up->user == NULL) {
        free(sign_up);
        return NULL;
    }
    sign_up->is_name_selected = true;
    sign_up->is_email_selected = false;
    sign_up->is_password_selected = false;
    return sign_up;
}
