#include "../includes/libftprintf.h"

static int ft_parse_flag(const char *format, size_t *i, t_element *element)
{
	if (format[*i] == '0')
		element->flags = element->flags | zero_padding;
	else if (format[*i] == '-')
		element->flags = element->flags | negative_field_width;
	else if (format[*i] == '#')
		element->flags = element->flags | alternate_form;
	else if (format[*i] == ' ')
		element->flags = element->flags | prepend_negative_or_space;
	else if (format[*i] == '+')
		element->flags = element->flags | prepend_sign;
	else
		return (1);
	(*i)++;
	return (0);
}

static int ft_parse_minimum_field_width(const char *format, size_t *i, t_element *element)
{
	element->minimum_field_width = 0;
	while (ft_isdigit(format[*i]))
	{
		element->minimum_field_width *= 10;
		element->minimum_field_width += format[*i];
		element->minimum_field_width -= '0';
		(*i)++;
	}
	return (0);
}

static int ft_parse_precision(const char *format, size_t *i, t_element *element)
{
	if (format[*i] != '.')
		return (1);
	(*i)++;
	element->flags = element->flags | precision_is_set;
	element->precision = 0;
	while (ft_isdigit(format[*i]))
	{
		element->precision *= 10;
		element->precision += format[*i];
		element->precision -= '0';
		(*i)++;
	}
	return (0);
}

static int ft_parse_conversion_type(const char *format, size_t *i, t_element *element, va_list arg_list)
{
	if (format[*i] == 'c')
		element->content_string = ft_convert_c(va_arg(arg_list, int));
	else if (format[*i] == 'd')
		element->content_string = ft_convert_d(va_arg(arg_list, int));
	else if (format[*i] == 'i')
		element->content_string = ft_convert_i(va_arg(arg_list, int));
	else if (format[*i] == 'p')
		element->content_string = ft_convert_p(va_arg(arg_list, void *));
	else if (format[*i] == '%')
		element->content_string = ft_convert_percent();
	else if (format[*i] == 's')
		element->content_string = ft_convert_s(va_arg(arg_list, char *));
	else if (format[*i] == 'u')
		element->content_string = ft_convert_u(va_arg(arg_list, unsigned int));
	else if (format[*i] == 'x')
		element->content_string = ft_convert_x(va_arg(arg_list, int));
	else if (format[*i] == 'X')
		element->content_string = ft_convert_x_upper(va_arg(arg_list, int));
	else
		return (1);
	element->conversion_type = format[*i];
	(*i)++;
	return (0);
}

t_element *ft_parser(const char *format, size_t *i, va_list arg_list)
{
	t_element *element;
	int error;

	if (format[*i] != '%')
		return (NULL);
	(*i)++;
	element = ft_element_create_empty();
	if (!element)
		return (NULL);
	error = 0;
	while (ft_isinstr(format[*i], "cspdiuxX%0-# +123456789.") && error == 0)
	{
		if (ft_isinstr(format[*i], "cspdiuxX%"))
		{
			error = ft_parse_conversion_type(format, i, element, arg_list);
			if (!error)
				return (element);
		}
		else if (ft_isinstr(format[*i], "0-# +"))
			error = ft_parse_flag(format, i, element);
		else if (ft_isinstr(format[*i], "123456789"))
			error = ft_parse_minimum_field_width(format, i, element);
		else if (ft_isinstr(format[*i], "."))
			error = ft_parse_precision(format, i, element);
		else
			error = 1;
	}
	free(element);
	return (NULL);
}