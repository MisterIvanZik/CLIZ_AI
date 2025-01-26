/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   events.c                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:15:47 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:15:47 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

void handle_mouse_click(chatbot_t *interface, sfVector2i mousePos)
{
    sfFloatRect inputBounds = sfRectangleShape_getGlobalBounds(interface->input.background);
    sfFloatRect buttonBounds = sfRectangleShape_getGlobalBounds(interface->sendButton);

    if (sfFloatRect_contains(&inputBounds, mousePos.x, mousePos.y))
        interface->input.isActive = sfTrue;
    else if (sfFloatRect_contains(&buttonBounds, mousePos.x, mousePos.y))
        send_message(interface);
    else
        interface->input.isActive = sfFalse;
}

void handle_key_press(chatbot_t *interface, sfKeyCode key)
{
    if (key == sfKeyReturn && interface->input.isActive)
        send_message(interface);
    else if (key == sfKeyEscape) {
        exit(0);
        sfRenderWindow_close(interface->window);
    }
}

void handle_scroll(chatbot_t *interface, sfEvent event)
{
    if (event.mouseWheelScroll.wheel == sfMouseVerticalWheel) {
        float messagesHeight = 0;
        sfText *text = sfText_create();
        sfText_setFont(text, interface->font);
        sfText_setCharacterSize(text, 18);
        for (int i = 0; i < interface->messageCount; i++)
            messagesHeight += calculate_message_height(text, interface->messages[i].content);
        sfText_destroy(text);
        interface->scroll -= event.mouseWheelScroll.delta * 20;
        if (interface->scroll < 0) {
            interface->scroll = 0;
        }
    }
}

void handle_mouse_events(chatbot_t *interface, sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft) {
        sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
        handle_mouse_click(interface, mousePos);
    }
}

void handle_chatbot_events(chatbot_t *interface)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(interface->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(interface->window);
                break;
            case sfEvtMouseButtonPressed:
                handle_mouse_events(interface, event);
                break;
            case sfEvtTextEntered:
                handle_text_input(interface, event);
                break;
            case sfEvtKeyPressed:
                handle_key_press(interface, event.key.code);
                break;
            case sfEvtMouseWheelScrolled:
                handle_scroll(interface, event);
                break;
        }
    }
}
