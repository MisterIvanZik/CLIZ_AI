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

#include "chatbot.h"

size_t callback(void *receivedData, size_t sizeOfOneElement, size_t numberOfElements, void *userData)
{
    size_t total_received_size = sizeOfOneElement * numberOfElements;
    api_t *response_buffer = (api_t *)userData;

    *response_buffer->data = realloc(*response_buffer->data, *response_buffer->size + total_received_size + 1);
    if (*response_buffer->data == NULL)
        return 0;
    memcpy(*response_buffer->data + *response_buffer->size, receivedData, total_received_size);
    *response_buffer->size += total_received_size;
    (*response_buffer->data)[*response_buffer->size] = '\0';
    return total_received_size;
}

char *prepareJsonPayload(CURL *curl, char *userInput)
{
    char *escapedInput = curl_easy_escape(curl, userInput, 0);
    char *buffer = malloc(my_strlen(escapedInput) * 1000);

    if (escapedInput == NULL || buffer == NULL)
        return NULL;
    char *template = "{\"model\":\"%s\","
             "\"messages\":["
             "{\"role\":\"system\",\"content\":\"Tu répondra le plus simplement possible sans donner trop de détails\"},"
             "{\"role\":\"user\",\"content\":\"%s\"}"
             "]}";
    snprintf(buffer, 1000, template, MODEL, escapedInput);
    curl_free(escapedInput);
    return buffer;
}

char *extractAiResponse(char *data)
{
    json_object *json = json_tokener_parse(data);
    char *aiResponse = NULL;

    if (!json)
        return NULL;
    json_object *choices = json_object_object_get(json, "choices");
    json_object *first_choice = json_object_array_get_idx(choices, 0);
    json_object *message = json_object_object_get(first_choice, "message");
    json_object *content = json_object_object_get(message, "content");
    aiResponse = strdup(json_object_get_string(content));
    json_object_put(json);
    return aiResponse;
}

char *getAiResponse(char *userInput)
{
    CURL *curl = curl_easy_init();
    char *data = NULL;
    size_t dataSize = 0;
    api_t response = {&data, &dataSize};
    char *jsonPayload = prepareJsonPayload(curl, userInput);
    struct curl_slist *httpHeaders = NULL;
    char *aiResponse = NULL;
    CURLcode curlResult;

    httpHeaders = curl_slist_append(httpHeaders, "Content-Type: application/json");
    httpHeaders = curl_slist_append(httpHeaders, "Authorization: Bearer " API_KEY);
    curl_easy_setopt(curl, CURLOPT_URL, API_BASE "/chat/completions");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, httpHeaders);
    curlResult = curl_easy_perform(curl);
    if (curlResult == CURLE_OK)
        aiResponse = extractAiResponse(data);
    curl_easy_cleanup(curl);
    free(jsonPayload);
    if (aiResponse) {
        return aiResponse;
    } else {
        printf("Désolé, je n'ai pas pu obtenir de réponse.\n");
        return NULL;
    }
}