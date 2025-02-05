/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   unit_tests.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2025/02/05 15:45:54 by ivan                  #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2025/02/05 15:45:54 by ivan                 ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "../header/includes.h"
#include "../header/prototypes.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(char *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_s, .init = redirect_all_std)
{
    my_printf("%s", "Monsieur Trancho est un excellent professeur de C");
    cr_assert_stdout_eq_str("Monsieur Trancho est un excellent professeur de C");
}

Test(my_printf, flag_d, .init = redirect_all_std)
{
    my_printf("%d", 123456789);
    cr_assert_stdout_eq_str("123456789");
}

Test(my_printf, flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'I');
    cr_assert_stdout_eq_str("I");
}

Test(my_printf, flag_i, .init = redirect_all_std)
{
    my_printf("%i", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, flag_u, .init = redirect_all_std)
{
    my_printf("%u", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, flag_u_signed_int, .init = redirect_all_std)
{
    my_printf("%u", -45);
    cr_assert_stdout_eq_str("4294967251");
}

Test(my_printf, flag_pourcentage, .init = redirect_all_std)
{
    my_printf("%%", '%');
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, multiple_integer, .init = redirect_all_std)
{
    int i = -2;
    int v = 6;
    int r = 54;
    int f = 630;

    my_printf("%i %i %i %i", i, v, r, f);
    cr_assert_stdout_eq_str("-2 6 54 630");
}

Test(my_printf, test_my_printf_i, .init = redirect_all_std)
{
    my_printf("%i", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, test_my_printf_i2, .init = redirect_all_std)
{
    my_printf("%i", -42);
    cr_assert_stdout_eq_str("-42");
}

Test(my_printf, test_my_printf_i3, .init = redirect_all_std)
{
    my_printf("%i", 261203);
    cr_assert_stdout_eq_str("261203");
}

Test(my_printf, test_my_printf_i4, .init = redirect_all_std)
{
    my_printf("%i", -261203);
    cr_assert_stdout_eq_str("-261203");
}

Test(my_printf, test_my_printf_d1, .init = redirect_all_std)
{
    my_printf("%d", 125);
    cr_assert_stdout_eq_str("125");
}

Test(my_printf, test_my_printf_d2, .init = redirect_all_std)
{
    my_printf("%d", -217);
    cr_assert_stdout_eq_str("-217");
}

Test(my_printf, test_my_printf_c1, .init = redirect_all_std)
{
    my_printf("%c", 'i');
    cr_assert_stdout_eq_str("i");
}

Test(my_printf, test_my_printf_c2, .init = redirect_all_std)
{
    my_printf("%c", 'X');
    cr_assert_stdout_eq_str("X");
}

Test(my_printf, test_my_printf_c3, .init = redirect_all_std)
{
    my_printf("%c", '7');
    cr_assert_stdout_eq_str("7");
}

Test(my_printf, test_my_printf_s2, .init = redirect_all_std)
{
    my_printf("%s", "Hamilton est le goat actuelle...");
    cr_assert_stdout_eq_str("Hamilton est le goat actuelle...");
}

Test(my_printf, test_my_printf_s3, .init = redirect_all_std)
{
    my_printf("%s", "gogo");
    cr_assert_stdout_eq_str("gogo");
}

Test(my_printf, test_my_printf_pourecnt, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_my_printf_u, .init = redirect_all_std)
{
    my_printf("%u", 123);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_my_printf_u2, .init = redirect_all_std)
{
    my_printf("%u", -123);
    cr_assert_stdout_eq_str("4294967173");
}

Test(my_printf, test_my_printf_multiple_pourcent, .init = redirect_all_std)
{
    char *str = "clara";
    int nb = 18;
    my_printf("%s %i %i", str, nb, 12);
    cr_assert_stdout_eq_str("clara 18 12");
}

Test(my_printf, test_my_printf_same_pourcent, .init = redirect_all_std)
{
    my_printf("%i %i %i", 0, -42, -2147483647);
    cr_assert_stdout_eq_str("0 -42 -2147483647");
}

Test(my_printf, test_my_printf_multi_char, .init = redirect_all_std)
{
    my_printf("%c %c %c", 'A', 'v', 'B');
    cr_assert_stdout_eq_str("A v B");
}

Test(utils, test_my_strncpy_normal, .init = redirect_all_std)
{
    char dest[20] = {0};
    char *src = "hello world";

    my_strncpy(dest, src, 5);
    cr_assert_str_eq(dest, "hello", "Expected dest to be \"hello\"");
}

Test(utils, test_my_strlen, .init = redirect_all_std)
{
    cr_assert_eq(my_strlen(""), 0, "Expected length of empty string to be 0");
    cr_assert_eq(my_strlen("hello"), 5, "Expected length of \"hello\" to be 5");
    cr_assert_eq(my_strlen("hello world"), 11, "Expected length of \"hello world\" to be 11");
}

Test(utils, test_my_strcmp_equal, .init = redirect_all_std)
{
    cr_assert_eq(my_strcmp("test", "test"), 0, "Expected identical strings to return 0");
}

Test(utils, test_my_strcmp_less, .init = redirect_all_std)
{
    int cmp = my_strcmp("abc", "abd");

    cr_assert(cmp < 0, "Expected \"abc\" to be less than \"abd\"");
}

Test(utils, test_my_strcmp_greater, .init = redirect_all_std)
{
    int cmp = my_strcmp("abd", "abc");

    cr_assert(cmp > 0, "Expected \"abd\" to be greater than \"abc\"");
}
