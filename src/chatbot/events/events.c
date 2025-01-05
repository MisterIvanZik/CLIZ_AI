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

#include "chatbot.h"

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

void handle_chatbot_events(chatbot_t *interface)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(interface->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(interface->window);
                break;
            case sfEvtMouseButtonPressed:
                if (event.mouseButton.button == sfMouseLeft) {
                    sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
                    handle_mouse_click(interface, mousePos);
                }
                break;
            case sfEvtTextEntered:
                handle_text_input(interface, event);
                break;
            case sfEvtKeyPressed:
                handle_key_press(interface, event.key.code);
                break;
        }
    }
}