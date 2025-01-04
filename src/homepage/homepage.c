/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   homepage.c                                                :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/03 21:50:06 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/03 21:50:06 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"
#include "chatbot.h"

void draw_current_page(cliz_t *cliz)
{
    switch (cliz->window->statePage) {
        case HOME_PAGE:
            draw_homepage(cliz);
            break;
        case CHATBOT_PAGE:
            // initAiInterface();
            break;
        case SIGN_UP_PAGE:
            // Draw sign up page
            break;
        case LOGIN_PAGE:
            draw_login_page(cliz);
            break;
        default:
            break;
    }
}

void homepage(cliz_t *cliz)
{
    cliz->window = init_window(cliz->window);
    cliz->login = login_page(cliz->login);
    while (sfRenderWindow_isOpen(WINDOW)) {
        handle_events(cliz);
        draw_current_page(cliz);
        sfRenderWindow_display(WINDOW);
    }
    destroyButton(cliz->login->email);
    destroyButton(cliz->login->password);
    sfText_destroy(cliz->login->login);
    sfSprite_destroy(cliz->window->backSprite);
    sfTexture_destroy(cliz->window->backTexture);
    sfRenderWindow_destroy(WINDOW);
}
