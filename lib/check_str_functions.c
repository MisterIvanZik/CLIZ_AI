/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   check_str_functions.c                                     :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/02/02 15:32:23 by lisika                #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/02/02 15:32:23 by lisika               ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "includes.h"

int has_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            return 1;
    }
    return 0;
}

int has_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i]))
            return 1;
    }
    return 0;
}

int has_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]))
            return 1;
    }
    return 0;
}

int has_special(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]))
            return 1;
    }
    return 0;
}
