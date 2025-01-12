/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   includes.h                                                :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2024/12/28 12:35:12 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2024/12/28 12:35:12 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef INCLUDES_H_
    #define INCLUDES_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <curl/curl.h>
    #include <json-c/json.h>
    #include <SFML/Graphics.h>
    #define MAX_MESSAGES 100
    #define MAX_INPUT_LENGTH 190
    #define KEY_DELETE '\b'
    #define API_KEY "glhf_bb498ff02a2a44460700746943cb0afd"
    #define API_BASE "https://glhf.chat/api/openai/v1"
    #define MODEL "hf:Qwen/Qwen2.5-7B-Instruct"

typedef struct api_s {
    char **data;
    size_t *size;
} api_t;

typedef struct input_s {
    sfRectangleShape *background;
    sfText *text;
    char content[1000];
    sfBool isActive;
} input_t;

typedef struct message_s{
    char content[1000];
    sfBool isUser;
    sfRectangleShape *background;
} message_t;

typedef struct chatbot_s {
    sfRenderWindow *window;
    sfFont *font;
    input_t input;
    message_t messages[MAX_MESSAGES];
    int messageCount;
    sfText *displayText;
    sfRectangleShape *sendButton;
    sfText *sendButtonText;
    int scroll;
} chatbot_t;

size_t callback(void *ptr, size_t size, size_t nmemb, void *stream);
char *getAiResponse(char *user_input);
input_t create_input_box(sfFont *font);
chatbot_t *create_chat_interface(void);
void add_message(chatbot_t *interface, char *content, sfBool isUser);
void send_message(chatbot_t *interface);
void draw_chatbot(chatbot_t *interface);
void destroy(chatbot_t *interface);
void handle_chatbot_events(chatbot_t *interface);
float calculate_message_height(sfText *messageText, char *content);
void draw_messages(chatbot_t *interface);
void handle_text_input(chatbot_t *interface, sfEvent event);
void destroy(chatbot_t *interface);
void initAiInterface(void);
char *my_strncpy(char *dest, char *src, int n);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);

#endif