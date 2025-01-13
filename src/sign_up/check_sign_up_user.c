/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   check_sign_up_user.c                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 14:05:33 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 14:05:33 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static int validate_sign_up_fields(user_t *user, sfText *message_text)
{
    if (strlen(user->name) == 0 || strlen(user->email) == 0 || strlen(user->password) == 0) {
        sfText_setString(message_text, "*Tous les champs doivent être remplis");
        return 1;
    }
    if (!strchr(user->email, '@')) {
        sfText_setString(message_text, "*Email invalide");
        return 1;
    }
    if (strlen(user->password) < 8) {
        sfText_setString(message_text, "*Le mot de passe doit contenir au moins 8 caractères");
        return 1;
    }
    return 0;
}

static int add_new_user(FILE *file, cliz_t *cliz)
{
    int result = 0;

    file = fopen("database.txt", "a");
    if (file == NULL) {
        sfText_setString(cliz->sign->message_text, "*Erreur lors de l'ouverture du fichier");
        return 84;
    }
    result = sign_up(file, cliz);
    fclose(file);
    if (result == 0) {
        cliz->window->statePage = HOME_PAGE;
    } else if (result == 1) {
        sfText_setString(cliz->sign->message_text, "*Cet email est déjà utilisé");
    } else {
        sfText_setString(cliz->sign->message_text, "*Erreur lors de l'inscription !");
    }
    return result;
}

void check_sign_up_user(cliz_t *cliz)
{
    user_t *user = cliz->sign->user;

    if (validate_sign_up_fields(user, cliz->sign->message_text) != 0)
        return;
    add_new_user(NULL, cliz);
}
