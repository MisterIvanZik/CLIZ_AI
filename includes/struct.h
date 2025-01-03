/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   struct.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 13:12:42 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 13:12:42 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef STRUCT_H
    #define STRUCT_H
    #include "include.h"

typedef struct window_s {
    sfRenderWindow *Window;
    sfVideoMode VideoMode;
    sfVector2u windowSize;
    sfEvent event;
    sfVector2i mousePos;
    sfSprite *backSprite;
    sfTexture *backTexture;
    sfVector2f backScale;
    sfVector2f backPos;
} window_t;

typedef struct cliz_s {
    window_t *window;
} cliz_t;

#endif
