/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   authentification_user.c                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/06 00:15:45 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/06 00:15:45 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"
#include "macros.h"
#include "struct.h"
#include "prototype.h"

static void read_login_data(const char *filename, char *email, char *password)
{
    FILE *file = fopen(filename, "r");
    char line[256];
    char *token;

    if (file == NULL)
        return;
    if (fgets(line, sizeof(line), file)) {
        token = strtok(line, ";");
        if (token) {
            strncpy(email, token, 50);
            token = strtok(NULL, ";");
            if (token) {
                strncpy(password, token, 50);
                password[strcspn(password, "\n")] = '\0';
            }
        }
    }

    fclose(file);
}

void check_login_user(cliz_t *cliz)
{
    char stored_email[50];
    char stored_password[50];

    read_login_data("database.txt", stored_email, stored_password);
    if (strcmp(cliz->login->email_input, stored_email) == 0 &&
        strcmp(cliz->login->password_input, stored_password) == 0) {
        printf("Connexion réussie !\n");
        cliz->window->statePage = CHATBOT_PAGE;
    } else {
        printf("Échec de la connexion. Email ou mot de passe incorrect.\n");
    }
}
