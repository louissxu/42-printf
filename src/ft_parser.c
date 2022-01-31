#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdarg.h>

t_element *priv_ft_parse_first(const char *format, size_t *format_i, va_list arg_list)
{
	t_element	*element;

	va_arg(arg_list, int);
	element = malloc(sizeof (*element) * 1);
	if (!element)
	{
		return (NULL);
	}
	if (format[*format_i])
	{
		priv_ft_parse_char(format[*format_i], &element);
		(*format_i)++;
	}
	return (element);
}

t_element	*priv_ft_create_empty_element()
{
	t_element	*element;
	
	element = malloc(sizeof (*element) * 1);
	if (!element)
	{
		return (NULL);
	}
	element->input_arg = NULL;
	element->flags = 0;
	element->conversion_type = '\0';
	element->is_conversion = '\0';
	element->precision = 0;
	element->minimum_field_width = 0;
	element->content_string = NULL;
	return(element);
}

void	priv_ft_parse_char(const char *format, size_t *format_i, t_element **element)
{
	if (format[*format_i] == '0')
		(*element)->flags = (*element)->flags | zero_padding;
	else if (format[*format_i] == '-')
		(*element)->flags = (*element)->flags | negative_field_width;
	else if (format[*format_i] == '#')
		(*element)->flags = (*element)->flags | alternate_form;
	else if (format[*format_i] == ' ')
		(*element)->flags = (*element)->flags | prepend_negative_or_space;
	else if (format[*format_i] == '+')
		(*element)->flags = (*element)->flags | prepend_sign;
	return ;
}

t_element	*priv_ft_parse_conversion(const char *format, size_t *format_i, va_list arg_list)
{
	t_element	*element;

	va_arg(arg_list, int);
	element = priv_ft_create_empty_element;
	if (!element)
	{
		return (NULL);
	}
	while(!ft_isinstr(format[*format_i], "cspdiuxX%"))
	{
		if 
	}

	size_t end_i = *format_i;
	(*format_i)--;
	while(format[end_i] && format[end_i] != '%')
	{
		end_i++;
	}
	element->content_string = malloc(sizeof (*(element->content_string)) * (end_i - *format_i + 1));
	ft_memcpy(element->content_string, &(format[*format_i]), end_i - *format_i + 1);
	(element->content_string)[end_i - *format_i] = '\0';
	*format_i = end_i;
	return (element);
}

t_element *priv_ft_parse_plain(const char *format, size_t *format_i)
{
	t_element	*element;
	size_t		str_start;
	size_t		str_end;
	char			*str_copy;

	str_start = *format_i;
	str_end = str_start;
	while (format[str_end]!= '\0' && format[str_end] != '%')
	{
		str_end++;
	}
	element = malloc(sizeof (*element) * 1);
	str_copy = malloc(sizeof (*str_copy) * (str_end - str_start + 1));
	if (!element || !str_copy)
	{
		if (element)
			free(element);
		if (str_copy)
			free(str_copy);
		return (NULL);
	}
	ft_memcpy(str_copy, &(format[str_start]), str_end - str_start + 1);
	str_copy[str_end - str_start] = '\0';
	element->content_string = str_copy;
	element->is_conversion = 0;
	*format_i = str_end;
	return (element);
}

t_list	*ft_parser(const char *format, va_list arg_list)
{
	t_list	*head;
	t_list	*current;
	size_t	i;
	t_element	*element;

	head = NULL;
	i = 0;
	va_arg(arg_list, int);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			element = priv_ft_parse_conversion(format, &i, arg_list);
		}
		else
		{
			element = priv_ft_parse_plain(format, &i);
		}
		//TODO: if not element, destroy, return.
		current = ft_lstnew(element);
		ft_lstadd_back(&head, current);
	}
	return (head);
}