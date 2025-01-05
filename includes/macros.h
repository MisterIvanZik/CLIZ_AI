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
    #define FONT "./assets/fonts/CreatoDisplay-Regular.otf"
    #define SETFONT setfont(FONT)
    #define EVENT cliz->window->event
    #define MOUSE_POS sfMouse_getPositionRenderWindow(WINDOW)
    #define LOGIN_BUTTON "./assets/images/login_button.png"
    #define LOGIN_ICON "./assets/images/login_icon.png"

#endif
