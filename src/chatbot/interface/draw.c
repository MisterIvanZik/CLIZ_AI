/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   draw.c                                                     :+:       :+:    :+: :+:    :+:    :+:       */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/30 12:44:06 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/30 12:44:06 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "chatbot.h"

void draw_chatbot(chatbot_t *interface)
{
    sfRenderWindow_clear(interface->window, sfColor_fromRGB(169, 169, 169));
    draw_messages(interface);
    sfRenderWindow_drawRectangleShape(interface->window, interface->input.background, NULL);
    sfRenderWindow_drawText(interface->window, interface->input.text, NULL);
    sfRenderWindow_drawRectangleShape(interface->window, interface->sendButton, NULL);
    sfRenderWindow_drawText(interface->window, interface->sendButtonText, NULL);
    sfRenderWindow_display(interface->window);
}
