/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   hash_table.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/26 03:10:47 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/26 03:10:47 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

// Fonction de hachage (addition des valeurs ASCII)
unsigned int hash_function(const char *key)
{
    unsigned int hash = 0;

    for (;*key; hash += (unsigned char)*key++);
    return hash % HASH_SIZE;
}

hash_table_t *hash_create(void)
{
    hash_table_t *table = malloc(sizeof(hash_table_t));

    if (!table)
        return NULL;
    table->size = HASH_SIZE;
    table->count = 0;
    table->items = malloc(HASH_SIZE * sizeof(hash_item_t *));
    for (int i = 0; i < HASH_SIZE; i++)
        table->items[i] = NULL;
    return table;
}

// Insertion d'un nouvel élément
int insert_elem(hash_table_t *table, const char *question, const char *response)
{
    unsigned int index = 0;
    hash_item_t *new_item = NULL;

    if (!table || !question || !response)
        return 84;
    new_item = malloc(sizeof(hash_item_t));
    if (!new_item)
        return 84;
    new_item->question = strdup(question);
    new_item->response = strdup(response);
    if (!new_item->question || !new_item->response) {
        free(new_item->question);
        free(new_item->response);
        free(new_item);
        return 84;
    }
    new_item->timestamp = time(NULL);
    new_item->next = NULL;
    index = hash_function(question);
    if (table->items[index]) // Gestion des collisions
        new_item->next = table->items[index];
    table->items[index] = new_item;
    table->count++;
    return 0;
}

// Recherche d'un élément
char *search_elem(hash_table_t *table, const char *question)
{
    unsigned int index = 0;
    hash_item_t *current = NULL;
    time_t current_time = time(NULL);

    if (!table || !question)
        return NULL;
    index = hash_function(question);
    current = table->items[index];
    while (current) {
        if (strcmp(current->question, question) == 0)
            return NULL;
        current = current->next;
    }
    return NULL;
}

void hash_destroy(hash_table_t *table)
{
    hash_item_t *current = NULL;
    hash_item_t *tmp = NULL;

    if (!table)
        return;
    for (int i = 0; i < table->size; i++) {
        current = table->items[i];
        while (current) {
            tmp = current;
            current = current->next;
            free(tmp->question);
            free(tmp->response);
            free(tmp);
        }
    }
    free(table->items);
    free(table);
}
