/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   sign_up.c                                                 :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 14:08:55 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 14:08:55 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static user_t *create_node(char *name, char *email, char *password)
{
    user_t *new_node = (user_t *)malloc(sizeof(user_t));

    if (new_node == NULL)
        return NULL;
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->password = strdup(password);
    if (new_node->name == NULL || new_node->email == NULL || new_node->password == NULL) {
        free(new_node->name);
        free(new_node->email);
        free(new_node->password);
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    return new_node;
}

static int add_node(user_t **head, char *name, char *email, char *password)
{
    user_t *new_node = create_node(name, email, password);

    if (new_node == NULL)
        return 84;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int sign_up(FILE *file, cliz_t *cliz)
{
    user_t *current = cliz->user_list;
    user_t *new_user = cliz->sign->user;

    while (current != NULL) {
        if (strcmp(current->email, new_user->email) == 0) {
            return 1;
        }
        current = current->next;
    }
    if (add_node(&cliz->user_list, new_user->name, new_user->email, new_user->password) != 0) {
        return 84;
    }
    fprintf(file, "%s:%s:%s\n", new_user->name, new_user->email, new_user->password);
    return 0;
}
