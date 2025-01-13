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
    #define WINDOW_SIZE cliz->window->windowSize
    #define LIGHT_HOMEPAGE "./assets/images/light_homepage.jpeg"
    #define DARK_HOMEPAGE "./assets/images/dark_homepage.jpeg"
    #define MOON_ICON "./assets/images/moon_icon.png"
    #define LIGHT_LOGIN "./assets/images/light_login.jpg"
    #define DARK_LOGIN "./assets/images/dark_login.png"
    #define SUN_ICON "./assets/images/sun_icon.png"
    #define FONT "./assets/fonts/InterVariable.ttf"
    #define SETFONT setfont(FONT)
    #define EVENT cliz->window->event
    #define MOUSE_POS sfMouse_getPositionRenderWindow(WINDOW)
    #define NAME_BUFFER 50
    #define EMAIL_BUFFER 100
    #define PASSWORD_BUFFER 50

#endif
