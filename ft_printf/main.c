/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:40:57 by muhaoz            #+#    #+#             */
/*   Updated: 2024/10/29 03:41:36 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int num = 42;
    ft_printf("Hello, %s!\n", "world");                 // String formatı
    ft_printf("Decimal: %d, Hexadecimal: %x\n", 42, 42); // Decimal ve hex formatı
    ft_printf("This is char : %c\n", 'C');               // Karakter formatı
    ft_printf("This is sign %%\n");                      // Yüzde işareti
    ft_printf("This is point : %p\n", &num);             // Pointer formatı
    ft_printf("This is u : %u\n", num);                  // Unsigned decimal formatı
    ft_printf("This is lowcase hex : %x\n", num);        // Hexadecimal (küçük harf)
    ft_printf("This is upcase hex : %X\n", num);         // Hexadecimal (büyük harf)
    ft_printf("This is integer : %i\n", 42);             // Integer formatı

    return 0;
}

