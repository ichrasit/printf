/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:26 by muhaoz            #+#    #+#             */
/*   Updated: 2024/10/29 03:33:41 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_int(int x)
{
    int len = 0;
    int temp;

    if (x == 0)
        return (write(1, "0", 1));
    if (x == -2147483648)
        return (write(1, "-2147483648", 11));
    if (x < 0)
    {
        if (write(1, "-", 1) == -1)
            return -1;
        len++;
        x *= -1;
    }
    if (x >= 10)
    {
        temp = print_int(x / 10);
        if (temp == -1)
            return -1;
        len += temp;
    }
    if (write(1, &"0123456789"[x % 10], 1) == -1)
        return -1;
    return len + 1;
}

int print_unsigned(unsigned int x)
{
    int len = 0;
    int temp;

    if (x >= 10)
    {
        temp = print_unsigned(x / 10);
        if (temp == -1)
            return -1;
        len += temp;
    }
    if (write(1, &"0123456789"[x % 10], 1) == -1)
        return -1;
    return len + 1;
}

int print_string(char *str)
{
    int i = 0;

    if (str == NULL)
    {
        if (write(1, "(null)", 6) == -1)
            return -1;
        return 6;
    }
    while (str[i])
    {
        if (write(1, &str[i], 1) == -1)
            return -1;
        i++;
    }
    return i;
}

int print_hex(unsigned int a, char x)
{
    int len = 0;
    int temp;

    if (a >= 16)
    {
        temp = print_hex(a / 16, x);
        if (temp == -1)
            return -1;
        len += temp;
    }
    if (x == 'X')
    {
        if (write(1, &"0123456789ABCDEF"[a % 16], 1) == -1)
            return -1;
    }
    else if (x == 'x')
    {
        if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
            return -1;
    }
    return len + 1;
}

int print_point(unsigned long w, int i)
{
    int len = 0;
    int temp;

    if (i == 1)
    {
        if (write(1, "0x", 2) == -1)
            return -1;
        len += 2;
    }
    if (w >= 16)
    {
        temp = print_point(w / 16, 0);
        if (temp == -1)
            return -1;
        len += temp;
    }
    if (write(1, &"0123456789abcdef"[w % 16], 1) == -1)
        return -1;
    return len + 1;
}
