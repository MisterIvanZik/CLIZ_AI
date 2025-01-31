/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   my_printf.h                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/01/31 11:33:21 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/01/31 11:33:21 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef PTR_H
    #define PTR_H
    #include "includes.h"
    #include "prototypes.h"
    #define NB_FLAGS 5

typedef struct ptr_fct {
    char c;
    int (*ptr)(char *format, va_list ap);
} ptr_fct_t;

static const ptr_fct_t array_fct[] = {
    {'c', &my_charflags},
    {'s', &my_strflags},
    {'d', &my_intflags},
    {'i', &my_intflags},
    {'u', &my_unsigned_int},
};

#endif
