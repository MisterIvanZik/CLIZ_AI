/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   handle_sign_input.c                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 12:40:45 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 12:40:45 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void handle_name_input(sign_up_t *sign, sfEvent event)
{
    char *input_content = sign->user->name;
    size_t len = strlen(input_content);

    if (event.text.unicode == '\b') {
        if (len > 0) {
            input_content[len - 1] = '\0';
        }
    } else if (len < NAME_BUFFER) {
        input_content[len] = (char)event.text.unicode;
        input_content[len + 1] = '\0';
    }
    sfText_setString(sign->name->text, input_content);
}

static void handle_email_input(sign_up_t *sign, sfEvent event)
{
    char *input_content = sign->user->email;
    size_t len = strlen(input_content);

    if (event.text.unicode == '\b') {
        if (len > 0) {
            input_content[len - 1] = '\0';
        }
    } else if (len < EMAIL_BUFFER) {
        input_content[len] = (char)event.text.unicode;
        input_content[len + 1] = '\0';
    }
    sfText_setString(sign->email->text, input_content);
}

static void handle_password_input(sign_up_t *sign, sfEvent event)
{
    char *input_content = sign->user->password;
    size_t len = strlen(input_content);

    if (event.text.unicode == '\b') {
        if (len > 0) {
            input_content[len - 1] = '\0';
        }
    } else if (len < PASSWORD_BUFFER) {
        input_content[len] = (char)event.text.unicode;
        input_content[len + 1] = '\0';
    }
    sfText_setString(sign->password->text, input_content);
}

void handle_sign_input(sign_up_t *sign, sfEvent event)
{
    if (sign->is_name_selected)
        handle_name_input(sign, event);
    if (sign->is_email_selected)
        handle_email_input(sign, event);
    if (sign->is_password_selected)
        handle_password_input(sign, event);
}
