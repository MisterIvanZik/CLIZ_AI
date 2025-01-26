/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   api.c                                                     :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/28 12:23:54 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/28 12:23:54 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "prototypes.h"

// Réception des données de la réponse HTTP
size_t callback(void *receivedData, size_t sizeOfOneElement, size_t numberOfElements, void *userData)
{
    size_t total_received_size = sizeOfOneElement * numberOfElements;
    api_t *response_buffer = (api_t *)userData;

    *response_buffer->data = realloc(*response_buffer->data, *response_buffer->size + total_received_size + 1);
    if (*response_buffer->data == NULL)
        return 0;
    memcpy(*response_buffer->data + *response_buffer->size, receivedData, total_received_size); // Copie des données reçues dans le buffer
    *response_buffer->size += total_received_size;
    (*response_buffer->data)[*response_buffer->size] = '\0';
    return total_received_size;
}

// Prépare le corps de la requête JSON à envoyer à l'API
char *prepareJsonPayload(CURL *curl, char *userInput)
{
    char *escapedInput = curl_easy_escape(curl, userInput, 0);
    char *buffer = malloc(my_strlen(escapedInput) + 1000);

    if (escapedInput == NULL || buffer == NULL)
        return NULL;
    char *template = "{\"model\":\"%s\","
             "\"messages\":["
             "{\"role\":\"system\",\"content\":\"Tu répondra le plus simplement possible sans donner trop de détails\"},"
             "{\"role\":\"user\",\"content\":\"%s\"}"
             "]}"; // Formatage du corps de la requête
    snprintf(buffer, 1000, template, MODEL, escapedInput);
    curl_free(escapedInput);
    return buffer;
}

// Extrait la réponse de l'IA à partir des données JSON reçues
char *extractAiResponse(char *data)
{
    json_object *json = json_tokener_parse(data); // Conversion des données JSON en objet JSON
    char *aiResponse = NULL;

    if (!json)
        return NULL;
    json_object *choices = json_object_object_get(json, "choices"); // tableau contenant les choix de réponses de l'IA
    if (!choices) {
        json_object_put(json);
        return NULL;
    }
    json_object *first_choice = json_object_array_get_idx(choices, 0); // Séléction du premier choix du tableau
    if (!first_choice) {
        json_object_put(json);
        return NULL;
    }
    json_object *message = json_object_object_get(first_choice, "message"); // informations sur la réponse de l'IA
    if (!message) {
        json_object_put(json);
        return NULL;
    }
    json_object *content = json_object_object_get(message, "content"); // chaine contenant la réponse texte de l'IA
    if (!content) {
        json_object_put(json);
        return NULL;
    }
    aiResponse = strdup(json_object_get_string(content));
    json_object_put(json);
    return aiResponse;
}

// Fonction principale pour interagir avec l'API
char *getAiResponse(chatbot_t *interface, char *userInput)
{
    // Vérifier d'abord dans le cache
    char *cached_response = hash_search(interface->responseCache, userInput);

    if (cached_response != NULL)
        return strdup(cached_response);  // Retourner une copie de la réponse du cache
    // Si pas dans le cache, appeler l'API
    CURL *curl = curl_easy_init(); // crée un objet CURL -> ouvrir un navigateur pour faire une requête à un site web
    char *data = NULL;
    size_t dataSize = 0;
    api_t response = {&data, &dataSize};
    char *jsonPayload = prepareJsonPayload(curl, userInput);
    struct curl_slist *httpHeaders = NULL;
    char *aiResponse = NULL;
    CURLcode curlResult;

    // Préparation des en-têtes HTTP
    httpHeaders = curl_slist_append(httpHeaders, "Content-Type: application/json"); // indiquer que c'est de type JSON
    httpHeaders = curl_slist_append(httpHeaders, "Authorization: Bearer " API_KEY); // indiquer la clé d'API
    // Configuration des options CURL
    curl_easy_setopt(curl, CURLOPT_URL, API_BASE "/chat/completions"); // URL de l'API
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload); // corps de la requête
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback); // fonction de rappel pour traiter les données reçues
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response); // stocker les données reçues
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, httpHeaders); // en-têtes HTTP à envoyer
    curlResult = curl_easy_perform(curl); // envoie de la requête
    if (curlResult == CURLE_OK)
        aiResponse = extractAiResponse(data);
    curl_easy_cleanup(curl);
    curl_slist_free_all(httpHeaders);
    free(jsonPayload);
    free(data);
    if (aiResponse) {
        // Stocker la réponse dans le cache avant de la retourner
        hash_insert(interface->responseCache, userInput, aiResponse);
        return aiResponse;
    } else {
        printf("Désolé, je n'ai pas pu obtenir de réponse.\n");
        return NULL;
    }
}
