/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   authentification_user.c                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/06 00:15:45 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/06 00:15:45 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

void check_login_user(cliz_t *cliz)
{
    const char *email_input = cliz->login->user->email;
    const char *password_input = cliz->login->user->password;
    user_t *current = cliz->user_list;

    if (cliz->user_list == NULL) {
        sfText_setString(cliz->login->message_text, "*Utilisateur inconnu");
        return;
    }
    while (current != NULL) {
        if (strcmp(email_input, current->email) == 0 &&
            strcmp(password_input, current->password) == 0) {
            cliz->window->statePage = CHATBOT_PAGE;
            return;
        }
        current = current->next;
    }
    sfText_setString(cliz->login->message_text, "*Email ou mot de passe incorrect");
}
