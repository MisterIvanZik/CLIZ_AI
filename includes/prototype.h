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

button_t *createButton(sfVector2f buttonPos, sfColor buttonOutlineColor, const char *buttonName, sfColor buttonNameColor);
sfText* createText(const char* string, unsigned int textSize, sfVector2f textPos, sfColor textColor);
void destroyButton(button_t *button);

char *my_strncpy(char *dest, char *src, int n);
int my_strlen(char *str);
char *my_strdup(char *str1);
int my_strcmp(char *str1, char *str2);

window_t *init_homepage(window_t *window);
void close_window(cliz_t *cliz);
int handle_events(cliz_t *cliz);
void handle_homepage_events(cliz_t *cliz, sfEvent event);
void draw_homepage(cliz_t *cliz);
void destroy_homepage(window_t *window);

login_t *init_login_page(login_t *login);
void check_login_user(cliz_t *cliz);
void process_user_input(login_t *login, sfEvent event);
void handle_login_events(cliz_t *cliz, sfEvent event);
void draw_login_page(cliz_t *cliz);
void destroy_login_page(login_t *login);

void homepage(cliz_t *cliz);

#endif
