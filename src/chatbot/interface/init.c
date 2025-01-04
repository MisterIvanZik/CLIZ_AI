/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init.c                                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:27:23 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:27:23 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "chatbot.h"

void initAiInterface(void)
{
    chatbot_t *interface = create_chat_interface();

    if (interface && interface->window)
        add_message(interface, "Bien le bonjour ! Je suis votre assistant Cliz AI ! Comment puis-je vous aider aujourd'hui?", sfFalse);
    while (sfRenderWindow_isOpen(interface->window)) {
        handle_chatbot_events(interface);
        draw_chatbot(interface);
    }
    destroy(interface);
}
