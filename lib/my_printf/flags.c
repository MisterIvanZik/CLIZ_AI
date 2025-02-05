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

#include "../../header/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    return (0);
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
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_unsigned_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    return (0);
}

int my_intflags(char *format, va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return (0);
}

int my_charflags(char *format, va_list ap)
{
    my_putchar(va_arg(ap, int));
    return (0);
}

int my_strflags(char *format, va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return (0);
}

int my_unsigned_int(char *format, va_list ap)
{
    my_unsigned_nbr(va_arg(ap, unsigned int));
    return (0);
}

int my_percent_flag(char *format, va_list ap)
{
    my_putchar('%');
    return (0);
}
