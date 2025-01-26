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

#include "prototypes.h"

void add_message(chatbot_t *ai, char *content, sfBool isUser)
{
    int size = my_strlen(content);

    if (ai->messageCount < MAX_MESSAGES) {
        my_strncpy(ai->messages[ai->messageCount].content, content, size);
        ai->messages[ai->messageCount].content[size] = '\0';
        ai->messages[ai->messageCount].isUser = isUser;
        ai->messages[ai->messageCount].background = sfRectangleShape_create();
        sfRectangleShape_setSize(ai->messages[ai->messageCount].background, (sfVector2f){600, 40});
        sfRectangleShape_setFillColor(ai->messages[ai->messageCount].background, isUser ? sfColor_fromRGB(200, 220, 255) : sfColor_fromRGB(240, 240, 240));
        sfRectangleShape_setOutlineThickness(ai->messages[ai->messageCount].background, 1);
        sfRectangleShape_setOutlineColor(ai->messages[ai->messageCount].background, sfColor_fromRGB(180, 180, 180));
        ai->messageCount++;
    }
}

float calculate_message_height(sfText *messageText, char *content)
{
    sfText_setString(messageText, content);
    sfFloatRect bounds = sfText_getGlobalBounds(messageText);
    return bounds.height + 30;
}

void draw_single_message(chatbot_t *ai, sfText *messageText, char *content, float x, float y, sfBool isUser, int index)
{
    sfRectangleShape *background = ai->messages[index].background;
    sfFloatRect textBounds = sfText_getGlobalBounds(messageText);
    sfRectangleShape_setSize(background, (sfVector2f){textBounds.width + 20, textBounds.height + 20});
    sfRectangleShape_setPosition(background, (sfVector2f){x - 10, y - 10});
    sfRenderWindow_drawRectangleShape(ai->window, background, NULL);
    sfText_setColor(messageText, sfBlack);
    sfText_setPosition(messageText, (sfVector2f){x, y});
    sfRenderWindow_drawText(ai->window, messageText, NULL);
}

void draw_messages(chatbot_t *ai)
{
    sfText *messageText = sfText_create();
    float maxWidthMess = 0;
    int currentPos = 40 - ai->scroll;

    sfText_setFont(messageText, ai->font);
    sfText_setCharacterSize(messageText, 18);
    for (int i = 0; i < ai->messageCount; i++) {
        maxWidthMess = calculate_message_height(messageText, ai->messages[i].content);
        draw_single_message(ai, messageText, ai->messages[i].content, 30, currentPos, ai->messages[i].isUser, i);
        currentPos += maxWidthMess + 20;
    }
    sfText_destroy(messageText);
}

void send_message(chatbot_t *ai)
{
    char *ai_response = NULL;
    char *special_response = NULL;

    if (my_strlen(ai->input.content) > 0) {
        add_message(ai, ai->input.content, sfTrue);
        if (my_strcmp(ai->input.content, "Qui est le meilleur prof de l'ESGI ?") == 0) {
            special_response = "Monsieur Trancho mais chut c'est un secret !";
        }
        if (special_response) {
            add_message(ai, special_response, sfFalse);
        } else if (ai_response = getAiResponse(ai, ai->input.content)) {
            add_message(ai, ai_response, sfFalse);
            free(ai_response);
        }
        ai->input.content[0] = '\0';
        sfText_setString(ai->input.text, "");
    }
}
