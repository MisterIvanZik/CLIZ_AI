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

#include "prototypes.h"

static int validate_email_domain(char *email, sfText *message_text)
{
    char *at = strchr(email, '@');
    char *domain = at + 1;
    char *dot = strchr(domain, '.');
    size_t domain_len = my_strlen(domain);
    size_t tld_len = my_strlen(dot + 1);

    if (!email || !message_text) {
        return 1;
    }
    if (!at) {
        sfText_setString(message_text, "*Email invalide : @ manquant");
        return 1;
    }
    if (!*domain) {
        sfText_setString(message_text, "*Email invalide : domaine manquant");
        return 1;
    }
    if (!dot || dot == domain || !*(dot + 1)) {
        sfText_setString(message_text, "Le domaine de l'email est invalide");
        return 1;
    }
    if (domain_len < 3 || tld_len < 2) {
        sfText_setString(message_text, "Le domaine de l'email est invalide");
        return 1;
    }
    return 0;
}

static int validate_password_strength(char *password, sfText *message_text)
{
    if (my_strlen(password) < 8) {
        sfText_setString(message_text, "Le mot de passe doit contenir au moins 8 caractères");
        return 1;
    }
    if (!has_upper(password)) {
        sfText_setString(message_text, "*Le mot de passe doit contenir au moins une lettre majuscule");
        return 1;
    }
    if (!has_lower(password)) {
        sfText_setString(message_text, "*Le mot de passe doit contenir au moins une lettre minuscule");
        return 1;
    }
    if (!has_digit(password)) {
        sfText_setString(message_text, "*Le mot de passe doit contenir au moins un chiffre");
        return 1;
    }
    if (!has_special(password)) {
        sfText_setString(message_text, "*Le mot de passe doit contenir au moins un caractère spécial");
        return 1;
    }
    return 0;
}

static int validate_sign_up_fields(user_t *user, sfText *message_text)
{
    if (my_strlen(user->name) == 0 || my_strlen(user->email) == 0 || my_strlen(user->password) == 0) {
        sfText_setString(message_text, "*Tous les champs doivent être remplis");
        return 1;
    }
    if (validate_email_domain(user->email, message_text)) {
        return 1;
    }
    return validate_password_strength(user->password, message_text);
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
