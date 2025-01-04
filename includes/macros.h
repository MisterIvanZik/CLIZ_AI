/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   macros.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/29 12:26:59 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/29 12:26:59 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MACROS_H
    #define MACROS_H
    #include "prototype.h"
    #define WINDOW_NAME "CLIZ_AI"
    #define WINDOW cliz->window->Window
    #define HOMEPAGE "./assets/images/homepage.jpg"
    #define FONT "./assets/fonts/peach.ttf"
    #define SETFONT setfont(FONT)
    #define MOUSE_POS sfMouse_getPositionRenderWindow(WINDOW)

#endif
