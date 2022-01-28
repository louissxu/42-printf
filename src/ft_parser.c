#include "../includes/libftprintf.h"
#include <stdarg.h>

int priv_ft_parse_char(char c, t_element **element)
{
	if (c == '0')
		(*element)->flags = (*element)->flags | zero_padding;
	else if (c == '-')
		(*element)->flags = (*element)->flags | negative_field_width;
	else if (c == '#')
		(*element)->flags = (*element)->flags | alternate_form;
	else if (c == ' ')
		(*element)->flags = (*element)->flags | prepend_negative_or_space;
	else if (c == '+')
		(*element)->flags = (*element)->flags | prepend_sign;
}

int priv_ft_parse_first(const char *format, size_t *format_i, va_list arg_list, t_list **head)
{
	t_element	*element;

	element = malloc(sizeof (*element) * 1);
	if (format[*format_i] == '%')
	{
		(*format_i)++;
		
		
	}
}

int ft_parser(const char *format, va_list arg_list)
{
	t_element	*head;
	t_element	*current;
	size_t		i;
	size_t		str_len;

	current = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			// handle special
		}
		else
		{
			str_len = 0;

		}
	}
}