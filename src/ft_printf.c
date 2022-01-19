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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*str;
	int		bytes_printed;

	bytes_printed = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == 'c')
				str = ft_convert_c(va_arg(ap, int));
			else if (format[i + 1] == 's')
				str = ft_convert_s(va_arg(ap, char *));
			else if (format[i + 1] == 'p')
				str = ft_convert_p(va_arg(ap, void *));
			else if (format[i + 1] == 'd')
				str = ft_convert_d(va_arg(ap, int));
			else if (format[i + 1] == 'i')
				str = ft_convert_i(va_arg(ap, int));
			else if (format[i + 1] == 'u')
				str = ft_convert_u(va_arg(ap, unsigned int));
			else if (format[i + 1] == 'x')
				str = ft_convert_x(va_arg(ap, int));
			else if (format[i + 1] == 'X')
				str = ft_convert_x_upper(va_arg(ap, int));
			else if (format[i + 1] == '%')
				str = ft_convert_percent();
			if (format[i + 1] == 'c')
				bytes_printed += write(1, str, 1);
			else
				bytes_printed += write(1, str, ft_strlen(str));
			free(str);
			i += 2;
		}
		else
		{
			bytes_printed += write(1, &format[i], 1);
			i++;
		}
	}
	return (bytes_printed);
}
