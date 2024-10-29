/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:28:04 by muhaoz            #+#    #+#             */
/*   Updated: 2024/10/29 03:31:52 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ags;
    int len = 0;
    int tmp;
    int count = 0;

    va_start(ags, str);
    while (str[count] != '\0')
    {
        if (str[count] == '%' && check(str[count + 1]))
        {
            tmp = print_format(&ags, str[++count]);
            if (tmp == -1)
            {
                va_end(ags);
                return -1;
            }
            len += tmp;
        }
        else
        {
            if (ft_putchar(str[count]) == -1) // ft_putchar kullanıldı
            {
                va_end(ags);
                return -1;
            }
            len++;
        }
        count++;
    }
    va_end(ags);
    return len;
}

int check(char str)
{
    return (str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i' ||
            str == 'u' || str == 'x' || str == 'X' || str == '%');
}

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int print_format(va_list *ags, char x)
{
    if (x == 'c')
        return (ft_putchar(va_arg((*ags), int)));
    else if (x == '%')
        return (ft_putchar('%'));
    else if (x == 'd' || x == 'i')
        return (print_int(va_arg((*ags), int)));
    else if (x == 'u')
        return (print_unsigned(va_arg((*ags), unsigned int)));
    else if (x == 'x' || x == 'X')
        return (print_hex(va_arg((*ags), unsigned int), x));
    else if (x == 'p')
        return (print_point(va_arg((*ags), unsigned long), 1));
    else if (x == 's')
        return (print_string(va_arg((*ags), char *)));
    return 0;
}
