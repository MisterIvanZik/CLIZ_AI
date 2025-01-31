/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   flags.c                                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/31 11:33:01 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/31 11:33:01 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        nb = nb % 10;
        my_putchar(nb % 10 + 48);
    }
    return (nb);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_unsigned_nbr(unsigned int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_unsigned_nbr(nb / 10);
        nb = nb % 10;
        my_putchar(nb % 10 + 48);
    }
    return (nb);
}

int my_intflags(char *format, va_list ap)
{
    int i = i + 1;

    my_put_nbr(va_arg(ap, int));
    return (0);
}

int my_charflags(char *format, va_list ap)
{
    int i = i + 1;

    my_putchar(va_arg(ap, int));
    return (0);
}

int my_strflags(char *format, va_list ap)
{
    int i = i + 1;

    my_putstr(va_arg(ap, char *));
    return (0);
}

int my_unsigned_int(char *format, va_list ap)
{
    int i = i + 1;

    my_unsigned_nbr(va_arg(ap, int));
    return (0);
}
