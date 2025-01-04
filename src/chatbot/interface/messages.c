/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   messages.c                                                :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/31 00:53:40 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/31 00:53:40 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "chatbot.h"

void add_message(chatbot_t *ai, char *content, sfBool isUser)
{
    int size = my_strlen(content);

    if (ai->messageCount < MAX_MESSAGES) {
        my_strncpy(ai->messages[ai->messageCount].content, content, size);
        ai->messages[ai->messageCount].content[size] = '\0';
        ai->messageCount++;
    }
}

float calculate_message_height(sfText *messageText, char *content)
{
    sfText_setString(messageText, content);
    sfFloatRect bounds = sfText_getGlobalBounds(messageText);
    return bounds.height + 30;
}

void draw_single_message(chatbot_t *ai, sfText *messageText, char *content, float x, float y)
{
    sfText_setColor(messageText, sfBlack);
    sfText_setPosition(messageText, (sfVector2f){x, y});
    sfRenderWindow_drawText(ai->window, messageText, NULL);
}

void draw_messages(chatbot_t *ai)
{
    sfText *messageText = sfText_create();
    sfText_setFont(messageText, ai->font);
    sfText_setCharacterSize(messageText, 18);
    float maxWidthMess = 0;
    int currentPos = 40;

    for (int i = 0; i < ai->messageCount; i++) {
        maxWidthMess = calculate_message_height(messageText, ai->messages[i].content);
        draw_single_message(ai, messageText, ai->messages[i].content, 30, currentPos);
        currentPos += maxWidthMess;
    }
    sfText_destroy(messageText);
}

void send_message(chatbot_t *ai)
{
    char *ai_response = NULL;

    if (my_strlen(ai->input.content) > 0) {
        add_message(ai, ai->input.content, sfTrue);
        if (ai_response = getAiResponse(ai->input.content)) {
            add_message(ai, ai_response, sfFalse);
            free(ai_response);
        }
        ai->input.content[0] = '\0';
        sfText_setString(ai->input.text, "");
    }
}
