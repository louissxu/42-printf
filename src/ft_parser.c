#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdarg.h>

int priv_ft_parse_flag(const char *format, size_t *format_i, t_element *element)
{
	if (format[*format_i] == '0')
		element->flags = element->flags | zero_padding;
	else if (format[*format_i] == '-')
		element->flags = element->flags | negative_field_width;
	else if (format[*format_i] == '#')
		element->flags = element->flags | alternate_form;
	else if (format[*format_i] == ' ')
		element->flags = element->flags | prepend_negative_or_space;
	else if (format[*format_i] == '+')
		element->flags = element->flags | prepend_sign;
	else
		return (1);
	(*format_i)++;
	return (0);
}

int priv_ft_parse_minimum_field_width(const char *format, size_t *format_i, t_element *element)
{
	element->minimum_field_width = 0;
	while (ft_isdigit(format[*format_i]))
	{
		element->minimum_field_width *= 10;
		element->minimum_field_width += format[*format_i];
		element->minimum_field_width -= '0';
		(*format_i)++;
	}
	return (0);
}

int priv_ft_parse_precision(const char *format, size_t *format_i, t_element *element)
{
	if (format[*format_i] != '.')
		return (1);
	(*format_i)++;
	element->flags = element->flags | precision_is_set;
	element->precision = 0;
	while (ft_isdigit(format[*format_i]))
	{
		element->precision *= 10;
		element->precision += format[*format_i];
		element->precision -= '0';
		(*format_i)++;
	}
	return (0);
}

int priv_ft_parse_conversion_type(const char *format, size_t *format_i, t_element *element, va_list arg_list)
{
	if (!ft_isinstr(format[*format_i], "cspdiuxX%"))
		return (1);
	element->conversion_type = format[*format_i];
	if (format[*format_i] == 'c')
		element->content_string = ft_convert_c(va_arg(arg_list, int));
	else if (format[*format_i] == 'd')
		element->content_string = ft_convert_d(va_arg(arg_list, int));
	else if (format[*format_i] == 'i')
		element->content_string = ft_convert_i(va_arg(arg_list, int));
	else if (format[*format_i] == 'p')
		element->content_string = ft_convert_p(va_arg(arg_list, void *));
	else if (format[*format_i] == '%')
		element->content_string = ft_convert_percent();
	else if (format[*format_i] == 's')
		element->content_string = ft_convert_s(va_arg(arg_list, char *));
	else if (format[*format_i] == 'u')
		element->content_string = ft_convert_u(va_arg(arg_list, unsigned int));
	else if (format[*format_i] == 'x')
		element->content_string = ft_convert_x(va_arg(arg_list, int));
	else if (format[*format_i] == 'X')
		element->content_string = ft_convert_x_upper(va_arg(arg_list, int));
	else
		return (1);
	(*format_i)++;
	return (0);
}

t_element *priv_ft_parse_conversion(const char *format, size_t *format_i, va_list arg_list)
{
	t_element *element;
	int error;

	if (format[*format_i] != '%')
		return (NULL);
	(*format_i)++;
	element = ft_element_create_empty();
	if (!element)
	{
		return (NULL);
	}
	error = 0;
	while (ft_isinstr(format[*format_i], "cspdiuxX%0-# +123456789.") && error == 0)
	{
		if (ft_isinstr(format[*format_i], "cspdiuxX%"))
		{
			error = priv_ft_parse_conversion_type(format, format_i, element, arg_list);
			if (!error)
				return (element);
		}
		else if (ft_isinstr(format[*format_i], "0-# +"))
			error = priv_ft_parse_flag(format, format_i, element);
		else if (ft_isinstr(format[*format_i], "123456789"))
			error = priv_ft_parse_minimum_field_width(format, format_i, element);
		else if (ft_isinstr(format[*format_i], "."))
			error = priv_ft_parse_precision(format, format_i, element);
		else
			error = 1;
	}
	free(element);
	return (NULL);
}

t_element *ft_parser(const char *format, size_t *i, va_list arg_list)
{
	t_element *element;

	element = priv_ft_parse_conversion(format, i, arg_list);
	return (element);
}