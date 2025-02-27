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

#include "prototypes.h"

static void draw_current_page(cliz_t *cliz)
{
    switch (cliz->window->statePage) {
        case HOME_PAGE:
            draw_homepage(cliz);
            break;
        case CHATBOT_PAGE:
            initAiInterface();
            break;
        case SIGN_UP_PAGE:
            draw_sign_up_page(cliz);
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
    cliz->homepage = init_homepage(cliz->homepage, WINDOW_SIZE);
    cliz->login = init_login_page(cliz->login, WINDOW_SIZE);
    cliz->sign = init_sign_up_page(cliz->sign, WINDOW_SIZE);
    cliz->user_list = NULL;

    load_users_from_file(cliz, "database.txt");
    while (sfRenderWindow_isOpen(WINDOW)) {
        handle_events(cliz);
        draw_current_page(cliz);
        sfRenderWindow_display(WINDOW);
    }
    destroy_user_list(cliz->user_list);
    destroy_sign_up_page(cliz->sign);
    destroy_login_page(cliz->login);
    destroy_homepage(cliz->homepage);
    destroy_window(cliz->window);
}
