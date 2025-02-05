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

#include "prototypes.h"

void destroy_interface(chatbot_t *interface)
{
    if (!interface)
        return;
    if (interface->responseCache)
        hash_destroy(interface->responseCache);
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
    for (int i = 0; i < 3; i++) {
        if (interface->modelTexts[i])
            sfText_destroy(interface->modelTexts[i]);
        if (interface->modelBackground[i])
            sfRectangleShape_destroy(interface->modelBackground[i]);
    }
    for (int i = 0; i < interface->messageCount; i++) {
        if (interface->messages[i].background) {
            sfRectangleShape_destroy(interface->messages[i].background);
        }
    }
    free(interface);
    curl_global_cleanup();
}
