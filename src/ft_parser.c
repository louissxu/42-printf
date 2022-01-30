#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdarg.h>

int priv_ft_parse_char(char c, t_element **element)
{
	// if (c == '0')
	// 	(*element)->flags = (*element)->flags | zero_padding;
	// else if (c == '-')
	// 	(*element)->flags = (*element)->flags | negative_field_width;
	// else if (c == '#')
	// 	(*element)->flags = (*element)->flags | alternate_form;
	// else if (c == ' ')
	// 	(*element)->flags = (*element)->flags | prepend_negative_or_space;
	// else if (c == '+')
	// 	(*element)->flags = (*element)->flags | prepend_sign;
	(*element)->content_string = ft_strdup(&c);
	return (0);
}

t_element *priv_ft_parse_first(const char *format, size_t *format_i, va_list arg_list)
{
	t_element	*element;

	va_arg(arg_list, int);
	element = malloc(sizeof (*element) * 1);
	if (format[*format_i])
	{
		priv_ft_parse_char(format[*format_i], &element);
		(*format_i)++;
	}
	return (element);
}

t_list	*ft_parser(const char *format, va_list arg_list)
{
	t_list	*head;
	t_list	*current;
	size_t	i;
	//t_element	*element;

	head = NULL;
	i = 0;
	while (format[i])
	{
		current = ft_lstnew(priv_ft_parse_first(format, &i, arg_list));
		ft_lstadd_back(&head, current);
	}
	return (head);
}