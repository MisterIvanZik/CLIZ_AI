/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   defines.h                                                 :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/26 03:46:03 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/26 03:46:03 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef DEFINES_H_
    #define DEFINES_H_
    /* Constantes de la fenêtre */
    #define WINDOW_NAME "CLIZ_AI"
    #define WINDOW cliz->window->Window
    #define WINDOW_SIZE cliz->window->windowSize
    #define EVENT cliz->window->event
    #define MOUSE_POS sfMouse_getPositionRenderWindow(WINDOW)

    /* Chemins des assets */
    #define LIGHT_HOMEPAGE "./assets/images/home_page_light.png"
    #define DARK_HOMEPAGE "./assets/images/home_page_dark.png"
    #define LIGHT_LOGIN "./assets/images/light_login.png"
    #define DARK_LOGIN "./assets/images/dark_login.png"
    #define LIGHT_SIGN_UP "./assets/images/light_sign_up.png"
    #define DARK_SIGN_UP "./assets/images/dark_sign_up.png"
    #define MOON_ICON "./assets/images/moon_icon.png"
    #define SUN_ICON "./assets/images/sun_icon.png"
    #define FONT "./assets/fonts/noto.ttf"
    #define SETFONT setfont(FONT)

    /* Constantes du chatbot */
    #define MAX_MESSAGES 100
    #define MAX_INPUT_LENGTH 190
    #define KEY_DELETE '\b'
    #define API_KEY "glhf_bb498ff02a2a44460700746943cb0afd"
    #define API_BASE "https://glhf.chat/api/openai/v1"
    #define MODEL1 "hf:Qwen/Qwen2.5-Coder-32B-Instruct"
    #define MODEL2 "hf:mistralai/Mistral-7B-Instruct-v0.3"
    #define MODEL3 "hf:meta-llama/Llama-3.2-3B-Instruct"

    /* Tailles des buffers */
    #define NAME_BUFFER 50
    #define EMAIL_BUFFER 100
    #define PASSWORD_BUFFER 50

    /* Constantes de la table de hachage */
    #define HASH_SIZE 100

#endif
