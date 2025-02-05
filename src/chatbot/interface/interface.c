/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   interface.c                                                 :+:       :+:    :+: :+:    :+:    :+:      */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/28 12:26:17 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/28 12:26:17 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

sfRectangleShape *createSendButton(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f){80, 40});
    sfRectangleShape_setPosition(button, (sfVector2f){1820, 980});
    sfRectangleShape_setFillColor(button, sfBlue);
    return button;
}

sfText *createSendButtonText(sfFont *font, sfRectangleShape *button)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, "Envoyer");
    sfText_setCharacterSize(text, 15);
    sfText_setColor(text, sfWhite);
    sfFloatRect buttonBounds = sfRectangleShape_getGlobalBounds(button);
    sfFloatRect textBounds = sfText_getGlobalBounds(text);
    sfText_setPosition(text, (sfVector2f){buttonBounds.left + 14, buttonBounds.top + 10});
    return text;
}

chatbot_t *create_chat_interface(void)
{
    chatbot_t *interface = malloc(sizeof(chatbot_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!interface)
        return NULL;
    interface->responseCache = hash_create();
    if (!interface->responseCache) {
        free(interface);
        return NULL;
    }
    interface->window = sfRenderWindow_create(mode, "CLIZ AI", sfResize | sfClose, NULL);
    interface->font = sfFont_createFromFile(FONT);
    interface->input = create_input_box(interface->font);
    interface->sendButton = createSendButton();
    interface->sendButtonText = createSendButtonText(interface->font, interface->sendButton);
    interface->messageCount = 0;
    interface->scroll = 0;
    init_model_menu(interface);
    return interface;
}
