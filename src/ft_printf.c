/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:24:41 by lxu               #+#    #+#             */
/*   Updated: 2022/01/19 14:41:01 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

//rename priv to static
//remove is_conversion flag (not used)
//when precision set to .0 dont print zero padding if minimum field width. ie check out %020.0p

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t i;
	t_element *element;
	size_t bytes_printed;

	va_start(ap, format);
	i = 0;
	bytes_printed = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			element = ft_parser(format, &i, ap);
			if (element)
			{
				bytes_printed += ft_element_print(element);
				ft_element_destroy(element);
			}
		}
		else
		{
			bytes_printed += write(1, &format[i], 1);
			i++;
		}
	}
	return (bytes_printed);
}
