/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   prototype.h                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:09:30 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:09:30 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_
    #include "include.h"
    #include "struct.h"

sfVector2f set_window_size(sfVector2u windowSize,
    sfTexture *texture, sfSprite *sprite);
sfTexture *settexture(char *filepath);
sfSprite *setsprite(sfTexture *texture);
sfFont *setfont(char *filepath);

button_t *createButton(sfVector2f buttonPos, sfColor buttonFillColor, const char *buttonName, sfColor buttonNameColor);
sfText* createText(const char* string, unsigned int textSize, sfVector2f textPos, sfColor textColor);
void destroyButton(button_t *button);

window_t *init_window(window_t *window);
int handle_events(cliz_t *cliz);
void events_homepage(cliz_t *cliz);
void draw_homepage(cliz_t *cliz);

void draw_login_page(cliz_t *cliz);
login_t *login_page(login_t *login);

void homepage(cliz_t *cliz);

#endif
