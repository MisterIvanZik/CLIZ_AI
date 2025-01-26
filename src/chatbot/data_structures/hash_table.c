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

// Fonction de hachage XOR Hash
unsigned int hash_function(const char *key)
{
    unsigned int hash = 0;

    while (*key) {
        hash ^= (unsigned char)*key++;
    }
    return hash % HASH_SIZE;
}

// Création d'une nouvelle table de hachage
hash_table_t *hash_create(void)
{
    hash_table_t *table = malloc(sizeof(hash_table_t));

    if (!table)
        return NULL;
    table->size = HASH_SIZE;
    table->count = 0;
    table->items = malloc(HASH_SIZE * sizeof(hash_item_t*));
    if (!table->items) {
        free(table);
        return NULL;
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        table->items[i] = NULL;
    }
    return table;
}

// Insertion d'un nouvel élément
int hash_insert(hash_table_t *table, const char *question, const char *response)
{
    unsigned int index;
    hash_item_t *new_item;

    if (!new_item || !table || !question || !response)
        return 0;
    index = hash_function(question);
    new_item = malloc(sizeof(hash_item_t));
    new_item->question = strdup(question);
    new_item->response = strdup(response);
    new_item->timestamp = time(NULL);
    new_item->next = NULL;
    if (!new_item->question || !new_item->response) {
        free(new_item->question);
        free(new_item->response);
        free(new_item);
        return 0;
    }
    if (table->items[index]) // Gestion des collisions par chaînage
        new_item->next = table->items[index];
    table->items[index] = new_item;
    table->count++;
    return 0;
}

// Recherche d'un élément
char *hash_search(hash_table_t *table, const char *question)
{
    unsigned int index;
    hash_item_t *current;
    time_t current_time = time(NULL);

    if (!table || !question)
        return NULL;
    index = hash_function(question);
    current = table->items[index];
    while (current) {
        if (my_strcmp(current->question, question) == 0) {
            if (current_time - current->timestamp <= CACHE_EXPIRATION) // Vérifier si l'entrée n'a pas expiré
                return current->response;
            return NULL;
        }
        current = current->next;
    }
    return NULL;
}

// Nettoyage des entrées expirées
void hash_cleanup(hash_table_t *table)
{
    time_t current_time = time(NULL);

    if (!table)
        return;
    for (int i = 0; i < table->size; i++) {
        hash_item_t *current = table->items[i];
        hash_item_t *prev = NULL;
        while (current) {
            if (current_time - current->timestamp > CACHE_EXPIRATION) {
                if (prev == NULL) // Suppression de l'élément expiré
                    table->items[i] = current->next;
                else
                    prev->next = current->next;
                free(current->question);
                free(current->response);
                hash_item_t *tmp = current;
                current = current->next;
                free(tmp);
                table->count--;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

// Destruction de la table
void hash_destroy(hash_table_t *table)
{
    hash_item_t *current;
    hash_item_t *tmp;

    if (!table)
        return;
    for (int i = 0; i < table->size; i++) {
        current = table->items[i];
        while (current) {
            tmp = current;
            current = current->next;
            free(temp->question);
            free(temp->response);
            free(temp);
        }
    }
    free(table->items);
    free(table);
}
