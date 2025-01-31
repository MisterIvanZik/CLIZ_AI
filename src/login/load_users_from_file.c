/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   load_users_from_file.c                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/11 23:46:24 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/11 23:46:24 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

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

void load_users_from_file(cliz_t *cliz, const char *filename)
{
    char *name = (char *)malloc(NAME_BUFFER * sizeof(char));
    char *email = (char *)malloc(EMAIL_BUFFER * sizeof(char));
    char *password = (char *)malloc(PASSWORD_BUFFER * sizeof(char));
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        my_printf("Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return;
    }
    if (name == NULL || email == NULL || password == NULL) {
        free(name);
        free(email);
        free(password);
        return;
    }
    while (fscanf(file, "%[^:]:%[^:]:%s\n", name, email, password) == 3) {
        if (add_node(&cliz->user_list, name, email, password) != 0) {
            my_printf("Erreur : impossible d'ajouter l'utilisateur %s\n", name);
        }
    }
    fclose(file);
    free(name);
    free(email);
    free(password);
}
