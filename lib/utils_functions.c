/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   utils_functions.c                                         :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/05 14:58:15 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/05 14:58:15 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "include.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int z = 0;

    while (src[z] != '\0' && z < n) {
        dest[z] = src[z];
        z = z + 1;
        dest[z] = '\0';
    }
    return dest;
}

int my_strlen(char *str)
{
    int z = 0;

    while (str[z] != '\0')
        z = z + 1;
    return z;
}

char *my_strdup(char *str1)
{
    int read = my_strlen(str1);
    char *str2;
    int i = 0;

    str2 = malloc(sizeof(str1) * (read + 1));
    if (str2 == NULL)
        return NULL;
    while (i < read) {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    return str2;
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
        i++;
    return (str1[i] - str2[i]);
}
