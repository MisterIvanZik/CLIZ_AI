/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy_window.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/12 22:55:52 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/12 22:55:52 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

void destroy_window(window_t *window)
{
    sfRenderWindow_destroy(window->Window);
    free(window);
}
