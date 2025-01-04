/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy.c                                                 :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/30 12:35:24 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/30 12:35:24 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "chatbot.h"

void destroy(chatbot_t *interface)
{
    if (interface->window)
        sfRenderWindow_destroy(interface->window);
    if (interface->font)
        sfFont_destroy(interface->font);
    if (interface->input.background)
        sfRectangleShape_destroy(interface->input.background);
    if (interface->input.text)
        sfText_destroy(interface->input.text);
    if (interface->sendButton)
        sfRectangleShape_destroy(interface->sendButton);
    if (interface->sendButtonText)
        sfText_destroy(interface->sendButtonText);
    free(interface);
    curl_global_cleanup();
}
