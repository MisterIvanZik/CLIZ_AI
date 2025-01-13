/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   create_functions.c                                        :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:57:06 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:57:06 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"

button_t *createButton(sfVector2f buttonPos, sfVector2f buttonSize, const char *buttonName, sfColor buttonNameColor)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->rec = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rec, buttonSize);
    sfRectangleShape_setPosition(button->rec, buttonPos);
    sfRectangleShape_setFillColor(button->rec, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->rec, 2);
    sfRectangleShape_setOutlineColor(button->rec, sfTransparent);
    button->text = sfText_create();
    button->textPos = (sfVector2f){buttonPos.x, buttonPos.y};
    sfText_setString(button->text, buttonName);
    sfText_setFont(button->text, SETFONT);
    sfText_setCharacterSize(button->text, 24);
    sfText_setColor(button->text, buttonNameColor);
    sfText_setPosition(button->text, button->textPos);

    return button;
}

sfText* createText(const char* string, unsigned int textSize, sfVector2f textPos, sfColor textColor)
{
    sfText* text = sfText_create();

    sfText_setString(text, string);
    sfText_setFont(text, SETFONT);
    sfText_setCharacterSize(text, textSize);
    sfText_setColor(text, textColor);
    sfText_setPosition(text, textPos);
    return text;
}
