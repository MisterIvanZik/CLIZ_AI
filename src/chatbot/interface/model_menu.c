/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   model_menu.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/02/05 17:59:00 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/02/05 17:59:00 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

sfText *create_model_text(sfFont *font, int index, const char *model_name)
{
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1720, 20 + (index * 50)});
    sfText_setString(text, model_name);
    return text;
}

sfRectangleShape *create_model_background(int index, sfBool isSelected)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape_setSize(background, (sfVector2f){180, 40});
    sfRectangleShape_setPosition(background, (sfVector2f){1710, 10 + (index * 50)});
    sfRectangleShape_setFillColor(background, isSelected ? sfColor_fromRGB(200, 200, 255) : sfWhite);
    return background;
}

void init_model_menu(chatbot_t *interface)
{
    char *model_names[3] = {"-> Qwen", "-> Mistral", "-> Llama"};

    interface->selectedModel = 0;
    for (int i = 0; i < 3; i++) {
        interface->modelTexts[i] = create_model_text(interface->font, i, model_names[i]);
        interface->modelBackground[i] = create_model_background(i, i == 0);
    }
}

void handle_model_selection(chatbot_t *interface, sfVector2i mousePos)
{
    sfFloatRect model_bounds;

    for (int i = 0; i < 3; i++) {
        model_bounds = sfRectangleShape_getGlobalBounds(interface->modelBackground[i]);
        if (sfFloatRect_contains(&model_bounds, mousePos.x, mousePos.y)) {
            sfRectangleShape_setFillColor(interface->modelBackground[interface->selectedModel], sfWhite);
            interface->selectedModel = i;
            sfRectangleShape_setFillColor(interface->modelBackground[i], sfColor_fromRGB(200, 200, 255));
            switch(i) {
                case 0:
                    printf("Modèle sélectionné : %s\n", MODEL1);
                    break;
                case 1:
                    printf("Modèle sélectionné : %s\n", MODEL2);
                    break;
                case 2:
                    printf("Modèle sélectionné : %s\n", MODEL3);
                    break;
            }
            return;
        }
    }
}
