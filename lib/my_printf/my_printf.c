/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   my_printf.c                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/31 11:33:07 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/31 11:33:07 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "../../header/my_printf.h"

void my_getflags(char flg, va_list ap, char *format)
{
    char c;

    for (int i = 0; i < NB_FLAGS; i++) {
        if (array_fct[i].c == flg)
            array_fct[i].ptr(format, ap);
    }
}

int my_printf(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            my_getflags(format[i + 1], ap, format);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return (0);
}
