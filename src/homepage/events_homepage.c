/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   events_homepage.c                                         :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/04 14:33:28 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/04 14:33:28 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void toggle_theme(homepage_t *homepage)
{
    if (homepage->is_dark_theme) {
        homepage->backTexture = settexture(LIGHT_HOMEPAGE);
        homepage->iconTexture = settexture(MOON_ICON);
        sfText_setColor(homepage->sign_text, sfWhite);
        sfText_setColor(homepage->login_text, sfWhite);
        sfText_setPosition(homepage->sign_text, (sfVector2f){900, 750});
        sfText_setPosition(homepage->login_text, (sfVector2f){1265, 750});
    } else {
        homepage->backTexture = settexture(DARK_HOMEPAGE);
        homepage->iconTexture = settexture(SUN_ICON);
        sfText_setColor(homepage->sign_text, sfWhite);
        sfText_setColor(homepage->login_text, sfWhite);
        sfText_setPosition(homepage->sign_text, (sfVector2f){890, 685});
        sfText_setPosition(homepage->login_text, (sfVector2f){1340, 685});
    }
    sfSprite_setTexture(homepage->backSprite, homepage->backTexture, sfTrue);
    sfSprite_setTexture(homepage->iconSprite, homepage->iconTexture, sfTrue);
    homepage->is_dark_theme = !homepage->is_dark_theme;
}

static int get_clicked_button(sfVector2i mouse_pos, Switch_Page *clicked_button, homepage_t *homepage)
{
    sfFloatRect iconBounds = sfSprite_getGlobalBounds(homepage->iconSprite);

    if (mouse_pos.x >= 485 && mouse_pos.x <= 735 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *clicked_button = CHATBOT_PAGE;
        return 1;
    }
    if (mouse_pos.x >= 830 && mouse_pos.x <= 1092 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *clicked_button = SIGN_UP_PAGE;
        return 1;
    }
    if (mouse_pos.x >= 1180 && mouse_pos.x <= 1430 &&
        mouse_pos.y >= 775 && mouse_pos.y <= 875) {
        *clicked_button = LOGIN_PAGE;
        return 1;
    }
    if (sfFloatRect_contains(&iconBounds, mouse_pos.x, mouse_pos.y)) {
        *clicked_button = TOGGLE_THEME;
        return 1;
    }
    return 0;
}

static void events_homepage(cliz_t *cliz)
{
    sfVector2i mouse_pos = MOUSE_POS;
    Switch_Page clicked_button;

    if (!get_clicked_button(mouse_pos, &clicked_button, cliz->homepage))
        return;

    switch (clicked_button) {
        case CHATBOT_PAGE:
            cliz->window->statePage = CHATBOT_PAGE;
            break;
        case SIGN_UP_PAGE:
            cliz->window->statePage = SIGN_UP_PAGE;
            break;
        case LOGIN_PAGE:
            cliz->window->statePage = LOGIN_PAGE;
            break;
        case TOGGLE_THEME:
            toggle_theme(cliz->homepage);
            break;
        default:
            break;
    }
}

void handle_homepage_events(cliz_t *cliz, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        events_homepage(cliz);
}
