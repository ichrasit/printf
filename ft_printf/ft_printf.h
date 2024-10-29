/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:20:38 by muhaoz            #+#    #+#             */
/*   Updated: 2024/10/29 03:31:36 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
int print_format(va_list *ags, char x);
int ft_putchar(char c);
int check(char str);
int print_point(unsigned long w, int i);
int print_hex(unsigned int a, char x);
int print_string(char *str);
int print_unsigned(unsigned int x);
int print_int(int x);

#endif