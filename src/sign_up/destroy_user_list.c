/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   destroy_user_list.c                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 23:44:52 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 23:44:52 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

void destroy_user_list(user_t *head)
{
    user_t *current = head;
    user_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current->email);
        free(current->password);
        free(current);
        current = next;
    }
}
