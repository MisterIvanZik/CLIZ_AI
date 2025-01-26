/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   input.c                                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/28 12:25:07 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/28 12:25:07 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

input_t create_input_box(sfFont *font)
{
    input_t input;

    input.background = sfRectangleShape_create();
    sfRectangleShape_setSize(input.background, (sfVector2f){1800, 40});
    sfRectangleShape_setPosition(input.background, (sfVector2f){20, 980});
    sfRectangleShape_setFillColor(input.background, sfTransparent);
    sfRectangleShape_setOutlineThickness(input.background, 1);
    sfRectangleShape_setOutlineColor(input.background, sfBlue);

    input.text = sfText_create();
    sfText_setFont(input.text, font);
    sfText_setCharacterSize(input.text, 20);
    sfText_setColor(input.text, sfBlack);
    sfText_setPosition(input.text, (sfVector2f){30, 988});
    input.content[0] = '\0';
    return input;
}

void handle_text_input(chatbot_t *interface, sfEvent event)
{
    size_t len = my_strlen(interface->input.content);

    if (event.text.unicode == KEY_DELETE) {
        if (len > 0)
            interface->input.content[len - 1] = '\0';
    } else if (len < MAX_INPUT_LENGTH) {
        interface->input.content[len] = event.text.unicode;
        interface->input.content[len + 1] = '\0';
    }
    sfText_setString(interface->input.text, interface->input.content);
}