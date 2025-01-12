/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   handle_login_input.c                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/06 00:17:11 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/06 00:17:11 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void handle_email_input(login_t *login, sfEvent event)
{
    char *input_content = login->user->email;
    size_t len = strlen(input_content);

    if (event.text.unicode == '\b') {
        if (len > 0)
            input_content[len - 1] = '\0';
    }
    else if (len < EMAIL_BUFFER) {
        input_content[len] = (char)event.text.unicode;
        input_content[len + 1] = '\0';
    }
    sfText_setString(login->email->text, input_content);
}

static void handle_password_input(login_t *login, sfEvent event)
{
    char *input_content = login->user->password;
    size_t len = strlen(input_content);

    if (event.text.unicode == '\b') {
        if (len > 0)
            input_content[len - 1] = '\0';
    }
    else if (len < PASSWORD_BUFFER) {
        input_content[len] = (char)event.text.unicode;
        input_content[len + 1] = '\0';
    }
    sfText_setString(login->password->text, input_content);
}

void handle_login_input(login_t *login, sfEvent event)
{
    if (login->is_email_selected) {
        handle_email_input(login, event);
    } else {
        handle_password_input(login, event);
    }
}
